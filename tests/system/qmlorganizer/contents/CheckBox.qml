// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtQuick 2.0

        Rectangle {
            id: checkBox;
            property bool checked: false
            property string checkMark: "x"

            signal clicked( bool checked )

            Component.onCompleted: {
                if (!checked)
                    text.text = ""
                else
                    text.text = checkMark
            }

            width: text.height + 5
            height: text.height + 5
            color: "lightgrey"
            opacity: 0.95
            border.width: 3
            border.color: "white"
            radius: 5
            smooth: true

            Text {
                id: text
                anchors.verticalCenter: checkBox.verticalCenter
                anchors.horizontalCenter: checkBox.horizontalCenter
                color: "black"
            }

            MouseArea {
                id: mouseArea

                anchors.fill: parent
                onClicked: {
                    checked = !checked
                    checkBox.clicked( checked )
                }
            }

            states: [
            State {
                id: stateChecked

                name: "checked"; when: checked

                PropertyChanges {
                    id: propertyChangeCheckMark

                    target: text
                    text: checkMark
                }
                PropertyChanges { target: checkBox; border.color: "white"; color: "white"}
                }
            ]
        }
