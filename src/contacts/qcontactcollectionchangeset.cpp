// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qcontactcollectionchangeset.h"
#include "qcontactcollectionchangeset_p.h"

#include "qcontactmanagerengine.h"

QT_BEGIN_NAMESPACE_CONTACTS

/*!
    \class QContactCollectionChangeSet
    \brief The QContactCollectionChangeSet class provides a simple API to simplify the emission
           of state-change signals for collections from QContactManagerEngine implementations.
    \inmodule QtContacts
    \ingroup contacts-main

    This class should only be used by backend developers.
 */

/*!
    Constructs a new change set.
 */
QContactCollectionChangeSet::QContactCollectionChangeSet()
    : d(new QContactCollectionChangeSetData)
{
}

/*!
    Constructs a copy of the \a other change set.
 */
QContactCollectionChangeSet::QContactCollectionChangeSet(const QContactCollectionChangeSet &other)
    : d(other.d)
{
}

/*!
    Frees the memory used by this change set.
 */
QContactCollectionChangeSet::~QContactCollectionChangeSet()
{
}

/*!
    Assigns this change set to be equal to \a other.
 */
QContactCollectionChangeSet &QContactCollectionChangeSet::operator=(const QContactCollectionChangeSet &other)
{
    d = other.d;
    return *this;
}

/*!
    Sets the data changed flag to \a dataChanged.

    If this is set to true prior to calling emitSignals(), only the QContactManagerEngine::dataChanged()
    signal will be emitted; otherwise, the appropriate finer-grained signals will be emitted.
 */
void QContactCollectionChangeSet::setDataChanged(bool dataChanged)
{
    d->m_dataChanged = dataChanged;
}

/*!
    Returns the value of the data changed flag.
 */
bool QContactCollectionChangeSet::dataChanged() const
{
    return d->m_dataChanged;
}

/*!
    Returns the set of IDs of collections which have been added to the database.
 */
QSet<QContactCollectionId> QContactCollectionChangeSet::addedCollections() const
{
    return d->m_addedCollections;
}

/*!
    Inserts the given \a collectionId into the set of IDs of collections which have been added to
    the database.
 */
void QContactCollectionChangeSet::insertAddedCollection(const QContactCollectionId &collectionId)
{
    d->m_addedCollections.insert(collectionId);
    d->m_modifiedCollections.append(QPair<QContactCollectionId, QContactManager::Operation>(collectionId, QContactManager::Add));
}

/*!
    Inserts each of the given \a collectionIds into the set of IDs of collections which have been
    added to the database.
 */
void QContactCollectionChangeSet::insertAddedCollections(const QList<QContactCollectionId> &collectionIds)
{
    foreach (const QContactCollectionId &id, collectionIds) {
        d->m_addedCollections.insert(id);
        d->m_modifiedCollections.append(QPair<QContactCollectionId, QContactManager::Operation>(id, QContactManager::Add));
    }
}

/*!
    Clears the set of IDs of collections which have been added to the database.
 */
void QContactCollectionChangeSet::clearAddedCollections()
{
    d->m_addedCollections.clear();
}

/*!
    Returns the set of IDs of collections which have been changed in the database.
 */
QSet<QContactCollectionId> QContactCollectionChangeSet::changedCollections() const
{
    return d->m_changedCollections;
}

/*!
    Inserts the given \a collectionId into the set of IDs of collections which have been changed in
    the database.
 */
void QContactCollectionChangeSet::insertChangedCollection(const QContactCollectionId &collectionId)
{
    d->m_changedCollections.insert(collectionId);
    d->m_modifiedCollections.append(QPair<QContactCollectionId, QContactManager::Operation>(collectionId, QContactManager::Change));
}

/*!
    Inserts each of the given \a collectionIds into the set of IDs of collections which have been
    changed in the database.
 */
void QContactCollectionChangeSet::insertChangedCollections(const QList<QContactCollectionId> &collectionIds)
{
    foreach (const QContactCollectionId &id, collectionIds) {
        d->m_changedCollections.insert(id);
        d->m_modifiedCollections.append(QPair<QContactCollectionId, QContactManager::Operation>(id, QContactManager::Change));
    }
}

/*!
    Clears the set of IDs of collections which have been changed in the database.
 */
void QContactCollectionChangeSet::clearChangedCollections()
{
    d->m_changedCollections.clear();
}

/*!
    Returns the set of IDs of collections which have been removed from the database.
 */
QSet<QContactCollectionId> QContactCollectionChangeSet::removedCollections() const
{
    return d->m_removedCollections;
}

/*!
    Inserts the given \a collectionId into the set of IDs of collections which have been removed from
    the database.
 */
void QContactCollectionChangeSet::insertRemovedCollection(const QContactCollectionId &collectionId)
{
    d->m_removedCollections.insert(collectionId);
    d->m_modifiedCollections.append(QPair<QContactCollectionId, QContactManager::Operation>(collectionId, QContactManager::Remove));
}

/*!
    Inserts each of the given \a collectionIds into the set of IDs of collections which have been
    removed from the database.
 */
void QContactCollectionChangeSet::insertRemovedCollections(const QList<QContactCollectionId> &collectionIds)
{
    foreach (const QContactCollectionId &id, collectionIds) {
        d->m_removedCollections.insert(id);
        d->m_modifiedCollections.append(QPair<QContactCollectionId, QContactManager::Operation>(id, QContactManager::Remove));
    }
}

/*!
    Clears the set of ids of collections which have been removed from the database.
 */
void QContactCollectionChangeSet::clearRemovedCollections()
{
    d->m_removedCollections.clear();
}

/*!
    Returns the list of ids of contact collections which have been added, changed or removed from
    the database. The list includes information about which database operation was done. The ids and
    operations are ordered so that the first operation is first in the list.
 */
QList<QPair<QContactCollectionId, QContactManager::Operation> > QContactCollectionChangeSet::modifiedCollections() const
{
    return d->m_modifiedCollections;
}

/*!
    Clears the list of ids of contact collections which have been added, changed or removed from the database
 */
void QContactCollectionChangeSet::clearModifiedCollections()
{
    d->m_modifiedCollections.clear();
}

/*!
    Clears all flags and sets of IDs in this change set.
 */
void QContactCollectionChangeSet::clearAll()
{
    d->m_dataChanged = false;
    d->m_addedCollections.clear();
    d->m_changedCollections.clear();
    d->m_removedCollections.clear();
    d->m_modifiedCollections.clear();
}

/*!
    Emits the appropriate signals from the given \a engine given the state of the change set. Note
    that the flags and sets of IDs are not cleared after signals are emitted.
 */
void QContactCollectionChangeSet::emitSignals(QContactManagerEngine *engine) const
{
    if (!engine)
        return;

    if (d->m_dataChanged) {
        emit engine->dataChanged();
    } else {
        if (!d->m_addedCollections.isEmpty())
            emit engine->collectionsAdded(d->m_addedCollections.values());
        if (!d->m_changedCollections.isEmpty())
            emit engine->collectionsChanged(d->m_changedCollections.values());
        if (!d->m_removedCollections.isEmpty())
            emit engine->collectionsRemoved(d->m_removedCollections.values());
        if (!d->m_modifiedCollections.isEmpty())
            emit engine->collectionsModified(d->m_modifiedCollections);

    }
}

QT_END_NAMESPACE_CONTACTS
