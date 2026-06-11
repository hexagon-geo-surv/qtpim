# Copyright (C) 2026 The Qt Company Ltd.
# SPDX-License-Identifier: BSD-3-Clause

qt_internal_add_test(tst_qversit
    SOURCES
        tst_qversit.cpp
        tst_qversit.h
    LIBRARIES
        Qt6::Contacts
        Qt6::Organizer
        Qt6::Test
        Qt6::Versit
        Qt6::VersitOrganizer
        Qt6::VersitPrivate
    DEFINES
        "TESTDATA_DIR=\"${CMAKE_CURRENT_SOURCE_DIR}/\""
        QT_DISABLE_DEPRECATED_BEFORE=0x050000
)
