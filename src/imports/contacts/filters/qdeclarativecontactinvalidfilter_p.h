// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QDECLARATIVECONTACTINVALIDFILTER_H
#define QDECLARATIVECONTACTINVALIDFILTER_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.
// This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <QtContacts/qcontactinvalidfilter.h>

#include "qdeclarativecontactfilter_p.h"

QTCONTACTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE

class QDeclarativeContactInvalidFilter : public QDeclarativeContactFilter
{
    Q_OBJECT
public:

    QDeclarativeContactInvalidFilter(QObject* parent=0)
        :QDeclarativeContactFilter(parent)
    {
    }
    QContactFilter filter() const override
    {
        return QContactInvalidFilter();
    }
};

QT_END_NAMESPACE

QML_DECLARE_TYPE(QDeclarativeContactInvalidFilter)

#endif // QDECLARATIVECONTACTINVALIDFILTER_H
