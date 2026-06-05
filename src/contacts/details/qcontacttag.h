// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QCONTACTTAG_H
#define QCONTACTTAG_H

#include <QtContacts/qcontactdetail.h>

QT_BEGIN_NAMESPACE_CONTACTS

class QContactFilter;

/* Leaf class */
class Q_CONTACTS_EXPORT QContactTag : public QContactDetail
{
public:
#ifndef Q_QDOC
    Q_DECLARE_CUSTOM_CONTACT_DETAIL(QContactTag)
#else
    static const DetailType Type;
#endif

    enum TagField {
        FieldTag = 0
    };

    void setTag(const QString& _tag);
    QString tag() const;

    // Convenience filter
    static QContactFilter match(const QString& subString);
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTTAG_H
