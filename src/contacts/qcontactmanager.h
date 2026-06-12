// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QCONTACTMANAGER_H
#define QCONTACTMANAGER_H

#include <QtCore/qmap.h>
#include <QtCore/qobject.h>
#include <QtCore/qstringlist.h>

#include <utility>

#include <QtContacts/qcontact.h>
#include <QtContacts/qcontactcollection.h>
#include <QtContacts/qcontactid.h>
#include <QtContacts/qcontactfetchhint.h>
#include <QtContacts/qcontactrelationship.h>
#include <QtContacts/qcontactsortorder.h>
#include <QtContacts/qcontacttype.h>

QT_BEGIN_NAMESPACE_CONTACTS

class QContactAction;
class QContactFilter;

class QContactManagerPrivate;
class Q_CONTACTS_EXPORT QContactManager : public QObject
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(QContactManager)

public:
#ifdef Q_QDOC // qdoc's parser fails to recognise the default map argument
    explicit QContactManager(const QString& managerName = QString(), const QMap<QString, QString>& parameters = 0, QObject* parent = nullptr);
    QContactManager(const QString& managerName, int implementationVersion, const QMap<QString, QString>& parameters = 0, QObject* parent = nullptr);
#else
    explicit QContactManager(const QString& managerName = QString(), const QMap<QString, QString>& parameters = (QMap<QString, QString>()), QObject* parent = nullptr);
    QContactManager(const QString& managerName, int implementationVersion, const QMap<QString, QString>& parameters = (QMap<QString, QString>()), QObject* parent = nullptr);
