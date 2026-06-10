// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QCONTACTSYNCTARGET_H
#define QCONTACTSYNCTARGET_H

#include <QtContacts/qcontactdetail.h>

QT_BEGIN_NAMESPACE_CONTACTS

/* Leaf class */
class Q_CONTACTS_EXPORT QContactSyncTarget : public QContactDetail
{
public:
#ifndef Q_QDOC
    Q_DECLARE_CUSTOM_CONTACT_DETAIL(QContactSyncTarget)
#else
    static const DetailType Type;
#endif

    enum SyncTargetField {
        FieldSyncTarget = 0
    };

    void setSyncTarget(const QString& _syncTarget);
    QString syncTarget() const;
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTSYNCTARGET_H
