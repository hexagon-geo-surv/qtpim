// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtQuick 2.0

Item {
    property alias label: nameField.text
    property variant value
    property alias newValue: textEdit.text

    height: 50
    width: detailsView.width

    Text {
        id: nameField
        width: parent.width * 0.4
        anchors { left: parent.left; margins: 3 }
        font.bold: true
        color: "white"
    }
    Rectangle {
        id: editorField
        anchors { left: nameField.right; right:  parent.right; margins: 3 }
        height: parent.height - nameField.height;
        color: textEdit.activeFocus ? "white" : "lightgray";
        border { width: 3; color: "white" }
        radius: 5
        opacity: 0.95
        TextEdit {
            id: textEdit
            anchors { fill: parent; margins: 3}
            width: parent.width
            text: value ? value.toString() : ""
            wrapMode: TextEdit.Wrap
        }
    }

    function setValue(initialValue) {
        if (textEdit.text != initialValue) {
            textEdit.text = initialValue;
        }
    }

}
