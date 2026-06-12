// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QORGANIZERITEMCHANGESET_H
#define QORGANIZERITEMCHANGESET_H

#include <QtCore/qlist.h>
#include <QtCore/qset.h>
#include <QtCore/qshareddata.h>

#include <utility>

#include <QtOrganizer/qorganizeritemdetail.h>
#include <QtOrganizer/qorganizeritemid.h>
#include <QtOrganizer/qorganizermanager.h>

QT_BEGIN_NAMESPACE_ORGANIZER

class QOrganizerManagerEngine;

class QOrganizerItemChangeSetPrivate;
class Q_ORGANIZER_EXPORT QOrganizerItemChangeSet
{
public:
    using ItemChangeList = std::pair<QList<QOrganizerItemDetail::DetailType>, QList<QOrganizerItemId>>;

    QOrganizerItemChangeSet();
    QOrganizerItemChangeSet(const QOrganizerItemChangeSet &other);
    ~QOrganizerItemChangeSet();

    QOrganizerItemChangeSet &operator=(const QOrganizerItemChangeSet &other);

    void setDataChanged(bool dataChanged);
    bool dataChanged() const;

    QSet<QOrganizerItemId> addedItems() const;
    void insertAddedItem(const QOrganizerItemId &itemId);
    void insertAddedItems(const QList<QOrganizerItemId> &itemIds);
    void clearAddedItems();

    QList<ItemChangeList> changedItems() const;
    void insertChangedItem(const QOrganizerItemId &itemId, const QList<QOrganizerItemDetail::DetailType> &typesChanged);
    void insertChangedItems(const QList<QOrganizerItemId> &itemIds, const QList<QOrganizerItemDetail::DetailType> &typesChanged);
    void clearChangedItems();

    QSet<QOrganizerItemId> removedItems() const;
    void insertRemovedItem(const QOrganizerItemId &itemId);
    void insertRemovedItems(const QList<QOrganizerItemId> &itemIds);
    void clearRemovedItems();

    QList<std::pair<QOrganizerItemId, QOrganizerManager::Operation>> modifiedItems() const;
    void clearModifiedItems();

    void clearAll();

    void emitSignals(QOrganizerManagerEngine *engine) const;

private:
    QSharedDataPointer<QOrganizerItemChangeSetPrivate> d;
};

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERITEMCHANGESET_H
