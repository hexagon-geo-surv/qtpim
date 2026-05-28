# Copyright (C) 2026 The Qt Company Ltd.
# SPDX-License-Identifier: BSD-3-Clause

qt_internal_add_test(tst_qorganizeritemasync
    SOURCES
        tst_qorganizeritemasync.cpp
        ../../qorganizermanagerdataholder.h
    LIBRARIES
        Qt6::Organizer
        Qt6::Test
    DEFINES
        QT_DISABLE_DEPRECATED_BEFORE=0
    INCLUDE_DIRECTORIES
        ${CMAKE_CURRENT_SOURCE_DIR}/../..
)
