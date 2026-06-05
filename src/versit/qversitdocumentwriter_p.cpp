// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qversitdocumentwriter_p.h"

#include <QtCore/qiodevice.h>
#include <QtCore/qstringconverter.h>

#include "qversitutils_p.h"

QT_BEGIN_NAMESPACE_VERSIT

#define MAX_LINE_LENGTH 76

/*!
  \class QVersitDocumentWriter
  \internal
  \brief The QVersitDocumentWriter class provides an interface for writing a
  single versit document into a vCard text string.
 */

/*! Constructs a writer.
 * \a documentType is the type of Versit document, as printed on the BEGIN line of output
 * eg. "VCARD"
 * \a version is the version of the Versit format, as printed on the VERSION line of output.
 * eg. "2.1"
 */
QVersitDocumentWriter::QVersitDocumentWriter(QVersitDocument::VersitType type)
    : mType(type),
    mDevice(nullptr),
    mEncoding(QStringConverter::Utf8),
    mCodecIsAscii(false),
    mCodecIsAsciiCompatible(true),
    mEncoder(QStringConverter::Utf8),
    mSuccessful(true),
    mCurrentLineLength(0)
{
}

QVersitDocumentWriter::~QVersitDocumentWriter()
{
}

/*!
  Sets the encoding to write with.
  */
void QVersitDocumentWriter::setEncoding(QStringConverter::Encoding encoding)
{
    mEncoding = encoding;
    // Create encoder without BOM - for UTF-8 the BOM is not added by default
    mEncoder = QStringEncoder(encoding);

    // UTF-16 and UTF-32 are the only encodings where characters in the base64 range aren't encoded
    // the same as in ASCII.  For ASCII-compatible encodings, we can do some optimizations.
    mCodecIsAsciiCompatible = (encoding == QStringConverter::Utf8
                               || encoding == QStringConverter::Latin1
                               || encoding == QStringConverter::System);
}

/*!
  Specifies that the codec is actually ASCII (setCodec must also be called with an ASCII-compatible
  codec.
 */
void QVersitDocumentWriter::setAsciiCodec()
{
    mCodecIsAscii = true;
}

/*!
  Sets the device to write to.
  */
void QVersitDocumentWriter::setDevice(QIODevice *device)
{
    mDevice = device;
}

/*!
 * Encodes the \a document and writes it to the device.  A "VERSION:" line is added iff \a
 * encodeVersion is true.
 */
bool QVersitDocumentWriter::encodeVersitDocument(const QVersitDocument& document, bool encodeVersion)
{
    mSuccessful = true;

    if (document.componentType().isEmpty()) {
        // for compatibility with code for Qt Mobility 1.0, which didn't have componentType
        writeString(QStringLiteral("BEGIN:VCARD"));
    } else {
        writeString(QStringLiteral("BEGIN:") + document.componentType());
    }
    writeCrlf();
    if (encodeVersion) {
        switch (mType) {
        case QVersitDocument::VCard21Type:
            writeString(QStringLiteral("VERSION:2.1"));
            writeCrlf();
            break;
        case QVersitDocument::VCard30Type:
            writeString(QStringLiteral("VERSION:3.0"));
            writeCrlf();
            break;
        case QVersitDocument::VCard40Type:
            writeString(QStringLiteral("VERSION:4.0"));
            writeCrlf();
            break;
        case QVersitDocument::ICalendar20Type:
            writeString(QStringLiteral("VERSION:2.0"));
            writeCrlf();
            break;
        default:
            ; // don't print version
        }
    }

    for (const QVersitProperty& property : document.properties()) {
        encodeVersitProperty(property);
    }

    for (const QVersitDocument& subDoc : document.subDocuments()) {
        encodeVersitDocument(subDoc, false);
    }

    if (document.componentType().isEmpty()) {
        writeString(QStringLiteral("END:VCARD"));
    } else {
        writeString(QStringLiteral("END:") + document.componentType());
    }
    writeCrlf();

    // This has been set by the methods called from this function
    return mSuccessful;
}

/*!
 * Encodes the groups and name in the \a property and writes it to the device
 */
