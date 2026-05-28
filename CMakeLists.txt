# Copyright (C) 2026 The Qt Company Ltd.
# SPDX-License-Identifier: BSD-3-Clause

cmake_minimum_required(VERSION 3.16)

include(.cmake.conf)
project(QtPim
    VERSION "${QT_REPO_MODULE_VERSION}"
    DESCRIPTION "Qt PIM Libraries"
    HOMEPAGE_URL "https://qt.io/"
    LANGUAGES CXX C
)

find_package(Qt6 ${PROJECT_VERSION} CONFIG REQUIRED COMPONENTS BuildInternals Core)
find_package(Qt6 ${PROJECT_VERSION} CONFIG OPTIONAL_COMPONENTS
    Gui
    Qml
    Quick
    QuickTest
    Widgets
    Xml
)

find_package(Qt6 ${PROJECT_VERSION} QUIET OPTIONAL_COMPONENTS ServiceFramework)

qt_build_repo()
