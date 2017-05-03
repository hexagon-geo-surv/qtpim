/****************************************************************************
**
** Copyright (C) 2017 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Mobility Components.
**
** $QT_BEGIN_LICENSE:GPL-EXCEPT$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 as published by the Free Software
** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

import QtQuick 2.0
import "month.js" as Month
import QtOrganizer 5.0

Rectangle  {
    id:monthView
    property int month
    property int year
    property date startDay:new Date(year, month, 1)
    property int startWeekday:startDay.getDay()
    property var containItems: calendar.organizer.items ? calendar.organizer.containsItems(Month.dateOfThisDay(startDay, 1 - startWeekday), Month.dateOfThisDay(startDay, 43 - startWeekday), 86400) : undefined
    anchors.fill: parent

    Grid {
        id:container
        anchors.fill: parent
        columns: 7
        Repeater {
            model:["Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"]
            Rectangle { width: container.width / 7
                        height: 35
                        color: "lightgray"
                        border.color: "#3f4947"
                        Text { text: modelData
                            font.bold: true
                            verticalAlignment: Text.AlignVCenter
                            style: Text.Sunken
                            styleColor: "#1365f3"
                            font.pointSize: 11
                            anchors.centerIn: parent
                        }
                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                calendar.state = "WeekView";
                            }
                        }
            }
        }

        Repeater { model: 42
                   Rectangle {
                       id:dayContainer
                       radius:10
                       width: container.width / 7
                       height: (container.height - 35) / 6
                       color:  {
                                  if (Month.isToday(startDay,   index - startWeekday +1)) {
                                      dayContainer.radius= 20
                                      return "lightsteelblue";
                                  }
                                  else if (monthView.containItems[index]) {
                                      dayContainer.radius= 20
                                      return "yellow";
                                  }
                                  else {
                                      dayContainer.radius= 0
                                      return Month.getColorOfDay(startDay,   index - startWeekday +1);
                                  }
                              }
                       Text {
                           color: "#6ba24b";
                           text: Month.getDayOfMonth(startDay,   index - startWeekday +1)
                           font.bold: true
                           style: Text.Raised
                           font.pointSize: 10
                           anchors.centerIn: parent
                       }

                       MouseArea {
                           hoverEnabled:true
                           anchors.fill: parent
                           onEntered: {
                               dayContainer.border.color = "#1365f3"; // Set a dark blue surrounding border...
                               dayContainer.border.width = 3;
                           }
                           onExited: {
                               dayContainer.border.color = "#ffffff"; // Must reset the border and turn off else becomes graphics artifact
                           }
                           onReleased: {
                               dayContainer.border.color = "#ffffff"; // Must reset the border and turn off else becomes graphics artifact
                           }
                           onClicked: {
                               dayContainer.border.color = "#ffffff"; // Must reset the border and turn off else becomes graphics artifact
                               calendar.currentDate = new Date(calendar.year, calendar.month, index - startWeekday +1);
                               calendar.state = "DayView";
                           }
                       }
                   }
        }
    }
}
