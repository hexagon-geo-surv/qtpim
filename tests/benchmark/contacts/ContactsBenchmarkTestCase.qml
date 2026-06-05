// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtQuick 2.0
import QtTest 1.0
import QtContacts 5.0

TestCase {
    name: "ContactsBenchmarkTestCase"
    id: contactsBenchmarkTestCase

    function createContacts(count) {
        contactsList = new Array(count);
        for (var it=0;it<count;it++) {
            var contact = Qt.createQmlObject(
                        "import QtContacts 5.0;" +
                        "Contact {}", contactsBenchmarkTestCase)
            var temp = contactsList
            temp[it] = contact;
            contactsList = temp
        }
    }
}
