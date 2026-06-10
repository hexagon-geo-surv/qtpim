// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QCONTACTEMAILADDRESS_H
#define QCONTACTEMAILADDRESS_H

#include <QtContacts/qcontactdetail.h>

QT_BEGIN_NAMESPACE_CONTACTS

class QContactFilter;

/* Leaf class */
class Q_CONTACTS_EXPORT QContactEmailAddress : public QContactDetail
{
public:
#ifndef Q_QDOC
    Q_DECLARE_CUSTOM_CONTACT_DETAIL(QContactEmailAddress)
#else
    static const DetailType Type;
#endif

    enum EmailAddressField {
        FieldEmailAddress = 0
    };

    void setEmailAddress(const QString& _emailAddress);
    QString emailAddress() const;

    // Convenience filter
    static QContactFilter match(const QString& emailAddress);
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTEMAILADDRESS_H
