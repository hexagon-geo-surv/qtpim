// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QORGANIZERITEMPRIORITY_H
#define QORGANIZERITEMPRIORITY_H

#include <QtOrganizer/qorganizeritemdetail.h>

QT_BEGIN_NAMESPACE_ORGANIZER

/* Leaf class */

class Q_ORGANIZER_EXPORT QOrganizerItemPriority : public QOrganizerItemDetail
{
public:
#ifndef Q_QDOC
    Q_DECLARE_CUSTOM_ORGANIZER_DETAIL(QOrganizerItemPriority, QOrganizerItemDetail::TypePriority)
#endif

    enum PriorityField {
        FieldPriority = TypePriority + 1
    };

    // time vs impact priority?  greater granularity?
    enum Priority {
        UnknownPriority = 0,
        HighestPriority = 1,
        ExtremelyHighPriority = 2,
        VeryHighPriority = 3,
        HighPriority = 4,
        MediumPriority = 5,
        LowPriority = 6,
        VeryLowPriority = 7,
        ExtremelyLowPriority = 8,
        LowestPriority = 9
    };

    void setPriority(Priority priority);
    Priority priority() const;
};

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERITEMPRIORITY_H
