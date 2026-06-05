// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtQuick 2.0

Rectangle {
    id: menuBar;

    property string info;
    BorderImage { source: "images/titlebar.sci"; width: parent.width; height: parent.height + 14; y: -7 }
    gradient: Gradient {
        GradientStop { position: 0.0; color: activePalette.dark }
        GradientStop { position: 1.0; color: Qt.darker(activePalette.dark); }
    }
    Row {
        spacing: 0
        Image {
            id: quitButton
            height: monthButton.height
            width:height
            source: "images/quit.png"
            MouseArea {
                anchors.fill: parent
                onClicked: Qt.quit()
            }
        }

        Button { id: dayButton; text: "Day";onClicked: calendar.state="DayView";}
        Button { id: weekButton; text: "Week";onClicked: calendar.state="WeekView";}
        Button { id: monthButton; text: "Month"; onClicked: calendar.state="MonthView";}
        Button { id: timelineButton; text: "Timeline";onClicked: calendar.state="TimelineView";}
        Button { id: todoButton; text: "Todos";onClicked: calendar.state="TodoView"; }
        Button { id: settingsButton; text: "Settings";onClicked: calendar.state="SettingsView";}

        Text { color: "#f5f210";text:info ; font.bold: true; verticalAlignment: Text.AlignVCenter; style: Text.Sunken;font.pointSize: 6}
    }
}

