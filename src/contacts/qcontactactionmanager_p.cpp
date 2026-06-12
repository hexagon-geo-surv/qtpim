// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qcontactactionmanager_p.h"

#include "qcontactaction.h"
#include "qcontactactionfactory.h"
#include "qcontactmanager_p.h"

QT_BEGIN_NAMESPACE_CONTACTS

Q_GLOBAL_STATIC(QContactActionManager, contactActionManagerInstance)

/*!
  \internal
  \class QContactActionManager
  This class uses a plugin to delegate discovery of actions (to avoid a dependency on SFW for QtContacts)
  It is an implementation detail of QContactAction.
 */

QContactActionManager* QContactActionManager::instance()
{
    return contactActionManagerInstance();
}

QContactActionManager::QContactActionManager()
    : QObject(),
    m_plugin(0)
{
}

void QContactActionManager::init()
{
    // We ask the qcontactmanager engine loading code, since it has to enumerate things anyway
    QContactManagerPrivate::loadFactoriesMetadata();
    m_plugin = QContactManagerPrivate::m_actionManagers.value(0);
}

QContactActionManager::~QContactActionManager()
{
    // Allow our subordinates to do their thing when they want,
    // since we just cache stuff
}

QList<QContactActionDescriptor> QContactActionManager::availableActions(const QContact &contact)
{
    QMutexLocker locker(&m_instanceMutex);
    init();

    QList<QContactActionDescriptor> ret;
    if (m_plugin) {
        QHash<QContactActionDescriptor, QContactActionFactory*> hash = m_plugin->actionFactoryHash();
        QHash<QContactActionDescriptor, QContactActionFactory*>::const_iterator it;
        for (it = hash.constBegin(); it != hash.constEnd(); ++it) {
            QContactActionFactory* curr = it.value();
            if (curr && curr->supportsContact(contact, it.key())) {
                ret.append(it.key());
            }
        }
    }

    return ret;
}

QList<QContactActionDescriptor> QContactActionManager::actionDescriptors(const QString& actionName)
{
    QMutexLocker locker(&m_instanceMutex);
    init();

    if (m_plugin) {
        if (actionName.isEmpty())
            return m_plugin->descriptorHash().values();
        return m_plugin->descriptorHash().values(actionName);
    }
    return QList<QContactActionDescriptor>();
}

/*! The caller takes ownership of the returned action pointer, and must delete it to avoid leaking memory. */
QContactAction* QContactActionManager::action(const QContactActionDescriptor& descriptor)
{
    QMutexLocker locker(&m_instanceMutex);
    init();

    if (m_plugin) {
        QContactActionFactory *factory = m_plugin->actionFactoryHash().value(descriptor);
        if (factory)
            return factory->create(descriptor);
    }
    return 0;
}

QT_END_NAMESPACE_CONTACTS

#include "moc_qcontactactionmanager_p.cpp"
