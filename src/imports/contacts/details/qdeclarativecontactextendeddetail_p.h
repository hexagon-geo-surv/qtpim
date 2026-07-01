// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QDECLARATIVECONTACTEXTENDEDDETAIL_P_H
#define QDECLARATIVECONTACTEXTENDEDDETAIL_P_H

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

#include <QtContacts/qcontactextendeddetail.h>

#include "qdeclarativecontactdetail_p.h"

QTCONTACTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE

class QDeclarativeContactExtendedDetail : public QDeclarativeContactDetail
{
    Q_OBJECT

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY valueChanged)
    Q_PROPERTY(QVariant data READ data WRITE setData NOTIFY valueChanged)
    Q_ENUMS(FieldType)
public:
    enum FieldType {
        Name = QContactExtendedDetail::FieldName,
        Data = QContactExtendedDetail::FieldData
    };

    QDeclarativeContactExtendedDetail (QObject *parent = Q_NULLPTR)
        :QDeclarativeContactDetail(parent)
    {
        setDetail(QContactExtendedDetail());
        connect(this, SIGNAL(valueChanged()), SIGNAL(detailChanged()));
    }

    DetailType detailType() const override
    {
        return QDeclarativeContactDetail::ExtendedDetail;
    }

    void setName(const QString &newDetailName)
    {
        if (newDetailName != name() && !readOnly()) {
            detail().setValue(QContactExtendedDetail::FieldName, newDetailName);
            emit valueChanged();
        }
    }

    QString name() const
    {
        return detail().value(QContactExtendedDetail::FieldName).toString();
    }

    void setData(const QVariant &newData);

    QVariant data() const
    {
        return detail().value(QContactExtendedDetail::FieldData);
    }

signals:
    void valueChanged();
};

QT_END_NAMESPACE

QML_DECLARE_TYPE(QDeclarativeContactExtendedDetail)

#endif // QDECLARATIVECONTACTEXTENDEDDETAIL_P_H
