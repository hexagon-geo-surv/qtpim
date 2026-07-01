// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QCONTACTREMOVEREQUEST_H
#define QCONTACTREMOVEREQUEST_H

#include <QtCore/qlist.h>
#include <QtCore/qmap.h>

#include <QtContacts/qcontactabstractrequest.h>
#include <QtContacts/qcontactid.h>

QT_BEGIN_NAMESPACE_CONTACTS

class QContactRemoveRequestPrivate;
class Q_CONTACTS_EXPORT QContactRemoveRequest : public QContactAbstractRequest
{
    Q_OBJECT

public:
    QContactRemoveRequest(QObject* parent = Q_NULLPTR);
    ~QContactRemoveRequest();

    /* Selection */
    void setContactId(const QContactId& contactId);
    void setContactIds(const QList<QContactId>& contactIds);
    QList<QContactId> contactIds() const;

    /* Results */
    QMap<int, QContactManager::Error> errorMap() const;

private:
    Q_DISABLE_COPY(QContactRemoveRequest)
    friend class QContactManagerEngine;
    Q_DECLARE_PRIVATE_D(d_ptr, QContactRemoveRequest)
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTREMOVEREQUEST_H
