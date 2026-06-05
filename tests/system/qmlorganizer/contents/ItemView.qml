// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtQuick 2.0

import QtOrganizer 5.0

Rectangle
{
    id:itemView
    property string  itemId
    property OrganizerItem item
    property int startTime
    property int endTime
    onItemIdChanged :{
        if (itemId != "") {
            item = calendar.organizer.item(itemId);
            startTime = item.itemStartTime.getHours() * 60 + item.itemStartTime.getMinutes();
            if (item.itemType == Type.Event)
                endTime = item.itemEndTime.getHours() * 60 + item.itemEndTime.getMinutes();
            else
                endTime = startTime;
            itemLabel.text = item.displayLabel;
            itemDesc.text = item.description;
        }
    }
    radius: 5
    color: Type.Event == item.itemType ? "steelblue" : "green"

    Column {
        spacing: 2
        Text { id: itemLabel; color: "yellow"; wrapMode: Text.Wrap;  font.bold: true; horizontalAlignment: Text.AlignHCenter; style: Text.Raised; verticalAlignment: Text.AlignVCenter; font.pointSize: 12 }
        Text { id: itemDesc; color: "white"; wrapMode: Text.Wrap;  font.pointSize: 10}
    }

    MouseArea {
        anchors.fill: parent
        onClicked : {
            detailsView.itemId = itemId
            detailsView.savedItem = true
            calendar.state = "DetailsView"
        }
    }
}
