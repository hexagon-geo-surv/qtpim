// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QCONTACTGENDER_H
#define QCONTACTGENDER_H

#include <QtContacts/qcontactdetail.h>

QT_BEGIN_NAMESPACE_CONTACTS

/* Leaf class */
class Q_CONTACTS_EXPORT QContactGender : public QContactDetail
{
public:
#ifndef Q_QDOC
    Q_DECLARE_CUSTOM_CONTACT_DETAIL(QContactGender)
#else
    static const DetailType Type;
#endif

    enum GenderField {
        FieldGender = 0
    };

    enum GenderType {
        GenderUnspecified = 0,
        GenderMale,
        GenderFemale
    };

    void setGender(GenderType _gender);
    GenderType gender() const;
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTGENDER_H
