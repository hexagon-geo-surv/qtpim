// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QDECLARATIVECONTACTADDRESS_H
#define QDECLARATIVECONTACTADDRESS_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.
// This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <QtContacts/qcontactaddress.h>

#include "qdeclarativecontactdetail_p.h"

QTCONTACTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE

class QDeclarativeContactAddress : public QDeclarativeContactDetail
{
    Q_OBJECT

    Q_PROPERTY(QString street READ street WRITE setStreet NOTIFY valueChanged)
    Q_PROPERTY(QString locality READ locality WRITE setLocality NOTIFY valueChanged)
    Q_PROPERTY(QString region READ region WRITE setRegion  NOTIFY valueChanged)
    Q_PROPERTY(QString postcode READ postcode WRITE setPostcode  NOTIFY valueChanged)
    Q_PROPERTY(QString country READ country WRITE setCountry  NOTIFY valueChanged)
    Q_PROPERTY(QList<int> subTypes READ subTypes WRITE setSubTypes NOTIFY valueChanged)
    Q_PROPERTY(QString postOfficeBox READ postOfficeBox WRITE setPostOfficeBox  NOTIFY valueChanged)
    Q_ENUMS(FieldType)
    Q_ENUMS(AddressSubType)
public:
    enum FieldType {
        Street = QContactAddress::FieldStreet,
        Locality = QContactAddress::FieldLocality,
        Region = QContactAddress::FieldRegion,
        Postcode = QContactAddress::FieldPostcode,
        Country = QContactAddress::FieldCountry,
        SubTypes = QContactAddress::FieldSubTypes,
        PostOfficeBox = QContactAddress::FieldPostOfficeBox
    };

    enum AddressSubType {
        Parcel = QContactAddress::SubTypeParcel,
        Postal = QContactAddress::SubTypePostal,
        Domestic = QContactAddress::SubTypeDomestic,
        International = QContactAddress::SubTypeInternational
    };

    QDeclarativeContactAddress(QObject* parent = Q_NULLPTR)
        :QDeclarativeContactDetail(parent)
    {
        setDetail(QContactAddress());
        connect(this, SIGNAL(valueChanged()), SIGNAL(detailChanged()));
    }

    DetailType detailType() const override
    {
        return QDeclarativeContactDetail::Address;
    }

    void setStreet(const QString& v)
    {
        if (!readOnly() && v != street()) {
            detail().setValue(QContactAddress::FieldStreet, v);
            emit valueChanged();
        }
    }
    QString street() const {return detail().value(QContactAddress::FieldStreet).toString();}
    void setLocality(const QString& v)
    {
        if (!readOnly() && v != locality()) {
            detail().setValue(QContactAddress::FieldLocality, v);
            emit valueChanged();
        }
    }
    QString locality() const {return detail().value(QContactAddress::FieldLocality).toString();}
    void setRegion(const QString& v)
    {
        if (!readOnly() && v != region()) {
            detail().setValue(QContactAddress::FieldRegion, v);
            emit valueChanged();
        }
    }
    QString region() const {return detail().value(QContactAddress::FieldRegion).toString();}
    void setPostcode(const QString& v)
    {
        if (!readOnly() && v != postcode()) {
            detail().setValue(QContactAddress::FieldPostcode, v);
            emit valueChanged();
        }
    }
    QString postcode() const {return detail().value(QContactAddress::FieldPostcode).toString();}
    void setCountry(const QString& v)
    {
        if (!readOnly() && v != country()) {
            detail().setValue(QContactAddress::FieldCountry, v);
            emit valueChanged();
        }
    }
    QString country() const {return detail().value(QContactAddress::FieldCountry).toString();}
    void setPostOfficeBox(const QString& v)
    {
        if (!readOnly() && v != postOfficeBox()) {
            detail().setValue(QContactAddress::FieldPostOfficeBox, v);
            emit valueChanged();
        }
    }
    QString postOfficeBox() const {return detail().value(QContactAddress::FieldPostOfficeBox).toString();}

    void setSubTypes(const QList<int>& subTypes)
    {
        QList<int>  oldList = detail().value< QList<int>  >(QContactAddress::FieldSubTypes);

        if (!readOnly() && QSet<int>(subTypes.cbegin(), subTypes.cend()) != QSet<int>(oldList.cbegin(), oldList.cend())) {
            detail().setValue(QContactAddress::FieldSubTypes, QVariant::fromValue(subTypes));
            emit valueChanged();
        }
    }

    QList<int> subTypes() const
    {
        return detail().value< QList<int> >(QContactAddress::FieldSubTypes);
    }
signals:
    void valueChanged();
};

QT_END_NAMESPACE

QML_DECLARE_TYPE(QDeclarativeContactAddress)

#endif // QDECLARATIVECONTACTADDRESS_H
