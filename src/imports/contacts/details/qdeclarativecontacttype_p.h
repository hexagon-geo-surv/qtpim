// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QDECLARATIVECONTACTTYPE_H
#define QDECLARATIVECONTACTTYPE_H

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

#include <QtContacts/qcontacttype.h>

#include "qdeclarativecontactdetail_p.h"

QTCONTACTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE

class QDeclarativeContactType : public QDeclarativeContactDetail
{
    Q_OBJECT
    Q_PROPERTY(ContactType type READ type WRITE setType NOTIFY valueChanged)
    Q_ENUMS(FieldType)
    Q_ENUMS(ContactType)
    Q_CLASSINFO("DefaultProperty", "type")
public:
    enum FieldType {
        TypeField = QContactType::FieldType
    };

    enum ContactType {
        Unspecified = 0,
        Contact = QContactType::TypeContact,
        Group = QContactType::TypeGroup,
        Facet = QContactType::TypeFacet
    };


    DetailType detailType() const
    {
        return QDeclarativeContactDetail::Type;
    }

    QDeclarativeContactType(QObject* parent = nullptr)
        :QDeclarativeContactDetail(parent)
    {
        setDetail(QContactType());
        connect(this, SIGNAL(valueChanged()), SIGNAL(detailChanged()));
    }

    void setType(ContactType newType)
    {
        if (!readOnly() && newType!=type())  {
            switch (newType) {
            case Contact:
            case Group:
            case Facet:
                detail().setValue(QContactType::FieldType, newType);
                break;
            default:
                detail().setValue(QContactType::FieldType, Unspecified);
            }
        }
    }

    ContactType type() const
    {
        return static_cast<ContactType>(detail().value(QContactType::FieldType).toInt());
    }
signals:
    void valueChanged();
};

QT_END_NAMESPACE

QML_DECLARE_TYPE(QDeclarativeContactType)

#endif // QDECLARATIVECONTACTTYPE_H
