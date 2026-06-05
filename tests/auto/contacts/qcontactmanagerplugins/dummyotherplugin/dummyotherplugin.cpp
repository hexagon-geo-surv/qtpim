// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

/* Implement a dynamic plugin with a non contacts interface to make sure it doesn't get used */
#include <QObject>
#include <QtPlugin>

class BoringInterface
{
    public:
        void doNothing() {}
};

QT_BEGIN_NAMESPACE
Q_DECLARE_INTERFACE(BoringInterface, "REALLYBORING!");
QT_END_NAMESPACE

class BoringFactory : public QObject, public BoringInterface
{
    Q_OBJECT
    Q_INTERFACES(BoringInterface)
    Q_PLUGIN_METADATA(IID "REALLYBORING!")
};

#include "dummyotherplugin.moc"
