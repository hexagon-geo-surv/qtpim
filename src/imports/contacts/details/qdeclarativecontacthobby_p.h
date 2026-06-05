// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QDECLARATIVECONTACTHOBBY_H
#define QDECLARATIVECONTACTHOBBY_H

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

#include <QtContacts/qcontacthobby.h>

#include "qdeclarativecontactdetail_p.h"

QTCONTACTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE

class QDeclarativeContactHobby : public QDeclarativeContactDetail
{
    Q_OBJECT
    Q_PROPERTY(QString hobby READ hobby WRITE setHobby NOTIFY valueChanged)
    Q_ENUMS(FieldType)
    Q_CLASSINFO("DefaultProperty", "hobby")
public:
    enum FieldType {
        Hobby = QContactHobby::FieldHobby
    };
    QDeclarativeContactHobby(QObject* parent = nullptr)
        :QDeclarativeContactDetail(parent)
    {
        setDetail(QContactHobby());
        connect(this, SIGNAL(valueChanged()), SIGNAL(detailChanged()));
    }

    DetailType detailType() const
    {
        return QDeclarativeContactDetail::Hobby;
    }

    void setHobby(const QString& v)
    {
        if (!readOnly() && v != hobby()) {
            detail().setValue(QContactHobby::FieldHobby, v);
            emit valueChanged();
        }
    }
    QString hobby() const {return detail().value(QContactHobby::FieldHobby).toString();}
signals:
    void valueChanged();
};

QT_END_NAMESPACE

QML_DECLARE_TYPE(QDeclarativeContactHobby)

#endif // QDECLARATIVECONTACTHOBBY_H
