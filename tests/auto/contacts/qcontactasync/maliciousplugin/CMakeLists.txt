# Copyright (C) 2026 The Qt Company Ltd.
# SPDX-License-Identifier: BSD-3-Clause

qt_internal_add_plugin(contacts_maliciousplugin
    TEST_PLUGIN
    PLUGIN_TYPE contacts
    CLASS_NAME MaliciousEngineFactory
    SOURCES
        maliciousplugin.cpp
        maliciousplugin_p.h
)
target_compile_definitions(contacts_maliciousplugin PRIVATE
    MALICIOUSPLUGINTARGET=contacts_maliciousplugin
    MALICIOUSPLUGINNAME=maliciousplugin
    QT_DISABLE_DEPRECATED_BEFORE=0
)
target_link_libraries(contacts_maliciousplugin PRIVATE Qt6::Contacts Qt6::Test)
