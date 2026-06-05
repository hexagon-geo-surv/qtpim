// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtQuick 2.0

// These buttons are very ugly
Rectangle {
    id: container

    signal clicked
    property string image: ""
    property string text: ""
    property int padding: 2

    color: activePalette.button;
    smooth: true
    border.width: 1;
    border.color: Qt.darker(activePalette.dark);
    radius: 2;


    gradient: Gradient {
        GradientStop { position: 0.0; color: Qt.lighter(activePalette.button) }
        GradientStop { position: 1.0; color : mr.pressed ?  Qt.lighter(activePalette.light) : Qt.darker(activePalette.dark) }
    }
    width: stuff.width + 4 * padding
    height: stuff.height + 2 * padding

    Item {
        id: stuff
        width: childrenRect.width;
        height: childrenRect.height;
        y: padding
        anchors.horizontalCenter: parent.horizontalCenter

        Row {
            Image {
                id: imgItem;
                smooth: true
                width: source != "" ? 16 : 0; height: source != "" ? 16 : 0;
                source: container.image;
                opacity: source == "" ? 0 : 1;
            }

            Text {
                horizontalAlignment: Text.AlignHCenter
                id: txtItem; text: container.text; font.pixelSize: 14; color: activePalette.buttonText
            }
        }
    }

    // Don't make mr part of the size determination, since it uses anchors.fill
    MouseArea { id: mr; anchors.fill: parent; onClicked: container.clicked() }

}
