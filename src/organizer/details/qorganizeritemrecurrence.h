// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QORGANIZERITEMRECURRENCE_H
#define QORGANIZERITEMRECURRENCE_H

#include <QtCore/qdatetime.h>
#include <QtCore/qset.h>
#include <QtCore/qurl.h>

#include <QtOrganizer/qorganizeritemdetail.h>
#include <QtOrganizer/qorganizerrecurrencerule.h>

QT_BEGIN_NAMESPACE_ORGANIZER

/* Leaf class */

class Q_ORGANIZER_EXPORT QOrganizerItemRecurrence : public QOrganizerItemDetail
{
public:
#ifndef Q_QDOC
    Q_DECLARE_CUSTOM_ORGANIZER_DETAIL(QOrganizerItemRecurrence, QOrganizerItemDetail::TypeRecurrence)
#endif

    enum RecurrenceField {
        FieldRecurrenceRules = TypeRecurrence + 1,
        FieldExceptionRules,
        FieldRecurrenceDates,
        FieldExceptionDates
    };

    void setRecurrenceRules(const QSet<QOrganizerRecurrenceRule> &rrules);
    QSet<QOrganizerRecurrenceRule> recurrenceRules() const;

    void setRecurrenceDates(const QSet<QDate> &rdates);
    QSet<QDate> recurrenceDates() const;

    void setExceptionRules(const QSet<QOrganizerRecurrenceRule> &xrules);
    QSet<QOrganizerRecurrenceRule> exceptionRules() const;

    void setExceptionDates(const QSet<QDate> &xdates);
    QSet<QDate> exceptionDates() const;

    bool operator==(const QOrganizerItemRecurrence &other) const;
    bool operator!=(const QOrganizerItemRecurrence &other) const {return !(other == *this);}
};

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERITEMRECURRENCE_H
