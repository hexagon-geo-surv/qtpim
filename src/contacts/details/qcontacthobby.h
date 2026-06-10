// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QCONTACTHOBBY_H
#define QCONTACTHOBBY_H

#include <QtContacts/qcontactdetail.h>

QT_BEGIN_NAMESPACE_CONTACTS

/* Leaf class */
class Q_CONTACTS_EXPORT QContactHobby : public QContactDetail
{
public:
#ifndef Q_QDOC
    Q_DECLARE_CUSTOM_CONTACT_DETAIL(QContactHobby)
#else
    static const DetailType Type;
#endif

    enum HobbyField {
        FieldHobby = 0
    };

    void setHobby(const QString& _hobby);
    QString hobby() const;
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTHOBBY_H
