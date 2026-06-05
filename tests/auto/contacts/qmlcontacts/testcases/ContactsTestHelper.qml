// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtQuick 2.0
import QtTest 1.0
import QtContacts 5.0

Item {
    id:myModel;
    property ContactModel model;

    property Contact myContact : Contact {
        id:myContact;
        Name {
            firstName: "";
        }
        PhoneNumber {
            number: ""
        }
    }

    property Contact mycontact2 : Contact {
        id:mycontact2
        Name {
            firstName: "";
        }
        PhoneNumber {
            number: ""
            contexts:["Home"]
            subTypes:[PhoneNumber.Mobile]
        }
        Organization {
            name: ""
            assistantName:""
        }
    }

    function addContacts(contactsData)
    {
        console.log("contactsTestHelper.addContacts: " + contactsData.length + " contacts");
        for (var index=0; index < contactsData.length; index++){
            var contactData = contactsData[index]
            myModel.myContact.name.firstName = contactData.firstName;
            myModel.myContact.name.lastName = contactData.lastName;
            myModel.myContact.phoneNumber.number = contactData.phoneNumber;
            model.saveContact (myModel.myContact)
            contactsChangedSpy.wait();
        }
    }

    function addContactDetail(contactDetails)
    {
        myModel.mycontact2.name.firstName = contactDetails[0].firstName;
        myModel.mycontact2.name.lastName = contactDetails[0].lastName;
        myModel.mycontact2.organization.name = contactDetails[0].name;
        myModel.mycontact2.organization.assistantName = contactDetails[0].assistantName;
        myModel.mycontact2.organization.startDate = contactDetails[0].startDate;
        myModel.mycontact2.organization.logoUrl = contactDetails[0].logoUrl;
        myModel.mycontact2.phoneNumber.number = contactDetails[0].phoneNumber;
        myModel.mycontact2.phoneNumber.subTypes = [contactDetails[0].phoneSubType];

        myModel.mycontact2.phoneNumber.contexts = [contactDetails[0].contexts];
        model.saveContact(myModel.mycontact2)
        contactsChangedSpy.wait();
    }

    function testContacts()
    {
        return model.contacts
    }

    function emptyContactsDb () {
        console.log("contactsTestHelper.emptyContactsDb");
        var id;
        var temp = model.contacts.length;
        for (var i = 0; i < temp; i++) {
            id = model.contacts[0].contactId;
            model.removeContact(id);
            console.log("contactsTestHelper.emptyContactsDb: remove " + id);
            contactsChangedSpy.wait();
        }
        if (model.contacts.length > 0) {
            console.log("contactsTestHelper.emptyContactsDb: Failed to empty Db");
        }
    }
}

