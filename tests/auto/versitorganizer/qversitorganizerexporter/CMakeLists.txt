# Copyright (C) 2026 The Qt Company Ltd.
# SPDX-License-Identifier: BSD-3-Clause

qt_internal_add_test(tst_qversitorganizerexporter
    SOURCES
        tst_qversitorganizerexporter.cpp
        tst_qversitorganizerexporter.h
    LIBRARIES
        Qt6::Organizer
        Qt6::Test
        Qt6::Versit
        Qt6::VersitOrganizer
    DEFINES
        QT_DISABLE_DEPRECATED_BEFORE=0
)
