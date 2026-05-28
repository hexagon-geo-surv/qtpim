# Copyright (C) 2026 The Qt Company Ltd.
# SPDX-License-Identifier: BSD-3-Clause

qt_internal_add_test(tst_qorganizere2e
    SOURCES
        tst_qorganizere2e.cpp
    LIBRARIES
        Qt6::Organizer
        Qt6::OrganizerPrivate
        Qt6::Test
    DEFINES
        QT_DISABLE_DEPRECATED_BEFORE=0
)
