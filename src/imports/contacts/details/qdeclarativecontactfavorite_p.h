// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QDECLARATIVECONTACTFAVORITE_H
#define QDECLARATIVECONTACTFAVORITE_H

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

#include <QtContacts/qcontactfavorite.h>

#include "qdeclarativecontactdetail_p.h"

QTCONTACTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE

class QDeclarativeContactFavorite : public QDeclarativeContactDetail
{
    Q_OBJECT
    Q_PROPERTY(bool favorite READ isFavorite WRITE setFavorite NOTIFY valueChanged)
    Q_PROPERTY(int index READ index WRITE setIndex NOTIFY valueChanged)
    Q_ENUMS(FieldType)
    Q_CLASSINFO("DefaultProperty", "index")
public:
    enum FieldType {
        Favorite = QContactFavorite::FieldFavorite,
        Index = QContactFavorite::FieldIndex
    };
    QDeclarativeContactFavorite(QObject* parent = Q_NULLPTR)
        :QDeclarativeContactDetail(parent)
    {
        setDetail(QContactFavorite());
        connect(this, SIGNAL(valueChanged()), SIGNAL(detailChanged()));
    }
    DetailType detailType() const override
    {
        return QDeclarativeContactDetail::Favorite;
    }

    void setFavorite(bool v)
    {
        if (!readOnly() && v != isFavorite()) {
            detail().setValue(QContactFavorite::FieldFavorite, v);
            emit valueChanged();
        }
    }
    bool isFavorite() const {return detail().value(QContactFavorite::FieldFavorite).toBool();}
    void setIndex(int v)
    {
        if (!readOnly() && v != index()) {
            detail().setValue(QContactFavorite::FieldIndex, v);
            emit valueChanged();
        }
    }
    int index() const {return detail().value(QContactFavorite::FieldIndex).toInt();}
signals:
    void valueChanged();
};

QT_END_NAMESPACE

QML_DECLARE_TYPE(QDeclarativeContactFavorite)

#endif // QDECLARATIVECONTACTFAVORITE_H
