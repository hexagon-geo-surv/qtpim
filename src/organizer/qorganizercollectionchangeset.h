// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QORGANIZERCOLLECTIONCHANGESET_H
#define QORGANIZERCOLLECTIONCHANGESET_H

#include <QtCore/qlist.h>
#include <QtCore/qset.h>
#include <QtCore/qshareddata.h>

#include <utility>

#include <QtOrganizer/qorganizercollectionid.h>
#include <QtOrganizer/qorganizermanager.h>

QT_BEGIN_NAMESPACE_ORGANIZER

class QOrganizerManagerEngine;

class QOrganizerCollectionChangeSetData;
class Q_ORGANIZER_EXPORT QOrganizerCollectionChangeSet
{
public:
    QOrganizerCollectionChangeSet();
    QOrganizerCollectionChangeSet(const QOrganizerCollectionChangeSet &other);
    ~QOrganizerCollectionChangeSet();

    QOrganizerCollectionChangeSet &operator=(const QOrganizerCollectionChangeSet &other);

    void setDataChanged(bool dataChanged);
    bool dataChanged() const;

    QSet<QOrganizerCollectionId> addedCollections() const;
    void insertAddedCollection(const QOrganizerCollectionId &collectionId);
    void insertAddedCollections(const QList<QOrganizerCollectionId> &collectionIds);
    void clearAddedCollections();

    QSet<QOrganizerCollectionId> changedCollections() const;
    void insertChangedCollection(const QOrganizerCollectionId &collectionId);
    void insertChangedCollections(const QList<QOrganizerCollectionId> &collectionIds);
    void clearChangedCollections();

    QSet<QOrganizerCollectionId> removedCollections() const;
    void insertRemovedCollection(const QOrganizerCollectionId &collectionId);
    void insertRemovedCollections(const QList<QOrganizerCollectionId> &collectionIds);
    void clearRemovedCollections();

    QList<std::pair<QOrganizerCollectionId, QOrganizerManager::Operation>> modifiedCollections() const;
    void clearModifiedCollections();

    void clearAll();

    void emitSignals(QOrganizerManagerEngine *engine) const;

private:
    QSharedDataPointer<QOrganizerCollectionChangeSetData> d;
};

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERCOLLECTIONCHANGESET_H
