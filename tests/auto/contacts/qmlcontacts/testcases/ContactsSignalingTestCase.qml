// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtQuick 2.0
import QtTest 1.0
import QtContacts 5.0

TestCase {
    name: "ContactsSignalingTestCase"
    id: contactsSignalingTestCase

    property SignalSpy spy
    property bool debug: false

    function initSignalingTest() {
        logDebug("initSignalingTest");
        spy = Qt.createQmlObject("import QtTest 1.0;" +
                                 "SignalSpy {}",
                                 contactsSignalingTestCase);
    }

    function listenToSignalFromObject(signalName, object) {
        logDebug("listenToSignalFromObject");
        spy.target = object;
        spy.signalName = signalName;
        spy.clear();
    }

    function verifySignalReceived() {
        logDebug("verifySignalReceived");
        spy.wait();
    }

    function verifyNoSignalReceived() {
        logDebug("verifyNoSignalReceived");
        wait(500);
        compare(spy.count, 0, "no signal received");
    }

    function logDebug(message) {
        if (debug)
            console.log(message);
    }
}
