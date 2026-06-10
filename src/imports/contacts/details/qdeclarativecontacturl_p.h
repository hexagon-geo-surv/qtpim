// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QDECLARATIVECONTACTURL_H
#define QDECLARATIVECONTACTURL_H

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

#include <QtContacts/qcontacturl.h>

#include "qdeclarativecontactdetail_p.h"

QTCONTACTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE

class QDeclarativeContactUrl : public QDeclarativeContactDetail
{
    Q_OBJECT

    Q_PROPERTY(QString url READ url WRITE setUrl NOTIFY valueChanged)
    Q_PROPERTY(UrlSubType subType READ subType WRITE setSubType NOTIFY valueChanged)

    Q_ENUMS(FieldType)
    Q_ENUMS(UrlSubType)
public:
    enum FieldType {
        Url = QContactUrl::FieldUrl,
        SubType = QContactUrl::FieldSubType
    };

    enum UrlSubType {
        Unknown = 0,
        HomePage = QContactUrl::SubTypeHomePage,
        Blog = QContactUrl::SubTypeBlog,
        Favourite = QContactUrl::SubTypeFavourite
    };

    QDeclarativeContactUrl(QObject* parent = nullptr)
        :QDeclarativeContactDetail(parent)
    {
        setDetail(QContactUrl());
        connect(this, SIGNAL(valueChanged()), SIGNAL(detailChanged()));
    }
    DetailType detailType() const override
    {
        return QDeclarativeContactDetail::Url;
    }

    void setUrl(const QString& v)
    {
        if (!readOnly() && v != url()) {
            detail().setValue(QContactUrl::FieldUrl, v);
            emit valueChanged();
        }
    }
    QString url() const {return detail().value(QContactUrl::FieldUrl).toString();}

    void setSubType(const UrlSubType& v)
    {
        switch (v) {
        case HomePage:
        case Blog:
        case Favourite:
            if (v != detail().value(QContactUrl::FieldSubType)) {
                detail().setValue(QContactUrl::FieldSubType, v);
                emit valueChanged();
            }
            break;
        default:
            if (detail().value(QContactUrl::FieldSubType) != Unknown) {
                detail().setValue(QContactUrl::FieldSubType, Unknown);
                emit valueChanged();
            }
        }
    }

    UrlSubType subType() const
    {
        return static_cast<UrlSubType>(detail().value(QContactUrl::FieldSubType).toInt());
    }
signals:
    void valueChanged();
};

QT_END_NAMESPACE

QML_DECLARE_TYPE(QDeclarativeContactUrl)

#endif // QDECLARATIVECONTACTURL_H
