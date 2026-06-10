// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QCONTACTFETCHREQUEST_H
#define QCONTACTFETCHREQUEST_H

#include <QtCore/qlist.h>

#include <QtContacts/qcontact.h>
#include <QtContacts/qcontactabstractrequest.h>
#include <QtContacts/qcontactsortorder.h>

QT_BEGIN_NAMESPACE_CONTACTS

class QContactFetchHint;
class QContactFilter;

class QContactFetchRequestPrivate;
class Q_CONTACTS_EXPORT QContactFetchRequest : public QContactAbstractRequest
{
    Q_OBJECT

public:
    QContactFetchRequest(QObject* parent = nullptr);
    ~QContactFetchRequest();

    /* Selection, restriction and sorting */
    void setFilter(const QContactFilter& filter);
    void setSorting(const QList<QContactSortOrder>& sorting);
    void setFetchHint(const QContactFetchHint& fetchHint);
    QContactFilter filter() const;
    QList<QContactSortOrder> sorting() const;
    QContactFetchHint fetchHint() const;

    /* Results */
    QList<QContact> contacts() const;

private:
    Q_DISABLE_COPY(QContactFetchRequest)
    friend class QContactManagerEngine;
    Q_DECLARE_PRIVATE_D(d_ptr, QContactFetchRequest)
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTFETCHREQUEST_H
