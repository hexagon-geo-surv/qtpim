# Copyright (C) 2026 The Qt Company Ltd.
# SPDX-License-Identifier: BSD-3-Clause

qt_internal_add_test(tst_qorganizeritemdetails
    SOURCES
        tst_qorganizeritemdetails.cpp
    LIBRARIES
        Qt6::Organizer
        Qt6::Test
    DEFINES
        QT_DISABLE_DEPRECATED_BEFORE=0
)
