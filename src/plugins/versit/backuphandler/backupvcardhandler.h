// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:critical reason:data-parser

#ifndef TESTVCARDHANDLER_H
#define TESTVCARDHANDLER_H

#include <QtCore/qplugin.h>

#include <QtVersit/qversitcontacthandler.h>

QT_BEGIN_NAMESPACE_VERSIT

class BackupVCardHandlerFactory : public QVersitContactHandlerFactory
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QVersitContactHandlerFactoryInterface" FILE "backuphandler.json")

public:
    QSet<QString> profiles() const override;
    QString name() const override;
    int index() const override;
    QVersitContactHandler* createHandler() const override;
    QStringList keys() const override;
};

QT_END_NAMESPACE_VERSIT

#endif // TESTVCARDHANDLER_H
