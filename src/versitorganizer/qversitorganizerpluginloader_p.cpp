// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qversitorganizerpluginloader_p.h"
#include "qversitorganizerpluginsearch_p.h"

#include <QtCore/qpluginloader.h>

#include "qversitorganizerhandler.h"
#include "qversittimezonehandler.h"

QT_BEGIN_NAMESPACE_VERSITORGANIZER

/*!
   A less-than function for factory indices (see QVersitOrganizerHandlerFactory::index()).
   Positive values come first (ascendingly), then zero, then negative values (ascendingly).
 */
bool factoryLessThan(QVersitOrganizerHandlerFactory* a, QVersitOrganizerHandlerFactory* b) {
    if ((a->index() > 0 && b->index() > 0)
            || (a->index() < 0 && b->index() < 0))
        // same sign
        return a->index() < b->index();
    else
        // a is zero
        // or b is zero
        // or opposite sign
        return b->index() < a->index();
}

QVersitOrganizerPluginLoader* QVersitOrganizerPluginLoader::mInstance = NULL;

/*!
 * \class QVersitOrganizerPluginLoader
 * \internal
 * This is a singleton class that loads Versit plugins for organizer item processing
 */

QVersitOrganizerPluginLoader::QVersitOrganizerPluginLoader() : mTimeZoneHandler(NULL)
{
}

/*!
 * Returns the singleton instance of the QVersitOrganizerPluginLoader.
 */
QVersitOrganizerPluginLoader* QVersitOrganizerPluginLoader::instance()
{
    if (!mInstance)
        mInstance = new QVersitOrganizerPluginLoader;
    return mInstance;
}

void QVersitOrganizerPluginLoader::loadPlugins() {
    QStringList plugins = mobilityPlugins(QStringLiteral("versit"));
    if (plugins != mPluginPaths) {
        mPluginPaths = plugins;

        foreach (const QString& pluginPath, mPluginPaths) {
            QPluginLoader qpl(pluginPath);
            QObject* plugin = qpl.instance();
            QVersitOrganizerHandlerFactory* organizerPlugin =
                qobject_cast<QVersitOrganizerHandlerFactory*>(plugin);
            if (organizerPlugin && !mLoadedFactories.contains(organizerPlugin->name())) {
                mLoadedFactories.insert(organizerPlugin->name());
                mOrganizerHandlerFactories.append(organizerPlugin);
            } else if (!mTimeZoneHandler) {
                QVersitTimeZoneHandler* timeZonePlugin =
                    qobject_cast<QVersitTimeZoneHandler*>(plugin);
                if (timeZonePlugin) {
                    mTimeZoneHandler = timeZonePlugin;
                }
            }
        }
        std::sort(mOrganizerHandlerFactories.begin(), mOrganizerHandlerFactories.end(), factoryLessThan);
    }
}

/*!
 * Creates and returns handlers from the plugin.  If \a profile is the empty string, only handlers
 * with an empty profile list are returned.  If \a profile is nonempty, only handlers with either
 * an empty profile list or a profile list that contains the given \a profile are returned.
 *
 * The caller is responsible for deleting all returned handlers.
 */
QList<QVersitOrganizerHandler*> QVersitOrganizerPluginLoader::createOrganizerHandlers(const QString& profile)
{
    loadPlugins();

    QList<QVersitOrganizerHandler*> handlers;
    foreach (const QVersitOrganizerHandlerFactory* factory, mOrganizerHandlerFactories) {
        if (factory->profiles().isEmpty() ||
                (!profile.isEmpty() && factory->profiles().contains(profile))) {
            QVersitOrganizerHandler* handler = factory->createHandler();
            handlers.append(handler);
        }
    }
    return handlers;
}

QVersitTimeZoneHandler* QVersitOrganizerPluginLoader::timeZoneHandler()
{
    loadPlugins();

    return mTimeZoneHandler;
}

QT_END_NAMESPACE_VERSITORGANIZER
