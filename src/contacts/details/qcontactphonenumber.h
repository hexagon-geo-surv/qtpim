// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QCONTACTPHONENUMBER_H
#define QCONTACTPHONENUMBER_H

#include <QtContacts/qcontactdetail.h>

QT_BEGIN_NAMESPACE_CONTACTS

class QContactFilter;

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
        FieldNormalizedNumber,
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
        SubTypeDtmfMenu,
        SubTypeIsdn
    };

    void setNumber(const QString &_number);
    QString number() const;

    void setNormalizedNumber(const QString &_normalizedNumber);
    QString normalizedNumber() const;

    void setSubTypes(const QList<int> &_subTypes);
    QList<int> subTypes() const;

    // Convenience filter
    static QContactFilter match(const QString& _number);
};
//! [0]

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTPHONENUMBER_H
