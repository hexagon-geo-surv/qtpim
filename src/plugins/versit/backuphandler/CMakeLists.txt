# Copyright (C) 2026 The Qt Company Ltd.
# SPDX-License-Identifier: BSD-3-Clause

qt_internal_add_plugin(QtVersitBackupHandlerPlugin
    OUTPUT_NAME qtversit_backuphandler
    PLUGIN_TYPE versit
    CLASS_NAME BackupVCardHandlerFactory
    SOURCES
        backupvcardhandler.cpp
        backupvcardhandler.h
)
target_link_libraries(QtVersitBackupHandlerPlugin PRIVATE Qt6::Contacts Qt6::VersitPrivate)
