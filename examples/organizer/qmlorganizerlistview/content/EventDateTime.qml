// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

//![Event Date Time Component]
//![Create Event Date Time Component]
import QtQuick 2.0

Rectangle {
    property alias date: eventDate.text
    property alias month: eventMonth.text
    property alias year: eventYear.text

    radius: 5
    border {color: "black"; width: 2}
    height: eventDate.height + eventMonth.height + eventYear.height * 1.3
    width: parent.width

//![Create Event Date Time Component]

//![Grid to edit Date Month Year]
    Grid {
        columns: 2
        spacing: 3
        //anchors.centerIn: parent

        Text {
            text: "Date:"
        }

        TextInput {
            id: eventDate
            validator: IntValidator {
                bottom: 1
                top: 31
            }
        }

        Text {
            text: "Month:"
        }
        TextInput {
            id: eventMonth
            validator: IntValidator {
                bottom: 1
                top: 12
            }
        }

        Text {
            text: "Year:"
        }
        TextInput {
            id: eventYear
            validator: IntValidator {
                bottom: 1970
                top: 2020
            }
        }
    }
//![Grid to edit Date Month Year]
}
//![Event Date Time Component]
