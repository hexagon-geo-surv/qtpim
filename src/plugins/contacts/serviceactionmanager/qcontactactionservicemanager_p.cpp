// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qcontactactionservicemanager_p.h"

#include <QtContacts/qcontactaction.h>
#include <QtContacts/qcontactactiondescriptor.h>
#include <QtContacts/qcontactactionfactory.h>

#include "qservice.h"
#include "qservicemanager.h"

QTM_BEGIN_NAMESPACE

Q_GLOBAL_STATIC(QContactActionServiceManager, contactActionServiceManagerInstance)
Q_EXPORT_PLUGIN2(qtcontacts_serviceactionmanager, QContactActionServiceManager);

/*!
  \internal
  \class QContactActionServiceManager
  This class uses the service framework to discover contact actions which are
  provided by third parties.  It is an implementation detail of QContactAction.
 */

QContactActionServiceManager* QContactActionServiceManager::instance()
{
    return contactActionServiceManagerInstance();
}

QContactActionServiceManager::QContactActionServiceManager()
    : QObject(), initLock(false)
{
}

QContactActionServiceManager::~QContactActionServiceManager()
{
    // we don't use qDeleteAll() because some factories produce more than one action descriptor.
    QList<QContactActionDescriptor> keys = m_actionFactoryHash.keys();
    QSet<QContactActionFactory*> deletedFactories;
    foreach (const QContactActionDescriptor& key, keys) {
        QContactActionFactory *curr = m_actionFactoryHash.value(key);
        if (!deletedFactories.contains(curr)) {
            deletedFactories.insert(curr);
            delete curr;
        }
    }
}

void QContactActionServiceManager::init()
{
    // XXX NOTE: should already be locked PRIOR to entering this function.
    if (!initLock) {
        initLock = true;
        // fill up our hashes
        QList<QServiceInterfaceDescriptor> sids = m_serviceManager.findInterfaces(); // all services, all interfaces.
        foreach (const QServiceInterfaceDescriptor& sid, sids) {
            if (sid.interfaceName() == QContactActionFactory::InterfaceName) {
                if (static_cast<QService::Type>(sid.attribute(QServiceInterfaceDescriptor::ServiceType).toInt()) != QService::Plugin) {
                    continue; // we don't allow IPC contact action factories.
                }
                QContactActionFactory* actionFactory = qobject_cast<QContactActionFactory*>(m_serviceManager.loadInterface(sid));
                if (actionFactory) {
                    // if we cannot get the action factory from the service manager, then we don't add it to our hash.
                    QList<QContactActionDescriptor> descriptors = actionFactory->actionDescriptors();
                    foreach (const QContactActionDescriptor& ad, descriptors) {
                        m_descriptorHash.insert(ad.actionName(), ad); // multihash insert.
                        m_actionFactoryHash.insert(ad, actionFactory);
                    }
                }
            }
        }

        // and listen for signals.
        connect(&m_serviceManager, SIGNAL(serviceAdded(QString,QService::Scope)), this, SLOT(serviceAdded(QString)));
        connect(&m_serviceManager, SIGNAL(serviceRemoved(QString,QService::Scope)), this, SLOT(serviceRemoved(QString)));
    }
}

QHash<QContactActionDescriptor, QContactActionFactory*> QContactActionServiceManager::actionFactoryHash()
{
    QMutexLocker locker(&m_instanceMutex);
    init();
    return m_actionFactoryHash;
}

QMultiHash<QString, QContactActionDescriptor> QContactActionServiceManager::descriptorHash()
{
    QMutexLocker locker(&m_instanceMutex);
    init();
    return m_descriptorHash;
}

void QContactActionServiceManager::serviceAdded(const QString& serviceName)
{
    QMutexLocker locker(&m_instanceMutex);
    QList<QServiceInterfaceDescriptor> sids = m_serviceManager.findInterfaces(serviceName);
    foreach (const QServiceInterfaceDescriptor& sid, sids) {
        if (sid.interfaceName() == QContactActionFactory::InterfaceName) {
            if (static_cast<QService::Type>(sid.attribute(QServiceInterfaceDescriptor::ServiceType).toInt()) != QService::Plugin) {
                continue; // we don't allow IPC contact action factories.
            }
            QContactActionFactory* actionFactory = qobject_cast<QContactActionFactory*>(m_serviceManager.loadInterface(sid));
            if (actionFactory) {
                // if we cannot get the action factory from the service manager, then we don't add it to our hash.
                QList<QContactActionDescriptor> descriptors = actionFactory->actionDescriptors();
                foreach (const QContactActionDescriptor& ad, descriptors) {
                    m_descriptorHash.insert(ad.actionName(), ad); // multihash insert.
                    m_actionFactoryHash.insert(ad, actionFactory);
                }
            }
        }
    }
}

void QContactActionServiceManager::serviceRemoved(const QString& serviceName)
{
    QMutexLocker locker(&m_instanceMutex);
    QList<QServiceInterfaceDescriptor> sids = m_serviceManager.findInterfaces(serviceName);
    foreach (const QServiceInterfaceDescriptor& sid, sids) {
        if (sid.interfaceName() == QContactActionFactory::InterfaceName) {
            if (static_cast<QService::Type>(sid.attribute(QServiceInterfaceDescriptor::ServiceType).toInt()) != QService::Plugin) {
                continue; // we don't allow IPC contact action factories.
            }
            QList<QContactActionDescriptor> cads = m_actionFactoryHash.keys();
            foreach (const QContactActionDescriptor& cad, cads) {
                if (cad.serviceName() != serviceName)
                    continue;
                delete m_actionFactoryHash.value(cad);
                m_actionFactoryHash.remove(cad);
                m_descriptorHash.remove(cad.actionName(), cad);
            }
        }
    }
}

#include "moc_qcontactactionservicemanager_p.cpp"

QTM_END_NAMESPACE
