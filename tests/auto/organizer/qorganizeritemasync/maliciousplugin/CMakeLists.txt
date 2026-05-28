# Copyright (C) 2026 The Qt Company Ltd.
# SPDX-License-Identifier: BSD-3-Clause

qt_internal_add_plugin(organizer_maliciousplugin
    TEST_PLUGIN
    PLUGIN_TYPE organizer
    CLASS_NAME MaliciousEngineFactory
    SOURCES
        maliciousplugin.cpp
        maliciousplugin_p.h
)
target_compile_definitions(organizer_maliciousplugin PRIVATE
    MALICIOUSPLUGINTARGET=organizer_maliciousplugin
    MALICIOUSPLUGINNAME=maliciousplugin
)
target_link_libraries(organizer_maliciousplugin PRIVATE Qt6::Core Qt6::Organizer)
