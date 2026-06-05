// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtQuick 2.0
import QtOrganizer 5.0

Rectangle
{
    id:weekView

    anchors.fill: parent
    ListView {
        id : dayList
        anchors.fill: parent
        clip: true
        focus: true
        opacity : parent.opacity
        preferredHighlightBegin: dayList.height * 0.5
        preferredHighlightEnd: preferredHighlightBegin
        highlightFollowsCurrentItem : true
        highlightMoveSpeed : 2000
        keyNavigationWraps : true
        Component.onCompleted : positionViewAtIndex(currentIndex, ListView.Beginning)
        onOpacityChanged: {
                currentIndex = calendar.weekDay;
         }

        model : ListModel {
                ListElement {day : "Sunday"}
                ListElement {day : "Monday"}
                ListElement {day : "Tuesday"}
                ListElement {day : "Wednesday"}
                ListElement {day : "Thursday"}
                ListElement {day : "Friday"}
                ListElement {day : "Saturday"}
         }

        delegate:  dayDelegate

        Component {
            id: dayDelegate
            Item {
                width : dayList.width
                height : childrenRect.height
                Column {
                    Rectangle {
                        height : 1
                        width : dayList.width
                        color : "black"
                    }
                    Text {
                        text: day
                    }
                    Repeater {
                        focus: true
                        model: calendar.organizer.items? calendar.organizer.itemsByTimePeriod(new Date(calendar.year,calendar.month, index - calendar.weekDay + calendar.day),
                                                         new Date(calendar.year,calendar.month, index - calendar.weekDay + calendar.day + 1))
                                                       : 0
                        Text {
                            clip: true
                            focus: true
                            text: "a <a href=\"#\">" + modelData.displayLabel + "</a>"
                            onLinkActivated: {
                                detailsView.isNewItem = false;
                                detailsView.item = modelData;
                                if (detailsView.item.itemType == Type.EventOccurrence || detailsView.item.itemType == Type.TodoOccurrence)
                                    calendar.state = "OccurrenceDialogView";
                                else
                                    calendar.state = "DetailsView";
                            }
                        }
                    }
                }
            }
        }


        highlight:  Component {
            Rectangle {
                width: dayList.width
                height: dayList.height /7
                color: "lightsteelblue"
                radius: 5
            }
        }

    }
}

