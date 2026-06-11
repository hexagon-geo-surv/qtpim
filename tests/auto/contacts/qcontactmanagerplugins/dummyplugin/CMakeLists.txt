# Copyright (C) 2026 The Qt Company Ltd.
# SPDX-License-Identifier: BSD-3-Clause

qt_internal_add_plugin(contacts_testdummy
    TEST_PLUGIN
    PLUGIN_TYPE contacts
    CLASS_NAME DummyEngineFactory
    SOURCES
        dummyplugin.cpp
        dummyplugin.h
)
target_compile_definitions(contacts_testdummy PRIVATE
    DUMMYPLUGINNAME=testdummy
    QT_DISABLE_DEPRECATED_BEFORE=0x050000
)
target_link_libraries(contacts_testdummy PRIVATE Qt6::Contacts)
