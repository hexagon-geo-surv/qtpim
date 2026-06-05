// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtQuick 2.0
import QtTest 1.0
import QtContacts 5.0

ContactsSignalingTestCase {
    name: "ContactModelSignalsTests"
    id: contactModelSignalsTests

    // This test case is a unit test for contact model
    // so it does not require updates to contacts.
    ContactModel {
        id: model
        autoUpdate: false
    }

    IdFilter {
        id: filter
        ids: []
    }

    function test_settingTheFilterSendsSignal() {
        listenToSignalFromObject("filterChanged", model)
        model.filter = filter;
        verifySignalReceived();
    }

    IdFilter {
        id: oldFilter
        ids: []
    }

    IdFilter {
        id: newFilter
        ids: []
    }

    function test_changingTheFilterSendsSignal() {
        model.filter = oldFilter;

        listenToSignalFromObject("filterChanged", model)
        model.filter = newFilter;
        verifySignalReceived();
    }

    IdFilter {
        id: nonNullFilter
        ids: []
    }

    function test_removingTheFilterSendsSignal() {
        model.filter = nonNullFilter;

        listenToSignalFromObject("filterChanged", model)
        model.filter = null;
        verifySignalReceived();
    }

    IdFilter {
        id: theSameFilter
        ids: []
    }

    function test_settingTheSameFilterDoesNotSendSignal() {
        model.filter = theSameFilter;

        listenToSignalFromObject("filterChanged", model)
        model.filter = theSameFilter;
        verifyNoSignalReceived();
    }

    function init() {
        initSignalingTest();
    }
}
