# Copyright (C) 2026 The Qt Company Ltd.
# SPDX-License-Identifier: BSD-3-Clause

qt_internal_add_test(tst_qmlorganizer
    SOURCES
        tst_qmlorganizer.cpp
    LIBRARIES
        Qt6::Organizer
        Qt6::QuickTest
        Qt6::Versit
    QML_IMPORTPATH
        "${CMAKE_BINARY_DIR}/qml"
    WORKING_DIRECTORY
        "${CMAKE_CURRENT_SOURCE_DIR}/testcases"
)
