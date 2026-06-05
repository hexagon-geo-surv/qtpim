// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QCONTACTMANAGER_P_H
#define QCONTACTMANAGER_P_H

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

#include <QtCore/qhash.h>
#include <QtCore/qjsonobject.h>
#include <QtCore/qmap.h>
#include <QtCore/qstringlist.h>

#include <QtContacts/qcontactid.h>
#include <QtContacts/qcontactmanager.h>
#include <QtContacts/qcontactmanagerengine.h>
#include <QtContacts/qcontactobserver.h>
#include <QtContacts/private/qcontactactionmanager_p.h>


QT_BEGIN_NAMESPACE_CONTACTS

class QContactManagerEngineFactory;

/* Data and stuff that is shared amongst all backends */
class QContactManagerData
{
public:
    QContactManagerData()
        : m_engine(0),
        m_lastError(QContactManager::NoError)
    {
    }

    ~QContactManagerData()
    {
        delete m_engine;
    }

    // helpers
    static bool parseUri(const QString &uriString, QString *managerName, QMap<QString, QString> *params, bool strict = true);
    static QString buildUri(const QString &managerName, const QMap<QString, QString> &params);

    static bool parseIdData(const QByteArray &idData, QString *managerName, QMap<QString, QString> *params, QString *managerUri = 0, QByteArray *localId = 0);

    static QByteArray buildIdData(const QString &managerUri, const QByteArray &localId = QByteArray());
    static QByteArray buildIdData(const QString &managerName, const QMap<QString, QString> &params, const QByteArray &localId = QByteArray());

    static QString cachedUri(const QString &managerUri);

    void createEngine(const QString &managerName, const QMap<QString, QString> &parameters);
    static QContactManagerData* get(const QContactManager *manager);
    static QContactManagerEngine* engine(const QContactManager *manager);

    QContactManagerEngine* m_engine;
    QContactManager::Error m_lastError;
    QMap<int, QContactManager::Error> m_lastErrorMap;

    /* Manager plugins */
    static QMultiHash<QString, QContactManagerEngineFactory*> m_engines;
    static QSet<QContactManager*> m_aliveEngines;
    static QContactManagerData* managerData(QContactManager *manager) {return manager->d;}
    static QContactManagerData* managerData(const QContactManager *manager) {return manager->d;} // laziness to avoid const_cast
    static QList<QContactActionManagerPlugin*> m_actionManagers;
    static bool m_discoveredStatic;
    static QList<QJsonObject> m_pluginPaths;
    static QList<QJsonObject> m_metaData;
    static QStringList m_managerNames;
    static void loadFactoriesMetadata();
    static void loadStaticFactories();

    // Observer stuff
    static void registerObserver(QContactManager *m, QContactObserver *observer);
    static void unregisterObserver(QContactManager *m, QContactObserver *observer);
    void _q_contactsUpdated(const QList<QContactId> &ids, const QList<QContactDetail::DetailType> &typesChanged);
    void _q_contactsDeleted(const QList<QContactId> &ids);

    QMultiHash<QContactId, QContactObserver*> m_observerForContact;
private:
    Q_DISABLE_COPY(QContactManagerData)
};

/*
    Helper to hold the error state of a synchronous operation - when destructed, updates the
    manager's last error variables to the result of this operation.  This means that during
    callbacks the error state can't be modified behind the engines back. and it's more conceptually
    correct.
 */
class QContactManagerSyncOpErrorHolder
{
public:
    QContactManagerSyncOpErrorHolder(const QContactManager *m, QMap<int, QContactManager::Error> *pUserError = 0)
        : error(QContactManager::NoError),
        data(QContactManagerData::managerData(m)),
        userError(pUserError)
    {
    }

    ~QContactManagerSyncOpErrorHolder()
    {
        data->m_lastError = error;
        data->m_lastErrorMap = errorMap;
        if (userError)
            *userError = errorMap;
    }

    QContactManager::Error error;
    QContactManagerData* data;
    QMap<int, QContactManager::Error> errorMap;
    QMap<int, QContactManager::Error> *userError;
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTMANAGER_P_H
