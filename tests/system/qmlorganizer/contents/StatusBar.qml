// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtQuick 2.0

Item {
    id: statusbar
    property string status
    signal leftClicked
    signal rightClicked
    signal addClicked
    signal managerChangeClicked

    BorderImage { source: "images/titlebar.sci"; width: parent.width; height: parent.height + 14; y: -7 }

    Button {//add new item button
        id: addButton
        text: "+"
        anchors.left: parent.left; anchors.leftMargin: 2; y: 3; width: 30; height: 32
        onClicked: statusbar.addClicked()
    }

    Button {
        id: leftButton
        text: "<"
        anchors.left: addButton.right; anchors.leftMargin: 2; y: 3; width: 30; height: 32
        onClicked: statusbar.leftClicked()
    }
    Text {
        id:statusText
        color: "#ecc70a"
        text:status
        font.family: "Monospace"
        font.bold: true
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pointSize: 6
        anchors.left: leftButton.right
        anchors.leftMargin: 2
        anchors.right: rightButton.left
        anchors.rightMargin: 2
        y: 5

    }

    Button {
        id: rightButton
        text: ">"
        anchors.right: todayButton.left; anchors.rightMargin: 2; y: 3; width: 30; height: 32
        onClicked: statusbar.rightClicked()
    }

    Button {
        //change the current Date to Today
        id: todayButton;
        anchors.right: parent.right; anchors.leftMargin: 2; y: 3; width: 50; height: 32
        text: "Today";
            onClicked: {
                var tempdate = new Date();
                calendar.currentDate = new Date(tempdate.getFullYear(), tempdate.getMonth(), tempdate.getDate());
            }
    }


}
