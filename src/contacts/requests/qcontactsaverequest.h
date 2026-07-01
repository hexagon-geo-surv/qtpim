// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QCONTACTSAVEREQUEST_H
#define QCONTACTSAVEREQUEST_H

#include <QtCore/qlist.h>
#include <QtCore/qmap.h>

#include <QtContacts/qcontact.h>
#include <QtContacts/qcontactabstractrequest.h>
#include <QtContacts/qcontactdetail.h>

QT_BEGIN_NAMESPACE_CONTACTS

class QContactSaveRequestPrivate;
class Q_CONTACTS_EXPORT QContactSaveRequest : public QContactAbstractRequest
{
    Q_OBJECT

public:
    QContactSaveRequest(QObject* parent = Q_NULLPTR);
    ~QContactSaveRequest();

    /* Selection */
    void setContact(const QContact& contact);
    void setContacts(const QList<QContact>& contacts);

    void setTypeMask(const QList<QContactDetail::DetailType> &typeMask);
    QList<QContactDetail::DetailType> typeMask() const;

    /* Results */
    QList<QContact> contacts() const;
    QMap<int, QContactManager::Error> errorMap() const;

private:
    Q_DISABLE_COPY(QContactSaveRequest)
    friend class QContactManagerEngine;
    Q_DECLARE_PRIVATE_D(d_ptr, QContactSaveRequest)
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTSAVEREQUEST_H
