// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtQuick 2.0

Item {
    property string text
    signal clicked

    id: container
    Image {
        id: normal
        source: "images/button.png"
    }
    Image {
        id: pressed
        opacity: 0
        source: "images/button-pressed.png"
    }
    MouseArea {
        id: clickRegion
        anchors.fill: normal
        onClicked: { container.clicked();}
    }
    Text {
        font.bold: true
        color: "white"
        anchors.centerIn: normal
        text: container.text
    }
    width: normal.width
    height: childrenRect.height

    states: State {
        name: "Pressed"
        when: clickRegion.pressed == true
        PropertyChanges { target: pressed; opacity: 1 }
    }
}
