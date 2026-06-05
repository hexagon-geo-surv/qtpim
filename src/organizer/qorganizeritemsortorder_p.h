// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QORGANIZERITEMSORTORDER_P_H
#define QORGANIZERITEMSORTORDER_P_H

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

#include <QtCore/qshareddata.h>

#include <QtOrganizer/qorganizeritemdetail.h>
#include <QtOrganizer/qorganizeritemsortorder.h>

QT_BEGIN_NAMESPACE_ORGANIZER

class QOrganizerItemSortOrderPrivate : public QSharedData
{
public:
    QOrganizerItemSortOrderPrivate()
        : QSharedData()
        , m_blankPolicy(QOrganizerItemSortOrder::BlanksLast)
        , m_direction(Qt::AscendingOrder)
        , m_sensitivity(Qt::CaseSensitive)
        , m_detailType(QOrganizerItemDetail::TypeUndefined)
        , m_detailField(-1)
    {
    }

    ~QOrganizerItemSortOrderPrivate()
    {
    }

    QOrganizerItemSortOrder::BlankPolicy m_blankPolicy;
    Qt::SortOrder m_direction;
    Qt::CaseSensitivity m_sensitivity;
    QOrganizerItemDetail::DetailType m_detailType;
    int m_detailField;
};

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERITEMSORTORDER_P_H
