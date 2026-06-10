# Copyright (C) 2026 The Qt Company Ltd.
# SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#! [cmake_use]
find_package(Qt6 REQUIRED COMPONENTS Organizer)
target_link_libraries(mytarget PRIVATE Qt6::Organizer)
#! [cmake_use]
