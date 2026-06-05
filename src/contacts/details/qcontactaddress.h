// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QCONTACTADDRESS_H
#define QCONTACTADDRESS_H

#include <QtContacts/qcontactdetail.h>

QT_BEGIN_NAMESPACE_CONTACTS

class QContactFilter;

/* Leaf class */
class Q_CONTACTS_EXPORT QContactAddress : public QContactDetail
{
public:
#ifndef Q_QDOC
    Q_DECLARE_CUSTOM_CONTACT_DETAIL(QContactAddress)
#else
    static const DetailType Type;
#endif

    enum AddressField {
        FieldStreet = 0,
        FieldLocality,
        FieldRegion,
        FieldPostcode,
        FieldCountry,
        FieldSubTypes,
        FieldPostOfficeBox
    };

    enum SubType {
        SubTypeParcel = 0,
        SubTypePostal,
        SubTypeDomestic,
        SubTypeInternational
    };

    void setStreet(const QString& _street);
    QString street() const;
    void setLocality(const QString& _locality);
    QString locality() const;
    void setRegion(const QString& _region);
    QString region() const;
    void setPostcode(const QString& _postcode);
    QString postcode() const;
    void setCountry(const QString& _country);
    QString country() const;
    void setPostOfficeBox(const QString& _postOfficeBox);
    QString postOfficeBox() const;

    void setSubTypes(const QList<int> &_subTypes);
    QList<int> subTypes() const;

    // Convenience filter
    static QContactFilter match(const QString& subString);
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTADDRESS_H
