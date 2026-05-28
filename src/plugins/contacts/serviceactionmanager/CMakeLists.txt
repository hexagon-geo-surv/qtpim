# Copyright (C) 2026 The Qt Company Ltd.
# SPDX-License-Identifier: BSD-3-Clause

qt_internal_add_plugin(qtcontacts_serviceactionmanager
    PLUGIN_TYPE contacts
    CLASS_NAME QContactActionServiceManager
    SOURCES
        qcontactactionservicemanager_p.cpp
        qcontactactionservicemanager_p.h
)
target_link_libraries(qtcontacts_serviceactionmanager PRIVATE
    Qt6::Contacts
    Qt6::Core
    Qt6::ServiceFramework
)
