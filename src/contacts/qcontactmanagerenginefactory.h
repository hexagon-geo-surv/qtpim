// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QCONTACTMANAGERENGINEFACTORY_H
#define QCONTACTMANAGERENGINEFACTORY_H

#include <QtCore/qfactoryinterface.h>
#include <QtCore/qplugin.h>

#include <QtContacts/qcontactmanager.h>

QT_BEGIN_NAMESPACE_CONTACTS

struct Q_CONTACTS_EXPORT QContactManagerEngineFactoryInterface : public QFactoryInterface
{
    virtual QContactManagerEngine *engine(const QMap<QString, QString> &parameters, QContactManager::Error *error) = 0;
    virtual QString managerName() const = 0;
};
QT_END_NAMESPACE_CONTACTS

QT_BEGIN_NAMESPACE
#define QT_CONTACT_MANAGER_ENGINE_INTERFACE "org.qt-project.Qt.QContactManagerEngineFactoryInterface"
Q_DECLARE_INTERFACE(QtContacts::QContactManagerEngineFactoryInterface, QT_CONTACT_MANAGER_ENGINE_INTERFACE)
QT_END_NAMESPACE

QT_BEGIN_NAMESPACE_CONTACTS
class Q_CONTACTS_EXPORT QContactManagerEngineFactory : public QObject, public QContactManagerEngineFactoryInterface
{
    Q_OBJECT
    Q_INTERFACES(QtContacts::QContactManagerEngineFactoryInterface:QFactoryInterface)
public:
    // engine factory functions
    virtual QList<int> supportedImplementationVersions() const;
    virtual ~QContactManagerEngineFactory();
    virtual QContactManagerEngine* engine(const QMap<QString, QString> &parameters, QContactManager::Error *error) override = 0;
    virtual QString managerName() const override = 0;
    virtual QStringList keys() const override;
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTMANAGERENGINEFACTORY_H
