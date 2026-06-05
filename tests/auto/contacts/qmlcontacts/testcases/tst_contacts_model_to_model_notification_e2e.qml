// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtQuick 2.0
import QtTest 1.0
import QtContacts 5.0

ContactsSavingTestCase {
    name: "ContactsModelToModelNotificationE2ETests"
    id: contactsModelToModelNotificationE2ETests

    ContactModel {
        id: modifiedModel
        manager: getManagerUnderTest()
        autoUpdate: false
        // otherwise this model will distract the test helper functions
    }

    ContactModel {
        id: notifiedModel
        manager: getManagerUnderTest()
        autoUpdate:true
    }

    function test_createContactShouldUpdateOtherModels()
    {
        initTestForModel(notifiedModel);

        modifiedModel.saveContact(createEmptyContact());
        waitForContactsChanged();
        compare(notifiedModel.contacts.length, 1,
                "contacts updated in the notified model");
    }

    Contact {
        id: contactWithDetailToBeVerified
        Name {
            firstName: "contactWithDetailToBeVerified"
        }
    }

    function test_createContactPassesDetailsToOtherModels()
    {
        initTestForModel(notifiedModel);

        modifiedModel.saveContact(contactWithDetailToBeVerified);

        waitForContactsChanged();
        compareContactArrays(notifiedModel.contacts, [contactWithDetailToBeVerified],
                             "contacts updated in the notified model");
    }

    Contact {
        id: firstOfMultipleContacts
    }

    Contact {
        id: secondOfMultipleContacts
    }

    function test_createMultipleContactsShouldUpdateOtherModels()
    {
        initTestForModel(notifiedModel);

        emptyContacts(notifiedModel);

        modifiedModel.saveContact(firstOfMultipleContacts);
        modifiedModel.saveContact(secondOfMultipleContacts);

        waitForContactsChanged();
        if (notifiedModel.contacts.length < 2) {
            waitForContactsChanged();
        }
        compare(notifiedModel.contacts.length, 2,
                "contacts updated in the notified model");
    }

    Contact {
        id: contactToBeUpdated
        Name {
            firstName: "old"
        }
    }

    function test_updateContactShouldUpdateOtherModels()
    {
        initTestForModel(modifiedModel);
        modifiedModel.saveContact(contactToBeUpdated);
        modifiedModel.update();
        waitForContactsChanged();
        var contact = modifiedModel.contacts[0];

        initTestForModel(notifiedModel);
        if (notifiedModel.contacts.length < 1)
            waitForContactsChanged();
        compare(notifiedModel.contacts.length, 1,
                "guard: contact present in the notified model");

        contact.name.firstName = "new";
        modifiedModel.saveContact(contact);
        waitForContactsChanged();

        compare(notifiedModel.contacts[0].name.firstName, "new", "first name");
    }

    Contact {
        id: contactWithNoDetails
    }

    Name {
        id: detailForContactWithNoDetails
        firstName: "detail"
    }

    function pending_updateContactByAddingDetail()
    {
        initTestForModel(modifiedModel);
        modifiedModel.saveContact(contactWithNoDetails);
        waitForContactsChanged();

        initTestForModel(notifiedModel);

        compareContactArrays(notifiedModel.contacts, [contactWithNoDetails], "contact present in the notified model");

        initTestForModel(notifiedModel);

        contactWithNoDetails.addDetail(detailForContactWithNoDetails);
        modifiedModel.saveContact(contactWithNoDetails);

        waitForContactsChanged();
        compareContactArrays(notifiedModel.contacts, [contactWithDetail], "contact updated in the notified model");
    }

    Contact {
        id: contactWithDetail
        Name {
            id: detailOfContactWithDetail
            firstName: "detail"
        }
    }

    function pending_updateContactByRemovingDetail()
    {
        initTestForModel(modifiedModel);
        modifiedModel.saveContact(contactWithDetail);
        waitForContactsChanged();

        initTestForModel(notifiedModel);

        compareContactArrays(notifiedModel.contacts, [contactWithDetail], "contact present in the notified model");

        initTestForModel(notifiedModel);

        contactWithDetail.removeDetail(detailOfContactWithDetail);
        modifiedModel.saveContact(contactWithDetail);

        waitForContactsChanged();
        compareContactArrays(notifiedModel.contacts, [contactWithDetail], "contact updated in the notified model");
    }

    function test_removeContactShouldUpdateOtherModel()
    {
        initTestForModel(modifiedModel);
        modifiedModel.saveContact(createEmptyContact());
        modifiedModel.update();
        waitForContactsChanged();
        var id = modifiedModel.contacts[0].contactId;

        initTestForModel(notifiedModel);
        if (notifiedModel.contacts.length < 1)
            waitForContactsChanged();
        compare(notifiedModel.contacts.length, 1, "guard: contact present in the notified model");

        modifiedModel.removeContact(id);
        waitForContactsChanged();

        compare(notifiedModel.contacts.length, 0, "contacts removed from the notified model");
    }

    function initTestCase() {
        initTestForModel(notifiedModel);
        waitUntilContactsChanged();
        emptyContacts(notifiedModel);
    }

    function init() {
        if (notifiedModel.manager == 'memory')
            skip("memory backend does not support this at the moment");
        initTestForModel(notifiedModel);
        emptyContacts(notifiedModel);
    }

    function cleanup() {
        initTestForModel(notifiedModel);
        emptyContacts(notifiedModel);
    }

    function cleanupTestCase() {
        initTestForModel(notifiedModel);
        emptyContacts(notifiedModel);
        finishTestForModel(notifiedModel);
        finishTestForModel(modifiedModel);
    }

    function compareContactArrays(actual, expected, message) {
        compare(actual.length, expected.length, message + ": length");
        for (var i = 0; i < expected.length; i++) {
            compareContacts(actual[i], expected[i], message);
        }
    }

    function compareContacts(actual, expected, message) {
        if (expected.name) {
            compare(actual.name.firstName, expected.name.firstName, message + ': name.firstName');
            compare(actual.name.lastName, expected.name.lastName, message + ': name.lastName');
        }
        if (expected.email) {
            compare(actual.email.emailAddress, expected.email.emailAddress,
                    message + ': email.emailAddress');
        }
    }
}
