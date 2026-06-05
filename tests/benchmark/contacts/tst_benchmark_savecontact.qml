// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtQuick 2.0
import QtTest 1.0
import QtContacts 5.0


ContactsBenchmarkTestCase {

    name: "ContactsSaveBenchmarkTests"
    id: contactsSaveBenchmarkTests
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
        createContacts(100);
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

    function benchmark_saveContacts() {
        for (var it=0 ; it<contactsList.length;it++) {
            model.saveContact(contactsList[it]);
            spy.wait()
        }
    }
}

