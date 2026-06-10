// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QCONTACTCHANGESET_H
#define QCONTACTCHANGESET_H

#include <QtCore/qlist.h>
#include <QtCore/qset.h>
#include <QtCore/qshareddata.h>

#include <utility>

#include <QtContacts/qcontactid.h>
#include <QtContacts/qcontactdetail.h>

QT_BEGIN_NAMESPACE_CONTACTS

class QContactManagerEngine;

class QContactChangeSetData;
class Q_CONTACTS_EXPORT QContactChangeSet
{
public:
    typedef std::pair<QList<QContactDetail::DetailType>, QList<QContactId> > ContactChangeList;

    QContactChangeSet();
    QContactChangeSet(const QContactChangeSet& other);
    ~QContactChangeSet();

    QContactChangeSet& operator=(const QContactChangeSet& other);

    void setDataChanged(bool dataChanged);
    bool dataChanged() const;

    QSet<QContactId> addedContacts() const;
    void insertAddedContact(QContactId addedContactId);
    void insertAddedContacts(const QList<QContactId>& addedContactIds);
    void clearAddedContacts();

    QList<ContactChangeList> changedContacts() const;
    void insertChangedContact(QContactId addedContactId, const QList<QContactDetail::DetailType> &typesChanged);
    void insertChangedContacts(const QList<QContactId>& addedContactIds, const QList<QContactDetail::DetailType> &typesChanged);
    void clearChangedContacts();

    QSet<QContactId> removedContacts() const;
    void insertRemovedContact(QContactId addedContactId);
    void insertRemovedContacts(const QList<QContactId>& addedContactIds);
    void clearRemovedContacts();

    QSet<QContactId> addedRelationshipsContacts() const;
    void insertAddedRelationshipsContact(QContactId affectedContactId);
    void insertAddedRelationshipsContacts(const QList<QContactId>& affectedContactIds);
    void clearAddedRelationshipsContacts();

    QSet<QContactId> removedRelationshipsContacts() const;
    void insertRemovedRelationshipsContact(QContactId affectedContactId);
    void insertRemovedRelationshipsContacts(const QList<QContactId>& affectedContactIds);
    void clearRemovedRelationshipsContacts();

    void setOldAndNewSelfContactId(const std::pair<QContactId, QContactId>& oldAndNewContactId);
    std::pair<QContactId, QContactId> oldAndNewSelfContactId() const;

    void clearAll();

    void emitSignals(QContactManagerEngine *engine) const;

private:
    QSharedDataPointer<QContactChangeSetData> d;
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTCHANGESET_H
