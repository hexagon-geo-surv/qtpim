# Copyright (C) 2026 The Qt Company Ltd.
# SPDX-License-Identifier: BSD-3-Clause

qt_internal_add_test(tst_qorganizermanager
    SOURCES
        tst_qorganizermanager.cpp
        ../qorganizermanagerdataholder.h
    LIBRARIES
        Qt6::Gui
        Qt6::Organizer
        Qt6::OrganizerPrivate
        Qt6::Test
    DEFINES
        QT_DISABLE_DEPRECATED_BEFORE=0x050000
    INCLUDE_DIRECTORIES
        ${CMAKE_CURRENT_SOURCE_DIR}/..
)
