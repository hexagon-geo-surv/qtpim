// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QVERSITORGANIZERPLUGINLOADER_P_H
#define QVERSITORGANIZERPLUGINLOADER_P_H

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

#include <QtVersitOrganizer/qversitorganizerglobal.h>

QT_BEGIN_NAMESPACE_VERSITORGANIZER

class QVersitOrganizerHandler;
class QVersitOrganizerHandlerFactory;
class QVersitTimeZoneHandler;

class QVersitOrganizerPluginLoader
{
    private:
        QVersitOrganizerPluginLoader();

    public:
        static QVersitOrganizerPluginLoader* instance();
        QList<QVersitOrganizerHandler*> createOrganizerHandlers(const QString& profile);
        QVersitTimeZoneHandler* timeZoneHandler();

    private:
        void loadPlugins();

        static QVersitOrganizerPluginLoader* mInstance;
        QSet<QString> mLoadedFactories;
        QList<QVersitOrganizerHandlerFactory*> mOrganizerHandlerFactories;
        QVersitTimeZoneHandler* mTimeZoneHandler;
        QStringList mPluginPaths;
};

QT_END_NAMESPACE_VERSITORGANIZER

#endif // QVERSITORGANIZERPLUGINLOADER_P_H
