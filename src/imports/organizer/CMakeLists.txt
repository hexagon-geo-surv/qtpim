# Copyright (C) 2026 The Qt Company Ltd.
# SPDX-License-Identifier: BSD-3-Clause

qt_internal_add_qml_module(declarative_organizer
    URI "QtOrganizer"
    VERSION "6.13"
    CLASS_NAME QOrganizerQmlPlugin
    PLUGIN_OPTIONAL
    NO_GENERATE_QMLTYPES
    TYPEINFO "plugins.qmltypes"
    SOURCES
        declarative_organizer_qmltyperegistrations.cpp
        plugin.cpp
        qdeclarativeorganizercollection.cpp
        qdeclarativeorganizeritem.cpp
        qdeclarativeorganizeritemdetail.cpp
        qdeclarativeorganizeritemfetchhint.cpp
        qdeclarativeorganizeritemfilter.cpp
        qdeclarativeorganizeritemsortorder.cpp
        qdeclarativeorganizermodel.cpp
        qdeclarativeorganizerrecurrencerule.cpp
        qdeclarativeorganizercollection_p.h
        qdeclarativeorganizeritem_p.h
        qdeclarativeorganizeritemdetail_p.h
        qdeclarativeorganizeritemfetchhint_p.h
        qdeclarativeorganizeritemfilter_p.h
        qdeclarativeorganizeritemsortorder_p.h
        qdeclarativeorganizermodel_p.h
        qdeclarativeorganizerrecurrencerule_p.h
)

target_compile_definitions(declarative_organizer PRIVATE QT_DISABLE_DEPRECATED_BEFORE=0)
target_link_libraries(declarative_organizer PRIVATE
    Qt6::Gui
    Qt6::Organizer
    Qt6::Qml
    Qt6::Versit
    Qt6::VersitOrganizer
)
# QT_LEAN_HEADERS=2 suppresses the transitive include of qtyperevision.h from
# qversionnumber.h, but qqmlprivate.h uses QTypeRevision without including it
# directly. Prepend the missing include via a precompiled header.
target_precompile_headers(declarative_organizer PRIVATE <QtCore/qtyperevision.h>)
