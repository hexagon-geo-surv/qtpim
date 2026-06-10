// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QCONTACTACTIONMANAGER_P_H
#define QCONTACTACTIONMANAGER_P_H

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

#include <QtCore/qhash.h>
#include <QtCore/qlist.h>
#include <QtCore/qmutex.h>
#include <QtCore/qobject.h>

#include <QtContacts/qcontact.h>
#include <QtContacts/qcontactactiondescriptor.h>

QT_BEGIN_NAMESPACE_CONTACTS

class QContactAction;
class QContactActionFactory;

// For now this is a very direct interface, not really designed for extensibility
class QContactActionManagerPlugin {
public:
    virtual QHash<QContactActionDescriptor, QContactActionFactory*> actionFactoryHash() = 0; // descriptor to action factory ptr.
    virtual QMultiHash<QString, QContactActionDescriptor> descriptorHash() = 0;  // action name to descriptor
};

class QContactActionManager : public QObject
{
    Q_OBJECT
public:
    static QContactActionManager* instance();

    // this is a private class, so despite being a singleton we make this ctor public.
    QContactActionManager();
    ~QContactActionManager();

    QList<QContactActionDescriptor> availableActions(const QContact& contact);
    QList<QContactActionDescriptor> actionDescriptors(const QString& actionName = QString());
    QContactAction* action(const QContactActionDescriptor& descriptor);

private:
    void init();
    QMutex m_instanceMutex;
    QContactActionManagerPlugin* m_plugin;
};

QT_END_NAMESPACE_CONTACTS

QT_BEGIN_NAMESPACE
Q_DECLARE_INTERFACE(QtContacts::QContactActionManagerPlugin, "org.qt-project.Qt.QContactActionManagerPlugin")
QT_END_NAMESPACE

#endif // QCONTACTACTIONMANAGER_P_H
