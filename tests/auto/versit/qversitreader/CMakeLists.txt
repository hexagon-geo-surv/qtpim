# Copyright (C) 2026 The Qt Company Ltd.
# SPDX-License-Identifier: BSD-3-Clause

qt_internal_add_test(tst_qversitreader
    SOURCES
        tst_qversitreader.cpp
        tst_qversitreader.h
    LIBRARIES
        Qt6::Test
        Qt6::Versit
        Qt6::VersitPrivate
    DEFINES
        QT_DISABLE_DEPRECATED_BEFORE=0
)
