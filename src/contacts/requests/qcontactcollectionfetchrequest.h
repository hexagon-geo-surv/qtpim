// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QCONTACTCOLLECTIONFETCHREQUEST_H
#define QCONTACTCOLLECTIONFETCHREQUEST_H

#include <QtCore/qlist.h>

#include <QtContacts/qcontactabstractrequest.h>
#include <QtContacts/qcontactcollection.h>

QT_BEGIN_NAMESPACE_CONTACTS

class QContactCollectionFetchRequestPrivate;

/* Leaf class */

class Q_CONTACTS_EXPORT QContactCollectionFetchRequest : public QContactAbstractRequest
{
    Q_OBJECT

public:
    QContactCollectionFetchRequest(QObject *parent = nullptr);
    ~QContactCollectionFetchRequest();

    QList<QContactCollection> collections() const;

private:
    Q_DISABLE_COPY(QContactCollectionFetchRequest)
    friend class QContactManagerEngine;
    Q_DECLARE_PRIVATE_D(d_ptr, QContactCollectionFetchRequest)
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTCOLLECTIONFETCHREQUEST_H
