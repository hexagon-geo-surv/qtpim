// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QVERSITCONTACTPLUGINLOADER_P_H
#define QVERSITCONTACTPLUGINLOADER_P_H

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

#include <QtCore/qset.h>
#include <QtCore/qstringlist.h>

#include <QtVersit/qversitcontacthandler.h>

QT_BEGIN_NAMESPACE_VERSIT

class QVersitContactPluginLoader
{
    private:
        QVersitContactPluginLoader();

    public:
        static QVersitContactPluginLoader* instance();
        QList<QVersitContactHandler*> createContactHandlers(const QStringList& profiles);

    private:
        void loadPlugins();

        static QVersitContactPluginLoader* mInstance;
        QSet<QString> mLoadedFactories;
        QList<QVersitContactHandlerFactory*> mContactHandlerFactories;
        QStringList mPluginPaths;
};

QT_END_NAMESPACE_VERSIT

#endif // QVERSITCONTACTPLUGINLOADER_P_H
