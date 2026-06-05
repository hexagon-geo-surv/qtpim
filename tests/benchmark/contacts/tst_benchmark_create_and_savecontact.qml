// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtQuick 2.0
import QtTest 1.0
import QtContacts 5.0

ContactsBenchmarkTestCase {
    name: "ContactsCreateAndSaveBenchmarkTests"
    id: contactsCreateAndSaveBenchmarkTests
    property Contact testContact
    property SignalSpy contactsChangedSpy
    property variant contactsList

    ContactModel {
        id: model
        manager:"memory";
        autoUpdate: true
    }

    SignalSpy {
        id: spy
        signalName: "contactsChanged"
        target: model
    }

    function initTestCase() {
    }

    function benchmark_createAndSaveContacts() {
        //bench marking creation and saving of 100 contacts
        for (var it=0;it<100;it++) {
            var contact = Qt.createQmlObject(
                        "import QtContacts 5.0;" +
                        "Contact {}", contactsCreateAndSaveBenchmarkTests)
            model.saveContact(contact);
            spy.wait()
       }
    }

    function cleanup() {
        var amt = model.contacts.length
        for (var i = 0; i < amt; i++) {
            var id = model.contacts[0].contactId
            model.removeContact(id)
            spy.wait()
        }
        compare(model.contacts.length, 0, "Failed to clean model")
    }

}

