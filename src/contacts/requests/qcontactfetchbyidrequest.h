// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QCONTACTFETCHBYIDREQUEST_H
#define QCONTACTFETCHBYIDREQUEST_H

#include <QtCore/qlist.h>
#include <QtCore/qmap.h>

#include <QtContacts/qcontact.h>
#include <QtContacts/qcontactabstractrequest.h>
#include <QtContacts/qcontactid.h>

QT_BEGIN_NAMESPACE_CONTACTS

class QContactFetchHint;

class QContactFetchByIdRequestPrivate;
class Q_CONTACTS_EXPORT QContactFetchByIdRequest : public QContactAbstractRequest
{
    Q_OBJECT

public:
    QContactFetchByIdRequest(QObject* parent = nullptr);
    ~QContactFetchByIdRequest();

    /* Selection, restriction and sorting */
    void setIds(const QList<QContactId>& ids);
    void setFetchHint(const QContactFetchHint& fetchHint);
    QList<QContactId> contactIds() const;
    QContactFetchHint fetchHint() const;

    /* Results */
    QList<QContact> contacts() const;
    QMap<int, QContactManager::Error> errorMap() const;

private:
    Q_DISABLE_COPY(QContactFetchByIdRequest)
    friend class QContactManagerEngine;
    Q_DECLARE_PRIVATE_D(d_ptr, QContactFetchByIdRequest)
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTFETCHBYIDREQUEST_H
