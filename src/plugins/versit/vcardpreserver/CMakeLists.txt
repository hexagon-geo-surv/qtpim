# Copyright (C) 2026 The Qt Company Ltd.
# SPDX-License-Identifier: BSD-3-Clause

qt_internal_add_plugin(QtVersitVCardPreserverPlugin
    OUTPUT_NAME qtversit_vcardpreserver
    PLUGIN_TYPE versit
    CLASS_NAME VCardPreserverFactory
    SOURCES
        vcardpreserver.cpp
        vcardpreserver.h
)
target_link_libraries(QtVersitVCardPreserverPlugin PRIVATE Qt6::Contacts Qt6::Versit)
