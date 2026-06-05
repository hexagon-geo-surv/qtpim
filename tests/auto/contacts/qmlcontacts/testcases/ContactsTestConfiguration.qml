// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtQuick 2.0

Item {
    function getManagerUnderTest() {
        // Adjust this to run the tests against different manager backends
        // Supported values:
        //   "memory"
        //   "" (selects the default backend)
        return "memory";
    }
}
