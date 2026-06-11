# Copyright (C) 2026 The Qt Company Ltd.
# SPDX-License-Identifier: BSD-3-Clause

qt_internal_add_plugin(contacts_testotherdummy
    TEST_PLUGIN
    PLUGIN_TYPE contacts
    CLASS_NAME BoringFactory
    SOURCES
        dummyotherplugin.cpp
)
target_compile_definitions(contacts_testotherdummy PRIVATE QT_DISABLE_DEPRECATED_BEFORE=0x050000)
target_link_libraries(contacts_testotherdummy PRIVATE Qt6::Contacts)
