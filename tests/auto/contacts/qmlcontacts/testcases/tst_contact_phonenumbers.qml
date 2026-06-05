// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtQuick 2.0
import QtTest 1.0
import QtContacts 5.0

TestCase {
    name: "ContactsPhoneNumbersTests"

    TestCase {
        name: "ContactsPhoneNumbersTests::NoPhoneNumber"

        Contact {
            id: contactWithoutPhoneNumber
        }

        Contact {
            id: anotherContactWithoutPhoneNumber
        }

        Contact {
            id: yetAnotherContactWithoutPhoneNumber
        }

        function test_phoneNumberOfContactWithoutPhoneNumberIsDefined() {
            verifyIsDefined(contactWithoutPhoneNumber.phoneNumber);
        }

        function test_phoneNumberOfContactWithoutPhoneNumberIsEmpty() {
            verifyIsUndefined(contactWithoutPhoneNumber.phoneNumber.number);
            compare(contactWithoutPhoneNumber.phoneNumber.subTypes.length, 0);
        }

        function test_phoneNumbersCountOfAnotherContactWithoutPhoneNumberIsZero() {
            // we do not access the phoneNumber property of the contact,
            // so in this case the expected length is 0
            compare(anotherContactWithoutPhoneNumber.phoneNumbers.length, 0);
        }

        function test_phoneNumbersCountOfYetAnotherContactWithoutPhoneNumberIsOne() {
            // we first access the phoneNumber property of the contact,
            // so in this case the expected length is 1
            verifyIsDefined(yetAnotherContactWithoutPhoneNumber.phoneNumber);
            compare(yetAnotherContactWithoutPhoneNumber.phoneNumbers.length, 1);
        }
    }

    TestCase {
        name: "ContactsPhoneNumbersTests::OnePhoneNumber"

        Contact {
            id: contactWithOnePhoneNumber

            PhoneNumber {
                number: "1111111111"
                subTypes:[PhoneNumber.Mobile]
            }
        }

        function test_accessPhoneNumberThroughPhoneNumber() {
            compare(contactWithOnePhoneNumber.phoneNumber.number, "1111111111");
        }

        function test_phoneNumberCount() {
            compare(contactWithOnePhoneNumber.phoneNumbers.length, 1);
        }

        function test_accessPhoneNumberThroughPhoneNumbers() {
            compare(contactWithOnePhoneNumber.phoneNumbers[0].number, "1111111111");
        }

        function test_accessPhoneNumberThroughDetails() {
            compare(contactWithOnePhoneNumber.details(
                        ContactDetail.PhoneNumber)[0].number, "1111111111");
        }
    }

    TestCase {
        name: "ContactsPhoneNumbersTests::MultiplePhoneNumbers"

        Contact {
            id: contactWithPhoneNumbers

            PhoneNumber {
                number: "1111111111"
                subTypes:[PhoneNumber.Mobile]
            }

            PhoneNumber {
                number: "2222222222"
                subTypes:[PhoneNumber.Fax]
            }
        }

        function test_accessPhoneNumberThroughPhoneNumber() {
            compare(contactWithPhoneNumbers.phoneNumber.number, "1111111111");
        }

        function test_phoneNumberCount() {
            compare(contactWithPhoneNumbers.phoneNumbers.length, 2);
        }

        function test_accessPhoneNumberThroughPhoneNumbers() {
            compare(contactWithPhoneNumbers.phoneNumbers[0].number, "1111111111");
            compare(contactWithPhoneNumbers.phoneNumbers[1].number, "2222222222");
        }

        function test_accessPhoneNumberThroughDetails() {
            compare(contactWithPhoneNumbers.details(
                        ContactDetail.PhoneNumber)[0].number, "1111111111");
        }
    }

    TestCase {
        name: "ContactsPhoneNumbersTests::DynamicallyAdded::MultiplePhoneNumbers"
        Contact {
            id: contact1
        }

        PhoneNumber {
            id: phoneNumber1
            number: "1111111111"
            subTypes:[PhoneNumber.Mobile]
        }

        PhoneNumber {
            id: phoneNumber2
            number: "2222222222"
            subTypes:[PhoneNumber.Fax]
        }

        function init() {
            contact1.clearDetails();
            contact1.addDetail(phoneNumber1);
            contact1.addDetail(phoneNumber2);
        }

        function test_accessPhoneNumberThroughPhoneNumber() {
            compare(contact1.phoneNumber.number, "1111111111");
        }

        function test_phoneNumberCount() {
            verify(contact1.phoneNumbers);
            compare(contact1.phoneNumbers.length, 2);
        }

        function test_accessPhoneNumberThroughPhoneNumbers() {
            compare(contact1.phoneNumbers[0].number, "1111111111");
            compare(contact1.phoneNumbers[1].number, "2222222222");
        }

        function test_accessPhoneNumberThroughDetails() {
            compare(contact1.details(
                        ContactDetail.PhoneNumber)[0].number, "1111111111");
        }

        function cleanup () {
            contact1.clearDetails();
        }
    }

    TestCase {
        name: "ContactsPhoneNumbersTests::ModificationSignaling"

        Contact {
            id: contactWithPhoneNumber
            PhoneNumber {
                number: "1234"
            }
        }

        function test_changeToDetailThroughPhoneNumbersEmitsSignal()
        {
            listenToSignalFromObject("contactChanged", contactWithPhoneNumber);
            contactWithPhoneNumber.phoneNumbers[0].number = "5678";
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

