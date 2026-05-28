# Copyright (C) 2026 The Qt Company Ltd.
# SPDX-License-Identifier: BSD-3-Clause

add_subdirectory(memory)

if(TARGET Qt6::ServiceFramework)
    add_subdirectory(serviceactionmanager)
endif()
