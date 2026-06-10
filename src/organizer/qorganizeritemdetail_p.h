// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QORGANIZERITEMDETAIL_P_H
#define QORGANIZERITEMDETAIL_P_H

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

#include <QtCore/qmap.h>
#include <QtCore/qshareddata.h>

#include <QtOrganizer/qorganizeritemdetail.h>

QT_BEGIN_NAMESPACE_ORGANIZER

class QOrganizerItemDetailPrivate : public QSharedData
{
public:
    QOrganizerItemDetailPrivate(QOrganizerItemDetail::DetailType detailType)
        : QSharedData()
        , m_id(lastDetailKey().fetchAndAddOrdered(1))
        , m_detailType(detailType)
    {
    }

    QOrganizerItemDetailPrivate(const QOrganizerItemDetailPrivate &other)
        : QSharedData(other)
        , m_id(other.m_id)
        , m_detailType(other.m_detailType)
        , m_values(other.m_values)
    {
    }

    ~QOrganizerItemDetailPrivate()
    {
    }

    int m_id; // internal, unique id.
    QOrganizerItemDetail::DetailType m_detailType;
    QMap<int, QVariant> m_values;

    static QAtomicInt &lastDetailKey()
    {
        static QAtomicInt counter(0);
        return counter;
    }
};

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERITEMDETAIL_P_H
