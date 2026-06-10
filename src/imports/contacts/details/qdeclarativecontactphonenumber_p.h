// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QDECLARATIVECONTACTPHONENUMBER_H
#define QDECLARATIVECONTACTPHONENUMBER_H

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

#include <QtContacts/qcontactphonenumber.h>

#include "qdeclarativecontactdetail_p.h"

QTCONTACTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE

class  QDeclarativeContactPhoneNumber : public QDeclarativeContactDetail
{
    Q_OBJECT

    Q_PROPERTY(QString number READ number WRITE setNumber NOTIFY valueChanged)
    Q_PROPERTY(QList<int> subTypes READ subTypes WRITE setSubTypes NOTIFY valueChanged)
    Q_ENUMS(FieldType)
    Q_ENUMS(PhoneNumberSubType)

    Q_CLASSINFO("DefaultProperty", "number")
public:
    enum FieldType {
        Number = QContactPhoneNumber::FieldNumber,
        SubTypes = QContactPhoneNumber::FieldSubTypes
    };

    enum PhoneNumberSubType {
        Landline = QContactPhoneNumber::SubTypeLandline,
        Mobile = QContactPhoneNumber::SubTypeMobile,
        Fax = QContactPhoneNumber::SubTypeFax,
        Pager = QContactPhoneNumber::SubTypePager,
        Voice = QContactPhoneNumber::SubTypeVoice,
        Modem = QContactPhoneNumber::SubTypeModem,
        Video = QContactPhoneNumber::SubTypeVideo,
        Car = QContactPhoneNumber::SubTypeCar,
        BulletinBoardSystem = QContactPhoneNumber::SubTypeBulletinBoardSystem,
        MessagingCapable = QContactPhoneNumber::SubTypeMessagingCapable,
        Assistant = QContactPhoneNumber::SubTypeAssistant,
        DtmfMenu = QContactPhoneNumber::SubTypeDtmfMenu
    };

    QDeclarativeContactPhoneNumber(QObject* parent = Q_NULLPTR)
        :QDeclarativeContactDetail(parent)
    {
        setDetail(QContactPhoneNumber());
        connect(this, SIGNAL(valueChanged()), SIGNAL(detailChanged()));
    }
    DetailType detailType() const override
    {
        return QDeclarativeContactDetail::PhoneNumber;
    }

    void setNumber(const QString& v)
    {
        if (!readOnly() && v != number()) {
            detail().setValue(QContactPhoneNumber::FieldNumber, v);
            emit valueChanged();
        }
    }
    QString number() const {return detail().value(QContactPhoneNumber::FieldNumber).toString();}


    void setSubTypes(const QList<int>& subTypes)
    {
        QList<int> oldList = detail().value< QList<int> >(QContactPhoneNumber::FieldSubTypes);

        if (!readOnly() && QSet<int>(subTypes.cbegin(), subTypes.cend()) != QSet<int>(oldList.cbegin(), oldList.cend())) {
            detail().setValue(QContactPhoneNumber::FieldSubTypes, QVariant::fromValue(subTypes));
            emit valueChanged();
        }
    }

    QList<int> subTypes() const
    {
        return detail().value< QList<int> >(QContactPhoneNumber::FieldSubTypes);
    }

signals:
    void valueChanged();

};

QT_END_NAMESPACE

QML_DECLARE_TYPE(QDeclarativeContactPhoneNumber)

#endif // QDECLARATIVECONTACTPHONENUMBER_H
