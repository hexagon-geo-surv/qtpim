// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QDECLARATIVECONTACTGUID_H
#define QDECLARATIVECONTACTGUID_H

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

#include <QtContacts/qcontactguid.h>

#include "qdeclarativecontactdetail_p.h"

QTCONTACTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE

class QDeclarativeContactGuid : public QDeclarativeContactDetail
{
    Q_OBJECT
    Q_PROPERTY(QString guid READ guid WRITE setGuid NOTIFY valueChanged)
    Q_ENUMS(FieldType)
    Q_CLASSINFO("DefaultProperty", "guid")
public:
    enum FieldType {
        Guid = QContactGuid::FieldGuid
    };
    QDeclarativeContactGuid(QObject* parent = nullptr)
        :QDeclarativeContactDetail(parent)
    {
        setDetail(QContactGuid());
        connect(this, SIGNAL(valueChanged()), SIGNAL(detailChanged()));
    }

    DetailType detailType() const
    {
        return QDeclarativeContactDetail::Guid;
    }

    void setGuid(const QString& v)
    {
        if (!readOnly() && v != guid()) {
            detail().setValue(QContactGuid::FieldGuid, v);
            emit valueChanged();
        }
    }
    QString guid() const {return detail().value(QContactGuid::FieldGuid).toString();}
signals:
    void valueChanged();
};

QT_END_NAMESPACE

QML_DECLARE_TYPE(QDeclarativeContactGuid)

#endif // QDECLARATIVECONTACTGUID_H
