// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QORGANIZERRECURRENCERULE_H
#define QORGANIZERRECURRENCERULE_H

#include <QtCore/qdatetime.h>
#include <QtCore/qmetatype.h>
#include <QtCore/qset.h>
#include <QtCore/qshareddata.h>

#include <QtOrganizer/qorganizerglobal.h>

QT_BEGIN_NAMESPACE_ORGANIZER

class QOrganizerRecurrenceRulePrivate;
class Q_ORGANIZER_EXPORT QOrganizerRecurrenceRule
{
public:
    enum Frequency {
        Invalid = 0,
        Daily,
        Weekly,
        Monthly,
        Yearly
    };

    enum Month {
        January = 1,
        February,
        March,
        April,
        May,
        June,
        July,
        August,
        September,
        October,
        November,
        December
    };

    enum LimitType {
        NoLimit = 0,
        CountLimit,
        DateLimit
    };

    QOrganizerRecurrenceRule();
    QOrganizerRecurrenceRule(const QOrganizerRecurrenceRule &other);
    ~QOrganizerRecurrenceRule();

    QOrganizerRecurrenceRule &operator=(const QOrganizerRecurrenceRule &other);

    bool operator==(const QOrganizerRecurrenceRule &other) const;
    inline bool operator!=(const QOrganizerRecurrenceRule &other) const { return !operator==(other); }

    void setFrequency(Frequency freq);
    Frequency frequency() const;

    void setLimit(int count);
    void setLimit(const QDate &date);
    void clearLimit();

    LimitType limitType() const;
    int limitCount() const;
    QDate limitDate() const;

    void setInterval(int interval);
    int interval() const;

    void setDaysOfWeek(const QSet<Qt::DayOfWeek> &days);
    QSet<Qt::DayOfWeek> daysOfWeek() const;

    void setDaysOfMonth(const QSet<int> &days);
    QSet<int> daysOfMonth() const;

    void setDaysOfYear(const QSet<int> &days);
    QSet<int> daysOfYear() const;

    void setMonthsOfYear(const QSet<Month> &months);
    QSet<Month> monthsOfYear() const;

    void setWeeksOfYear(const QSet<int> &weeks);
    QSet<int> weeksOfYear() const;

    void setFirstDayOfWeek(Qt::DayOfWeek day);
    Qt::DayOfWeek firstDayOfWeek() const;

    void setPositions(const QSet<int> &pos);
    QSet<int> positions() const;

private:
    QSharedDataPointer<QOrganizerRecurrenceRulePrivate> d;
};

//hash functions
Q_ORGANIZER_EXPORT size_t qHash(const QOrganizerRecurrenceRule &rule, size_t seed = 0) noexcept;

#ifndef QT_NO_DEBUG_STREAM
Q_ORGANIZER_EXPORT QDebug operator<<(QDebug dbg, const QOrganizerRecurrenceRule &rule);
#endif // QT_NO_DEBUG_STREAM

inline size_t qHash(QOrganizerRecurrenceRule::Month month, size_t seed = 0) noexcept
{
    return ::qHash(static_cast<int>(month), seed);
}

QT_END_NAMESPACE_ORGANIZER

QT_BEGIN_NAMESPACE
Q_DECLARE_TYPEINFO(QTORGANIZER_PREPEND_NAMESPACE(QOrganizerRecurrenceRule), Q_MOVABLE_TYPE);
QT_END_NAMESPACE

Q_DECLARE_METATYPE(QTORGANIZER_PREPEND_NAMESPACE(QOrganizerRecurrenceRule))
Q_DECLARE_METATYPE(QSet<QTORGANIZER_PREPEND_NAMESPACE(QOrganizerRecurrenceRule)>)
Q_DECLARE_METATYPE(QSet<QDate>)

#endif // QORGANIZERRECURRENCERULE_H
