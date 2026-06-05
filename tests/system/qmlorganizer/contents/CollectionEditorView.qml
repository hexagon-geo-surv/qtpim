// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtQuick 2.0
import QtOrganizer 5.0

Item {
    anchors.centerIn: parent
    opacity: 0
    width: calendar.width;
    height: settingsView.height - settingsView.buttonTabsRow.height;

    property Collection collection;
    property bool isNewCollection: false

    Column {
        id: editorItems
        y: settingsView.buttonTabsRow.height

        spacing: 4
        opacity: 0.8
        width: parent.width; height: parent.height;

        Text {
            text: "Collection"
            height: 30
            anchors { horizontalCenter: parent.horizontalCenter }
            color: "White"
            font { pointSize: 15; weight: Font.Bold }
        }
        FieldRow {
            id: nameRow
            label: "Name"
            value: collection ? collection.name : ""
        }
//        FieldRow {
//            id: idRow
//            label: "Id"
//            value: collection.collectionId
//        }
        FieldRow {
            id: descRow
            label: "Description"
            value: collection? collection.description : ""
        }
        FieldRow {
            id: colorRow
            label: "Color"
            value: collection? collection.color : ""
        }
        FieldRow {
            id: imageRow
            label: "Image"
            value: collection? collection.image : ""
        }
    }

    Rectangle {
        id: buttonRow
        anchors { bottom: parent.bottom; left: parent.left; right: parent.right;  }
        height: saveCollectionButton.height
        color:"#343434"

        Button { id: saveCollectionButton; text: "Save"; width: calendar.width/2; onClicked: saveCollection(); anchors.left:parent.left }
        Button { id: removeCollectionButton; text: "Delete"; width: calendar.width/2; onClicked: removeCollection(); anchors.left:saveCollectionButton.right }
    }


    function saveCollection() {
        var newCollection = Qt.createQmlObject('import QtQuick 2.0; import QtOrganizer 5.0; Collection {}',organizer);
        newCollection.name = nameRow.newValue;
        newCollection.collectionId = collection.collectionId;
        newCollection.description = descRow.newValue;
        newCollection.color = colorRow.newValue;
        newCollection.image = imageRow.newValue;
        organizer.saveCollection(newCollection);
        settingsView.state = "CollectionManagerView";
    }

    function removeCollection() {
        organizer.removeCollection(collection.collectionId);
        settingsView.state = "CollectionManagerView";
    }
}
