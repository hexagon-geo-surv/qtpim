// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QVERSITDOCUMENTWRITER_H
#define QVERSITDOCUMENTWRITER_H

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

#include <QtCore/qhash.h>
#include <QtCore/qstringconverter.h>
#include <QtCore/qstringlist.h>

#include <QtVersit/qversitdocument.h>

QT_FORWARD_DECLARE_CLASS(QByteArray)
QT_FORWARD_DECLARE_CLASS(QIODevice)

QT_BEGIN_NAMESPACE_VERSIT

class QVersitProperty;

class Q_VERSIT_EXPORT QVersitDocumentWriter
{
public:
    QVersitDocumentWriter(QVersitDocument::VersitType type);
    virtual ~QVersitDocumentWriter();

    void setEncoding(QStringConverter::Encoding encoding);
    void setAsciiCodec();
    void setDevice(QIODevice* device);

    virtual void encodeVersitProperty(const QVersitProperty& property) = 0;
    virtual void encodeParameters(const QMultiHash<QString,QString>& parameters) = 0;
    bool encodeVersitDocument(const QVersitDocument& document, bool encodeVersion = true);
    void encodeGroupsAndName(const QVersitProperty& property);

    void writeBytes(const QByteArray& value);
    void writeString(const QString& value);
    void writeStringQp(const QString& value);
    void writeCrlf();

protected:
    QVersitDocument::VersitType mType;
    QIODevice* mDevice;
    QStringConverter::Encoding mEncoding;
    bool mCodecIsAscii;
    bool mCodecIsAsciiCompatible;
    QStringEncoder mEncoder;
    bool mSuccessful;
    int mCurrentLineLength;
};

QT_END_NAMESPACE_VERSIT

#endif // QVERSITDOCUMENTWRITER_H
