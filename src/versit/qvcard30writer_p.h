// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QVCARD30WRITER_P_H
#define QVCARD30WRITER_P_H

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

class Q_VERSIT_EXPORT QVCard30Writer : public QVersitDocumentWriter
{
public:
    QVCard30Writer(QVersitDocument::VersitType type);
    ~QVCard30Writer();

    void encodeVersitProperty(const QVersitProperty& property) override;
    void encodeParameters(const QMultiHash<QString,QString>& parameters) override;
    static void backSlashEscape(QString* text);
    QHash<QString,QString> mPropertyNameMappings;
};

QT_END_NAMESPACE_VERSIT

#endif // QVCARD30WRITER_P_H
