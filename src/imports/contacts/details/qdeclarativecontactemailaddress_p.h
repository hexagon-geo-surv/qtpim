// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QDECLARATIVECONTACTEMAILADDRESS_H
#define QDECLARATIVECONTACTEMAILADDRESS_H

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

#include <QtContacts/qcontactemailaddress.h>

#include "qdeclarativecontactdetail_p.h"

QTCONTACTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE

class QDeclarativeContactEmailAddress : public QDeclarativeContactDetail
{
    Q_OBJECT
    Q_PROPERTY(QString emailAddress READ emailAddress WRITE setEmailAddress NOTIFY valueChanged)
    Q_ENUMS(FieldType)
public:
    enum FieldType {
        EmailAddress = QContactEmailAddress::FieldEmailAddress
    };
    QDeclarativeContactEmailAddress(QObject* parent = nullptr)
        :QDeclarativeContactDetail(parent)
    {
        setDetail(QContactEmailAddress());
        connect(this, SIGNAL(valueChanged()), SIGNAL(detailChanged()));
    }

    DetailType detailType() const override
    {
        return QDeclarativeContactDetail::Email;
    }

    void setEmailAddress(const QString& v)
    {
        if (!readOnly() && v != emailAddress()) {
            detail().setValue(QContactEmailAddress::FieldEmailAddress, v);
            emit valueChanged();
        }
    }
    QString emailAddress() const {return detail().value(QContactEmailAddress::FieldEmailAddress).toString();}

signals:
    void valueChanged();
};

QT_END_NAMESPACE

QML_DECLARE_TYPE(QDeclarativeContactEmailAddress)

#endif // QDECLARATIVECONTACTEMAILADDRESS_H
