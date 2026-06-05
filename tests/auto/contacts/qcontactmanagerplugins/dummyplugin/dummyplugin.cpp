// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only


/* We build multiple plugins with the same code, just different names */
#ifndef DUMMYPLUGINTARGET
#define DUMMYPLUGINTARGET contacts_testdummy
#endif

#define makestr(x) (#x)
#define makename(x) makestr(x)

#include <QtContacts/qcontactmanager.h>
#include <QtContacts/qcontactmanagerengine.h>
#include <QtContacts/qcontactmanagerenginefactory.h>

#include "dummyplugin.h"

QTCONTACTS_USE_NAMESPACE

QContactManagerEngine* DummyEngineFactory::engine(const QMap<QString, QString>& parameters, QContactManager::Error* error)
{
    return new DummyEngine(parameters, error);
}

QString DummyEngineFactory::managerName() const
{
#ifdef DUMMYPLUGINNAME
    return QString(makename(DUMMYPLUGINNAME));
#else
    return QString();
#endif
}

DummyEngine::DummyEngine(const QMap<QString, QString>& parameters, QContactManager::Error* error)
{
    Q_UNUSED(parameters);
    *error = QContactManager::AlreadyExistsError; // Another random choice
}

DummyEngine::DummyEngine(const DummyEngine& other)
    : QContactManagerEngine()
{
    Q_UNUSED(other);
}

DummyEngine& DummyEngine::operator=(const DummyEngine& other)
{
    Q_UNUSED(other);
    return *this;
}

DummyEngine::~DummyEngine()
{
}

QContactManagerEngine* DummyEngine::clone()
{
    // Disallow sharing
    return new DummyEngine(*this);
}

void DummyEngine::deref()
{
    delete this;
}

QString DummyEngine::managerName() const
{
#ifdef DUMMYPLUGINNAME
    return QString(makename(DUMMYPLUGINNAME));
#else
    return QString();
#endif
}

QList<QContactId> DummyEngine::contacts(QContactManager::Error* error) const
{
    QList<QContactId> allCIds;

    if (allCIds.count() > 0 && *error == QContactManager::NoError)
        *error = QContactManager::DoesNotExistError;

    return allCIds;
}

QContact DummyEngine::contact(const QContactId& contactId, QContactManager::Error* error) const
{
    Q_UNUSED(contactId);
    *error = QContactManager::DoesNotExistError;
    return QContact();
}

QContact DummyEngine::contact(const QContactId& contactId, const QContactFetchHint& fetchHint, QContactManager::Error* error) const
{
    Q_UNUSED(contactId);
    Q_UNUSED(fetchHint);
    *error = QContactManager::DoesNotExistError;
    return QContact();
}

bool DummyEngine::saveContact(QContact* contact, bool batch, QContactManager::Error* error)
{
    // ensure that the contact's details conform to their definitions
    if (!validateContact(*contact, error)) {
        *error = QContactManager::InvalidDetailError;
        return false;
    }

    // success!
    QContactId newId;
    contact->setId(newId);
    *error = QContactManager::NoError;

    // if we need to emit signals (ie, this isn't part of a batch operation)
    // then emit the correct one.
    if (!batch) {
        QList<QContactId> emitList;
        emitList.append(contact->id());
        emit contactsAdded(emitList);
    }

    return true;
}

bool DummyEngine::removeContact(const QContactId& contactId, bool batch, QContactManager::Error* error)
{
    /* TODO: fix this
    if (contactId != "5") {
        *error = QContactManager::DoesNotExistError;
        return false;
    }*/

    *error = QContactManager::NoError;

    // if we need to emit signals (ie, this isn't part of a batch operation)
    // then emit the correct one.
    if (!batch) {
        QList<QContactId> emitList;
        emitList.append(contactId);
        emit contactsRemoved(emitList);
    }

    return true;
}

/*! Returns the capabilities of the in-memory engine. */
QStringList DummyEngine::capabilities() const
{
    QStringList caplist;
    caplist << "Locking" << "Batch" << "ReadOnly" << "Filtering" << "Sorting" << "Preferences";
    // ie, doesn't support: Changelog, Volatile, Asynchronous.
    return caplist;
}

/*!
 * Returns a list of definition identifiers which are natively (fast) filterable
 * on the default backend store managed by the manager from which the capabilities object was accessed
 */
QStringList DummyEngine::fastFilterableDefinitions() const
{
    QStringList fastlist;
    fastlist << "Name::First" << "Name::Last" << "PhoneNumber::PhoneNumber" << "EmailAddress::EmailAddress";
    return fastlist;
}

/*!
 * Returns the list of data types supported by the vCard engine
 */
QList<QMetaType::Type> DummyEngine::supportedDataTypes() const
{
    QList<QMetaType::Type> st;
    st.append(QMetaType::QString);
    st.append(QMetaType::QDate);
    st.append(QMetaType::QDateTime);

    return st;
}

#include "moc_dummyplugin.cpp"
