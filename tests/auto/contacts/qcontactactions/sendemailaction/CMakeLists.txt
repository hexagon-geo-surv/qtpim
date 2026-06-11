# Copyright (C) 2026 The Qt Company Ltd.
# SPDX-License-Identifier: BSD-3-Clause

qt_internal_add_plugin(contacts_sendemailaction
    TEST_PLUGIN
    PLUGIN_TYPE contacts
    CLASS_NAME SendEmailAction
    SOURCES
        sendemailaction.cpp
        sendemailaction_p.h
)
target_compile_definitions(contacts_sendemailaction PRIVATE
    ACTIONPLUGINTARGET=contacts_sendemailaction
    ACTIONPLUGINNAME=SendEmailAction
    QT_DISABLE_DEPRECATED_BEFORE=0x050000
)
target_link_libraries(contacts_sendemailaction PRIVATE
    Qt6::Contacts
    Qt6::Core
    Qt6::ServiceFramework
)
