// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:critical reason:data-parser

#ifndef QVERSITORGANIZERIMPORTER_P_H
#define QVERSITORGANIZERIMPORTER_P_H

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

#include <QtCore/qset.h>

#include <utility>

#include <QtOrganizer/qorganizeritem.h>
#include <QtOrganizer/qorganizeritemdetail.h>

#include <QtVersitOrganizer/qversitorganizerimporter.h>
#include <QtVersitOrganizer/private/qtimezones_p.h>

QT_BEGIN_NAMESPACE_ORGANIZER
class QOrganizerRecurrenceRule;
QT_END_NAMESPACE_ORGANIZER

QTORGANIZER_USE_NAMESPACE

QT_BEGIN_NAMESPACE_VERSITORGANIZER

class QVersitOrganizerHandler;
class QVersitTimeZoneHandler;

class Duration
{
    public:
        Duration() :
            mNegative(false), mWeeks(0), mDays(0), mHours(0), mMinutes(0), mSeconds(0), mValid(true)
            {}
        static Duration invalidDuration() { Duration d; d.setValid(false); return d; }
        static Duration parseDuration(QString str);
        static void parseDurationTime(QString* str, Duration* dur);
        static void parseDurationMinutes(QString* str, Duration* dur);
        static void parseDurationSeconds(QString* str, Duration* dur);
        static QString nextToken(QString* str);

        void setNegative(bool neg) { mNegative = neg; }
        void setWeeks(int weeks) { mWeeks = weeks; }
        void setDays(int days) { mDays = days; }
        void setHours(int hours) { mHours = hours; }
        void setMinutes(int minutes) { mMinutes = minutes; }
        void setSeconds(int seconds) { mSeconds = seconds; }
        void setValid(bool val) { mValid = val; }
        int weeks() { return mNegative ? -mWeeks : mWeeks; }
        int days() { return mNegative ? -mDays : mDays; }
        int hours() { return mNegative ? -mHours : mHours; }
        int minutes() { return mNegative ? -mMinutes : mMinutes; }
        int seconds() { return mNegative ? -mSeconds : mSeconds; }
        bool isValid() { return mValid; }
        int toSeconds() { return (seconds()
                                  + 60*minutes()
                                  + 3600*hours()
                                  + 86400*days()
                                  + 604800*weeks());
                        }

    private:
        bool mNegative;
        int mWeeks;
        int mDays;
        int mHours;
        int mMinutes;
        int mSeconds;
        bool mValid;
};

class QVersitOrganizerImporterPrivate
{
public:
    QVersitOrganizerImporterPrivate(const QString& profile = QString());
    ~QVersitOrganizerImporterPrivate();
    bool importDocument(const QVersitDocument& topLevel,
                        const QVersitDocument& subDocument,
                        QOrganizerItem* item,
                        QVersitOrganizerImporter::Error* error);
    void importProperty(const QVersitDocument& document,
                        const QVersitProperty& property,
                        QOrganizerItem* item);

    QList<QOrganizerItem> mItems;
    QMap<int, QVersitOrganizerImporter::Error> mErrors;
    QVersitOrganizerImporterPropertyHandler* mPropertyHandler;
    QList<QVersitOrganizerHandler*> mPluginPropertyHandlers;
    QVersitTimeZoneHandler* mTimeZoneHandler;
    bool mDurationSpecified; // true iff a valid DURATION property has been seen in the current
                             // document with no subsequent DTEND property

private:
    bool createSimpleDetail(
            const QVersitProperty& property,
            QOrganizerItem* item,
            QList<QOrganizerItemDetail>* updatedDetails);
    bool createTimestampCreated(
            const QVersitProperty& property,
            QOrganizerItem* item,
            QList<QOrganizerItemDetail>* updatedDetails);
    bool createTimestampModified(
            const QVersitProperty& property,
            QOrganizerItem* item,
            QList<QOrganizerItemDetail>* updatedDetails);
    bool createVersion(
            const QVersitProperty& property,
            QOrganizerItem* item,
            QList<QOrganizerItemDetail>* updatedDetails);
    bool createPriority(
            const QVersitProperty& property,
            QOrganizerItem* item,
            QList<QOrganizerItemDetail>* updatedDetails);
    bool createComment(
            const QVersitProperty& property,
            QList<QOrganizerItemDetail>* updatedDetails);
    bool createItemReminder(
            const QVersitDocument &valarmDocument,
            QOrganizerItem *item,
            QList<QOrganizerItemDetail> *updatedDetails);
    int triggerToSecondsBeforeStart(const QVersitProperty& triggerProperty, const QOrganizerItem &item);

    bool createExtendedDetail(
            const QVersitProperty &property,
            QList<QOrganizerItemDetail> *updatedDetails);
    bool createRecurrenceId(
            const QVersitProperty& property,
            QOrganizerItem* item,
            QList<QOrganizerItemDetail>* updatedDetails);
    bool createStartDateTime(
            const QVersitProperty& property,
            QOrganizerItem* item,
            QList<QOrganizerItemDetail>* updatedDetails);
    bool createEndDateTime(
            const QVersitProperty& property,
            QOrganizerItem* item,
            QList<QOrganizerItemDetail>* updatedDetails);
    bool createDuration(
            const QVersitProperty& property,
            QOrganizerItem* item,
            QList<QOrganizerItemDetail>* updatedDetails);
    bool createTodoStartDateTime(
            const QVersitProperty& property,
            QOrganizerItem* item,
            QList<QOrganizerItemDetail>* updatedDetails);
    bool createDueDateTime(
            const QVersitProperty& property,
            QOrganizerItem* item,
            QList<QOrganizerItemDetail>* updatedDetails);
    bool createJournalEntryDateTime(
            const QVersitProperty& property,
            QOrganizerItem* item,
            QList<QOrganizerItemDetail>* updatedDetails);
    QDateTime parseDateTime(const QVersitProperty& property, bool* hasTime = 0) const;
    QDateTime parseDateTime(QString str) const;

    bool createRecurrenceRule(
            const QVersitProperty& property,
            QOrganizerItem* item,
            QList<QOrganizerItemDetail>* updatedDetails);
    bool parseRecurRule(const QString& str, QOrganizerRecurrenceRule* rule) const;
    void parseRecurFragment(const QString& key, const QString& value,
                            QOrganizerRecurrenceRule* rule) const;
    QSet<int> parseInts(const QString& str, int min, int max) const;
    int parseDayOfWeek(const QString& str) const;

    bool createRecurrenceDates(
            const QVersitProperty& property,
            QOrganizerItem* item,
            QList<QOrganizerItemDetail>* updatedDetails);
    bool parseDates(const QString& str, QSet<QDate>* dates) const;
    QDate parseDate(QString str) const;

    bool createStatus(
            const QVersitProperty& property,
            QOrganizerItem* item,
            QList<QOrganizerItemDetail>* updatedDetails);
    bool createPercentageComplete(
            const QVersitProperty& property,
            QOrganizerItem* item,
            QList<QOrganizerItemDetail>* updatedDetails);
    bool createFinishedDateTime(
            const QVersitProperty& property,
            QOrganizerItem* item,
            QList<QOrganizerItemDetail>* updatedDetails);

    TimeZone importTimeZone(const QVersitDocument& document) const;
    TimeZonePhase importTimeZonePhase(const QVersitDocument& document) const;

    QString takeFirst(QList<QString>& list) const;

    // versit property name -> <definition name, field name>:
    QMap<QString, std::pair<QOrganizerItemDetail::DetailType, int> > mPropertyMappings;
    TimeZones mTimeZones;
};

QT_END_NAMESPACE_VERSITORGANIZER

#endif // QVERSITORGANIZERIMPORTER_P_H
