// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QDECLARATIVECONTACTTIMESTAMP_H
#define QDECLARATIVECONTACTTIMESTAMP_H

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

#include <QtContacts/qcontacttimestamp.h>

#include "qdeclarativecontactdetail_p.h"

QTCONTACTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE

class QDeclarativeContactTimestamp : public QDeclarativeContactDetail
{
    Q_OBJECT
    Q_PROPERTY(QDateTime lastModified READ lastModified WRITE setLastModified NOTIFY valueChanged)
    Q_PROPERTY(QDateTime created READ created WRITE setCreated NOTIFY valueChanged)
    Q_ENUMS(FieldType)
    Q_CLASSINFO("DefaultProperty", "lastModified")
public:
    enum FieldType {
        LastModified = QContactTimestamp::FieldModificationTimestamp,
        Created = QContactTimestamp::FieldCreationTimestamp
    };

    DetailType detailType() const override
    {
        return QDeclarativeContactDetail::Timestamp;
    }

    QDeclarativeContactTimestamp(QObject* parent = Q_NULLPTR)
        :QDeclarativeContactDetail(parent)
    {
        setDetail(QContactTimestamp());
        connect(this, SIGNAL(valueChanged()), SIGNAL(detailChanged()));
    }
    void setLastModified(const QDateTime& v)
    {
        if (!readOnly() && v != lastModified()) {
            detail().setValue(QContactTimestamp::FieldModificationTimestamp, v);
            emit valueChanged();
        }
    }
    QDateTime lastModified() const {return detail().value<QDateTime>(QContactTimestamp::FieldModificationTimestamp);}
    void setCreated(const QDateTime& v)
    {
        if (!readOnly() && v != created()) {
            detail().setValue(QContactTimestamp::FieldCreationTimestamp, v);
            emit valueChanged();
        }
    }
    QDateTime created() const {return detail().value<QDateTime>(QContactTimestamp::FieldCreationTimestamp);}
signals:
    void valueChanged();
};

QT_END_NAMESPACE

QML_DECLARE_TYPE(QDeclarativeContactTimestamp)

#endif // QDECLARATIVECONTACTTIMESTAMP_H
