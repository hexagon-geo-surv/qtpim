// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

import QtQuick 2.0

Rectangle {
    width: parent.width
    color: "pink"
    property variant contact // contact that is shown in editView

    // ![Widgets for manipulating contact details]
    Column {
        spacing: 8
        anchors {
            fill: parent
            leftMargin: 10
            topMargin: 10
        }
        DetailEditWidget {
            id: nameField
            label: "Name "
            value: contact ? contact.name.firstName : " "
        }
        DetailEditWidget {
            id: emailField
            label: "Email Address "
            value: contact ? contact.email.emailAddress : " "
            showPreferredField: true
            isPreferred: contact ? contact.isPreferredDetail("MESSAGE", contact.email) : false
        }
        DetailEditWidget {
            id: phoneField
            label: "Phone Number "
            value: contact ? contact.phoneNumber.number : " "
            showPreferredField: true
            isPreferred: contact ? contact.isPreferredDetail("CALL", contact.phoneNumber) : false
        }
    }
    // ![Widgets for manipulating contact details]

    function deleteContact() {
        contactsModel.removeContact(contactEditor.contact.contactId)
        statusBar.updateMsg("contact successfully deleted")
     }

    function updateContact() {
        // read in values from the input fields
        var values = [nameField.value,
                      emailField.value, emailField.requestPreferred || emailField.isPreferred,
                      phoneField.value, phoneField.requestPreferred || phoneField.isPreferred]
        if (!contact) { // create new contact
            var newContact = Qt.createQmlObject("import QtContacts 5.0; Contact{ }", contactEditor)
            setDetailValues(newContact, values)
            newContact.save()
            contactsModel.saveContact(newContact)
            statusBar.updateMsg("new contact successfully created")
        } else { // update existing contact
            setDetailValues(contact, values)
            if (contact.modified) {
                contact.save()
                statusBar.updateMsg("contact successfully updated")
            } else {
                statusBar.updateMsg("nothing to update, contact already is up-to-date")
            }
        }
    }

    function setDetailValues(c, values) {
        c.name.firstName = values[0]
        c.email.emailAddress = values[1]
        c.phoneNumber.number = values[3]
        if (values[2]) {
            c.setPreferredDetail("MESSAGE", c.email)
        }

        if (values[4]) {
            c.setPreferredDetail("CALL", c.phoneNumber)
        }
    }

    function cancel() {
        contact = ""
    }

    function resetToDefaults() {
        nameField.inputFocus = false
        emailField.inputFocus = false
        phoneField.inputFocus = false
        emailField.requestPreferred = false
        phoneField.requestPreferred = false
        nameField.color = "black"
        emailField.color = "black"
        phoneField.color = "black"
    }
}

