// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QTIMEZONES_P_H
#define QTIMEZONES_P_H

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
#include <QtCore/qlist.h>
#include <QtCore/qhash.h>

#include <QtOrganizer/qorganizerrecurrencerule.h>

#include <QtVersitOrganizer/qversitorganizerglobal.h>

QT_BEGIN_NAMESPACE_ORGANIZER
class QOrganizerManager;
QT_END_NAMESPACE_ORGANIZER

QTORGANIZER_USE_NAMESPACE

QT_BEGIN_NAMESPACE_VERSITORGANIZER

class TimeZonePhase {
    public:
        TimeZonePhase() : mStandard(true), mUtcOffset(100000) {} // invalid offset
        void setStandard(bool standard) { mStandard = standard; }
        bool isStandard() const { return mStandard; }
        void setUtcOffset(int offset) { mUtcOffset = offset; }
        int utcOffset() const { return mUtcOffset; }
        void setStartDateTime(const QDateTime& dateTime) { mStartDateTime = dateTime; }
        QDateTime startDateTime() const { return mStartDateTime; }
        void setRecurrenceRule(const QOrganizerRecurrenceRule& rrule) { mRecurrenceRule = rrule; }
        QOrganizerRecurrenceRule recurrenceRule() const { return mRecurrenceRule; }
        void setRecurrenceDates(const QSet<QDate>& rdates) { mRecurrenceDates = rdates; }
        QSet<QDate> recurrenceDates() const { return mRecurrenceDates; }
        bool isValid() const {
            // offset must be within -24 hours to +24 hours
            return mStartDateTime.isValid() && mUtcOffset < 86400 && mUtcOffset > -86400;
        }
    private:
        bool mStandard; // true for STANDARD, false for DAYLIGHT
        int mUtcOffset; // in seconds, the offset to apply after mStartDateTime
        QDateTime mStartDateTime; // local time, when the phase comes into effect
        QOrganizerRecurrenceRule mRecurrenceRule;
        QSet<QDate> mRecurrenceDates;
};

class TimeZone {
    public:
        QDateTime convert(const QDateTime& dateTime) const;
        void setTzid(const QString& tzid) { mTzid = tzid; }
        QString tzid() const { return mTzid; }
        void addPhase(const TimeZonePhase& phase) { mPhases.append(phase); }
        bool isValid() const {
            for (const TimeZonePhase& phase : mPhases) {
                if (!phase.isValid()) return false;
            }
            return !mPhases.isEmpty();
        }

    private:
        static QOrganizerManager* getManager();
        QString mTzid;
        QList<TimeZonePhase> mPhases;
};

class TimeZones {
    public:
        QDateTime convert(const QDateTime& dateTime, const QString& tzid) const;
        void addTimeZone(const TimeZone& timezone) {
            if (!timezone.tzid().isEmpty())
                    mTimeZones.insert(timezone.tzid(), timezone);
        }
    private:
        QHash<QString, TimeZone> mTimeZones;
};

QT_END_NAMESPACE_VERSITORGANIZER

#endif // QTIMEZONES_P_H