#endif
    explicit QContactManager(QObject* parent);

    inline static const QString ParameterSignalSources() {return QStringLiteral("SignalSources");};
    inline static const QString ParameterSignalDefinitions() {return QStringLiteral("SignalDefinitions");};
    inline static const QString ParameterValueOnlyOtherProcesses() {return QStringLiteral("OnlyOtherProcesses");};
    inline static const QString ParameterValueOnlyOtherManagers() {return QStringLiteral("OnlyOtherManagers");};

    static QContactManager* fromUri(const QString& uri, QObject* parent = nullptr);
    ~QContactManager();                     // dtor

    QString managerName() const;                       // e.g. "memory"
    QMap<QString, QString> managerParameters() const;  // e.g. "filename=private.db"
    QString managerUri() const;                        // managerName + managerParameters
    int managerVersion() const;

    static bool parseUri(const QString &uri, QString *managerName, QMap<QString, QString> *params);
    static QString buildUri(const QString &managerName, const QMap<QString, QString> &params);
    static QString buildUri(const QString &managerName, const QMap<QString, QString> &params, int implementationVersion);

    enum Error {
        NoError = 0,
        DoesNotExistError,
        AlreadyExistsError,
        InvalidDetailError,
        InvalidRelationshipError,
        LockedError,
        DetailAccessError,
        PermissionsError,
        OutOfMemoryError,
        NotSupportedError,
        BadArgumentError,
        UnspecifiedError,
        VersionMismatchError,
        LimitReachedError,
        InvalidContactTypeError,
        TimeoutError,
        MissingPlatformRequirementsError
    };

    enum Operation {
        Add,
        Change,
        Remove
    };

    /* Error reporting */
    QContactManager::Error error() const;
    QMap<int, QContactManager::Error> errorMap() const;

    /* Contacts - Accessors and Mutators */
    QList<QContactId> contactIds(const QList<QContactSortOrder>& sortOrders = QList<QContactSortOrder>()) const;
    QList<QContactId> contactIds(const QContactFilter& filter, const QList<QContactSortOrder>& sortOrders = QList<QContactSortOrder>()) const;

    QList<QContact> contacts(const QList<QContactSortOrder>& sortOrders = QList<QContactSortOrder>(), const QContactFetchHint& fetchHint = QContactFetchHint()) const;
    QList<QContact> contacts(const QContactFilter& filter, const QList<QContactSortOrder>& sortOrders = QList<QContactSortOrder>(), const QContactFetchHint& fetchHint = QContactFetchHint()) const;
    QList<QContact> contacts(const QList<QContactId>& contactIds, const QContactFetchHint& fetchHint = QContactFetchHint(), QMap<int, QContactManager::Error>* errorMap = nullptr) const;

    QContact contact(const QContactId& contactId, const QContactFetchHint& fetchHint = QContactFetchHint()) const;  // retrieve a contact

    bool saveContact(QContact* contact);                 // note: MODIFIES contact (sets the contactId)
    bool removeContact(const QContactId& contactId);      // remove the contact from the persistent store

    bool saveContacts(QList<QContact>* contacts, QMap<int, QContactManager::Error>* errorMap = nullptr); // batch API - save.
    bool saveContacts(QList<QContact>* contacts, const QList<QContactDetail::DetailType>& typeMask, QMap<int, QContactManager::Error>* errorMap = nullptr); // Partial save
    bool removeContacts(const QList<QContactId>& contactIds, QMap<int, QContactManager::Error>* errorMap = nullptr); // batch API - remove.

    /* "Self" contact id (MyCard) */
    bool setSelfContactId(const QContactId& contactId);
    QContactId selfContactId() const;

    /* Relationships */
    QList<QContactRelationship> relationships(const QContactId& participantId, QContactRelationship::Role role = QContactRelationship::Either) const;
    QList<QContactRelationship> relationships(const QString& relationshipType = QString(), const QContactId& participantId = QContactId(), QContactRelationship::Role role = QContactRelationship::Either) const;
    bool saveRelationship(QContactRelationship* relationship);
    bool saveRelationships(QList<QContactRelationship>* relationships, QMap<int, QContactManager::Error>* errorMap = nullptr);
    bool removeRelationship(const QContactRelationship& relationship);
    bool removeRelationships(const QList<QContactRelationship>& relationships, QMap<int, QContactManager::Error>* errorMap = nullptr);

    /* Capabilities reporting */
    bool isRelationshipTypeSupported(const QString& relationshipType, QContactType::TypeValues  contactType = QContactType::TypeContact) const;
    QList<QMetaType::Type> supportedDataTypes() const;
    bool isFilterSupported(const QContactFilter& filter) const;
    QList<QContactType::TypeValues> supportedContactTypes() const;
    QList<QContactDetail::DetailType> supportedContactDetailTypes() const;

    // collections
    QContactCollectionId defaultCollectionId() const;
    QContactCollection collection(const QContactCollectionId& collectionId) const;
    QList<QContactCollection> collections() const;
    bool saveCollection(QContactCollection* collection);
    bool removeCollection(const QContactCollectionId& collectionId);

    /* return a list of available backends for which a QContactManager can be constructed. */
    static QStringList availableManagers();

Q_SIGNALS:
    void dataChanged();
    void contactsAdded(const QList<QtContacts::QContactId>& contactIds);
    void contactsChanged(const QList<QtContacts::QContactId>& contactIds, const QList<QtContacts::QContactDetail::DetailType>& typesChanged);
    void contactsRemoved(const QList<QtContacts::QContactId>& contactIds);
    void relationshipsAdded(const QList<QtContacts::QContactId>& affectedContactIds);
    void relationshipsRemoved(const QList<QtContacts::QContactId>& affectedContactIds);
    void selfContactIdChanged(const QtContacts::QContactId& oldId, const QtContacts::QContactId& newId);
    void collectionsAdded(const QList<QtContacts::QContactCollectionId> &collectionIds);
    void collectionsChanged(const QList<QtContacts::QContactCollectionId> &collectionIds);
    void collectionsRemoved(const QList<QtContacts::QContactCollectionId> &collectionIds);
    void collectionsModified(const QList<std::pair<QtContacts::QContactCollectionId, QtContacts::QContactManager::Operation> > &collectionIds);

protected:
    void connectNotify(const QMetaMethod &signal) override;
    void disconnectNotify(const QMetaMethod &signal) override;

private:
    void createEngine(const QString& managerName, const QMap<QString, QString>& parameters);

    Q_DISABLE_COPY(QContactManager)
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTMANAGER_H
