// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtQuick 2.0

Item {
    property alias label: nameField.text
    property alias newValue: checkBox.checked

    signal checkBoxChanged

    height: 50
    width: detailsView.width

    Text {
        id: nameField
        width: parent.width * 0.4
        anchors { left: parent.left; margins: 3 }
        font.bold: true
        color: "white"
    }
    CheckBox {
        id: checkBox
        anchors { left: nameField.right; margins: 3 }
        checked: false
        onClicked: {
            checkBoxChanged();
        }
    }

    function setValue(initialValue) {
        if (checkBox.checked != initialValue) {
            checkBox.checked = initialValue;
            checkBoxChanged();
        }
    }

}
