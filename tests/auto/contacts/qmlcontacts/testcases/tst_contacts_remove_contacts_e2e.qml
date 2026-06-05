// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtQuick 2.0
import QtTest 1.0
import QtContacts 5.0

ContactsSavingTestCase {
    name: "ContactsRemoveContactsE2ETests"
    id: contactsRemoveContactsE2ETests

    ContactModel {
        id: model
        manager: getManagerUnderTest()
        autoUpdate: true
    }

    property Contact firstContact
    property Contact secondContact

    function init() {
        initTestForModel(model);
        emptyContacts(model);

        firstContact = createEmptyContact();
        model.saveContact(firstContact);
        waitForContactsChanged();

        secondContact = createEmptyContact();
        model.saveContact(secondContact);
        waitForContactsChanged();
    }

    function cleanup() {
        emptyContacts(model);
    }

    // Tests

    function test_removeEmptyList() {
        model.removeContacts([]);
        wait(500);

        compare(model.contacts.length, 2, "contacts.length");
    }

    function test_removeInvalidId() {
        model.removeContacts(["invalid"]);
        wait(500);

        compare(model.contacts.length, 2, "contacts.length");
    }

    function test_removeOneContact() {
        var id1 = model.contacts[0].contactId;
        var id2 = model.contacts[1].contactId;

        model.removeContacts([id1]);
        waitForContactsChanged();

        compare(model.contacts.length, 1, "contacts.length");
        compare(model.contacts[0].contactId, id2, "id of the second contact");
    }

    function test_removeMultipleContacts() {
        var id1 = model.contacts[0].contactId;
        var id2 = model.contacts[1].contactId;

        model.removeContacts([id1, id2]);
        waitForContactsChanged();
        if (model.contacts.length > 0)
            waitForContactsChanged();


        compare(model.contacts.length, 0, "contacts is empty");
    }

    function test_saveRemovedContactFails() {
        var id1 = model.contacts[0].contactId;
        var contactToFirstRemoveAndThenSave = model.contacts[0];

        model.removeContacts([id1]);
        waitForContactsChanged();

        var errorSpy = initTestForTargetListeningToSignal(model, "errorChanged");
        model.saveContact(contactToFirstRemoveAndThenSave);
        waitForTargetSignal(errorSpy);

        compare(model.error, "DoesNotExist", "model.error");
    }


    // Init & teardown

    function initTestCase() {
        initTestForModel(model);
        waitUntilContactsChanged();
        // The wait is needed so the model is populated
        // (e.g. with garbage left from previous test runs)
        // before cleanup() is called.
        emptyContacts(model);
    }

    function cleanupTestCase() {
        emptyContacts(model);
        finishTestForModel(model);
    }

    // Helpers

    function verifyIsUndefined(object) {
        verify(!object, "Object " + object + " is undefined");
    }
}
