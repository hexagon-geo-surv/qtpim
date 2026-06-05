// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtQuick 2.0
import QtTest 1.0
import QtContacts 5.0

TestCase {
    name: "ContactsEmailsTests"

    TestCase {
        name: "ContactsEmailsTests::NoEmail"

        Contact {
            id: contactWithoutEmail
        }

        Contact {
            id: anotherContactWithoutEmail
        }

        Contact {
            id: yetAnotherContactWithoutEmail
        }

        function test_emailOfContactWithoutEmailIsDefined() {
            verifyIsDefined(contactWithoutEmail.email);
        }

        function test_emailOfContactWithoutEmailIsEmpty() {
            verifyIsUndefined(contactWithoutEmail.email.emailAddress);
        }

        function test_emailsCountOfAnotherContactWithoutEmailIsZero() {
            // we do not access the email property of the contact,
            // so in this case the expected length is 0
            compare(anotherContactWithoutEmail.emails.length, 0);
        }

        function test_emailsCountOfYetAnotherContactWithoutEmailIsOne() {
            // we first access the email property of the contact,
            // so in this case the expected length is 1
            verifyIsDefined(yetAnotherContactWithoutEmail.email);
            compare(yetAnotherContactWithoutEmail.emails.length, 1);
        }
    }

    TestCase {
        name: "ContactsEmailsTests::OneEmail"

        Contact {
            id: contactWithOneEmail

            EmailAddress {
                emailAddress: "a@ovi.com"
            }
        }

        function test_accessEmailThroughEmail() {
            compare(contactWithOneEmail.email.emailAddress, "a@ovi.com");
        }

        function test_emailCount() {
            compare(contactWithOneEmail.emails.length, 1);
        }

        function test_accessEmailThroughEmails() {
            compare(contactWithOneEmail.emails[0].emailAddress, "a@ovi.com");
        }

        function test_accessEmailThroughDetails() {
            compare(contactWithOneEmail.details(
                        ContactDetail.Email)[0].emailAddress, "a@ovi.com");
        }
    }

    TestCase {
        name: "ContactsEmailsTests::MultipleEmails"

        Contact {
            id: contactWithEmails

            EmailAddress {
                emailAddress: "a@ovi.com"
            }

            EmailAddress {
                emailAddress: "b@ovi.com"
            }
        }

        function test_accessEmailThroughEmail() {
            compare(contactWithEmails.email.emailAddress, "a@ovi.com");
        }

        function test_emailCount() {
            compare(contactWithEmails.emails.length, 2);
        }

        function test_accessEmailThroughEmails() {
            compare(contactWithEmails.emails[0].emailAddress, "a@ovi.com");
            compare(contactWithEmails.emails[1].emailAddress, "b@ovi.com");
        }

        function test_accessEmailThroughDetails() {
            compare(contactWithEmails.details(
                        ContactDetail.Email)[0].emailAddress, "a@ovi.com");
            compare(contactWithEmails.details(
                        ContactDetail.Email)[1].emailAddress, "b@ovi.com");
        }
    }

    TestCase {
        name: "ContactsEmailsTests::DynamicallyAdded::MultipleEmails"

        Contact {
            id: contact1
        }

        EmailAddress {
            id: emailAddress1
            emailAddress: "a@ovi.com"
        }

        EmailAddress {
            id: emailAddress2
            emailAddress: "b@ovi.com"
        }

        function init() {
            contact1.clearDetails();
            contact1.addDetail(emailAddress1);
            contact1.addDetail(emailAddress2);
        }

        function test_accessEmailThroughEmail() {
            compare(contact1.email.emailAddress, "a@ovi.com");
        }

        function test_emailCount() {
            verify(contact1.emails);
            compare(contact1.emails.length, 2);
        }

        function test_accessEmailThroughEmails() {
            compare(contact1.emails[0].emailAddress, "a@ovi.com");
            compare(contact1.emails[1].emailAddress, "b@ovi.com");
        }

        function test_accessEmailThroughDetails() {
            compare(contact1.details(
                        ContactDetail.Email)[0].emailAddress, "a@ovi.com");
            compare(contact1.details(
                        ContactDetail.Email)[1].emailAddress, "b@ovi.com");
        }

        function cleanup () {
            contact1.clearDetails();
        }
    }

    TestCase {
        name: "ContactsEmailsTests::ModificationSignaling"

        Contact {
            id: contactWithEmailAddress
            EmailAddress {
                emailAddress: "a@a"
            }
        }

        function test_changeToDetailThroughEmailsEmitsSignal()
        {
            listenToSignalFromObject("contactChanged", contactWithEmailAddress);
            contactWithEmailAddress.emails[0].emailAddress = "b@b";
            verifySignalReceived();
        }


        function init() {
            spy = Qt.createQmlObject("import QtTest 1.0;" +
                                     "SignalSpy {}",
                                     this);
        }
    }

    property SignalSpy spy

    function listenToSignalFromObject(signalName, object) {
        spy.target = object;
        spy.signalName = signalName;
        spy.clear();
    }

    function verifySignalReceived() {
        spy.wait();
    }

    function verifyNoSignalReceived() {
        verify(spy.count == 0, "no signal was received");
    }

    function verifyIsUndefined(object) {
        verify(!object, "Object " + object + " is undefined");
    }

    function verifyIsDefined(object) {
        verify(object, "Object " + object + " is defined");
    }
}

