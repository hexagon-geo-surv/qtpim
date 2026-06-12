# Copyright (C) 2026 The Qt Company Ltd.
# SPDX-License-Identifier: BSD-3-Clause

# Excluded on QNX: the test passes there but its total run time on the QNX
# qemu target exceeds the CI test timeout. The QML bindings exercised here are
# not platform-specific, so the coverage is fully provided by the other
# platforms.
if(NOT QNX)
    qt_internal_add_test(tst_qmlorganizer
        SOURCES
            tst_qmlorganizer.cpp
        LIBRARIES
            Qt6::Organizer
            Qt6::QuickTest
            Qt6::Versit
        QML_IMPORTPATH
            "${CMAKE_BINARY_DIR}/qml"
        DEFINES
            QUICK_TEST_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}/testcases"
        WORKING_DIRECTORY
            "${CMAKE_CURRENT_SOURCE_DIR}/testcases"
    )
endif()
