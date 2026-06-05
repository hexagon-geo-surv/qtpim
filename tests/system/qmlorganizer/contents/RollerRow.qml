// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtQuick 2.0
import "datetimerollercontents"

Item {
    property variant value
    property variant valueSet
    property alias label: nameField.text
    property alias valueRoller : valueRoller
    property alias currentIndex : valueSpinner.currentIndex
    property alias spinnerDelegate : valueSpinner.delegate

    signal rollerChanged

    height: 100
    width: detailsView.width

    onValueChanged: {
        valueSpinner.currentIndex = value
    }

    Text {
        id: nameField
        width: parent.width * 0.4
        anchors { left: parent.left; margins: 3 }
        font.bold: true
        color: "white"
    }

    Rectangle {
        id: valueRoller

        width: roller.width
        height: roller.height
        anchors { left: nameField.right; margins: 3}
        color: "white";
        border { width: 3; color: "white" }
        radius: 5

        Grid {
            id: roller
            spacing: 2
            columns: 1
            Spinner {
                id: valueSpinner
                width: 150
                model: valueSet.length //10
                delegate: Text { text: valueRoller.valueName(index); }
                onCurrentIndexChanged: rollerChanged()
            }
        }

        function valueName(valueIndex) {
            if (valueSet.length > valueIndex)
                return valueSet[valueIndex];
            else
                return valueIndex;
        }

        // component API

        // use this to read selected datetime
        function selectedValue() {
            return valueSpinner.currentIndex;
        }
    }
}
