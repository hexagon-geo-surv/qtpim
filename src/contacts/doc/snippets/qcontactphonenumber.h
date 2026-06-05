// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause


#ifndef QCONTACTPHONENUMBER_H
#define QCONTACTPHONENUMBER_H

#include <QString>

#include <QtContacts/qcontactsglobal.h>
#include <QtContacts/qcontactdetail.h>
#include <QtContacts/qcontactfilter.h>

QT_BEGIN_NAMESPACE_CONTACTS

/* Leaf class */
//! [0]
class Q_CONTACTS_EXPORT QContactPhoneNumber : public QContactDetail
{
public:
#ifndef Q_QDOC
    Q_DECLARE_CUSTOM_CONTACT_DETAIL(QContactPhoneNumber)
#else
    static const DetailType Type;
#endif

    enum PhoneNumberField {
        FieldNumber = 0,
        FieldSubTypes
    };

    enum SubType {
        SubTypeLandline = 0,
        SubTypeMobile,
        SubTypeFax,
        SubTypePager,
        SubTypeVoice,
        SubTypeModem,
        SubTypeVideo,
        SubTypeCar,
        SubTypeBulletinBoardSystem,
        SubTypeMessagingCapable,
        SubTypeAssistant,
        SubTypeDtmfMenu
    };

    void setNumber(const QString& number) {setValue(FieldNumber, number);}
    QString number() const {return value(FieldNumber).toString();}

    void setSubTypes(const QList<int> &subTypes) {setValue(FieldSubTypes, QVariant::fromValue(subTypes));}
    QList<int> subTypes() const {return value< QList<int> >(FieldSubTypes);}

    // Convenience filter
    static QContactFilter match(const QString& number);
};
//! [0]

QT_END_NAMESPACE_CONTACTS

#endif

