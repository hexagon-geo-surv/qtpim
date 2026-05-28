# Copyright (C) 2026 The Qt Company Ltd.
# SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

cmake_minimum_required(VERSION 3.16)
project(todo LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Organizer Widgets)

qt_standard_project_setup()

qt_add_executable(todo_pim
    main.cpp
    todoeditor.cpp
    todoeditor.h
    window.cpp
    window.h
)
set_target_properties(todo_pim PROPERTIES AUTOMOC ON)
target_link_libraries(todo_pim PRIVATE Qt6::Organizer Qt6::Widgets)

install(TARGETS todo_pim
    RUNTIME DESTINATION "${CMAKE_INSTALL_PREFIX}/examples/organizer/todo"
)
