// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtQuick 2.0
import QtTest 1.0
import QtContacts 5.0

ContactsSavingTestCase {
    id: testcase
    name: "ContactsRemoveDetailE2ETests"

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

    function test_remove_detail() {
        contact1.removeDetail(contact1.detail(ContactDetail.Name))
        verifyIsUndefined(contact1.detail(ContactDetail.Name))
    }

    Contact {
        id: contact2
        Name {
            firstName: "2"
        }
    }

    function test_remove_detail_of_contact_in_the_model() {
        model.saveContact(contact2)
        waitForContactsChanged()
        var contact = model.contacts[0]
        contact.removeDetail(contact.detail(ContactDetail.Name))
        verifyIsUndefined(contact.detail(ContactDetail.Name));
    }

    Contact {
        id: contact3
        Name {
            firstName: "3"
        }
    }

    function test_remove_detail_and_save_modified() {
        model.saveContact(contact3)
        waitForContactsChanged()
        var contact = model.contacts[0]
        contact.removeDetail(contact.detail(ContactDetail.Name))
        contact.save()
        waitForContactsChanged()
        verifyIsUndefined(contact.detail(ContactDetail.Name))
    }

    Contact {
        id: contact3_1
        Name {
            firstName: "3_1"
        }
    }

    function test_remove_detail_save_modified_and_refetch_from_model() {
        model.saveContact(contact3_1)
        waitForContactsChanged()
        var contact = model.contacts[0]
        contact.removeDetail(contact.detail(ContactDetail.Name))
        contact.save()
        waitForContactsChanged()
        contact = model.contacts[0]
        verifyIsUndefined(contact.detail(ContactDetail.Name))
    }

    Contact {
        id: contact4
        Name {
            firstName: "4"
        }
    }

    function test_remove_detail_and_save_through_model() {
        model.saveContact(contact4)
        waitForContactsChanged()
        var contact = model.contacts[0]
        contact.removeDetail(contact.detail(ContactDetail.Name))

        model.saveContact(contact)
        waitForContactsChanged()

        contact = model.contacts[0]
        verifyIsUndefined(contact.detail(ContactDetail.Name))
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
