// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QCONTACTTYPE_H
#define QCONTACTTYPE_H

#include <QtContacts/qcontactdetail.h>

QT_BEGIN_NAMESPACE_CONTACTS

/* Leaf class */
class Q_CONTACTS_EXPORT QContactType : public QContactDetail
{
public:
#ifndef Q_QDOC
    Q_DECLARE_CUSTOM_CONTACT_DETAIL(QContactType)
#else
    static const DetailType Type;
#endif

    enum TypeField {
        FieldType = 0
    };
    enum TypeValues {
        TypeContact = 0,
        TypeGroup,
        TypeFacet
    };

    void setType(TypeValues newType);
    TypeValues type() const;
};

QT_END_NAMESPACE_CONTACTS

Q_DECLARE_METATYPE(QTCONTACTS_PREPEND_NAMESPACE(QContactType::TypeValues))

#endif // QCONTACTTYPE_H
