# Copyright (C) 2026 The Qt Company Ltd.
# SPDX-License-Identifier: BSD-3-Clause

qt_internal_add_plugin(versit_plugin5
    TEST_PLUGIN
    PLUGIN_TYPE versit
    CLASS_NAME Plugin5
    SOURCES
        plugin5.cpp
        plugin5.h
)
target_link_libraries(versit_plugin5 PRIVATE Qt6::Contacts Qt6::Versit)
set_target_properties(versit_plugin5 PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/../unittest/plugins/versit"
)
