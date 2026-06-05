// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QCONTACTEXTENDEDDETAIL_H
#define QCONTACTEXTENDEDDETAIL_H

#include <QtContacts/qcontactdetail.h>

QT_BEGIN_NAMESPACE_CONTACTS

/* Leaf class */
class Q_CONTACTS_EXPORT QContactExtendedDetail : public QContactDetail
{
public:
#ifndef Q_QDOC
    Q_DECLARE_CUSTOM_CONTACT_DETAIL(QContactExtendedDetail)
#else
    static const DetailType Type;
#endif

    enum ExtendedDetailField {
        FieldName = 0,
        FieldData
    };

    void setName(const QString &_name);
    QString name() const;

    void setData(const QVariant &_data);
    QVariant data() const;
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTEXTENDEDDETAIL_H
