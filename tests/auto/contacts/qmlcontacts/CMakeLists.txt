# Copyright (C) 2026 The Qt Company Ltd.
# SPDX-License-Identifier: BSD-3-Clause

qt_internal_add_test(tst_qmlcontacts
    SOURCES
        tst_qmlcontacts.cpp
    LIBRARIES
        Qt6::Contacts
        Qt6::QuickTest
    QML_IMPORTPATH
        "${CMAKE_BINARY_DIR}/qml"
    WORKING_DIRECTORY
        "${CMAKE_CURRENT_SOURCE_DIR}/testcases"
)
