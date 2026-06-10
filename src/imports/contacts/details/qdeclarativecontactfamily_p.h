// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QDECLARATIVECONTACTFAMILY_H
#define QDECLARATIVECONTACTFAMILY_H

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

#include <QtContacts/qcontactfamily.h>

#include "qdeclarativecontactdetail_p.h"

QTCONTACTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE

class QDeclarativeContactFamily : public QDeclarativeContactDetail
{
    Q_OBJECT
    Q_PROPERTY(QString spouse READ spouse WRITE setSpouse NOTIFY valueChanged)
    Q_PROPERTY(QStringList children READ children WRITE setChildren NOTIFY valueChanged)
    Q_ENUMS(FieldType)
public:
    enum FieldType {
        Spouse = QContactFamily::FieldSpouse,
        Children = QContactFamily::FieldChildren
    };
    QDeclarativeContactFamily(QObject* parent = Q_NULLPTR)
        :QDeclarativeContactDetail(parent)
    {
        setDetail(QContactFamily());
        connect(this, SIGNAL(valueChanged()), SIGNAL(detailChanged()));
    }
    DetailType detailType() const override
    {
        return QDeclarativeContactDetail::Family;
    }

    void setSpouse(const QString& v)
    {
        if (!readOnly() && v != spouse()) {
            detail().setValue(QContactFamily::FieldSpouse, v);
            emit valueChanged();
        }
    }
    QString spouse() const {return detail().value(QContactFamily::FieldSpouse).toString();}
    void setChildren(const QStringList& v)
    {
        if (!readOnly() && QSet<QString>(v.cbegin(), v.cend()) != QSet<QString>(children().cbegin(), children().cend())) {
            detail().setValue(QContactFamily::FieldChildren, v);
            emit valueChanged();
        }
    }
    QStringList children() const {return detail().value<QStringList>(QContactFamily::FieldChildren);}
signals:
    void valueChanged();
};

QT_END_NAMESPACE

QML_DECLARE_TYPE(QDeclarativeContactFamily)

#endif // QDECLARATIVECONTACTFAMILY_H
