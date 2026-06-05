// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qversitutils_p.h"

#include <QtCore/qstring.h>
#include <QtCore/qstringconverter.h>
#include <QtCore/qvariant.h>

#include <QtCore/QJsonArray>
#include <QtCore/QJsonDocument>
#include <QtCore/QJsonValue>

#include "qversitdocument.h"

QT_BEGIN_NAMESPACE_VERSIT

QStringConverter::Encoding VersitUtils::m_previousEncoding = QStringConverter::Utf8;
QList<QByteArrayMatcher>* VersitUtils::m_newlineList = 0;
QByteArray VersitUtils::m_encodingMap[256];
QBasicMutex VersitUtils::m_staticLock;
bool VersitUtils::m_initialized = false;

/*!
 * Encode \a ch with \a encoding, without adding a byte-order mark
 */
QByteArray VersitUtils::encode(char ch, QStringConverter::Encoding encoding)
{
    changeCodec(encoding);
    return m_encodingMap[(unsigned char)ch];
}

/*!
 * Encode \a ba with \a encoding, without adding a byte-order mark.  \a ba is interpreted as ASCII
 */
QByteArray VersitUtils::encode(const QByteArray& ba, QStringConverter::Encoding encoding)
{
    QStringEncoder enc(encoding);
    return enc.encode(QString::fromLatin1(ba.constData(), ba.size()));
}

/*!
 * Returns the list of DOS, UNIX and Mac newline characters for \a encoding.
 */
QList<QByteArrayMatcher>* VersitUtils::newlineList(QStringConverter::Encoding encoding)
{
    changeCodec(encoding);
    return m_newlineList;
}

/*!
 * Update the cached tables of pregenerated encoded text with \a encoding.
 */
void VersitUtils::changeCodec(QStringConverter::Encoding encoding) {
    QMutexLocker readWriterLocker(&VersitUtils::m_staticLock);

    if (m_initialized && encoding == m_previousEncoding)
        return;

    // Build m_encodingMap
    QStringEncoder enc(encoding);
    for (int c = 0; c < 256; c++) {
        QString qch = QString(QLatin1Char(c));
        m_encodingMap[c] = enc.encode(qch);
    }

    // Build m_newlineList
    if (m_newlineList != 0)
        delete m_newlineList;
    m_newlineList = new QList<QByteArrayMatcher>;
    m_newlineList->append(QByteArrayMatcher(encode("\r\n", encoding)));
    m_newlineList->append(QByteArrayMatcher(encode("\n", encoding)));
    m_newlineList->append(QByteArrayMatcher(encode("\r", encoding)));

    m_previousEncoding = encoding;
    m_initialized = true;
}

/*!
 * Finds a property in the \a document with the given \a propertyName, adds it to \a toBeRemoved,
 * and returns it.
 */
QVersitProperty VersitUtils::takeProperty(const QVersitDocument& document,
                                          const QString& propertyName,
                                          QList<QVersitProperty>* toBeRemoved) {
    for (const QVersitProperty& currentProperty : document.properties()) {
        if (currentProperty.name() == propertyName) {
            *toBeRemoved << currentProperty;
            return currentProperty;
        }
    }
    return QVersitProperty();
}

/*!
 * Returns true iff \a bytes is a valid UTF-8 sequence.
 */
bool VersitUtils::isValidUtf8(const QByteArray& bytes) {
    int sequenceLength = 1; // number of bytes in total for a sequence
    int continuation = 0;   // number of bytes left in a continuation
    quint32 codePoint = 0;
    for (int i = 0; i < bytes.size(); i++) {
        quint8 byte = bytes[i];
        if (continuation == 0) {
            if (byte & 0x80) { // 1xxxxxxx
                if (byte & 0x40) { // 11xxxxxx
                    if (byte == 0xc0 || byte == 0xc1) // 1100000x
                        return false; // overlong 2 byte sequence
                    if (byte & 0x20) { // 111xxxxx
                        if (byte & 0x10) { // 1111xxxx
                            if (byte & 0x08) { // 11111xxx
                                // Outside unicode range
                                return false;
                            } else { // 11110xxx
                                sequenceLength = 4;
                                continuation = 3; // three more bytes
                                codePoint = byte & 0x07; // take the last 3 bits
                            }
                        } else { // 1110xxxx
                            sequenceLength = 3;
                            continuation = 2; // two more bytes
                            codePoint = byte & 0x0f; // take last 4 bits
                        }
                    } else { // 110xxxxx
                        sequenceLength = 2;
                        continuation = 1; // one more byte
                        codePoint = byte & 0x1f; // take last 5 bits
                    }
                } else { // 10xxxxxx
                    // unexpected continuation
                    return false;
                }
            } else { // 0xxxxxxx
                sequenceLength = 1;
            }
        } else { // continuation > 0
            if ((byte & 0xc0) != 0x80) // 10xxxxxx
                return false; // expected continuation not found
            codePoint = (codePoint << 6) | (byte & 0x3f); // append last 6 bits
            continuation--;
        }

        if (continuation == 0) {
            // Finished decoding a character - it's not overlong and that it's in range
            switch (sequenceLength) {
                // 1-byte sequence can't be overlong
                // 2-byte sequence has already been checked for overlongness
                case 3:
                    if (codePoint < 0x800) // overlong
                        return false;

                    // Filter out codepoints outside the Unicode range
                    if ((codePoint >= 0xd800 && codePoint <= 0xdfff) // utf-16 surrogate halves
                            || (codePoint >= 0xfffe && codePoint <= 0xffff)) { // reversed utf-16 BOM
                        return false;
                    }
                    break;
                case 4:
                    if (codePoint < 0x10000      // overlong
                        || codePoint > 0x10ffff) // above Unicode range
                        return false;
                    break;
            }
            codePoint = 0;
        }
    }
    return continuation == 0;
}

/*!
 * Convert variant \a data to string \a json in JSON format.
 *
 * The data is encoded as an array containing one item
 * to allow the same encoding to be used for both
 * primitive and compound data types.
 *
 * Returns true if the conversion is successful, false otherwise.
 *
 * \sa convertFromJson()
 */
bool VersitUtils::convertToJson(const QVariant &data, QString *json)
{
    const QJsonValue dataAsJsonValue = QJsonValue::fromVariant(data);
    // In Qt 6, QVariant(nullptr_t) converts to a JSON null — preserve that for round-trip.
    if (data.isValid() && dataAsJsonValue.isNull()
            && data.userType() != QMetaType::Nullptr)
        return false;
    QJsonArray jsonArray;
    jsonArray.append(dataAsJsonValue);
    const QJsonDocument jsonDocument(jsonArray);
    *json = QString::fromUtf8(jsonDocument.toJson());
    return true;
}

/*!
 * Convert string \a json in JSON format to variant \a data.
 *
 * The format of the json string is assumed to be a one-item array.
 *
 * Returns true if the conversion is successful, false otherwise.
 *
 * \sa convertToJson()
 */
bool VersitUtils::convertFromJson(const QString &json, QVariant *data)
{
    const QJsonDocument jsonDoc = QJsonDocument::fromJson(json.toUtf8());
    const QJsonValue jsonValue = jsonDoc.array().at(0);
    if (jsonValue.isUndefined())
        return false;
    *data = jsonValue.toVariant();
    return true;
}

QT_END_NAMESPACE_VERSIT
