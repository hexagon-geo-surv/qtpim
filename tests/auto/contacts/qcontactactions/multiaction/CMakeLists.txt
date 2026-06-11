# Copyright (C) 2026 The Qt Company Ltd.
# SPDX-License-Identifier: BSD-3-Clause

qt_internal_add_plugin(contacts_multiaction
    TEST_PLUGIN
    PLUGIN_TYPE contacts
    CLASS_NAME MultiAction
    SOURCES
        multiaction.cpp
        multiaction_p.h
)
target_compile_definitions(contacts_multiaction PRIVATE
    ACTIONPLUGINTARGET=contacts_multiaction
    ACTIONPLUGINNAME=MultiAction
    QT_DISABLE_DEPRECATED_BEFORE=0x050000
)
target_link_libraries(contacts_multiaction PRIVATE
    Qt6::Contacts
    Qt6::Core
    Qt6::ServiceFramework
)
