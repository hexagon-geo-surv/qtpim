// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QCONTACTTIMESTAMP_H
#define QCONTACTTIMESTAMP_H

#include <QtCore/qdatetime.h>

#include <QtContacts/qcontactdetail.h>

QT_BEGIN_NAMESPACE_CONTACTS

/* Leaf class */
class Q_CONTACTS_EXPORT QContactTimestamp : public QContactDetail
{
public:
#ifndef Q_QDOC
    Q_DECLARE_CUSTOM_CONTACT_DETAIL(QContactTimestamp)
#else
    static const DetailType Type;
#endif

    enum TimestampField {
        FieldModificationTimestamp = 0,
        FieldCreationTimestamp,
        FieldDeletionTimestamp
    };

    void setLastModified(const QDateTime& timestamp);
    QDateTime lastModified() const;
    void setCreated(const QDateTime& timestamp);
    QDateTime created() const;
    void setDeleted(const QDateTime& timestamp);
    QDateTime deleted() const;
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTTIMESTAMP_H
