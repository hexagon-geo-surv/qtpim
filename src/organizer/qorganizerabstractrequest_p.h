// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QORGANIZERABSTRACTREQUEST_P_H
#define QORGANIZERABSTRACTREQUEST_P_H

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

#include <QtOrganizer/qorganizerabstractrequest.h>
#include <QtOrganizer/qorganizermanagerengine.h>
#include <QtOrganizer/private/qorganizermanager_p.h>

QT_BEGIN_NAMESPACE_ORGANIZER

class QOrganizerAbstractRequestPrivate
{
public:
    QOrganizerAbstractRequestPrivate(QOrganizerAbstractRequest::RequestType type = QOrganizerAbstractRequest::InvalidRequest)
        : m_type(type)
        , m_error(QOrganizerManager::NoError)
        , m_state(QOrganizerAbstractRequest::InactiveState)
        , m_manager(0)
    {
    }

    virtual ~QOrganizerAbstractRequestPrivate()
    {
    }

#ifndef QT_NO_DEBUG_STREAM
    virtual QDebug &debugStreamOut(QDebug &dbg) const = 0;
#endif

    const QOrganizerAbstractRequest::RequestType m_type;

    QOrganizerManager::Error m_error;
    QOrganizerAbstractRequest::State m_state;
    QPointer<QOrganizerManager> m_manager;
    QPointer<QOrganizerManagerEngine> m_engine;

    mutable QMutex m_mutex;
};

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERABSTRACTREQUEST_P_H
