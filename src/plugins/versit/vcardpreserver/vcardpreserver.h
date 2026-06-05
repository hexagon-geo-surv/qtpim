// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef VCARDPRESERVER_H
#define VCARDPRESERVER_H

#include <QtCore/qplugin.h>

#include <QtVersit/qversitcontacthandler.h>

QT_BEGIN_NAMESPACE_VERSIT

class VCardPreserverFactory : public QVersitContactHandlerFactory
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QVersitContactHandlerFactoryInterface" FILE "vcardpreserver.json")

public:
    QSet<QString> profiles() const;
    QString name() const;
    int index() const;
    QVersitContactHandler* createHandler() const;
    virtual QStringList keys() const;
};

QT_END_NAMESPACE_VERSIT

#endif // VCARDPRESERVER_H
