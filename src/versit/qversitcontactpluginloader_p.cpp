// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qversitcontactpluginloader_p.h"

#include <QtCore/qpluginloader.h>

#include <utility>

#include "qversitpluginsearch_p.h"

QT_BEGIN_NAMESPACE_VERSIT

/*!
   A less-than function for factory indices (see QVersitContactHandlerFactory::index()).
   Positive values come first (ascendingly), then zero, then negative values (ascendingly).
 */
bool factoryLessThan(QVersitContactHandlerFactory* a, QVersitContactHandlerFactory* b) {
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

QVersitContactPluginLoader* QVersitContactPluginLoader::mInstance = NULL;

/*!
 * \class QVersitContactPluginLoader
 * This is a singleton class that loads Versit plugins for contacts processing
  \inmodule QtVersit
 */

QVersitContactPluginLoader::QVersitContactPluginLoader()
{
}

/*!
 * Returns the singleton instance of the QVersitContactPluginLoader.
 */
QVersitContactPluginLoader* QVersitContactPluginLoader::instance()
{
    if (!mInstance)
        mInstance = new QVersitContactPluginLoader;
    return mInstance;
}

void QVersitContactPluginLoader::loadPlugins() {
    QStringList plugins = mobilityPlugins(QStringLiteral("versit"));
    if (plugins != mPluginPaths) {
        mPluginPaths = plugins;

        for (const QString& pluginPath : std::as_const(mPluginPaths)) {
            QPluginLoader qpl(pluginPath);
            QObject* plugin = qpl.instance();
            QVersitContactHandlerFactory* contactPlugin =
                qobject_cast<QVersitContactHandlerFactory*>(plugin);
            if (contactPlugin && !mLoadedFactories.contains(contactPlugin->name())) {
                mLoadedFactories.insert(contactPlugin->name());
                mContactHandlerFactories.append(contactPlugin);
            }
        }
        std::sort(mContactHandlerFactories.begin(), mContactHandlerFactories.end(), factoryLessThan);
    }
}

/*!
 * Creates and returns handlers from the plugin.  If \a profiles is the empty string, only handlers
 * with an empty profile list are returned.  If \a profiles is nonempty, only handlers with either
 * an empty profile list or a profile list that contains the given \a profiles are returned.
 *
 * The caller is responsible for deleting all returned handlers.
 */
QList<QVersitContactHandler*> QVersitContactPluginLoader::createContactHandlers(const QStringList& profiles)
{
    loadPlugins();

    QList<QVersitContactHandler*> handlers;
    for (const QVersitContactHandlerFactory* factory : std::as_const(mContactHandlerFactories)) {
        // if the plugin specifies no profiles, include it
        QSet<QString> factoryProfiles(factory->profiles());
        bool includePlugin = factory->profiles().isEmpty();
        if (!includePlugin) {
            // if the plugin's profile list intersects with the requested profile list, include it.
            for (const QString& profile : profiles) {
                if (factoryProfiles.contains(profile)) {
                    includePlugin = true;
                    break;
                }
            }
        }

        if (includePlugin) {
            QVersitContactHandler* handler = factory->createHandler();
            handlers.append(handler);
        }
    }
    return handlers;
}

QT_END_NAMESPACE_VERSIT
