// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtQuick 2.0
import QtTest 1.0
import QtContacts 5.0

ContactsSavingTestCase {

    name: "ContactsExportImportE2ETests"

    ContactModel {
        id: model
        manager: getManagerUnderTest()
        autoUpdate: true
    }

    Contact {
        id: testContact
        Name {
            firstName: "First"
            lastName: "Last"
        }

        PhoneNumber {
            contexts: ContactDetail.ContextOther
            number: "5874983729"
        }
    }

    // Base for vcard file names.
    property string vcardFileNameBase: 'tst_contacts_export_import_e2e_'

    function test_contactExportImportWithTinyContactExportSignaling() {

        var signalSpy = initTestForTargetListeningToSignal(model, "exportCompleted");

        // Save and fetch test contact.
        model.saveContact(testContact);
        waitForContactsChanged();

        // Export contacts to vcard file.
        var vcardFilePath = Qt.resolvedUrl(vcardFileNameBase + "1.vcard");
        model.exportContacts(vcardFilePath, ["Sync"]);
        waitForTargetSignal(signalSpy);

        // Empty all contacts and import just created vcard file.
        emptyContacts(model);
        listenToContactsChanged();
        model.importContacts(vcardFilePath, ["Sync"]);
        waitForContactsChanged();
        compare (model.error, "NoError", "importError");

        // Check that imported contact has correct data.
        compare (model.contacts.length, 1, "import count");
        var importedContact = model.contacts[0];
        compare(importedContact.name.firstName,"First", "imported contact first name");
        compare(importedContact.name.lastName,"Last", "imported contact last name");
    }

    function test_exportListOfDeclarativeContacts() {
        var signalSpy = initTestForTargetListeningToSignal(model, "exportCompleted");

        // Export contacts to vcard file.
        var vcardFilePath = Qt.resolvedUrl(vcardFileNameBase + "contactsList.vcard");
        var temp = new Array(1);
        temp[0] = testContact;
        model.exportContacts(vcardFilePath, ["Sync"], temp);
        waitForTargetSignal(signalSpy);

        // Empty all contacts and import just created vcard file.
        emptyContacts(model);
        listenToContactsChanged();
        model.importContacts(vcardFilePath, ["Sync"]);
        waitForContactsChanged();
        compare (model.error, "NoError", "importError");

        // Check that imported contact has correct data.
        compare (model.contacts.length, 1, "import count");
        var importedContact = model.contacts[0];
        compare(importedContact.name.firstName,"First", "imported contact first name");
        compare(importedContact.name.lastName,"Last", "imported contact last name");
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

}
