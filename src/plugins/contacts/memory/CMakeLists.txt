# Copyright (C) 2026 The Qt Company Ltd.
# SPDX-License-Identifier: BSD-3-Clause

qt_internal_add_plugin(qtcontacts_memory
    PLUGIN_TYPE contacts
    CLASS_NAME QContactMemoryEngineFactory
    SOURCES
        qcontactmemorybackend.cpp
        qcontactmemorybackend_p.h
)
target_link_libraries(qtcontacts_memory PRIVATE Qt6::Contacts Qt6::Core)
