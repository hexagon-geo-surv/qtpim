// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtQuick 2.0
import QtOrganizer 5.0

Item {
    anchors.centerIn: parent
    opacity: 0
    width: calendar.width;
    height: calendar.height - menuBar.height - statusBar.height - 50;

    Column {
        spacing: 2
        width: parent.width; height: parent.height;

        Text {
            text: "Todos:"
            height: 30
            anchors { horizontalCenter: parent.horizontalCenter }
            color: "white"
            font { pointSize: 15; weight: Font.Bold }
        }

        ListView {
            width: parent.width; height: parent.height;
            model: organizer.items
            clip: true
            delegate: Text {
                anchors { horizontalCenter: parent.horizontalCenter }
                color:  "white"
                text: "- " + displayLabel + " -"
            }
        }
    }
}
