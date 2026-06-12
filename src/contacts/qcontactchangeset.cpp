// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qcontactchangeset.h"
#include "qcontactchangeset_p.h"

#include "qcontactmanagerengine.h"

#include <algorithm>
#include <utility>

QT_BEGIN_NAMESPACE_CONTACTS

/*!
   \class QContactChangeSet

  \inmodule QtContacts

   \brief The QContactChangeSet class provides a simple API to
   simplify the emission of state-change signals from
   QContactManagerEngine implementations.

   This class can be utilised by backend implementations to ensure
   correct emission of the \l QContactManagerEngine::dataChanged(), \l
   QContactManagerEngine::contactsAdded(), \l
   QContactManagerEngine::contactsChanged() and \l
   QContactManagerEngine::contactsRemoved().

   \sa QContactManagerEngine
 */

/*!
   \typedef QContactChangeSet::ContactChangeList

   This type describes a set of contact changes, where each contact whose
   ID is listed in \c second is subject to a change that affects some or
   all of the property types listed in \c first.

   Note that change grouping is of contacts affected by equivalent changes,
   rather than of multiple changes affecting the same contact.

   \code
        for (const QContactChangeSet::ContactChangeList &changeList : set.changedContacts()) {
            if (changeList.first.contains(QContactAvatar::Type)) {
                qDebug() << "Contact IDs with avatar changes:" << changeList.second;
            }
        }
   \endcode

   \sa QContactChangeSet::changedContacts()
 */

/*!
   Constructs a new change set
 */
QContactChangeSet::QContactChangeSet()
    : d(new QContactChangeSetPrivate)
{
}

/*!
   Constructs a copy of the \a other change set
 */
QContactChangeSet::QContactChangeSet(const QContactChangeSet& other)
    : d(other.d)
{
}

/*!
   Frees the memory used by this change set
 */
QContactChangeSet::~QContactChangeSet()
{
}

/*!
   Assigns this change set to be equal to \a other
 */
QContactChangeSet& QContactChangeSet::operator=(const QContactChangeSet& other)
{
    d = other.d;
    return *this;
}

/*!
   Sets the data changed flag to \a dataChanged.  If this is set to true prior to calling \l emitSignals(),
   only the \l QContactManagerEngine::dataChanged() signal will be emitted; otherwise, the appropriate
   finer-grained signals will be emitted.
 */
void QContactChangeSet::setDataChanged(bool dataChanged)
{
    d->m_dataChanged = dataChanged;
}

/*!
   Returns the value of the data changed flag
 */
bool QContactChangeSet::dataChanged() const
{
    return d->m_dataChanged;
}

/*!
   Returns the set of ids of contacts which have been added to
   the database.
 */
QSet<QContactId> QContactChangeSet::addedContacts() const
{
    return d->m_addedContacts;
}

/*!
  Inserts the given contact id \a addedContactId into the set of ids of contacts
  which have been added to the database.
 */
void QContactChangeSet::insertAddedContact(QContactId addedContactId)
{
    d->m_addedContacts.insert(addedContactId);
}

/*!
  Inserts each of the given contact ids \a addedContactIds into the set of ids of contacts
  which have been added to the database.
 */
void QContactChangeSet::insertAddedContacts(const QList<QContactId>& addedContactIds)
{
    for (const QContactId &id : addedContactIds)
        d->m_addedContacts.insert(id);
}

/*!
  Clears the set of ids of contacts which have been added to the database
 */
void QContactChangeSet::clearAddedContacts()
{
    d->m_addedContacts.clear();
}

/*!
   Returns a list of ContactChangeLists describing which contacts have been
   changed in the database, and what properties of those contacts have changed.
 */
QList<QContactChangeSet::ContactChangeList> QContactChangeSet::changedContacts() const
{
    return d->m_changedContacts;
}

/*!
  Inserts the given contact ID \a changedContactId into the set of IDs of contacts
  which have been changed in the database, with the changes described by \a typesChanged.
 */
void QContactChangeSet::insertChangedContact(QContactId changedContactId, const QList<QContactDetail::DetailType> &typesChanged)
{
    insertChangedContacts(QList<QContactId>() << changedContactId, typesChanged);
}

