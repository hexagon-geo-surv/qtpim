// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QCONTACTCOLLECTIONSAVEREQUEST_H
#define QCONTACTCOLLECTIONSAVEREQUEST_H

#include <QtCore/qlist.h>
#include <QtCore/qmap.h>

#include <QtContacts/qcontactabstractrequest.h>
#include <QtContacts/qcontactcollection.h>

QT_BEGIN_NAMESPACE_CONTACTS

class QContactCollectionSaveRequestPrivate;

/* Leaf class */

class Q_CONTACTS_EXPORT QContactCollectionSaveRequest : public QContactAbstractRequest
{
    Q_OBJECT

public:
    QContactCollectionSaveRequest(QObject *parent = nullptr);
    ~QContactCollectionSaveRequest();

    void setCollection(const QContactCollection &collection);
    void setCollections(const QList<QContactCollection> &collections);
    QList<QContactCollection> collections() const;

    QMap<int, QContactManager::Error> errorMap() const;

private:
    Q_DISABLE_COPY(QContactCollectionSaveRequest)
    friend class QContactManagerEngine;
    Q_DECLARE_PRIVATE_D(d_ptr, QContactCollectionSaveRequest)
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTCOLLECTIONSAVEREQUEST_H
