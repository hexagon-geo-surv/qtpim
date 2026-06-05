// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

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
    QDeclarativeContactIntersectionFilter(QObject* parent = nullptr)
        :QDeclarativeContactCompoundFilter(parent)
    {
    }

    QContactFilter filter() const
    {
        QList<QContactFilter> filters;
        foreach (QDeclarativeContactFilter* f, m_filters) {
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
