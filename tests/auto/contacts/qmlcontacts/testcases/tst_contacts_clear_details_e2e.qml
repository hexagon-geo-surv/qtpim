// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtQuick 2.0
import QtTest 1.0
import QtContacts 5.0

ContactsSavingTestCase {
    name: "ContactsClearDetailsE2ETests"

    ContactModel {
        id: model
        manager: getManagerUnderTest()
        autoUpdate: true
    }

    // Tests

    Contact {
        id: contact1
        Name {
            firstName: "1"
        }
    }

    function test_clear_details() {
        var contact = contact1;

        contact.clearDetails();

        var detail = contact1.detail(ContactDetail.Name);
        verifyIsUndefined(detail);
    }

    Contact {
        id: contact2
        Name {
            firstName: "2"
        }
    }

    function test_clear_details_of_contact_in_the_model() {
        var contact = contact2;
        model.saveContact(contact);
        waitForContactsChanged();
        contact = model.contacts[0];

        contact.clearDetails();

        var detail = contact.detail(ContactDetail.Name);
        verifyIsUndefined(detail);
    }

    Contact {
        id: contact3
        Name {
            firstName: "3"
        }
    }

    function test_clear_details_and_save_modified() {
        var contact = contact3;
        model.saveContact(contact);
        waitForContactsChanged();
        contact = model.contacts[0];

        contact.clearDetails();
        contact.save();
        waitForContactsChanged();

        var detail = contact.detail(ContactDetail.Name);
        verifyIsUndefined(detail);
    }

    Contact {
        id: contact3_1
        Name {
            firstName: "3_1"
        }
    }

    function test_clear_details_save_modified_and_refetch_from_model() {
        var contact = contact3_1;
        model.saveContact(contact);
        waitForContactsChanged();
        contact = model.contacts[0];

        contact.clearDetails();
        contact.save();
        waitForContactsChanged();

        contact = model.contacts[0];
        var detail = contact.detail(ContactDetail.Name);
        verifyIsUndefined(detail);
    }

    Contact {
        id: contact4
        Name {
            firstName: "4"
        }
    }

    function test_clear_details_and_save_through_model() {
        var contact = contact4;
        model.saveContact(contact);
        waitForContactsChanged();
        contact = model.contacts[0];

        contact.clearDetails();
        model.saveContact(contact);
        waitForContactsChanged();

        contact = model.contacts[0];
        var detail = contact.detail(ContactDetail.Name);
        verifyIsUndefined(detail);
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

    function init() {
        initTestForModel(model);
    }

    function cleanup() {
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
