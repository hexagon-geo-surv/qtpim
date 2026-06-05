// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtQuick 2.0

Rectangle {
    id: selectionView

    property alias title: title.text
    property alias model: container.model

    height: 150
    width: calendar.width
    anchors.centerIn: parent
    opacity: 0

    Column {
        spacing: 2
        anchors { horizontalCenter: parent.horizontalCenter; verticalCenter: parent.verticalCenter }

        Text {
            id: title
            font { pointSize: 15; weight: Font.Bold }
        }
        Repeater {
            id: container
        }
    }
}
