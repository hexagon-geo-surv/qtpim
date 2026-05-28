# Copyright (C) 2026 The Qt Company Ltd.
# SPDX-License-Identifier: BSD-3-Clause

qt_internal_add_plugin(qtorganizer_skeleton
    PLUGIN_TYPE organizer
    CLASS_NAME QOrganizerItemSkeletonFactory
    SOURCES
        qorganizerskeleton.cpp
        qorganizerskeleton_p.h
)
target_link_libraries(qtorganizer_skeleton PRIVATE Qt6::Core Qt6::Organizer)
