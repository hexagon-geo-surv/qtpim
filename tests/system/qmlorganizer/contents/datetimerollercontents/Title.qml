// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtQuick 2.0

Rectangle {
    height: 10
    property alias label: text.text
    color: "black"
    radius: 3
    Text {
        id: text
        anchors.centerIn: parent
        font.pixelSize: 10
        color: "white"
    }
}
