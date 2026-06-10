// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QORGANIZERTODO_H
#define QORGANIZERTODO_H

#include <QtCore/qdatetime.h>
#include <QtCore/qset.h>

#include <QtOrganizer/qorganizeritem.h>
#include <QtOrganizer/qorganizeritempriority.h>
#include <QtOrganizer/qorganizeritemrecurrence.h>
#include <QtOrganizer/qorganizertodoprogress.h>

QT_BEGIN_NAMESPACE_ORGANIZER

/* Leaf class */

class Q_ORGANIZER_EXPORT QOrganizerTodo : public QOrganizerItem
{
public:
    Q_DECLARE_CUSTOM_ORGANIZER_ITEM(QOrganizerTodo, QOrganizerItemType::TypeTodo)

    void setStartDateTime(const QDateTime &dueDateTime);
    QDateTime startDateTime() const;

    void setDueDateTime(const QDateTime &dueDateTime);
    QDateTime dueDateTime() const;

    void setAllDay(bool isAllDay);
    bool isAllDay() const;

    void setRecurrenceDates(const QSet<QDate> &rdates);
    QSet<QDate> recurrenceDates() const;

    void setRecurrenceRule(const QOrganizerRecurrenceRule &rrule);
    void setRecurrenceRules(const QSet<QOrganizerRecurrenceRule> &rrules);
    QSet<QOrganizerRecurrenceRule> recurrenceRules() const;
    QOrganizerRecurrenceRule recurrenceRule() const;

    void setExceptionDates(const QSet<QDate> &exdates);
    QSet<QDate> exceptionDates() const;

    void setExceptionRule(const QOrganizerRecurrenceRule &exrule);
    void setExceptionRules(const QSet<QOrganizerRecurrenceRule> &exrules);
    QSet<QOrganizerRecurrenceRule> exceptionRules() const;
    QOrganizerRecurrenceRule exceptionRule() const;

    void setPriority(QOrganizerItemPriority::Priority priority);
    QOrganizerItemPriority::Priority priority() const;

    void setProgressPercentage(int percentage);
    int progressPercentage() const;

    void setStatus(QOrganizerTodoProgress::Status status);
    QOrganizerTodoProgress::Status status() const;

    void setFinishedDateTime(const QDateTime &finishedDateTime);
    QDateTime finishedDateTime() const;
};

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERTODO_H
