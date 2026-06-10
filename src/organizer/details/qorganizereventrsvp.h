// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QORGANIZEREVENTRSVP_H
#define QORGANIZEREVENTRSVP_H

#include <QtOrganizer/qorganizereventattendee.h>
#include <QtOrganizer/qorganizeritemdetail.h>

QT_FORWARD_DECLARE_CLASS(QDate)

QT_BEGIN_NAMESPACE_ORGANIZER

/* Leaf class */

class Q_ORGANIZER_EXPORT QOrganizerEventRsvp : public QOrganizerItemDetail
{
public:
#ifndef Q_QDOC
    Q_DECLARE_CUSTOM_ORGANIZER_DETAIL(QOrganizerEventRsvp, QOrganizerItemDetail::TypeEventRsvp)
#endif

    enum EventRsvpField {
        FieldParticipationStatus = TypeEventRsvp + 1,
        FieldParticipationRole,
        FieldResponseRequirement,
        FieldResponseDeadline,
        FieldResponseDate,
        FieldOrganizerName,
        FieldOrganizerEmail
    };

    enum ResponseRequirement {
        ResponseNotRequired = 0,
        ResponseRequired = 1
    };

    void setParticipationStatus(QOrganizerEventAttendee::ParticipationStatus status);
    QOrganizerEventAttendee::ParticipationStatus participationStatus() const;

    void setParticipationRole(QOrganizerEventAttendee::ParticipationRole role);
    QOrganizerEventAttendee::ParticipationRole participationRole() const;

    void setResponseRequirement(ResponseRequirement responseRequirement);
    ResponseRequirement responseRequirement() const;

    void setResponseDeadline(const QDate &date);
    QDate responseDeadline() const;

    void setResponseDate(const QDate &date);
    QDate responseDate() const;

    void setOrganizerName(const QString &name);
    QString organizerName() const;

    void setOrganizerEmail(const QString &email);
    QString organizerEmail() const;
};

QT_END_NAMESPACE_ORGANIZER

#endif// QORGANIZEREVENTRSVP_H

