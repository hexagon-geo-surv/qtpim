// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QDECLARATIVECONTACTSYNCTARGET_H
#define QDECLARATIVECONTACTSYNCTARGET_H

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

#include <QtContacts/qcontactsynctarget.h>

#include "qdeclarativecontactdetail_p.h"

QTCONTACTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE

class  QDeclarativeContactSyncTarget : public QDeclarativeContactDetail
{
    Q_OBJECT
    Q_PROPERTY(QString syncTarget READ syncTarget WRITE setSyncTarget NOTIFY valueChanged)
    Q_ENUMS(FieldType)
    Q_CLASSINFO("DefaultProperty", "syncTarget")
public:
    enum FieldType {
        SyncTarget = QContactSyncTarget::FieldSyncTarget
    };

    QDeclarativeContactSyncTarget(QObject* parent = nullptr)
        :QDeclarativeContactDetail(parent)
    {
        setDetail(QContactSyncTarget());
        connect(this, SIGNAL(valueChanged()), SIGNAL(detailChanged()));
    }
    DetailType detailType() const override
    {
        return QDeclarativeContactDetail::SyncTarget;
    }

    void setSyncTarget(const QString& v)
    {
        if (!readOnly() && v != syncTarget()) {
            detail().setValue(QContactSyncTarget::FieldSyncTarget, v);
            emit valueChanged();
        }
    }
    QString syncTarget() const {return detail().value(QContactSyncTarget::FieldSyncTarget).toString();}
signals:
    void valueChanged();

};

QT_END_NAMESPACE

QML_DECLARE_TYPE(QDeclarativeContactSyncTarget)

#endif // QDECLARATIVECONTACTSYNCTARGET_H
