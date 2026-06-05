// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QCONTACTAVATAR_H
#define QCONTACTAVATAR_H

#include <QtCore/qurl.h>

#include <QtContacts/qcontactdetail.h>

QT_BEGIN_NAMESPACE_CONTACTS

/* Leaf class */
class Q_CONTACTS_EXPORT QContactAvatar : public QContactDetail
{
public:
#ifndef Q_QDOC
    Q_DECLARE_CUSTOM_CONTACT_DETAIL(QContactAvatar)
#else
    static const DetailType Type;
#endif

    enum AvatarField {
        FieldImageUrl = 0,
        FieldVideoUrl,
        FieldMetaData
    };

    void setImageUrl(const QUrl& _imageUrl);
    QUrl imageUrl() const;

    void setVideoUrl(const QUrl& _videoUrl);
    QUrl videoUrl() const;

    void setMetaData(const QString& _metaData);
    QString metaData() const;
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTAVATAR_H
