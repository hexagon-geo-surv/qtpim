// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QCONTACTURL_H
#define QCONTACTURL_H

#include <QtCore/qurl.h>

#include <QtContacts/qcontactdetail.h>

QT_BEGIN_NAMESPACE_CONTACTS

/* Leaf class */
class Q_CONTACTS_EXPORT QContactUrl : public QContactDetail
{
public:
#ifndef Q_QDOC
    Q_DECLARE_CUSTOM_CONTACT_DETAIL(QContactUrl)
#else
    static const DetailType Type;
#endif

    enum UrlField {
        FieldUrl = 0,
        FieldSubType
    };
    enum SubType {
        SubTypeHomePage = 0,
        SubTypeBlog,
        SubTypeFavourite
    };

    void setUrl(const QUrl& _url);
    void setUrl(const QString& _url);
    QString url() const;

    void setSubType(QContactUrl::SubType _subType);
    QContactUrl::SubType subType() const;
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTURL_H
