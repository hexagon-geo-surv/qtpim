# Copyright (C) 2026 The Qt Company Ltd.
# SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

cmake_minimum_required(VERSION 3.16)
project(calendardemo LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Organizer Versit Widgets)

qt_standard_project_setup()

qt_add_executable(calendardemo_pim
    src/main.cpp
    src/addcalendarpage.cpp
    src/addcalendarpage.h
    src/calendardemo.cpp
    src/calendardemo.h
    src/daypage.cpp
    src/daypage.h
    src/editcalendarspage.cpp
    src/editcalendarspage.h
    src/eventeditpage.cpp
    src/eventeditpage.h
    src/eventoccurrenceeditpage.cpp
    src/eventoccurrenceeditpage.h
    src/journaleditpage.cpp
    src/journaleditpage.h
    src/monthpage.cpp
    src/monthpage.h
    src/todoeditpage.cpp
    src/todoeditpage.h
)

set_target_properties(calendardemo_pim PROPERTIES AUTOMOC ON)
target_link_libraries(calendardemo_pim PRIVATE Qt6::Organizer Qt6::Versit Qt6::Widgets)

install(TARGETS calendardemo_pim
    RUNTIME DESTINATION "${CMAKE_INSTALL_PREFIX}/examples/organizer/calendardemo"
)