void QVersitDocumentWriter::encodeGroupsAndName(const QVersitProperty& property)
{
    QStringList groups = property.groups();
    if (!groups.isEmpty()) {
        writeString(groups.join(QStringLiteral(".")));
        writeString(QStringLiteral("."));
    }
    writeString(property.name());
}

/*!
  Writes \a value to the device.

  This function tracks how many characters have been written to the line and folds (wraps) the line
  according to RFC2425.
  */
void QVersitDocumentWriter::writeBytes(const QByteArray &value)
{
    int spaceRemaining = MAX_LINE_LENGTH - mCurrentLineLength;
    int charsWritten = 0;
    while (spaceRemaining < value.length() - charsWritten) {
        // Write the first "spaceRemaining" characters
        if (mDevice->write(value.constData() + charsWritten, spaceRemaining) < 0
               || mDevice->write("\r\n ") < 0)
            mSuccessful = false;
        charsWritten += spaceRemaining;
        spaceRemaining = MAX_LINE_LENGTH - 1; // minus 1 for the space at the front.
        mCurrentLineLength = 1;
    }

    if (mDevice->write(value.constData() + charsWritten) < 0)
        mSuccessful = false;
    mCurrentLineLength += value.length() - charsWritten;
}

/*!
  Writes \a value to the device.

  This function tracks how many characters have been written to the line and folds (wraps) the line
  according to RFC2425.
  */
void QVersitDocumentWriter::writeString(const QString &value)
{
    int spaceRemaining = MAX_LINE_LENGTH - mCurrentLineLength;
    int charsWritten = 0;
    QString crlfSpace(QStringLiteral("\r\n "));
    while (spaceRemaining < value.length() - charsWritten) {
        // Write the first "spaceRemaining" characters
        QString line = value.mid(charsWritten, spaceRemaining);
        charsWritten += spaceRemaining;
        if (mDevice->write(mEncoder.encode(line)) < 0
               || mDevice->write(mEncoder.encode(crlfSpace)) < 0)
            mSuccessful = false;
        spaceRemaining = MAX_LINE_LENGTH - 1; // minus 1 for the space at the front.
        mCurrentLineLength = 1;
    }

    if (mDevice->write(mEncoder.encode(value.mid(charsWritten))) < 0)
        mSuccessful = false;
    mCurrentLineLength += value.length() - charsWritten;
}

/*!
  Writes \a value to the device.

  This function tracks how many characters have been written to the line and wraps the line
  according to RFC2045 (a Quoted-Printable soft line break is an EQUALS-CR-LF sequence)
  */
void QVersitDocumentWriter::writeStringQp(const QString &value)
{
    int spaceRemaining = MAX_LINE_LENGTH - mCurrentLineLength - 1;
                                             // minus 1 for the equals required at the end
    int charsWritten = 0;
    QString softBreak(QStringLiteral("=\r\n"));
    while (spaceRemaining < value.length() - charsWritten) {
        // Write the first "spaceRemaining" characters
        if (value[charsWritten + spaceRemaining - 2] == QLatin1Char('=')) {
            spaceRemaining -= 2;
        } else if (value[charsWritten + spaceRemaining - 1] == QLatin1Char('=')) {
            spaceRemaining -= 1;
        }
        QString line = value.mid(charsWritten, spaceRemaining);

        charsWritten += spaceRemaining;
        if (mDevice->write(mEncoder.encode(line)) < 0
               || mDevice->write(mEncoder.encode(softBreak)) < 0)
            mSuccessful = false;
        spaceRemaining = MAX_LINE_LENGTH - 1; // minus 1 for the equals required at the end
        mCurrentLineLength = 0;
    }

    if (mDevice->write(mEncoder.encode(value.mid(charsWritten))) < 0)
        mSuccessful = false;
    mCurrentLineLength += value.length() - charsWritten;
}

/*!
  Writes a CRLF to the device.  By using this function, rather than writeString("\\r\\n"), you will
  allow the writer to know where a line starts, for folding purposes.
  */
void QVersitDocumentWriter::writeCrlf()
{
    writeString(QStringLiteral("\r\n"));
    mCurrentLineLength = 0;
}

QT_END_NAMESPACE_VERSIT
