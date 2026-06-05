// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtQuick 2.0

Image {
    property alias model: view.model
    property alias delegate: view.delegate
    property alias currentIndex: view.currentIndex
    property real itemHeight: 15

    source: "spinner-bg.png"
    clip: true
    focus: true
    width: 30; height: 60

    PathView {
        id: view
        anchors.fill: parent
        clip: true

        pathItemCount: height/itemHeight
        preferredHighlightBegin: 0.5
        preferredHighlightEnd: 0.5
        //highlight: Rectangle { color: "lightblue"; width: view.width; height: itemHeight+4; }
        highlight: Image { source: "spinner-select.png"; width: view.width; height: itemHeight+4 }
        dragMargin: view.width/2

        path: Path {
            startX: view.width/2; startY: -itemHeight/2
            PathLine { x: view.width/2; y: view.pathItemCount*itemHeight + itemHeight }
        }
    }

    Keys.onDownPressed: view.incrementCurrentIndex()
    Keys.onUpPressed: view.decrementCurrentIndex()
}
