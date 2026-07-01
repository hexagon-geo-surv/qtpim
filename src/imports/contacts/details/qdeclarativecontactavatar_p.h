// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QDECLARATIVECONTACTAVATAR_H
#define QDECLARATIVECONTACTAVATAR_H

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

#include <QtContacts/qcontactavatar.h>
#include <QtCore/qurl.h>

#include "qdeclarativecontactdetail_p.h"

QTCONTACTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE

class  QDeclarativeContactAvatar : public QDeclarativeContactDetail
{
    Q_OBJECT
    Q_PROPERTY(QUrl imageUrl READ imageUrl WRITE setImageUrl NOTIFY valueChanged)
    Q_PROPERTY(QUrl videoUrl READ videoUrl WRITE setVideoUrl NOTIFY valueChanged)
    Q_ENUMS(FieldType)
public:
    enum FieldType {
        ImageUrl = QContactAvatar::FieldImageUrl,
        VideoUrl = QContactAvatar::FieldVideoUrl
    };
    QDeclarativeContactAvatar(QObject* parent = Q_NULLPTR)
        :QDeclarativeContactDetail(parent)
    {
        setDetail(QContactAvatar());
        connect(this, SIGNAL(valueChanged()), SIGNAL(detailChanged()));
    }
    void setImageUrl(const QUrl& v)
    {
        if (!readOnly() && v != imageUrl()) {
            detail().setValue(QContactAvatar::FieldImageUrl, v);
            emit valueChanged();
        }
    }
    QUrl imageUrl() const {return detail().value<QUrl>(QContactAvatar::FieldImageUrl);}

    void setVideoUrl(const QUrl& v)
    {
        if (!readOnly() && v != videoUrl()) {
            detail().setValue(QContactAvatar::FieldVideoUrl, v);
            emit valueChanged();
        }
    }
    QUrl videoUrl() const {return detail().value<QUrl>(QContactAvatar::FieldVideoUrl);}

    DetailType detailType() const override
    {
        return QDeclarativeContactDetail::Avatar;
    }

signals:
    void valueChanged();

};

QT_END_NAMESPACE

QML_DECLARE_TYPE(QDeclarativeContactAvatar)

#endif // QDECLARATIVECONTACTAVATAR_H
