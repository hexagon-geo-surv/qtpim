// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QVERSITCONTACTHANDLER_H
#define QVERSITCONTACTHANDLER_H

#include <QtCore/qfactoryinterface.h>
#include <QtCore/qset.h>

#include <QtVersit/qversitcontactimporter.h>
#include <QtVersit/qversitcontactexporter.h>

QT_BEGIN_NAMESPACE_VERSIT

// qdoc seems to not find QVersitContactHandler if it is declared first.. ugh
class QVersitContactHandler;

struct Q_VERSIT_EXPORT QVersitContactHandlerFactoryInterface : public QFactoryInterface
{
    virtual QSet<QString> profiles() const =0;
    virtual QString name() const = 0;
    virtual int index() const = 0;
    virtual QVersitContactHandler* createHandler() const = 0;
};
QT_END_NAMESPACE_VERSIT

QT_BEGIN_NAMESPACE
#define QT_VERSIT_CONTACT_HANDLER_INTERFACE "org.qt-project.Qt.QVersitContactHandlerFactoryInterface"
Q_DECLARE_INTERFACE(QtVersit::QVersitContactHandlerFactoryInterface, QT_VERSIT_CONTACT_HANDLER_INTERFACE)
QT_END_NAMESPACE

QT_BEGIN_NAMESPACE_VERSIT

class Q_VERSIT_EXPORT QVersitContactHandlerFactory : public QObject, public QVersitContactHandlerFactoryInterface
{
    Q_OBJECT
    Q_INTERFACES(QtVersit::QVersitContactHandlerFactoryInterface:QFactoryInterface)
public:
    virtual ~QVersitContactHandlerFactory() {}
    virtual QSet<QString> profiles() const override { return QSet<QString>(); }
    virtual QString name() const override = 0;
    virtual int index() const override { return 0; }
    virtual QVersitContactHandler* createHandler() const override = 0;
    virtual QStringList keys() const override;

    inline static const QString ProfileSync() {return QStringLiteral("Sync");};
    inline static const QString ProfileBackup() {return QStringLiteral("Backup");};
};

class Q_VERSIT_EXPORT QVersitContactHandler : public QVersitContactImporterPropertyHandlerV2,
                                              public QVersitContactExporterDetailHandlerV2
{
public:
    virtual ~QVersitContactHandler() {}
};
QT_END_NAMESPACE_VERSIT

#endif // QVERSITCONTACTHANDLER_H
