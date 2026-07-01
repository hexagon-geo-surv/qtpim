// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QDECLARATIVECONTACTNICKNAME_H
#define QDECLARATIVECONTACTNICKNAME_H

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

#include <QtContacts/qcontactnickname.h>

#include "qdeclarativecontactdetail_p.h"

QTCONTACTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE

class QDeclarativeContactNickname : public QDeclarativeContactDetail
{
    Q_OBJECT
    Q_PROPERTY(QString nickname READ nickname WRITE setNickname NOTIFY valueChanged)
    Q_ENUMS(FieldType)
    Q_CLASSINFO("DefaultProperty", "nickname")
public:
    enum FieldType {
        NickName = QContactNickname::FieldNickname
    };

    QDeclarativeContactNickname(QObject* parent = Q_NULLPTR)
        :QDeclarativeContactDetail(parent)
    {
        setDetail(QContactNickname());
        connect(this, SIGNAL(valueChanged()), SIGNAL(detailChanged()));
    }
    DetailType detailType() const override
    {
        return QDeclarativeContactDetail::NickName;
    }

    void setNickname(const QString& v)
    {
        if (!readOnly() && v != nickname()) {
            detail().setValue(QContactNickname::FieldNickname, v);
            emit valueChanged();
        }
    }
    QString nickname() const {return detail().value(QContactNickname::FieldNickname).toString();}
signals:
    void valueChanged();
};

QT_END_NAMESPACE

QML_DECLARE_TYPE(QDeclarativeContactNickname)

#endif // QDECLARATIVECONTACTNICKNAME_H
