// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QCONTACTIDFETCHREQUEST_H
#define QCONTACTIDFETCHREQUEST_H

#include <QtCore/qlist.h>

#include <QtContacts/qcontactabstractrequest.h>
#include <QtContacts/qcontactid.h>
#include <QtContacts/qcontactsortorder.h>

QT_BEGIN_NAMESPACE_CONTACTS

class QContactFilter;

class QContactIdFetchRequestPrivate;
class Q_CONTACTS_EXPORT QContactIdFetchRequest : public QContactAbstractRequest
{
    Q_OBJECT

public:
    QContactIdFetchRequest(QObject* parent = nullptr);
    ~QContactIdFetchRequest();

    /* Selection, restriction and sorting */
    void setFilter(const QContactFilter& filter);
    void setSorting(const QList<QContactSortOrder>& sorting);
    QContactFilter filter() const;
    QList<QContactSortOrder> sorting() const;

    /* Results */
    QList<QContactId> ids() const;

private:
    Q_DISABLE_COPY(QContactIdFetchRequest)
    friend class QContactManagerEngine;
    Q_DECLARE_PRIVATE_D(d_ptr, QContactIdFetchRequest)
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTIDFETCHREQUEST_H
