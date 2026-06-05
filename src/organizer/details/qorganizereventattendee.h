// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QORGANIZEREVENTATTENDEE_H
#define QORGANIZEREVENTATTENDEE_H

#include <QtOrganizer/qorganizeritemdetail.h>

QT_BEGIN_NAMESPACE_ORGANIZER

/* Leaf class */

class Q_ORGANIZER_EXPORT QOrganizerEventAttendee : public QOrganizerItemDetail
{
public:
#ifndef Q_QDOC
    Q_DECLARE_CUSTOM_ORGANIZER_DETAIL(QOrganizerEventAttendee, QOrganizerItemDetail::TypeEventAttendee)
#endif

    enum EventAttendeeField {
        FieldName = TypeEventAttendee + 1,
        FieldEmailAddress,
        FieldAttendeeId,
        FieldParticipationStatus,
        FieldParticipationRole
    };

    enum ParticipationStatus {
        StatusUnknown = 0,
        StatusAccepted,
        StatusDeclined,
        StatusTentative,
        StatusDelegated,
        StatusInProcess,
        StatusCompleted
    };

    enum ParticipationRole {
        RoleUnknown = 0,
        RoleOrganizer,
        RoleChairperson,
        RoleHost,
        RoleRequiredParticipant,
        RoleOptionalParticipant,
        RoleNonParticipant
    };

    void setName(const QString &name);
    QString name() const;

    void setEmailAddress(const QString &emailAddress);
    QString emailAddress() const;

    void setParticipationStatus(ParticipationStatus status);
    ParticipationStatus participationStatus() const;

    void setParticipationRole(ParticipationRole role);
    ParticipationRole participationRole() const;

    void setAttendeeId(const QString &attendeeId);
    QString attendeeId() const;
};

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZEREVENTATTENDEE_H
