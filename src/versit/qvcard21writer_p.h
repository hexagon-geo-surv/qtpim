// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QVCARD21WRITER_P_H
#define QVCARD21WRITER_P_H

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

#include <QtVersit/private/qversitdocumentwriter_p.h>

QT_BEGIN_NAMESPACE_VERSIT

class Q_VERSIT_EXPORT QVCard21Writer : public QVersitDocumentWriter
{
public:
    QVCard21Writer(QVersitDocument::VersitType type);
    ~QVCard21Writer();

    void encodeVersitProperty(const QVersitProperty& property) override;
    bool requiresUtf8(const QStringList& values);
    void encodeVersitValue(QMultiHash<QString,QString>& parameters, QString& value, bool forceUtf8);
    void encodeParameters(const QMultiHash<QString,QString>& parameters) override;
    static bool containsNonAscii(const QString& str);
    static bool quotedPrintableEncode(QString& text);
    static bool shouldBeQuotedPrintableEncoded(QChar chr);

private:
    static QTextEncoder* utf8Encoder();
};

QT_END_NAMESPACE_VERSIT

#endif // QVCARD21WRITER_P_H
