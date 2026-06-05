// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QCONTACTCOLLECTIONCHANGESET_H
#define QCONTACTCOLLECTIONCHANGESET_H

#include <QtCore/qlist.h>
#include <QtCore/qset.h>
#include <QtCore/qshareddata.h>

#include <utility>

#include <QtContacts/qcontactcollectionid.h>
#include <QtContacts/qcontactmanager.h>

QT_BEGIN_NAMESPACE_CONTACTS

class QContactManagerEngine;

class QContactCollectionChangeSetData;
class Q_CONTACTS_EXPORT QContactCollectionChangeSet
{
public:
    QContactCollectionChangeSet();
    QContactCollectionChangeSet(const QContactCollectionChangeSet &other);
    ~QContactCollectionChangeSet();

    QContactCollectionChangeSet &operator=(const QContactCollectionChangeSet &other);

    void setDataChanged(bool dataChanged);
    bool dataChanged() const;

    QSet<QContactCollectionId> addedCollections() const;
    void insertAddedCollection(const QContactCollectionId &collectionId);
    void insertAddedCollections(const QList<QContactCollectionId> &collectionIds);
    void clearAddedCollections();

    QSet<QContactCollectionId> changedCollections() const;
    void insertChangedCollection(const QContactCollectionId &collectionId);
    void insertChangedCollections(const QList<QContactCollectionId> &collectionIds);
    void clearChangedCollections();

    QSet<QContactCollectionId> removedCollections() const;
    void insertRemovedCollection(const QContactCollectionId &collectionId);
    void insertRemovedCollections(const QList<QContactCollectionId> &collectionIds);
    void clearRemovedCollections();

    QList<std::pair<QContactCollectionId, QContactManager::Operation> > modifiedCollections() const;
    void clearModifiedCollections();

    void clearAll();

    void emitSignals(QContactManagerEngine *engine) const;

private:
    QSharedDataPointer<QContactCollectionChangeSetData> d;
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTCOLLECTIONCHANGESET_H
