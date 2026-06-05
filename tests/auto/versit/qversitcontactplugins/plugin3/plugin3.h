// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

#ifndef PLUGIN_H
#define PLUGIN_H

#include <QObject>
#include <QtVersit/qversitcontacthandler.h>
#include <QtVersit/qversitproperty.h>

QTVERSIT_USE_NAMESPACE

class Plugin3 : public QVersitContactHandlerFactory
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QVersitContactHandlerFactoryInterface" FILE "plugin3.json")

public:
    QString name() const override;
    int index() const override;
    QVersitContactHandler* createHandler() const override;
    QSet<QString> profiles() const override;
};

#endif
