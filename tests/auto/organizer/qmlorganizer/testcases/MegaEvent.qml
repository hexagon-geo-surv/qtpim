// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtOrganizer 5.0

Event {

    startDateTime: new Date("2012-01-01T12:00:00Z")
    endDateTime: new Date("2012-01-01T13:00:00Z")
    allDay: false

    Comment {
        comment: "Comment"
    }

    Description {
        description: "Description"
    }

    DisplayLabel {
        label: "Display label"
    }

    Location {
        latitude: 1.1
        longitude: 1.2
        label: "Location"
    }

    Priority {
        priority: Priority.Lowest
    }

    Tag {
        tag: "Tag"
    }

    Timestamp {
        created: new Date("2012-01-01T12:00:00Z")
        lastModified: new Date("2012-01-01T12:00:00Z")
    }

    AudibleReminder {
        repetitionCount: 1
        repetitionDelay: 1
        secondsBeforeStart: 0
        dataUrl: "ftp://Audible_reminder_data_url"
    }

    EmailReminder {
        repetitionCount: 1
        repetitionDelay: 1
        secondsBeforeStart: 0
        body: "Email reminder body"
        subject: "Email reminder subject"
        recipients: ["Recipient 1", "Recipient 2"]
        attachments: ["Attachment 1", "Attachment 2"]
    }

    VisualReminder {
        repetitionCount: 1
        repetitionDelay: 1
        secondsBeforeStart: 0
        message: "Visual reminder message"
        dataUrl: "ftp://visual_reminder_data_url"
    }

    ExtendedDetail {
        name: "extended detail: string data"
        data: "data"
    }

    ExtendedDetail {
        name: "extended detail: integer data"
        data: 1
    }

    ExtendedDetail {
        name: "extended detail: array data"
        data: ["string 1", "string 2"]
    }

    ExtendedDetail {
        name: "extended detail: object data"
        data: {"key 1": "string 1", "key 2": "string 2"}
    }

    EventAttendee {
        name: "Event attendee"
        emailAddress: "new.attendee@qt.com"
        attendeeId: "123444455555"
        participationStatus: EventAttendee.StatusAccepted
        participationRole: EventAttendee.RoleRequiredParticipant
    }

    EventRsvp {
        organizerName: "Organizer name"
        organizerEmail: "Organizer email"
        responseDate: new Date("2012-01-01T12:00:00Z")
        responseDeadline: new Date("2012-01-01T12:00:00Z")
        participationStatus: EventAttendee.StatusAccepted
        participationRole: EventAttendee.RoleOrganizer
        responseRequirement: EventRsvp.ResponseRequired
    }

    Classification {
        classification: Classification.AccessConfidential
    }

    Version {
        version: 1
        extendedVersion: "1234"
    }

}