/*!
  Inserts each of the contact IDs listed in \a changedContactIds into the set of IDs of contacts
  which have been changed in the database, with the changes described by \a typesChanged.
 */
void QContactChangeSet::insertChangedContacts(const QList<QContactId>& changedContactIds, const QList<QContactDetail::DetailType> &typesChanged)
{
    // Sort and de-duplicate the IDs and change types
    QList<QContactId> contactIds(changedContactIds);
    std::sort(contactIds.begin(), contactIds.end());
    {
        QList<QContactId>::iterator iit = std::unique(contactIds.begin(), contactIds.end());
        while (iit != contactIds.end()) {
            iit = contactIds.erase(iit);
        }
    }

    QList<QContactDetail::DetailType> changeSet(typesChanged);
    std::sort(changeSet.begin(), changeSet.end());
    {
        QList<QContactDetail::DetailType>::iterator cit = std::unique(changeSet.begin(), changeSet.end());
        while (cit != changeSet.end()) {
            cit = changeSet.erase(cit);
        }
    }

    // Add these contacts to the list of contacts that match this change set
    QList<ContactChangeList>::iterator it = d->m_changedContacts.begin(), end = d->m_changedContacts.end();
    for ( ; it != end; ++it) {
        if ((*it).first == changeSet) {
            break;
        }
    }
    if (it == end) {
        // Add a list for this set of changes
        d->m_changedContacts.append(std::make_pair(changeSet, contactIds));
    } else {
        QList<QContactId> &changedIds((*it).second);
        QList<QContactId>::iterator iit = changedIds.begin();

        for (const QContactId &contactId : contactIds) {
            // Add this ID if not yet present
            iit = std::lower_bound(iit, changedIds.end(), contactId);
            if (iit == changedIds.end() || *iit != contactId) {
                iit = changedIds.insert(iit, contactId);
            }
        }
    }
}

/*!
  Clears the set of ids of contacts which have been changed to the database
 */
void QContactChangeSet::clearChangedContacts()
{
    d->m_changedContacts.clear();
}

/*!
   Returns the set of ids of contacts which have been removed from
   the database.
 */
QSet<QContactId> QContactChangeSet::removedContacts() const
{
    return d->m_removedContacts;
}

/*!
  Inserts the given contact id \a removedContactId into the set of ids of contacts
  which have been removed to the database.
 */
void QContactChangeSet::insertRemovedContact(QContactId removedContactId)
{
    d->m_removedContacts.insert(removedContactId);
}

/*!
  Inserts each of the given contact ids \a removedContactIds into the set of ids of contacts
  which have been removed to the database.
 */
void QContactChangeSet::insertRemovedContacts(const QList<QContactId>& removedContactIds)
{
    for (const QContactId &id : removedContactIds)
        d->m_removedContacts.insert(id);
}

/*!
  Clears the set of ids of contacts which have been removed to the database
 */
void QContactChangeSet::clearRemovedContacts()
{
    d->m_removedContacts.clear();
}

/*!
   Returns the set of ids of contacts which have been affected
   by the addition of relationships to the database.
 */
QSet<QContactId> QContactChangeSet::addedRelationshipsContacts() const
{
    return d->m_addedRelationships;
}

/*!
  Inserts the given contact id \a affectedContactId into the set of ids of contacts
  which have been affected by the addition of a relationship to the database.
 */
void QContactChangeSet::insertAddedRelationshipsContact(QContactId affectedContactId)
{
    d->m_addedRelationships.insert(affectedContactId);
}

/*!
  Inserts each of the given contact ids \a affectedContactIds into the set of ids of contacts
  which have been affected by the addition of a relationship to the database.
 */
void QContactChangeSet::insertAddedRelationshipsContacts(const QList<QContactId>& affectedContactIds)
{
    for (const QContactId &id : affectedContactIds)
        d->m_addedRelationships.insert(id);
}

/*!
  Clears the set of ids of contacts which have been affected by the addition of a relationship to the database.
 */
void QContactChangeSet::clearAddedRelationshipsContacts()
{
    d->m_addedRelationships.clear();
}

/*!
   Returns the set of ids of contacts which have been affected
   by the removal of relationships from the database.
 */
