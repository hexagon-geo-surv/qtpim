// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QCONTACTCOLLECTIONREMOVEREQUEST_H
#define QCONTACTCOLLECTIONREMOVEREQUEST_H

#include <QtCore/qlist.h>
#include <QtCore/qmap.h>

#include <QtContacts/qcontactabstractrequest.h>
#include <QtContacts/qcontactcollectionid.h>

QT_BEGIN_NAMESPACE_CONTACTS

class QContactCollectionRemoveRequestPrivate;

/* Leaf class */

class Q_CONTACTS_EXPORT QContactCollectionRemoveRequest : public QContactAbstractRequest
{
    Q_OBJECT

public:
    QContactCollectionRemoveRequest(QObject *parent = nullptr);
    ~QContactCollectionRemoveRequest();

    void setCollectionId(const QContactCollectionId &collectionId);
    void setCollectionIds(const QList<QContactCollectionId> &collectionIds);
    QList<QContactCollectionId> collectionIds() const;

    QMap<int, QContactManager::Error> errorMap() const;

private:
    Q_DISABLE_COPY(QContactCollectionRemoveRequest)
    friend class QtContactManagerEngine;
    Q_DECLARE_PRIVATE_D(d_ptr, QContactCollectionRemoveRequest)
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTCOLLECTIONREMOVEREQUEST_H
