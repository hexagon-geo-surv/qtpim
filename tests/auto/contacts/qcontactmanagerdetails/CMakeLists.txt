# Copyright (C) 2026 The Qt Company Ltd.
# SPDX-License-Identifier: BSD-3-Clause

qt_internal_add_test(tst_qcontactmanagerdetails
    SOURCES
        tst_qcontactmanagerdetails.cpp
        ../qcontactmanagerdataholder.h
    LIBRARIES
        Qt6::Contacts
        Qt6::ContactsPrivate
        Qt6::Test
    DEFINES
        QT_DISABLE_DEPRECATED_BEFORE=0x050000
    INCLUDE_DIRECTORIES
        ${CMAKE_CURRENT_SOURCE_DIR}/..
        ${CMAKE_CURRENT_SOURCE_DIR}/../..
)
