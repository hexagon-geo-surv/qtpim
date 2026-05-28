# Copyright (C) 2026 The Qt Company Ltd.
# SPDX-License-Identifier: BSD-3-Clause

qt_internal_add_module(VersitOrganizer
    SOURCES
        qtimezones_p.cpp
        qversitorganizerexporter.cpp
        qversitorganizerexporter_p.cpp
        qversitorganizerhandler.cpp
        qversitorganizerimporter.cpp
        qversitorganizerimporter_p.cpp
        qversitorganizerpluginloader_p.cpp
        qversitorganizerdefs_p.h
        qversitorganizerexporter.h
        qversitorganizerglobal.h
        qversitorganizerhandler.h
        qversitorganizerimporter.h
        qversittimezonehandler.h
        qtimezones_p.h
        qversitorganizerexporter_p.h
        qversitorganizerhandler.h
        qversitorganizerimporter_p.h
        qversitorganizerpluginloader_p.h
        qversitorganizerpluginsearch_p.h
    LIBRARIES
        Qt::VersitPrivate
    PUBLIC_LIBRARIES
        Qt::Core
        Qt::Organizer
        Qt::Versit
)
