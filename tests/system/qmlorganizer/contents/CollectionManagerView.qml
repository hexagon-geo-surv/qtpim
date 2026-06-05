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

    Column {
        spacing: 2
        y: settingsView.buttonTabsRow.height

        width: parent.width; height: parent.height;

        Text {
            text: "Collections:"
            height: 30
            anchors { horizontalCenter: parent.horizontalCenter }
            color: "White"
            font { pointSize: 15; weight: Font.Bold }
        }

        ListView {
            id: collectionList
            opacity: 0.8
            width: parent.width; height: parent.height - instructionsText.height;
            model: organizer.collections

            clip: true
            focus: true
            delegate: listViewDelegate
        }

        Text {
            id: instructionsText
            text: "<To start filtering collections, check the squares of wanted collections, by default all collections are enabled>"
            height: 100; width: parent.width
            anchors { horizontalCenter: parent.horizontalCenter }
            color: "White"
            wrapMode: TextEdit.WordWrap
            font { italic: true }
        }
    }

    Component {
        id: listViewDelegate
        Row {
            property bool isEnabledInCollectionFilter: modelCollectionFilter.ids.indexOf(collectionId) != -1
            anchors { horizontalCenter: parent.horizontalCenter }
            spacing: 5
            Text {
                text: name
                height: 30
                color: "White"
                font { weight: Font.Bold }

                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        collectionList.currentIndex = index;
                        modifyCollection();
                    }
                }
            }
            CheckBox {
                checked: isEnabledInCollectionFilter
                onClicked: {
                    collectionList.currentIndex = index;
                    isEnabledInCollectionFilter = !isEnabledInCollectionFilter;
                    modifyCollectionFilter(isEnabledInCollectionFilter, index);
                }
            }
        }
    }

    function addCollection() {
        collectionEditorView.collection = Qt.createQmlObject('import QtQuick 2.0; import QtOrganizer 5.0; Collection {}',organizer);
        collectionEditorView.collection.name = "Collection"+(organizer.collections.length+1);
        collectionEditorView.isNewCollection = true;
        settingsView.state = "CollectionEditorView";
    }

    function modifyCollection() {
        collectionEditorView.collection = organizer.collections[collectionList.currentIndex];
        collectionEditorView.isNewCollection = false;
        settingsView.state = "CollectionEditorView";
    }

    function modifyCollectionFilter(enabled, index) {
        //Get exist filter id list,
        var filterIdsList = modelCollectionFilter.ids;
        //Collection id will be added or removed from filter
        var collectionId = organizer.collections[index].collectionId;
        var filterIndex = filterIdsList.indexOf(collectionId);
        if (false == enabled) {
            if (filterIndex >= 0) //If the enable is false, remove from the list if we found inside list
                filterIdsList.splice(filterIndex, 1);
            else
                console.log("Warning: Collection id is not found in filter list" + collectionId);
        } else {//Add this id in the filter list if we do not have it in list
            if (filterIndex == -1)
                filterIdsList.push(collectionId);
            else
                console.log("Warning: Collection id exists in filter list :" + collectionId);
        }
        //Update model collection filter
        modelCollectionFilter.ids = filterIdsList;
    }
}

