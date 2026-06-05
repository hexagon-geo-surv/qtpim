// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

import QtQuick 2.0

//![Generic Button]
//![Create Button Rectangle]
Rectangle {
    signal clicked
    property alias buttonText: buttonLabel.text

    radius: 5
    height: buttonLabel.height
    color: "black"
//![Create Button Rectangle]

//![Create Button Border]
    border {
        width: 1
        color: "black"
    }
//![Create Button Border]

//![Button Text]
    Text {
        id: buttonLabel
        font.pixelSize: 12
        anchors.centerIn: parent
        color: "white"
    }
//![Button Text]

//![Setup Button Mouse Area]
    MouseArea {
        anchors.fill: parent
        onPressed: {
            parent.color = "white"
        }
        onReleased: {
            parent.color = "black"
            parent.clicked()
        }
    }
//![Setup Button Mouse Area]

}
//![Generic Button]