QSet<QContactId> QContactChangeSet::removedRelationshipsContacts() const
{
    return d->m_removedRelationships;
}

/*!
  Inserts the given contact id \a affectedContactId into the set of ids of contacts
  which have been affected by the removal of a relationship to the database.
 */
void QContactChangeSet::insertRemovedRelationshipsContact(QContactId affectedContactId)
{
    d->m_removedRelationships.insert(affectedContactId);
}

/*!
  Inserts each of the given contact ids \a affectedContactIds into the set of ids of contacts
  which have been affected by the removal of a relationship to the database.
 */
void QContactChangeSet::insertRemovedRelationshipsContacts(const QList<QContactId>& affectedContactIds)
{
    for (const QContactId &id : affectedContactIds)
        d->m_removedRelationships.insert(id);
}

/*!
  Clears the set of ids of contacts which have been affected by the removal of a relationship to the database.
 */
void QContactChangeSet::clearRemovedRelationshipsContacts()
{
    d->m_removedRelationships.clear();
}

/*!
  Sets the pair of ids which represent the old and new self contact ids
  to the given pair of ids \a oldAndNewContactId.
  The first id in the pair is the old self contact id, while the second
  id in the pair is the new self contact id.  If the new id is different
  to the old id at the point in time when emitSignals() is called,
  the QContactManagerEngine::selfContactIdChanged signal will be emitted.
 */
void QContactChangeSet::setOldAndNewSelfContactId(const std::pair<QContactId, QContactId> &oldAndNewContactId)
{
    d->m_oldAndNewSelfContactId = oldAndNewContactId;
}

/*!
   Returns the pair of ids which represents the
   old and new self contact ids.  The first id in the pair is the
   old self contact id, while the second id in the pair is the
   new self contact id.  If the new id is different to the old id
   at the point in time when emitSignals() is called,
   the QContactManagerEngine::selfContactIdChanged() signal will be emitted.
 */
std::pair<QContactId, QContactId> QContactChangeSet::oldAndNewSelfContactId() const
{
    return d->m_oldAndNewSelfContactId;
}

/*!
   Clears all flags and sets of ids in this change set
 */
void QContactChangeSet::clearAll()
{
    d->m_dataChanged = false;
    d->m_addedContacts.clear();
    d->m_changedContacts.clear();
    d->m_removedContacts.clear();
    d->m_addedRelationships.clear();
    d->m_removedRelationships.clear();
    d->m_oldAndNewSelfContactId = std::pair<QContactId, QContactId>();
}

/*!
   Emits the appropriate signals from the given \a engine given the state of the change set
 */
void QContactChangeSet::emitSignals(QContactManagerEngine *engine) const
{
    if (!engine)
        return;

    if (d->m_dataChanged) {
        emit engine->dataChanged();
    } else {
        if (!d->m_addedContacts.isEmpty())
            emit engine->contactsAdded(QList<QContactId>(d->m_addedContacts.begin(), d->m_addedContacts.end()));
        if (!d->m_changedContacts.isEmpty()) {
            QList<ContactChangeList>::const_iterator it = d->m_changedContacts.constBegin(), end = d->m_changedContacts.constEnd();
            for ( ; it != end; ++it)
                emit engine->contactsChanged((*it).second, (*it).first);
        }
        if (!d->m_removedContacts.isEmpty())
            emit engine->contactsRemoved(QList<QContactId>(d->m_removedContacts.begin(), d->m_removedContacts.end()));
        if (!d->m_addedRelationships.isEmpty())
            emit engine->relationshipsAdded(QList<QContactId>(d->m_addedRelationships.begin(), d->m_addedRelationships.end()));
        if (!d->m_removedRelationships.isEmpty())
            emit engine->relationshipsRemoved(QList<QContactId>(d->m_removedRelationships.begin(), d->m_removedRelationships.end()));
        if (d->m_oldAndNewSelfContactId.first != d->m_oldAndNewSelfContactId.second)
            emit engine->selfContactIdChanged(d->m_oldAndNewSelfContactId.first, d->m_oldAndNewSelfContactId.second);
    }
}

QT_END_NAMESPACE_CONTACTS
