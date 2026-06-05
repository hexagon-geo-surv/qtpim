// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qtimezones_p.h"

#include <QtOrganizer/qorganizer.h>

QTORGANIZER_USE_NAMESPACE

QT_BEGIN_NAMESPACE_VERSITORGANIZER

QOrganizerManager* TimeZone::getManager()
{
    // We use the memory engine to do time zone recurrence calculations
    static QOrganizerManager* manager(new QOrganizerManager(QString::fromLatin1("memory")));
    return manager;
}

QDateTime TimeZone::convert(const QDateTime& dateTime) const
{
    Q_ASSERT(isValid());
    QOrganizerManager* manager = getManager();
    int offset = 100000; // impossible value
    QDateTime latestPhase;
    for (const TimeZonePhase& phase : mPhases) {
        QOrganizerEvent event;
        event.setStartDateTime(phase.startDateTime());
        event.setRecurrenceRules(QSet<QOrganizerRecurrenceRule>() << phase.recurrenceRule());
        event.setRecurrenceDates(phase.recurrenceDates());
        QList<QOrganizerItem> occurrences =
            manager->itemOccurrences(event, phase.startDateTime(), dateTime, 500);
        if (!occurrences.isEmpty()) {
            QDateTime phaseStart(static_cast<const QOrganizerEventOccurrence &>(occurrences.last()).startDateTime());
            if (phaseStart > latestPhase) {
                latestPhase = phaseStart;
                offset = phase.utcOffset();
            }
        }
        else {
            offset = phase.utcOffset();
        }
    }
    QDateTime retn(dateTime);
    retn.setTimeSpec(Qt::UTC);
    if (offset >= -86400 && offset <= 86400) // offset must be within -24hours to +24hours
        return retn.addSecs(-offset);
    else
        return retn;
}

QDateTime TimeZones::convert(const QDateTime& dateTime, const QString& tzid) const
{
    if (!mTimeZones.contains(tzid))
        return QDateTime();
    TimeZone tz = mTimeZones.value(tzid);
    if (!tz.isValid())
        return QDateTime();
    return tz.convert(dateTime);
}

QT_END_NAMESPACE_VERSITORGANIZER
