// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QDECLARATIVECONTACTGENDER_H
#define QDECLARATIVECONTACTGENDER_H

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

#include <QtContacts/qcontactgender.h>

#include "qdeclarativecontactdetail_p.h"

QTCONTACTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE

class QDeclarativeContactGender : public QDeclarativeContactDetail
{
    Q_OBJECT
    Q_PROPERTY(GenderType gender READ gender WRITE setGender NOTIFY valueChanged)
    Q_ENUMS(FieldType)
    Q_ENUMS(GenderType)
    Q_CLASSINFO("DefaultProperty", "gender")
public:
    enum FieldType {
        Gender = QContactGender::FieldGender
    };

    enum GenderType {
        Male = QContactGender::GenderMale,
        Female = QContactGender::GenderFemale,
        Unspecified = QContactGender::GenderUnspecified
    };

    QDeclarativeContactGender(QObject* parent = nullptr)
        :QDeclarativeContactDetail(parent)
    {
        setDetail(QContactGender());
        connect(this, SIGNAL(valueChanged()), SIGNAL(detailChanged()));
    }
    DetailType detailType() const
    {
        return QDeclarativeContactDetail::Gender;
    }

    void setGender(const GenderType v)
    {
        if (!readOnly() && v != gender()) {
            switch (v) {
            case Male:
            case Female:
                detail().setValue(QContactGender::FieldGender, v);
                break;
            default:
                detail().setValue(QContactGender::FieldGender, Unspecified);
            }
            emit valueChanged();
            }
        }

    GenderType gender() const
    {
        if (detail().value(QContactGender::FieldGender) == QContactGender::GenderMale) {
            return Male;
        }
        return Female;
    }
signals:
    void valueChanged();
};

QT_END_NAMESPACE

QML_DECLARE_TYPE(QDeclarativeContactGender)

#endif // QDECLARATIVECONTACTGENDER_H
