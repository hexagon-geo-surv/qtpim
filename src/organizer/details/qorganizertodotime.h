// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QORGANIZERTODOTIME_H
#define QORGANIZERTODOTIME_H

#include <QtOrganizer/qorganizeritemdetail.h>

QT_FORWARD_DECLARE_CLASS(QDateTime)

QT_BEGIN_NAMESPACE_ORGANIZER

/* Leaf class */

class Q_ORGANIZER_EXPORT QOrganizerTodoTime : public QOrganizerItemDetail
{
public:
#ifndef Q_QDOC
    Q_DECLARE_CUSTOM_ORGANIZER_DETAIL(QOrganizerTodoTime, QOrganizerItemDetail::TypeTodoTime)
#endif

    enum TodoTimeField {
        FieldStartDateTime = TypeTodoTime + 1,
        FieldDueDateTime,
        FieldAllDay
    };

    void setStartDateTime(const QDateTime &startDateTime);
    QDateTime startDateTime() const;

    void setDueDateTime(const QDateTime &dueDateTime);
    QDateTime dueDateTime() const;

    void setAllDay(bool isAllDay);
    bool isAllDay() const;
};

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERTODOTIME_H
