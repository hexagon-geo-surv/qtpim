// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:critical reason:data-parser

#ifndef QVERSITUTILS_P_H
#define QVERSITUTILS_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <QtCore/qbytearray.h>
#include <QtCore/qbytearraymatcher.h>
#include <QtCore/qlist.h>
#include <QtCore/QMutex>
#include <QtCore/qstringconverter.h>

#include <QtVersit/qversitproperty.h>

QT_FORWARD_DECLARE_CLASS(QString)
QT_FORWARD_DECLARE_CLASS(QVariant)

QT_BEGIN_NAMESPACE_VERSIT

class QVersitDocument;

class Q_VERSIT_EXPORT VersitUtils
{
public:
    static QByteArray encode(const QByteArray& ba, QStringConverter::Encoding encoding);
    static QByteArray encode(char ch, QStringConverter::Encoding encoding);
    static QList<QByteArrayMatcher>* newlineList(QStringConverter::Encoding encoding);
    static void changeCodec(QStringConverter::Encoding encoding);
    static QVersitProperty takeProperty(const QVersitDocument& document,
                                        const QString& propertyName,
                                        QList<QVersitProperty>* toBeRemoved);
    static bool isValidUtf8(const QByteArray& bytes);
    static bool convertToJson(const QVariant &data, QString *json);
    static bool convertFromJson(const QString &json, QVariant *data);

private:
    // These are caches for performance:
    // The previous encoding that encode(char, encoding) was called with
    static QStringConverter::Encoding m_previousEncoding;
    static bool m_initialized;
    // The QByteArray corresponding to each char from 0-255, encoded with m_previousEncoding
    static QByteArray m_encodingMap[256];
    // List of different newline delimiters, encoded with m_previousEncoding
    static QList<QByteArrayMatcher>* m_newlineList;
    static QBasicMutex m_staticLock;
};

QT_END_NAMESPACE_VERSIT

#endif // QVERSITUTILS_P_H
