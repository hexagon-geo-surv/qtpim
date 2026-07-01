// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QDECLARATIVECONTACTINTERSECTIONFILTER_H
#define QDECLARATIVECONTACTINTERSECTIONFILTER_H

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

#include <QtContacts/qcontactintersectionfilter.h>

#include "qdeclarativecontactfilter_p.h"

QTCONTACTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE

class QDeclarativeContactIntersectionFilter : public QDeclarativeContactCompoundFilter
{
    Q_OBJECT

public:
    QDeclarativeContactIntersectionFilter(QObject* parent = Q_NULLPTR)
        :QDeclarativeContactCompoundFilter(parent)
    {
    }

    QContactFilter filter() const override
    {
        QList<QContactFilter> filters;
        for (QDeclarativeContactFilter* f : std::as_const(m_filters)) {
            filters << f->filter();
        }
        QContactIntersectionFilter f;
        f.setFilters(filters);
        return f;
    }
};

QT_END_NAMESPACE

QML_DECLARE_TYPE(QDeclarativeContactIntersectionFilter)

#endif // QDECLARATIVECONTACTINTERSECTIONFILTER_H
