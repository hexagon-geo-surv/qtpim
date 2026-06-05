// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QORGANIZERMANAGERENGINEFACTORY_H
#define QORGANIZERMANAGERENGINEFACTORY_H

#include <QtCore/qfactoryinterface.h>
#include <QtCore/qplugin.h>

#include <QtOrganizer/qorganizermanager.h>

QT_BEGIN_NAMESPACE_ORGANIZER
struct Q_ORGANIZER_EXPORT QOrganizerManagerEngineFactoryInterface : public QFactoryInterface
{
    virtual QOrganizerManagerEngine *engine(const QMap<QString, QString> &parameters, QOrganizerManager::Error *error) = 0;
    virtual QString managerName() const = 0;
};
QT_END_NAMESPACE_ORGANIZER

QT_BEGIN_NAMESPACE
#define QT_ORGANIZER_MANAGER_ENGINE_INTERFACE "org.qt-project.Qt.QOrganizerManagerEngineFactoryInterface"
Q_DECLARE_INTERFACE(QtOrganizer::QOrganizerManagerEngineFactoryInterface, QT_ORGANIZER_MANAGER_ENGINE_INTERFACE)
QT_END_NAMESPACE

QT_BEGIN_NAMESPACE_ORGANIZER
class Q_ORGANIZER_EXPORT QOrganizerManagerEngineFactory : public QObject, public QOrganizerManagerEngineFactoryInterface
{
    Q_OBJECT
    Q_INTERFACES(QtOrganizer::QOrganizerManagerEngineFactoryInterface:QFactoryInterface)

public:
    virtual ~QOrganizerManagerEngineFactory();
    virtual QOrganizerManagerEngine *engine(const QMap<QString, QString> &parameters, QOrganizerManager::Error *error) override = 0;
    virtual QString managerName() const override = 0;

    QStringList keys() const override;
};
QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERMANAGERENGINEFACTORY_H
