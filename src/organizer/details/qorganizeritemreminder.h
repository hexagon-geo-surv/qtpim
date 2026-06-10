// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QORGANIZERITEMREMINDER_H
#define QORGANIZERITEMREMINDER_H

#include <QtOrganizer/qorganizeritemdetail.h>

QT_BEGIN_NAMESPACE_ORGANIZER

/* Leaf class */

class Q_ORGANIZER_EXPORT QOrganizerItemReminder : public QOrganizerItemDetail
{
public:
#ifndef Q_QDOC
    Q_DECLARE_CUSTOM_ORGANIZER_DETAIL(QOrganizerItemReminder, QOrganizerItemDetail::TypeReminder)
#endif

    enum ReminderField {
        FieldSecondsBeforeStart = TypeReminder + 1,
        FieldRepetitionCount,
        FieldRepetitionDelay
    };

    enum ReminderType {
        NoReminder = 0,
        VisualReminder,
        AudibleReminder,
        EmailReminder

        // other types of reminders?
        //ProcedureReminder,
        //TactileReminder,
    };

    ReminderType reminderType() const;

    void setSecondsBeforeStart(int seconds);
    int secondsBeforeStart() const;

    void setRepetition(int count, int delaySeconds);
    int repetitionDelay() const;
    int repetitionCount() const;

protected:
    /*! \internal */
    QOrganizerItemReminder(DetailType detailType) : QOrganizerItemDetail(detailType) {}
    /*! \internal */
    QOrganizerItemReminder(const QOrganizerItemDetail &detail, DetailType detailType) : QOrganizerItemDetail(detail, detailType) {}
};

#define Q_DECLARE_CUSTOM_ORGANIZER_REMINDER_DETAIL(className, reminderType) \
    className() : QOrganizerItemReminder(reminderType) {} \
    className(const QOrganizerItemDetail &field) : QOrganizerItemReminder(field, reminderType) {} \
    className& operator=(const QOrganizerItemDetail &other) {assign(other, reminderType); return *this;}

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERITEMREMINDER_H
