// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QVERSITCONTACTSDEFS_P_H
#define QVERSITCONTACTSDEFS_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <QtContacts/qcontactdetails.h>

#include <QtVersit/private/qversitdefs_p.h>

QTCONTACTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE_VERSIT

//! [Property name mappings]
// Mappings from versit property names to Qt contact details
// For the case that there are multiple property names corresponding to the same detail, put the
// primary one first and it will be the one used when exporting.
const VersitContactDetailMapping versitContactDetailMappings[] = {
    {"ADR",           QContactAddress::Type,
                      -1},
    {"BDAY",          QContactBirthday::Type,
                      QContactBirthday::FieldBirthday},
    {"CATEGORIES",    QContactTag::Type,
                      QContactTag::FieldTag},
    {"FN",            QContactDisplayLabel::Type,
                      QContactDisplayLabel::FieldLabel},
    {"GEO",           QContactGeoLocation::Type,
                      -1},
    {"EMAIL",         QContactEmailAddress::Type,
                      QContactEmailAddress::FieldEmailAddress},
    {"IMPP",          QContactOnlineAccount::Type,
                      -1},
    {"LOGO",          QContactOrganization::Type,
                      QContactOrganization::FieldLogoUrl},
    {"N",             QContactName::Type,
                      -1},
    {"NICKNAME",      QContactNickname::Type,
                      QContactNickname::FieldNickname},
    {"NOTE",          QContactNote::Type,
                      QContactNote::FieldNote},
    {"PHOTO",         QContactAvatar::Type,
                      -1},
    {"ORG",           QContactOrganization::Type,
                      QContactOrganization::FieldName},
    {"REV",           QContactTimestamp::Type,
                      -1},
    {"ROLE",          QContactOrganization::Type,
                      QContactOrganization::FieldRole},
    {"SOUND",         QContactRingtone::Type,
                      QContactRingtone::FieldAudioRingtoneUrl},
    {"TEL",           QContactPhoneNumber::Type,
                      QContactPhoneNumber::FieldNumber},
    {"TITLE",         QContactOrganization::Type,
                      QContactOrganization::FieldTitle},
    {"UID",           QContactGuid::Type,
                      QContactGuid::FieldGuid},
    {"URL",           QContactUrl::Type,
                      QContactUrl::FieldUrl},
    {"X-ABUID",       QContactGuid::Type,
                      QContactGuid::FieldGuid},
    {"X-AIM",         QContactOnlineAccount::Type,
                      -1},
    {"X-ANNIVERSARY", QContactAnniversary::Type,
                      -1},
    {"X-ASSISTANT",   QContactOrganization::Type,
                      QContactOrganization::FieldAssistantName},
    {"X-ASSISTANT-TEL", QContactPhoneNumber::Type,
                      QContactPhoneNumber::SubTypeAssistant},
    {"X-CHILDREN",    QContactFamily::Type,
                      QContactFamily::FieldChildren},
    {"X-EPOCSECONDNAME",QContactNickname::Type,
                      QContactNickname::FieldNickname},
    {"X-EVOLUTION-SPOUSE", QContactFamily::Type,
                      QContactFamily::FieldSpouse},
    {"X-EVOLUTION-ANNIVERSARY", QContactAnniversary::Type,
                      -1},
    {"X-GADUGADU",    QContactOnlineAccount::Type,
                      -1},
    {"X-GENDER",      QContactGender::Type,
                      QContactGender::FieldGender},
    {"X-ICQ",         QContactOnlineAccount::Type,
                      -1},
    {"X-IMPP",        QContactOnlineAccount::Type,
                      -1},
    {"X-JABBER",      QContactOnlineAccount::Type,
                      -1},
    {"X-KADDRESSBOOK-X-SPOUSENAME", QContactFamily::Type,
                      QContactFamily::FieldSpouse},
    {"X-KADDRESSBOOK-X-ANNIVERSARY", QContactAnniversary::Type,
                      -1},
    {"X-KADDRESSBOOK-X-IMADDRESS", QContactOnlineAccount::Type,
                      -1},
    {"X-MS-CARDPICTURE", QContactAvatar::Type,
                      -1},
    {"X-MS-IMADDRESS", QContactOnlineAccount::Type,
                      -1},
    {"X-MSN",         QContactOnlineAccount::Type,
                      -1},
    {"X-NICKNAME",    QContactNickname::Type,
                      QContactNickname::FieldNickname},
    {"X-QQ",          QContactOnlineAccount::Type,
                      -1},
    {"X-QTPROJECT-EXTENDED-DETAIL", QContactExtendedDetail::Type,
                      -1},
    {"X-QTPROJECT-FAVORITE", QContactFavorite::Type,
                      -1},
    {"X-QTPROJECT-VERSION", QContactVersion::Type,
                      -1},
    {"X-SIP",         QContactOnlineAccount::Type,
                      -1},
    {"X-SKYPE",       QContactOnlineAccount::Type,
                      -1},
    {"X-SKYPE-USERNAME", QContactOnlineAccount::Type,
                      -1},
    {"X-SPOUSE",      QContactFamily::Type,
                      QContactFamily::FieldSpouse},
    {"X-YAHOO",       QContactOnlineAccount::Type,
                      -1},
    // In the bottom, because these are lower-priority properties:
    {"X-FOLKS-FAVOURITE", QContactFavorite::Type,
                      -1},
};
//! [Property name mappings]

