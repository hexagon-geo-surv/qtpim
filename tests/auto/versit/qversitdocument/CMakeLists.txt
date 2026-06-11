# Copyright (C) 2026 The Qt Company Ltd.
# SPDX-License-Identifier: BSD-3-Clause

qt_internal_add_test(tst_qversitdocument
    SOURCES
        tst_qversitdocument.cpp
        tst_qversitdocument.h
    LIBRARIES
        Qt6::Test
        Qt6::Versit
    DEFINES
        QT_DISABLE_DEPRECATED_BEFORE=0x050000
)
