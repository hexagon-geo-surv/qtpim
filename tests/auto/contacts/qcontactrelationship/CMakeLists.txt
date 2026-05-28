# Copyright (C) 2026 The Qt Company Ltd.
# SPDX-License-Identifier: BSD-3-Clause

qt_internal_add_test(tst_qcontactrelationship
    SOURCES
        tst_qcontactrelationship.cpp
    LIBRARIES
        Qt6::Contacts
        Qt6::Test
    DEFINES
        QT_DISABLE_DEPRECATED_BEFORE=0
)
