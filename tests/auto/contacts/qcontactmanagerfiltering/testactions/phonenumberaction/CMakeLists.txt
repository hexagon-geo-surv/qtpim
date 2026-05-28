# Copyright (C) 2026 The Qt Company Ltd.
# SPDX-License-Identifier: BSD-3-Clause

qt_internal_add_plugin(contacts_phonenumberaction
    TEST_PLUGIN
    PLUGIN_TYPE contacts
    CLASS_NAME PhoneNumberAction
    SOURCES
        phonenumberaction_p.h
)
target_compile_definitions(contacts_phonenumberaction PRIVATE
    ACTIONPLUGINTARGET=contacts_phonenumberaction
    ACTIONPLUGINNAME=PhoneNumberAction
    QT_DISABLE_DEPRECATED_BEFORE=0
)
target_link_libraries(contacts_phonenumberaction PRIVATE
    Qt6::Contacts
    Qt6::Core
    Qt6::ServiceFramework
)