// Mappings from versit TYPE parameters to Qt contact detail contexts
const VersitContextMapping versitContextMappings[] = {
    {"HOME", QContactDetail::ContextHome},
    {"WORK", QContactDetail::ContextWork},
    {"OTHER", QContactDetail::ContextOther}
};

//! [Property type parameter mappings]
// Mappings from versit TYPE parameters to Qt contact detail subtypes
const VersitSubTypeMapping versitSubTypeMappings[] = {
    {"DOM",    QContactDetail::TypeAddress, QContactAddress::SubTypeDomestic},
    {"INTL",   QContactDetail::TypeAddress, QContactAddress::SubTypeInternational},
    {"POSTAL", QContactDetail::TypeAddress, QContactAddress::SubTypePostal},
    {"PARCEL", QContactDetail::TypeAddress, QContactAddress::SubTypeParcel},
    {"VOICE",  QContactDetail::TypePhoneNumber, QContactPhoneNumber::SubTypeVoice},
    {"CELL",   QContactDetail::TypePhoneNumber, QContactPhoneNumber::SubTypeMobile},
    {"MODEM",  QContactDetail::TypePhoneNumber, QContactPhoneNumber::SubTypeModem},
    {"CAR",    QContactDetail::TypePhoneNumber, QContactPhoneNumber::SubTypeCar},
    {"VIDEO",  QContactDetail::TypePhoneNumber, QContactPhoneNumber::SubTypeVideo},
    {"FAX",    QContactDetail::TypePhoneNumber, QContactPhoneNumber::SubTypeFax},
    {"BBS",    QContactDetail::TypePhoneNumber, QContactPhoneNumber::SubTypeBulletinBoardSystem},
    {"PAGER",  QContactDetail::TypePhoneNumber, QContactPhoneNumber::SubTypePager},
    {"ISDN",   QContactDetail::TypePhoneNumber, QContactPhoneNumber::SubTypeIsdn},
    {"VOICE",  QContactDetail::TypePhoneNumber, QContactPhoneNumber::SubTypeLandline},
    {"SWIS",   QContactDetail::TypeOnlineAccount, QContactOnlineAccount::SubTypeVideoShare},
    {"VOIP",   QContactDetail::TypeOnlineAccount, QContactOnlineAccount::SubTypeSipVoip}
};
//! [Property type parameter mappings]

QT_END_NAMESPACE_VERSIT

#endif // QVERSITCONTACTSDEFS_P_H
