// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtQuick 2.0
import QtTest 1.0
import QtContacts 5.0

ContactsSavingTestCase {
    id: testcase
    name: "Contacts collection filter test"

    property string defaultCollectionId: ""

    ContactModel {
        id: model
        manager: getManagerUnderTest()
        autoUpdate: true
    }

    Collection {
        id: testCollection
        name: 'My collection filter test'
        description: 'collection filter test'
    }

    Contact {
        id: contact1;
        Name {
            firstName: "A"
        }
        PhoneNumber {
            number: "1111111111"
        }
    }

    Contact {
        id: contact2;
        Name {
            firstName: "B"
        }
        PhoneNumber {
            number: "2222222222"
        }
    }

    Contact {
        id: contact3;
        Name {
            firstName: "John Joe"
        }
        PhoneNumber {
            number: "3333333333"
        }
    }

    function createCollectionFilter(ids)
    {
        var filter = Qt.createQmlObject(
                    "import QtContacts 5.0;" +
                    "CollectionFilter {}",
                    testcase);

        filter.ids = ids
        return filter;
    }

    function initTestCase() {
        initTestForModel(model);
        waitUntilContactsChanged();
        compare(model.collections.length, 1);
        defaultCollectionId = model.collections[0].collectionId
        // The wait is needed so the model is populated
        // (e.g. with garbage left from previous test runs)
        // before cleanup() is called.
        emptyContacts(model);
        model.saveCollection(testCollection)
        waitForCollectionsChanged();
        compare(model.collections.length, 2);
        model.saveContact(contact1);
        waitForContactsChanged();
        compare(contact1.collectionId, defaultCollectionId);
        contact2.collectionId = testCollection.collectionId
        model.saveContact(contact2);
        waitForContactsChanged();
        contact3.collectionId = testCollection.collectionId
        model.saveContact(contact3);
        waitForContactsChanged();
        compare(model.contacts.length, 3);
    }

    function test_collectionFilter(data) {
        var filterDefaultCollection = createCollectionFilter([defaultCollectionId]);
        model.filter = filterDefaultCollection;
        waitForContactsChanged();
        compare(model.contacts.length, 1);

        var filterOnlyNewCollection = createCollectionFilter([testCollection.collectionId]);
        model.filter = filterOnlyNewCollection;
        waitForContactsChanged();
        compare(model.contacts.length, 2);

        var filterNewCollectionAndDefaultCollection = createCollectionFilter([defaultCollectionId, testCollection.collectionId])
        model.filter = filterNewCollectionAndDefaultCollection;
        waitForContactsChanged();
        compare(model.contacts.length, 3);

        var filterEmpty = createCollectionFilter([])
        model.filter = filterEmpty;
        waitForContactsChanged();
        compare(model.contacts.length, 0);

        var filterValidAndInvalidIds = createCollectionFilter([defaultCollectionId, "12345678", testCollection.collectionId])
        model.filter = filterValidAndInvalidIds;
        waitForContactsChanged();
        compare(model.contacts.length, 3);

        var filterWithInvalidId = createCollectionFilter(["12345678"])
        model.filter = filterWithInvalidId;
        waitForContactsChanged();
        compare(model.contacts.length, 0);
    }
}
