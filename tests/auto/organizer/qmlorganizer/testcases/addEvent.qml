// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtQuick 2.0
import QtOrganizer 5.0

OrganizerModel {
    id:myModel;

    property Event myEvent : Event {id:myEvent; startDateTime: new Date(); endDateTime: new Date() }
    property RecurrenceRule myReccuranceRule: RecurrenceRule {
                                                    id: myReccuranceRule
                                                    frequency: RecurrenceRule.Monthly
                                                    daysOfWeek:[Qt.Friday]
                                                    limit: 2
                                                }
    property bool testComplete : false

    function addEvents(testEvents)
    {
        for (var index=0; index < testEvents.length; index++){
            var event = testEvents[index]
            console.log("Creating event " + event.subject)
            myModel.myEvent.description = event.subject
            myModel.myEvent.startDateTime = event.startDateTime
            myModel.myEvent.endDateTime = event.endDateTime

            // only support testing simple RecurrenceRules ATM
            if (event.repeat){
                myReccuranceRule.frequency = event.repeat
                myReccuranceRule.limit = event.repeatCount
                myReccuranceRule.daysOfWeek = event.repeatDays
                //myModel.myEvent.recurrence.recurrenceRules = [myReccuranceRule]
            }

            // TODO verify that the OrganizerModel::itemsSaved() signal is fired
            saveItem(myModel.myEvent)
        }
        update()
        myModel.testComplete = (items.length == testEvents.length)
    }

    function testEvents()
    {
        return myModel.items
    }
}

