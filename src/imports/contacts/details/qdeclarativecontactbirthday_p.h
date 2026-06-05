// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QDECLARATIVECONTACTBIRTHDAY_H
#define QDECLARATIVECONTACTBIRTHDAY_H

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

#include <QtContacts/qcontactbirthday.h>

#include "qdeclarativecontactdetail_p.h"

QTCONTACTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE

class  QDeclarativeContactBirthday : public QDeclarativeContactDetail
{
    Q_OBJECT

    Q_PROPERTY(QDateTime birthday READ birthday WRITE setBirthday NOTIFY valueChanged)
    Q_ENUMS(FieldType)
public:
    enum FieldType {
        Birthday = QContactBirthday::FieldBirthday
    };
    QDeclarativeContactBirthday(QObject* parent = nullptr)
        :QDeclarativeContactDetail(parent)
    {
        setDetail(QContactBirthday());
        connect(this, SIGNAL(valueChanged()), SIGNAL(detailChanged()));
    }

    DetailType detailType() const override
    {
        return QDeclarativeContactDetail::Birthday;
    }

    void setBirthday(const QDateTime& v)
    {
        if (!readOnly() && v != birthday()) {
            detail().setValue(QContactBirthday::FieldBirthday, v);
            emit valueChanged();
        }
    }
    QDateTime birthday() const {return detail().value<QDateTime>(QContactBirthday::FieldBirthday);}
signals:
    void valueChanged();
};

QT_END_NAMESPACE

QML_DECLARE_TYPE(QDeclarativeContactBirthday)

#endif // QDECLARATIVECONTACTBIRTHDAY_H
