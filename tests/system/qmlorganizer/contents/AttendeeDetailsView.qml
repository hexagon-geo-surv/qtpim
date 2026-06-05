// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtQuick 2.0
import QtOrganizer 5.0

Rectangle {
    id: attendeeDetailsView
    anchors.top: menuBar.bottom
    opacity: 0
    width: calendar.width;
    height: calendar.height - menuBar.height
    property variant item

    onItemChanged: {
        attendeeEditNameRow.value = "name";
        attendeeEditEmailRow.value = "name@qt.nokia.com";
        attendeeEditAttendeeIdRow.value = "contact id";
        attendeeEditRoleRow.value = 4;
    }

    Image { source: "images/stripes.png"; fillMode: Image.Tile; anchors.fill: parent; opacity: 0.8 }
    color: "#343434";

    Column {
        Repeater {
            model: item? item.attendees : 0
            Rectangle {
                width: attendeeDetailsView.width;
                height: 25
                Text {
                    id : nameText;
                    width: parent.width
                    text: "attendee " + index + " : " + name + "," + emailAddress;
                }
                Button {
                    text: "remove"
                    width: parent.width / 6
                    height: 30
                    anchors.right: nameText.right
                    onClicked: {
                        item.removeDetail(modelData);
                    }
                }
            }
        }

        FieldRow {
            id: attendeeEditNameRow
            label: "Attendee name"
            value: "name"
        }
        FieldRow {
            id: attendeeEditEmailRow
            label: "Attendee email"
            value: "name@qt.nokia.com"
        }
        FieldRow {
            id: attendeeEditAttendeeIdRow
            label: "Attendee attendeeId"
            value: ""
        }
        RollerRow {
            id: attendeeEditRoleRow
            label: "Attendee role"
            height: 80
            valueSet: ["Unknown", "Organizer", "Chairperson", "Host", "RequiredParticipant", "OptionalParticipant", "NonParticipant"]
        }
        RollerRow {
            id: attendeeEditStatusRow
            label: "Attendee Status"
            height: 80
            valueSet: ["Unknown", "StatusAccepted", "StatusDeclined", "StatusTentative", "StatusDelegated", "StatusInProcess", "StatusCompleted"]
        }
        Row {
            Button {
                id: addAttendeeButton
                text: "Add New"
                width: attendeeDetailsView.width / 2
                onClicked: {
                    if (attendeeEditNameRow.newValue) {
                        var eventAttendee = Qt.createQmlObject("import QtOrganizer 5.0;EventAttendee {}", organizer);
                        eventAttendee.name = attendeeEditNameRow.newValue;
                        if (attendeeEditEmailRow.newValue)
                            eventAttendee.emailAddress = attendeeEditEmailRow.newValue;
                        if (attendeeEditAttendeeIdRow.newValue)
                            eventAttendee.attendeeId = attendeeEditAttendeeIdRow.newValue;
                        eventAttendee.participationRole = attendeeEditRoleRow.valueRoller.selectedValue()
                        eventAttendee.participationStatus = attendeeEditStatusRow.valueRoller.selectedValue()
                        item.setDetail(eventAttendee);
                    }
                }
            }
            Button {
                id: closeButton
                text: "Close"
                width: attendeeDetailsView.width / 2
                onClicked: {
                    calendar.state = "DetailsView";
                }
            }
        }
    }
}
