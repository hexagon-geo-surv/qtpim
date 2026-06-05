// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QVERSITDOCUMENT_P_H
#define QVERSITDOCUMENT_P_H

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

#include <QtCore/qlist.h>
#include <QtCore/qshareddata.h>

#include <QtVersit/qversitdocument.h>
#include <QtVersit/qversitproperty.h>

QT_BEGIN_NAMESPACE_VERSIT

class QVersitDocumentPrivate : public QSharedData
{
public:
    QVersitDocumentPrivate();

    QVersitDocumentPrivate(const QVersitDocumentPrivate& other);

    ~QVersitDocumentPrivate()
    {
    }

    QVersitDocument::VersitType mVersitType;
    QString mComponentType;
    QList<QVersitProperty> mProperties;
    QList<QVersitDocument> mSubDocuments;
};

QT_END_NAMESPACE_VERSIT

#endif // QVERSITDOCUMENT_P_H
