// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QCONTACTGUID_H
#define QCONTACTGUID_H

#include <QtContacts/qcontactdetail.h>

QT_BEGIN_NAMESPACE_CONTACTS

/* Leaf class */
class Q_CONTACTS_EXPORT QContactGuid : public QContactDetail
{
public:
#ifndef Q_QDOC
    Q_DECLARE_CUSTOM_CONTACT_DETAIL(QContactGuid)
#else
    static const DetailType Type;
#endif

    enum GuidField {
        FieldGuid = 0
    };

    void setGuid(const QString& _guid);
    QString guid() const;
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTGUID_H
