// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include <QtQml/qqml.h>

#include <QtContacts/qcontactid.h>
#include <QtContacts/qcontactabstractrequest.h>

#include "qdeclarativecontact_p.h"
#include "qdeclarativecontactcollection_p.h"
#include "qdeclarativecontactdetail_p.h"
#include "qdeclarativecontactfetchhint_p.h"
#include "qdeclarativecontactfilter_p.h"
#include "filters/qdeclarativecontactfilters_p.h"
#include "qdeclarativecontactmodel_p.h"
#include "qdeclarativecontactrelationship_p.h"
#include "qdeclarativecontactrelationshipmodel_p.h"
#include "qdeclarativecontactsortorder_p.h"

QTCONTACTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE

void qtcontacts_qml_register_types(const char *uri)
{
    int major = 5;
    int minor = 0;
    qRegisterMetaType<QContactAbstractRequest::State>("QContactAbstractRequest::State");
    qRegisterMetaType<QContactId>("QContactId");
    qRegisterMetaType<QList<QContactId> >("QList<QContactId>");
    qRegisterMetaType<QList<QContactCollectionId> >("QList<QContactCollectionId>");
    qmlRegisterType<QDeclarativeContactModel>(uri, major, minor, "ContactModel");
    qmlRegisterType<QDeclarativeContact>(uri, major, minor, "Contact");
    qmlRegisterType<QDeclarativeContactCollection>(uri, major, minor, "Collection");
    qmlRegisterType<QDeclarativeContactFetchHint>(uri, major, minor, "FetchHint");
    qmlRegisterType<QDeclarativeContactRelationshipModel>(uri, major, minor, "RelationshipModel");
    qmlRegisterType<QDeclarativeContactRelationship>(uri, major, minor, "Relationship");
    qmlRegisterType<QDeclarativeContactSortOrder>(uri, major, minor, "SortOrder");

    //details
    qmlRegisterType<QDeclarativeContactDetail>(uri, major, minor, "ContactDetail");
    qmlRegisterType<QDeclarativeContactAddress>(uri, major, minor, "Address");
    qmlRegisterType<QDeclarativeContactAnniversary>(uri, major, minor, "Anniversary");
    qmlRegisterType<QDeclarativeContactAvatar>(uri, major, minor, "Avatar");
    qmlRegisterType<QDeclarativeContactBirthday>(uri, major, minor, "Birthday");
    qmlRegisterType<QDeclarativeContactDisplayLabel>(uri, major, minor, "DisplayLabel");
    qmlRegisterType<QDeclarativeContactEmailAddress>(uri, major, minor, "EmailAddress");
    qmlRegisterType<QDeclarativeContactFamily>(uri, major, minor, "Family");
    qmlRegisterType<QDeclarativeContactFavorite>(uri, major, minor, "Favorite");
    qmlRegisterType<QDeclarativeContactGender>(uri, major, minor, "Gender");
    qmlRegisterType<QDeclarativeContactGeoLocation>(uri, major, minor, "Location");
    qmlRegisterType<QDeclarativeContactGlobalPresence>(uri, major, minor, "GlobalPresence");
    qmlRegisterType<QDeclarativeContactGuid>(uri, major, minor, "Guid");
    qmlRegisterType<QDeclarativeContactName>(uri, major, minor, "Name");
    qmlRegisterType<QDeclarativeContactNickname>(uri, major, minor, "Nickname");
    qmlRegisterType<QDeclarativeContactNote>(uri, major, minor, "Note");
    qmlRegisterType<QDeclarativeContactOnlineAccount>(uri, major, minor, "OnlineAccount");
    qmlRegisterType<QDeclarativeContactOrganization>(uri, major, minor, "Organization");
    qmlRegisterType<QDeclarativeContactPhoneNumber>(uri, major, minor, "PhoneNumber");
    qmlRegisterType<QDeclarativeContactPresence>(uri, major, minor, "Presence");
    qmlRegisterType<QDeclarativeContactRingtone>(uri, major, minor, "Ringtone");
    qmlRegisterType<QDeclarativeContactSyncTarget>(uri, major, minor, "SyncTarget");
    qmlRegisterType<QDeclarativeContactTag>(uri, major, minor, "Tag");
    qmlRegisterType<QDeclarativeContactTimestamp>(uri, major, minor, "Timestamp");
    qmlRegisterType<QDeclarativeContactType>(uri, major, minor, "Type");
    qmlRegisterType<QDeclarativeContactUrl>(uri, major, minor, "Url");
    qmlRegisterType<QDeclarativeContactVersion>(uri, major, minor, "Version");
    qmlRegisterType<QDeclarativeContactHobby>(uri, major, minor, "Hobby");
    qmlRegisterType<QDeclarativeContactExtendedDetail>(uri, major, minor, "ExtendedDetail");

    //filters
    qmlRegisterType<QDeclarativeContactFilter>(uri, major, minor, "Filter");
    qmlRegisterType<QDeclarativeContactActionFilter>(uri, major, minor, "ActionFilter");
    qmlRegisterType<QDeclarativeContactChangeLogFilter>(uri, major, minor, "ChangeLogFilter");
    qmlRegisterType<QDeclarativeContactCollectionFilter>(uri, major, minor, "CollectionFilter");
    qmlRegisterType<QDeclarativeContactDetailFilter>(uri, major, minor, "DetailFilter");
    qmlRegisterType<QDeclarativeContactDetailRangeFilter>(uri, major, minor, "DetailRangeFilter");
    qmlRegisterType<QDeclarativeContactIdFilter>(uri, major, minor, "IdFilter");
    qmlRegisterType<QDeclarativeContactRelationshipFilter>(uri, major, minor, "RelationshipFilter");
    qmlRegisterType<QDeclarativeContactIntersectionFilter>(uri, major, minor, "IntersectionFilter");
    qmlRegisterType<QDeclarativeContactUnionFilter>(uri, major, minor, "UnionFilter");
    qmlRegisterType<QDeclarativeContactInvalidFilter>(uri, major, minor, "InvalidFilter");
    qmlRegisterUncreatableType<QDeclarativeContactCompoundFilter>(uri, major, minor, "CompoundFilter",
                                                                 QStringLiteral("CompoundFilter is abstract"));
}

QT_END_NAMESPACE
