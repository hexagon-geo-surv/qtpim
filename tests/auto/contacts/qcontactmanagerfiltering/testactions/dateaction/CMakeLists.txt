# Copyright (C) 2026 The Qt Company Ltd.
# SPDX-License-Identifier: BSD-3-Clause

qt_internal_add_plugin(contacts_dateaction
    TEST_PLUGIN
    PLUGIN_TYPE contacts
    CLASS_NAME DateAction
    SOURCES
        dateaction_p.h
)
target_compile_definitions(contacts_dateaction PRIVATE
    ACTIONPLUGINTARGET=contacts_dateaction
    ACTIONPLUGINNAME=DateAction
    QT_DISABLE_DEPRECATED_BEFORE=0x050000
)
target_link_libraries(contacts_dateaction PRIVATE
    Qt6::Contacts
    Qt6::Core
    Qt6::ServiceFramework
)
