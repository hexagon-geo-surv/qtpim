# Copyright (C) 2026 The Qt Company Ltd.
# SPDX-License-Identifier: BSD-3-Clause

qt_internal_add_plugin(versit_plugin1
    TEST_PLUGIN
    PLUGIN_TYPE versit
    CLASS_NAME Plugin1
    SOURCES
        plugin1.cpp
        plugin1.h
)
target_link_libraries(versit_plugin1 PRIVATE Qt6::Contacts Qt6::Versit)
set_target_properties(versit_plugin1 PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/../unittest/plugins/versit"
)
