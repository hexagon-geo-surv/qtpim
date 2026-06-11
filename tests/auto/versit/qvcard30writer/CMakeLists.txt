# Copyright (C) 2026 The Qt Company Ltd.
# SPDX-License-Identifier: BSD-3-Clause

qt_internal_add_test(tst_qvcard30writer
    SOURCES
        tst_qvcard30writer.cpp
        tst_qvcard30writer.h
    LIBRARIES
        Qt6::Test
        Qt6::Versit
        Qt6::VersitPrivate
    DEFINES
        QT_ASCII_CAST_WARNINGS
        QT_DISABLE_DEPRECATED_BEFORE=0x050000
)
