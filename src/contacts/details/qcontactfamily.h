// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QCONTACTFAMILY_H
#define QCONTACTFAMILY_H

#include <QtContacts/qcontactdetail.h>

QT_BEGIN_NAMESPACE_CONTACTS

/* Leaf class */
class Q_CONTACTS_EXPORT QContactFamily : public QContactDetail
{
public:
#ifndef Q_QDOC
    Q_DECLARE_CUSTOM_CONTACT_DETAIL(QContactFamily)
#else
    static const DetailType Type;
#endif

    enum FamilyField {
        FieldSpouse = 0,
        FieldChildren
    };

    void setSpouse(const QString& spouseName);
    QString spouse() const;
    void setChildren(const QStringList& childrenNames);
    QStringList children() const;
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTFAMILY_H
