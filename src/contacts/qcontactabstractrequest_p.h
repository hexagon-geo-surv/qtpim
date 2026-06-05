// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QCONTACTABSTRACTREQUEST_P_H
#define QCONTACTABSTRACTREQUEST_P_H

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

#include <QtCore/qmutex.h>
#include <QtCore/qpointer.h>

#include <QtContacts/qcontactabstractrequest.h>
#include <QtContacts/qcontactmanager.h>
#include <QtContacts/private/qcontactmanager_p.h>

QT_BEGIN_NAMESPACE_CONTACTS

class QContactAbstractRequestPrivate
{
public:
    QContactAbstractRequestPrivate(QContactAbstractRequest::RequestType type = QContactAbstractRequest::InvalidRequest)
        : m_type(type),
          m_error(QContactManager::NoError),
            m_state(QContactAbstractRequest::InactiveState),
            m_manager(0)
    {
    }

    virtual ~QContactAbstractRequestPrivate()
    {
    }

    const QContactAbstractRequest::RequestType m_type;

    QContactManager::Error m_error;
    QContactAbstractRequest::State m_state;
    QPointer<QContactManager> m_manager;

    mutable QMutex m_mutex;

#ifndef QT_NO_DEBUG_STREAM
    // NOTE: on platforms where Qt is built without debug streams enabled, vtable will differ!
    virtual QDebug& debugStreamOut(QDebug& dbg) const = 0;
#endif
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTABSTRACTREQUEST_P_H
