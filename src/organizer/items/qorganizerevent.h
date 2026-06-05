// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QORGANIZEREVENT_H
#define QORGANIZEREVENT_H

#include <QtCore/qdatetime.h>
#include <QtCore/qset.h>

#include <QtOrganizer/qorganizeritem.h>
#include <QtOrganizer/qorganizeritempriority.h>
#include <QtOrganizer/qorganizerrecurrencerule.h>

QT_BEGIN_NAMESPACE_ORGANIZER

/* Leaf class */

class Q_ORGANIZER_EXPORT QOrganizerEvent : public QOrganizerItem
{
public:
    Q_DECLARE_CUSTOM_ORGANIZER_ITEM(QOrganizerEvent, QOrganizerItemType::TypeEvent)

    void setStartDateTime(const QDateTime &startDateTime);
    QDateTime startDateTime() const;

    void setEndDateTime(const QDateTime &endDateTime);
    QDateTime endDateTime() const;

    void setAllDay(bool isAllDay);
    bool isAllDay() const;

    void setRecurrenceDate(const QDate &rdate);
    void setRecurrenceDates(const QSet<QDate> &rdates);
    QSet<QDate> recurrenceDates() const;

    void setRecurrenceRule(const QOrganizerRecurrenceRule &rrule);
    void setRecurrenceRules(const QSet<QOrganizerRecurrenceRule> &rrules);
    QOrganizerRecurrenceRule recurrenceRule() const;
    QSet<QOrganizerRecurrenceRule> recurrenceRules() const;

    void setExceptionDate(const QDate &exdate);
    void setExceptionDates(const QSet<QDate> &exdates);
    QSet<QDate> exceptionDates() const;

    void setExceptionRule(const QOrganizerRecurrenceRule &xrule);
    void setExceptionRules(const QSet<QOrganizerRecurrenceRule> &exrules);
    QOrganizerRecurrenceRule exceptionRule() const;
    QSet<QOrganizerRecurrenceRule> exceptionRules() const;

    void setPriority(QOrganizerItemPriority::Priority priority);
    QOrganizerItemPriority::Priority priority() const;

    QString location() const;
    void setLocation(const QString &label);
};

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZEREVENT_H
