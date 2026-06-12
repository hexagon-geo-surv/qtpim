// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

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
#include <QtCore/qlist.h>
#include <QtCore/qmap.h>
#include <QtCore/qstringlist.h>
#include <QtCore/private/qobject_p.h>

#include <QtOrganizer/qorganizermanager.h>
#include <QtOrganizer/qorganizermanagerengine.h>

QT_BEGIN_NAMESPACE_ORGANIZER

class QOrganizerItemObserver;
class QOrganizerManagerEngineFactory;

class QOrganizerManagerPrivate : public QObjectPrivate
{
    Q_DECLARE_PUBLIC(QOrganizerManager)
public:
    QOrganizerManagerPrivate()
        : m_engine(0), m_lastError(QOrganizerManager::NoError)
    {
    }

    ~QOrganizerManagerPrivate()
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
    static QOrganizerManagerPrivate *get(const QOrganizerManager *manager)
    { return static_cast<QOrganizerManagerPrivate *>(QObjectPrivate::get(const_cast<QOrganizerManager *>(manager))); }
    static QOrganizerManagerEngine *engine(const QOrganizerManager *manager);

    QOrganizerManagerEngine *m_engine;
    QOrganizerManager::Error m_lastError;
    QMap<int, QOrganizerManager::Error> m_lastErrorMap;

    // manager plugins
    static QMultiHash<QString, QOrganizerManagerEngineFactory *> m_engines;
    static bool m_discovered;
    static bool m_discoveredStatic;
    static QStringList m_pluginPaths;
    static void loadFactories();
    static void loadStaticFactories();

    // observer stuff
    void registerObserver(QOrganizerItemObserver *observer);
    void unregisterObserver(QOrganizerItemObserver *observer);
    void handleItemsChanged(const QList<QOrganizerItemId> &ids, const QList<QOrganizerItemDetail::DetailType> &typesChanged);
    void handleItemsRemoved(const QList<QOrganizerItemId> &ids);
    QMultiHash<QOrganizerItemId, QOrganizerItemObserver *> m_observerForItem;

    // helpers
    static QOrganizerManagerPrivate *managerData(const QOrganizerManager *m) { return get(m); }
};

/*!
    \internal

    Helper to hold the error state of a synchronous operation - when destructed, updates the
    manager's last error variables to the result of this operation.  This means that during
    callbacks the error state can't be modified behind the engines back. and it's more conceptually
    correct.
 */
class QOrganizerManagerSyncOpErrorHolder
{
public:
    QOrganizerManagerSyncOpErrorHolder(const QOrganizerManager *m, QMap<int, QOrganizerManager::Error> *pUserError = 0)
        : error(QOrganizerManager::NoError), data(QOrganizerManagerPrivate::managerData(m)), userError(pUserError)
    {
    }

    ~QOrganizerManagerSyncOpErrorHolder()
    {
        data->m_lastError = error;
        data->m_lastErrorMap = errorMap;
        if (userError)
            *userError = errorMap;
    }

    QOrganizerManager::Error error;
    QOrganizerManagerPrivate *data;
    QMap<int, QOrganizerManager::Error> errorMap;
    QMap<int, QOrganizerManager::Error> *userError;
};

QT_END_NAMESPACE_ORGANIZER

#endif // QCONTACTMANAGER_P_H
