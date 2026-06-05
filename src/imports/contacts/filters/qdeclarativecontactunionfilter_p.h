// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QDECLARATIVECONTACTUNIONFILTER_H
#define QDECLARATIVECONTACTUNIONFILTER_H

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

#include <QtContacts/qcontactunionfilter.h>

#include "qdeclarativecontactfilter_p.h"

QTCONTACTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE

class QDeclarativeContactUnionFilter : public QDeclarativeContactCompoundFilter
{
    Q_OBJECT
public:
    QDeclarativeContactUnionFilter(QObject* parent = nullptr)
        :QDeclarativeContactCompoundFilter(parent)
    {
    }

    QContactFilter filter() const override
    {
        QList<QContactFilter> filters;
        for (QDeclarativeContactFilter* f : std::as_const(m_filters)) {
            filters << f->filter();
        }
        QContactUnionFilter f;
        f.setFilters(filters);
        return f;
    }
};

QT_END_NAMESPACE

QML_DECLARE_TYPE(QDeclarativeContactUnionFilter)

#endif // QDECLARATIVECONTACTUNIONFILTER_H
