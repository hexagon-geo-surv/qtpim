// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QCONTACTNICKNAME_H
#define QCONTACTNICKNAME_H

#include <QtContacts/qcontactdetail.h>

QT_BEGIN_NAMESPACE_CONTACTS

/* Leaf class */
class Q_CONTACTS_EXPORT QContactNickname : public QContactDetail
{
public:
#ifndef Q_QDOC
    Q_DECLARE_CUSTOM_CONTACT_DETAIL(QContactNickname)
#else
    static const DetailType Type;
#endif

    enum NicknameField {
        FieldNickname = 0
    };

    void setNickname(const QString& _nickname);
    QString nickname() const;
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTNICKNAME_H
