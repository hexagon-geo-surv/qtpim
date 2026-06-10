// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QCONTACTACTIONSERVICEMANAGER_P_H
#define QCONTACTACTIONSERVICEMANAGER_P_H

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
#include <QtCore/qmutex.h>

#include <QtContacts/private/qcontactactionmanager_p.h>

#include "qservicemanager.h"

QTM_BEGIN_NAMESPACE

class QContactAction;
class QContactActionFactory;

class QContactActionServiceManager : public QObject, public QContactActionManagerPlugin
{
    Q_OBJECT
    Q_INTERFACES(QtMobility::QContactActionManagerPlugin)
public:
    static QContactActionServiceManager* instance();

    // this is a private class, so despite being a singleton we make this ctor public.
    QContactActionServiceManager();
    ~QContactActionServiceManager();

    QHash<QContactActionDescriptor, QContactActionFactory*> actionFactoryHash();
    QMultiHash<QString, QContactActionDescriptor> descriptorHash();

public slots:
    void serviceAdded(const QString& serviceName);
    void serviceRemoved(const QString& serviceName);

private:
    void init();
    bool initLock;

    QMutex m_instanceMutex;
    QServiceManager m_serviceManager;

    QHash<QContactActionDescriptor, QContactActionFactory*> m_actionFactoryHash; // descriptor to action factory ptr.
    QMultiHash<QString, QContactActionDescriptor> m_descriptorHash;  // action name to descriptor
};

QTM_END_NAMESPACE

#endif // QCONTACTACTIONSERVICEMANAGER_P_H
