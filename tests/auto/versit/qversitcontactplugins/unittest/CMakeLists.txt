# Copyright (C) 2026 The Qt Company Ltd.
# SPDX-License-Identifier: BSD-3-Clause

qt_internal_add_test(tst_qversitcontactplugins
    SOURCES
        tst_qversitcontactplugins.cpp
    LIBRARIES
        Qt6::Contacts
        Qt6::Test
        Qt6::Versit
    DEFINES
        QT_DISABLE_DEPRECATED_BEFORE=0x050000
)

add_dependencies(tst_qversitcontactplugins
    versit_plugin1 versit_plugin2 versit_plugin3 versit_plugin4 versit_plugin5
)
