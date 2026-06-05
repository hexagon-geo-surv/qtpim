// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only
#ifndef DUMMYPLUGIN_H
#define DUMMYPLUGIN_H

#include <QtContacts/qcontactmanager.h>
#include <QtContacts/qcontactmanagerengine.h>
#include <QtContacts/qcontactmanagerenginefactory.h>
#include <QtCore/qscopedpointer.h>

QTCONTACTS_USE_NAMESPACE

class DummyEngine : public QContactManagerEngine
{
    Q_OBJECT
public:
    DummyEngine(const QMap<QString, QString>& parameters, QContactManager::Error* error);
    DummyEngine(const DummyEngine& other);
    ~DummyEngine();
    DummyEngine& operator=(const DummyEngine& other);
    QContactManagerEngine* clone();
    void deref();
    QString managerName() const override;

    /* Contacts - Accessors and Mutators */
    QList<QContactId> contacts(QContactManager::Error* error) const;
    QContact contact(const QContactId& contactId, QContactManager::Error* error) const;
    QContact contact(const QContactId& contactId, const QContactFetchHint& fetchHint, QContactManager::Error* error) const override;
    bool saveContact(QContact* contact, bool batch, QContactManager::Error* error);
    bool removeContact(const QContactId& contactId, bool batch, QContactManager::Error* error);

    /* Capabilities reporting */
    QStringList capabilities() const;
    QStringList fastFilterableDefinitions() const;
    QList<QVariant::Type> supportedDataTypes() const override;

    QMap<QString, QString> managerParameters() const override {return QMap<QString, QString>();}
    int managerVersion() const override {return 0;}

    QList<QContactId> contactIds(const QContactFilter&, const QList<QContactSortOrder>&, QContactManager::Error* error) const override
    {
        *error = QContactManager::NotSupportedError;
        return QList<QContactId>();
    }

    QList<QContact> contacts(const QContactFilter&, const QList<QContactSortOrder>&, const QContactFetchHint&, QContactManager::Error* error) const override
    {
        *error = QContactManager::NotSupportedError;
        return QList<QContact>();
    }

    bool saveContacts(QList<QContact>*, QMap<int, QContactManager::Error>*, QContactManager::Error* error) override
    {
        *error = QContactManager::NotSupportedError;
        return false;
    }

    bool removeContacts(const QList<QContactId>&, QMap<int, QContactManager::Error>*, QContactManager::Error* error) override
    {
        *error = QContactManager::NotSupportedError;
        return false;
    }

    QContact conformingContact(const QContact&, QContactManager::Error* error)
    {
        *error = QContactManager::NotSupportedError;
        return QContact();
    }

    /* "Self" contact id (MyCard) */
    virtual bool setSelfContactId(const QContactId&, QContactManager::Error* error) override
    {
        *error = QContactManager::NotSupportedError;
        return false;
    }

    QContactId selfContactId(QContactManager::Error* error) const override
    {
        return QContactManagerEngine::selfContactId(error);
    }

    /* Relationships between contacts */
    virtual QList<QContactRelationship> relationships(const QString&, const QContactId&, QContactRelationship::Role, QContactManager::Error* error) const override
    {
        *error = QContactManager::NotSupportedError;
        return QList<QContactRelationship>();
    }

    virtual bool saveRelationships(QList<QContactRelationship>*, QMap<int, QContactManager::Error>*, QContactManager::Error* error) override
    {
        *error = QContactManager::NotSupportedError;
        return false;
    }

    virtual bool removeRelationships(const QList<QContactRelationship>&, QMap<int, QContactManager::Error>*, QContactManager::Error* error) override
    {
        *error = QContactManager::NotSupportedError;
        return false;
    }

    /* Validation for saving */
    virtual bool validateContact(const QContact&, QContactManager::Error* error) const override
    {
        *error = QContactManager::NotSupportedError;
        return false;
    }

    /* Asynchronous Request Support */
    virtual void requestDestroyed(QContactAbstractRequest*) override {}
    virtual bool startRequest(QContactAbstractRequest*) override {return false;}
    virtual bool cancelRequest(QContactAbstractRequest*) override {return false;}
    virtual bool waitForRequestFinished(QContactAbstractRequest*, int) override {return false;}

    virtual bool isRelationshipTypeSupported(const QString&, QContactType::TypeValues) const override
    {
        return false;
    }

    virtual bool isFilterSupported(const QContactFilter&) const override
    {
        return false;
    }

    virtual QList<QContactType::TypeValues> supportedContactTypes() const override
    {
        return QList<QContactType::TypeValues>();
    }

};

class DummyEngineFactory : public QContactManagerEngineFactory
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QContactManagerEngineFactoryInterface" FILE "dummy.json")
    public:
        QContactManagerEngine* engine(const QMap<QString, QString>& parameters, QContactManager::Error* error) override;
        QString managerName() const override;
};

#endif // DUMMYPLUGIN_H
