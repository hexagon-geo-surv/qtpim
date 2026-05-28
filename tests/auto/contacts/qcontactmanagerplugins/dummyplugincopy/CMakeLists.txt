# Copyright (C) 2026 The Qt Company Ltd.
# SPDX-License-Identifier: BSD-3-Clause

qt_internal_add_plugin(contacts_testdummycopy
    TEST_PLUGIN
    PLUGIN_TYPE contacts
    CLASS_NAME DummyEngineFactory
    SOURCES
        ../dummyplugin/dummyplugin.cpp
        ../dummyplugin/dummyplugin.h
)
target_compile_definitions(contacts_testdummycopy PRIVATE
    DUMMYPLUGINTARGET=contacts_testdummycopy
    DUMMYPLUGINNAME=testdummy
    QT_DISABLE_DEPRECATED_BEFORE=0
)
target_link_libraries(contacts_testdummycopy PRIVATE Qt6::Contacts)
