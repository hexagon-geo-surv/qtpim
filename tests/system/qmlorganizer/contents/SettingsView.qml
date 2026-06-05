// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtQuick 2.0
import QtOrganizer 5.0

Item {
        id: view
        anchors.centerIn: parent
        opacity: 0
        width: calendar.contentArea.width;
        height: calendar.contentArea.height;
        state: "CollectionManagerView"
        property alias collectionManagerView: collectionManagerView
        property alias buttonTabsRow : buttonTabsRow

        states: [
            State {name: "CollectionManagerView"; PropertyChanges { target: collectionManagerView; opacity: 1; }},
            State {name: "CollectionEditorView"; PropertyChanges { target: collectionEditorView; opacity: 1; }}
        ]
        transitions: [
            Transition {
                NumberAnimation {
                    properties: "opacity"
                    easing.type: "Linear"
                    duration: 10
                }
            }
        ]

        Row {
            id: buttonTabsRow
            anchors { top: parent.top }
            Button {
                text: "Collections"
                width: calendar.width / 2
                onClicked: { view.state = "CollectionManagerView"}
            }
        }

        CollectionManagerView {
            id: collectionManagerView;
        }
        CollectionEditorView {
            id: collectionEditorView;
        }
}
