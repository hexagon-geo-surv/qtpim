// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtQuick 2.0
import QtTest 1.0
import QtContacts 5.0

TestCase {
    name: "ContactsOrganizationsTests"

    TestCase {
        name: "ContactsOrganizationsTests::NoOrganization"

        Contact {
            id: contactWithoutOrganization
        }

        Contact {
            id: anotherContactWithoutOrganization
        }

        Contact {
            id: yetAnotherContactWithoutOrganization
        }

        function test_organizationOfContactWithoutOrganizationIsDefined() {
            verifyIsDefined(contactWithoutOrganization.organization);
        }

        function test_organizationOfContactWithoutOrganizationIsEmpty() {
            verifyIsUndefined(contactWithoutOrganization.organization.assistantName);
            compare(contactWithoutOrganization.organization.department.length, 0);
            verifyIsUndefined(contactWithoutOrganization.organization.location);
            compare(contactWithoutOrganization.organization.logoUrl, "");
            verifyIsUndefined(contactWithoutOrganization.organization.name);
            verifyIsUndefined(contactWithoutOrganization.organization.role);
            verifyIsUndefined(contactWithoutOrganization.organization.title);
        }

        function test_organizationsCountOfAnotherContactWithoutOrganizationIsZero() {
            // we do not access the organization property of the contact,
            // so in this case the expected length is 0
            compare(anotherContactWithoutOrganization.organizations.length, 0);
        }

        function test_organizationsCountOfYetAnotherContactWithoutOrganizationIsOne() {
            // we first access the organization property of the contact,
            // so in this case the expected length is 1
            verifyIsDefined(yetAnotherContactWithoutOrganization.organization);
            compare(yetAnotherContactWithoutOrganization.organizations.length, 1);
        }
    }

    TestCase {
        name: "ContactsOrganizationsTests::OneOrganization"

        Contact {
            id: contactWithOneOrganization

            Organization {
                name: "myOrganization"
            }
        }

        function test_accessOrganizationThroughOrganization() {
            compare(contactWithOneOrganization.organization.name, "myOrganization");
        }

        function test_OrganizationCount() {
            compare(contactWithOneOrganization.organizations.length, 1);
        }

        function test_accessOrganizationThroughOrganizations() {
            compare(contactWithOneOrganization.organizations[0].name, "myOrganization");
        }

        function test_accessOrganizationThroughDetails() {
            compare(contactWithOneOrganization.details(
                        ContactDetail.Organization)[0].name, "myOrganization");
        }
    }

    TestCase {
        name: "ContactsOrganizationsTests::MultipleOrganizations"

        Contact {
            id: contactWithOrganizations

            Organization {
                name: "myOrganization1"
            }

            Organization {
                name: "myOrganization2"
            }
        }

        function test_accessOrganizationThroughOrganization() {
            compare(contactWithOrganizations.organization.name, "myOrganization1");
        }

        function test_organizationCount() {
            compare(contactWithOrganizations.organizations.length, 2);
        }

        function test_accessOrganizationThroughOrganizations() {
            compare(contactWithOrganizations.organizations[0].name, "myOrganization1");
            compare(contactWithOrganizations.organizations[1].name, "myOrganization2");
        }

        function test_accessOrganizationThroughDetails() {
            compare(contactWithOrganizations.details(
                        ContactDetail.Organization)[0].name, "myOrganization1");
        }
    }

    TestCase {
        name: "ContactsOrganizationsTests::DynamicallyAdded::MultipleOrganizations"

        Contact {
            id: contact1
        }

        Organization {
            id: organization1
            name: "myOrganization1"
        }

        Organization {
            id: organization2
            name: "myOrganization2"
        }

        function init() {
            contact1.clearDetails();
            contact1.addDetail(organization1);
            contact1.addDetail(organization2);
        }

        function test_accessOrganizationThroughOrganization() {
            compare(contact1.organization.name, "myOrganization1");
        }

        function test_organizationCount() {
            verify(contact1.organizations);
            compare(contact1.organizations.length, 2);
        }

        function test_accessOrganizationThroughOrganizations() {
            compare(contact1.organizations[0].name, "myOrganization1");
            compare(contact1.organizations[1].name, "myOrganization2");
        }

        function test_accessOrganizationThroughDetails() {
            compare(contact1.details(
                        ContactDetail.Organization)[0].name, "myOrganization1");
        }

        function cleanup () {
            contact1.clearDetails();
        }
    }

    TestCase {
        name: "ContactsOrganizationsTests::ModificationSignaling"

        Contact {
            id: contactWithOrganization
            Organization {
                name: "old"
            }
        }

        function test_changeToDetailThroughOrganizationsEmitsSignal()
        {
            listenToSignalFromObject("contactChanged", contactWithOrganization);
            contactWithOrganization.organizations[0].name = "new";
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

