# Copyright (C) 2026 The Qt Company Ltd.
# SPDX-License-Identifier: BSD-3-Clause

qt_internal_add_plugin(qtorganizer_memory
    PLUGIN_TYPE organizer
    CLASS_NAME QOrganizerItemMemoryFactory
    SOURCES
        qorganizeritemmemorybackend.cpp
        qorganizeritemmemorybackend_p.h
)
target_link_libraries(qtorganizer_memory PRIVATE Qt6::Core Qt6::OrganizerPrivate)
