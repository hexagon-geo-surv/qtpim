// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

//! [Basic list Complete Snippet]
import QtQuick 2.0
import QtOrganizer 5.0

Rectangle {
    id : organizerSample
    width: 200
    height: 400

    Rectangle {
        id:organizerEventView

        anchors.fill: parent
        color: "white"

//! [Organizer Model]
        OrganizerModel {
            id: organizer

            startPeriod: "1970-01-01"
            endPeriod:'2012-12-31'
            autoUpdate:true

            //! [Manager Choice]
            manager:"qtorganizer:memory:id=qml"
            //! [Manager Choice]

            Component.onCompleted : {
                if (managerName == "memory") {
                    organizer.importItems(Qt.resolvedUrl("content/organizer_ical_test.ics"));
                    console.log("Memory backend : import Items executed.");
                }
            }
        }
//! [Organizer Model]

//! [List View]
        ListView {
            id: calendar
            anchors.fill: parent

            clip: true

            delegate: Text { text: model.item.displayLabel }
            model: organizer
        }
//! [List View]
    }
}
//! [Basic list Complete Snippet]
