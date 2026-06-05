// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QDECLARATIVECONTACTNAME_H
#define QDECLARATIVECONTACTNAME_H

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

#include <QtContacts/qcontactname.h>

#include "qdeclarativecontactdetail_p.h"

QTCONTACTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE

class QDeclarativeContactName : public QDeclarativeContactDetail
{
    Q_OBJECT
    Q_PROPERTY(QString prefix READ prefix WRITE setPrefix NOTIFY valueChanged)
    Q_PROPERTY(QString firstName READ firstName WRITE setFirstName NOTIFY valueChanged)
    Q_PROPERTY(QString middleName READ middleName WRITE setMiddleName NOTIFY valueChanged)
    Q_PROPERTY(QString lastName READ lastName WRITE setLastName NOTIFY valueChanged)
    Q_PROPERTY(QString suffix READ suffix WRITE setSuffix NOTIFY valueChanged)

    Q_ENUMS(FieldType)
    Q_CLASSINFO("DefaultProperty", "firstName")
public:
    enum FieldType {
        Prefix = QContactName::FieldPrefix,
        FirstName = QContactName::FieldFirstName,
        MiddleName = QContactName::FieldMiddleName,
        LastName = QContactName::FieldLastName,
        Suffix = QContactName::FieldSuffix,
    };

    QDeclarativeContactName(QObject* parent = nullptr)
        :QDeclarativeContactDetail(parent)
    {
        setDetail(QContactName());
        connect(this, SIGNAL(valueChanged()), SIGNAL(detailChanged()));
    }
    DetailType detailType() const override
    {
        return QDeclarativeContactDetail::Name;
    }

    QString prefix() const {return detail().value(QContactName::FieldPrefix).toString();}
    QString firstName() const {return detail().value(QContactName::FieldFirstName).toString();}
    QString middleName() const {return detail().value(QContactName::FieldMiddleName).toString();}
    QString lastName() const {return detail().value(QContactName::FieldLastName).toString();}
    QString suffix() const {return detail().value(QContactName::FieldSuffix).toString();}

    void setPrefix(const QString& v)
    {
        if (!readOnly() && v != prefix()) {
            detail().setValue(QContactName::FieldPrefix, v);
            emit valueChanged();
        }
    }

    void setFirstName(const QString& v)
    {
        if (!readOnly() && v != firstName()) {
            detail().setValue(QContactName::FieldFirstName, v);
            emit valueChanged();
        }
    }
    void setMiddleName(const QString& v)
    {
        if (!readOnly() && v != middleName()) {
            detail().setValue(QContactName::FieldMiddleName, v);
            emit valueChanged();
        }
    }
    void setLastName(const QString& v)
    {
        if (!readOnly() && v != lastName()) {
            detail().setValue(QContactName::FieldLastName, v);
            emit valueChanged();
        }
    }
    void setSuffix(const QString& v)
    {
        if (!readOnly() && v != suffix()) {
            detail().setValue(QContactName::FieldSuffix, v);
            emit valueChanged();
        }
    }

signals:
    void valueChanged();
};

QT_END_NAMESPACE

QML_DECLARE_TYPE(QDeclarativeContactName)

#endif // QDECLARATIVECONTACTNAME_H
