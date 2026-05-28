# Copyright (C) 2026 The Qt Company Ltd.
# SPDX-License-Identifier: BSD-3-Clause

qt_internal_add_qml_module(declarative_contacts
    URI "QtContacts"
    VERSION "6.13"
    CLASS_NAME QContactQmlPlugin
    PLUGIN_OPTIONAL
    NO_GENERATE_QMLTYPES
    TYPEINFO "plugins.qmltypes"
    SOURCES
        declarative_contacts_qmltyperegistrations.cpp
        plugin.cpp
        qdeclarativecontact.cpp
        qdeclarativecontactcollection.cpp
        qdeclarativecontactdetail.cpp
        qdeclarativecontactfetchhint.cpp
        qdeclarativecontactfilter.cpp
        qdeclarativecontactmodel.cpp
        qdeclarativecontactrelationship.cpp
        qdeclarativecontactrelationshipmodel.cpp
        qdeclarativecontactsortorder.cpp
        details/qdeclarativecontactmoc_p.cpp
        filters/qdeclarativecontactfiltermoc.cpp
        details/qdeclarativecontactaddress_p.h
        details/qdeclarativecontactanniversary_p.h
        details/qdeclarativecontactavatar_p.h
        details/qdeclarativecontactbirthday_p.h
        details/qdeclarativecontactdetails_p.h
        details/qdeclarativecontactdisplaylabel_p.h
        details/qdeclarativecontactemailaddress_p.h
        details/qdeclarativecontactextendeddetail_p.h
        details/qdeclarativecontactfamily_p.h
        details/qdeclarativecontactfavorite_p.h
        details/qdeclarativecontactgender_p.h
        details/qdeclarativecontactgeolocation_p.h
        details/qdeclarativecontactglobalpresence_p.h
        details/qdeclarativecontactguid_p.h
        details/qdeclarativecontacthobby_p.h
        details/qdeclarativecontactname_p.h
        details/qdeclarativecontactnickname_p.h
        details/qdeclarativecontactnote_p.h
        details/qdeclarativecontactonlineaccount_p.h
        details/qdeclarativecontactorganization_p.h
        details/qdeclarativecontactphonenumber_p.h
        details/qdeclarativecontactpresence_p.h
        details/qdeclarativecontactringtone_p.h
        details/qdeclarativecontactsynctarget_p.h
        details/qdeclarativecontacttag_p.h
        details/qdeclarativecontacttimestamp_p.h
        details/qdeclarativecontacttype_p.h
        details/qdeclarativecontacturl_p.h
        details/qdeclarativecontactversion_p.h
        filters/qdeclarativecontactactionfilter_p.h
        filters/qdeclarativecontactchangelogfilter_p.h
        filters/qdeclarativecontactcollectionfilter_p.h
        filters/qdeclarativecontactdetailfilter_p.h
        filters/qdeclarativecontactdetailrangefilter_p.h
        filters/qdeclarativecontactfilters_p.h
        filters/qdeclarativecontactidfilter_p.h
        filters/qdeclarativecontactintersectionfilter_p.h
        filters/qdeclarativecontactinvalidfilter_p.h
        filters/qdeclarativecontactrelationshipfilter_p.h
        filters/qdeclarativecontactunionfilter_p.h
        qdeclarativecontact_p.h
        qdeclarativecontactcollection_p.h
        qdeclarativecontactdetail_p.h
        qdeclarativecontactfetchhint_p.h
        qdeclarativecontactfilter_p.h
        qdeclarativecontactmodel_p.h
        qdeclarativecontactrelationship_p.h
        qdeclarativecontactrelationshipmodel_p.h
        qdeclarativecontactsortorder_p.h
        qdeclarativeglobal_p.h
    RESOURCES
        contacts.qrc
)

target_compile_definitions(declarative_contacts PRIVATE QT_DISABLE_DEPRECATED_BEFORE=0)
target_link_libraries(declarative_contacts PRIVATE Qt6::Contacts Qt6::Gui Qt6::Qml Qt6::Versit)
# QT_LEAN_HEADERS=2 suppresses the transitive include of qtyperevision.h from
# qversionnumber.h, but qqmlprivate.h uses QTypeRevision without including it
# directly. Prepend the missing include via a precompiled header.
target_precompile_headers(declarative_contacts PRIVATE <QtCore/qtyperevision.h>)
