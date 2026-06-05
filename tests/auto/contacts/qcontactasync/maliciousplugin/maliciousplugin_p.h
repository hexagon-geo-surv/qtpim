// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

#ifndef QCONTACTMALICIOUSPLUGIN_P_H
#define QCONTACTMALICIOUSPLUGIN_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <QtContacts/qcontactmanager.h>
#include <QtContacts/qcontactmanagerengine.h>
#include <QtContacts/qcontactmanagerenginefactory.h>

#include <QObject>
#include <QString>

QT_BEGIN_NAMESPACE
class QThread;
QT_END_NAMESPACE

QTCONTACTS_USE_NAMESPACE

class MaliciousThreadObject;
class MaliciousAsyncManagerEngine : public QContactManagerEngine
{
    Q_OBJECT

public:
    MaliciousAsyncManagerEngine();
    ~MaliciousAsyncManagerEngine();

    QString managerName() const override;
    bool startRequest(QContactAbstractRequest* req) override;
    bool cancelRequest(QContactAbstractRequest *req) override;

    QMap<QString, QString> managerParameters() const override {return QMap<QString, QString>();}
    int managerVersion() const override {return 0;}

    QList<QContactId> contactIds(const QContactFilter& filter, const QList<QContactSortOrder>& sort, QContactManager::Error* error) const override
    {
        return QContactManagerEngine::contactIds(filter, sort, error);
    }

    QList<QContact> contacts(const QContactFilter& filter, const QList<QContactSortOrder>& sort, const QContactFetchHint& fetch, QContactManager::Error* error) const override
    {
        return QContactManagerEngine::contacts(filter, sort, fetch, error);
    }

    QContact contact(const QContactId& id, const QContactFetchHint& fetch, QContactManager::Error* error) const override
    {
        return QContactManagerEngine::contact(id, fetch, error);
    }

    bool saveContacts(QList<QContact>* contacts, QMap<int, QContactManager::Error>* errorMap, QContactManager::Error* error) override
    {
        return QContactManagerEngine::saveContacts(contacts, errorMap, error);
    }

    bool removeContacts(const QList<QContactId>& contacts, QMap<int, QContactManager::Error>* errorMap, QContactManager::Error* error) override
    {
        return QContactManagerEngine::removeContacts(contacts, errorMap, error);
    }

    /* "Self" contact id (MyCard) */
    bool setSelfContactId(const QContactId& id, QContactManager::Error* error) override
    {
        return QContactManagerEngine::setSelfContactId(id, error);
    }

    QContactId selfContactId(QContactManager::Error* error) const override
    {
        return QContactManagerEngine::selfContactId(error);
    }

    /* Relationships between contacts */
    QList<QContactRelationship> relationships(const QString& relType, const QContactId& contactId, QContactRelationship::Role role, QContactManager::Error* error) const override
    {
        return QContactManagerEngine::relationships(relType, contactId, role, error);
    }

    bool saveRelationships(QList<QContactRelationship>* relationships, QMap<int, QContactManager::Error>* errorMap, QContactManager::Error* error) override
    {
        return QContactManagerEngine::saveRelationships(relationships, errorMap, error);
    }

    bool removeRelationships(const QList<QContactRelationship>& relationships, QMap<int, QContactManager::Error>* errorMap, QContactManager::Error* error) override
    {
        return QContactManagerEngine::removeRelationships(relationships, errorMap, error);
    }

    /* Contact validation */
    bool validateContact(const QContact& contact, QContactManager::Error* error) const override
    {
        return QContactManagerEngine::validateContact(contact, error);
    }

    /* Asynchronous Request Support */
    void requestDestroyed(QContactAbstractRequest* req) override;
    bool waitForRequestFinished(QContactAbstractRequest* req, int msecs) override {return QContactManagerEngine::waitForRequestFinished(req, msecs);}

    bool isRelationshipTypeSupported(const QString& relType, QContactType::TypeValues type) const override
    {
        return QContactManagerEngine::isRelationshipTypeSupported(relType, type);
    }

    bool isFilterSupported(const QContactFilter& fil) const override
    {
        return QContactManagerEngine::isFilterSupported(fil);
    }

    QList<QVariant::Type> supportedDataTypes() const override
    {
        return QContactManagerEngine::supportedDataTypes();
    }
    QList<QContactType::TypeValues> supportedContactTypes() const override
    {
        return QContactManagerEngine::supportedContactTypes();
    }

signals:
    void doStartRequest(QContactAbstractRequest *req);
    void doFinishRequest(QContactAbstractRequest *req);
private:
    QThread* thread;
    MaliciousThreadObject* threadObject;
};

class MaliciousEngineFactory : public QContactManagerEngineFactory
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QContactManagerEngineFactoryInterface" FILE "malicious.json")

    public:
        QContactManagerEngine* engine(const QMap<QString, QString>& parameters, QContactManager::Error* error) override;
        QString managerName() const override;

    private:
        MaliciousAsyncManagerEngine mame;
};

#endif

