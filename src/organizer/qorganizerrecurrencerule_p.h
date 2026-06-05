// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QORGANIZERRECURRENCERULE_P_H
#define QORGANIZERRECURRENCERULE_P_H

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

#include <QtCore/qdatetime.h>
#include <QtCore/qset.h>
#include <QtCore/qshareddata.h>

#include <QtOrganizer/qorganizerrecurrencerule.h>

QT_BEGIN_NAMESPACE_ORGANIZER

class QOrganizerRecurrenceRulePrivate : public QSharedData
{
public:
    QOrganizerRecurrenceRulePrivate()
        : QSharedData(), frequency(QOrganizerRecurrenceRule::Invalid),
          limitCount(-1), limitType(QOrganizerRecurrenceRule::NoLimit),
          interval(1), firstDayOfWeek(Qt::Monday)
    {
    }

    QOrganizerRecurrenceRulePrivate(const QOrganizerRecurrenceRulePrivate &other)
        : QSharedData(other), frequency(other.frequency),
          limitCount(other.limitCount), limitDate(other.limitDate),
          limitType(other.limitType), interval(other.interval),
          daysOfWeek(other.daysOfWeek), daysOfMonth(other.daysOfMonth),
          daysOfYear(other.daysOfYear), monthsOfYear(other.monthsOfYear),
          weeksOfYear(other.weeksOfYear), positions(other.positions),
          firstDayOfWeek(other.firstDayOfWeek)

    {
    }

    ~QOrganizerRecurrenceRulePrivate()
    {
    }

    QOrganizerRecurrenceRule::Frequency frequency;
    int limitCount;
    QDate limitDate;
    QOrganizerRecurrenceRule::LimitType limitType;
    int interval;
    QSet<Qt::DayOfWeek> daysOfWeek;
    QSet<int> daysOfMonth;
    QSet<int> daysOfYear;
    QSet<QOrganizerRecurrenceRule::Month> monthsOfYear;
    QSet<int> weeksOfYear;
    QSet<int> positions;
    Qt::DayOfWeek firstDayOfWeek;
};

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERRECURRENCERULE_P_H
