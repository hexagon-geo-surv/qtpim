// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtQuick 2.0

Rectangle {
    Rectangle {
        id: frameRateCounter
        anchors.fill: parent
        property int dummy: 0
        property int fpsCount: 0
        color: "black"

        Text {
            id: fpsText
            color: "white"
            anchors.centerIn: parent
        }

        NumberAnimation on dummy {
            duration: 500
            from: 0
            to: 10000
            loops: Animation.Infinite
        }
        onDummyChanged: ++fpsCount;

        Timer {
            interval: 1000
            repeat: true
            running: true
            onTriggered: {
                fpsText.text = "Frame rate: " + parent.fpsCount + " fps";
                parent.fpsCount = 0;
            }
        }
    }
}

