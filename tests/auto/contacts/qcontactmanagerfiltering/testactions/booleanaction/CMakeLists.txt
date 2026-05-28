# Copyright (C) 2026 The Qt Company Ltd.
# SPDX-License-Identifier: BSD-3-Clause

qt_internal_add_plugin(contacts_booleanaction
    TEST_PLUGIN
    PLUGIN_TYPE contacts
    CLASS_NAME BooleanAction
    SOURCES
        booleanaction_p.h
)
target_compile_definitions(contacts_booleanaction PRIVATE
    ACTIONPLUGINTARGET=contacts_booleanaction
    ACTIONPLUGINNAME=BooleanAction
    QT_DISABLE_DEPRECATED_BEFORE=0
)
target_link_libraries(contacts_booleanaction PRIVATE
    Qt6::Contacts
    Qt6::Core
    Qt6::ServiceFramework
)
