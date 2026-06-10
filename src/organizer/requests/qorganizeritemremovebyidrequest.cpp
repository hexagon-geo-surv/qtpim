// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qorganizeritemremovebyidrequest.h"

#include "qorganizeritemrequests_p.h"

QT_BEGIN_NAMESPACE_ORGANIZER

/*!
   \class QOrganizerItemRemoveByIdRequest
   \brief The QOrganizerItemRemoveByIdRequest class allows a client to asynchronously
   request that certain organizer items be removed from a organizer items store.
   \inmodule QtOrganizer

   For a QOrganizerItemRemoveByIdRequest, the resultsUpdated() signal will be emitted when
   the individual item errors (which may be retrieved by calling errorMap()) are updated, or if the overall
   operation error (which may be retrieved by calling error()) is updated.

   \ingroup organizer-requests
 */

/*!
    Constructs a new organizer item remove request whose parent is the specified \a parent
 */
QOrganizerItemRemoveByIdRequest::QOrganizerItemRemoveByIdRequest(QObject* parent)
    : QOrganizerAbstractRequest(new QOrganizerItemRemoveByIdRequestPrivate, parent)
{
}

/*!
    Frees memory in use by this request
*/
QOrganizerItemRemoveByIdRequest::~QOrganizerItemRemoveByIdRequest()
{
}

/*!
   Sets the id of the organizer item which will be removed to \a organizeritemId.
   Equivalent to calling:
   \code
       setOrganizerItemIds(QList<QOrganizerItemId>() << organizeritemIds);
   \endcode
 */
void QOrganizerItemRemoveByIdRequest::setItemId(const QOrganizerItemId& organizeritemId)
{
    Q_D(QOrganizerItemRemoveByIdRequest);
    QMutexLocker ml(&d->m_mutex);
    d->m_organizeritemIds.clear();
    d->m_organizeritemIds.append(organizeritemId);
}

/*!
    Sets the list of ids of organizer items which will be removed to \a organizeritemIds
 */
void QOrganizerItemRemoveByIdRequest::setItemIds(const QList<QOrganizerItemId>& organizeritemIds)
{
    Q_D(QOrganizerItemRemoveByIdRequest);
    QMutexLocker ml(&d->m_mutex);
    d->m_organizeritemIds = organizeritemIds;
}

/*!
    Returns the list of ids of organizer items which will be removed
 */
QList<QOrganizerItemId> QOrganizerItemRemoveByIdRequest::itemIds() const
{
    Q_D(const QOrganizerItemRemoveByIdRequest);
    QMutexLocker ml(&d->m_mutex);
    return d->m_organizeritemIds;
}

/*!
    Returns the map of input organizer item list indices to errors which occurred
 */
QMap<int, QOrganizerManager::Error> QOrganizerItemRemoveByIdRequest::errorMap() const
{
    Q_D(const QOrganizerItemRemoveByIdRequest);
    QMutexLocker ml(&d->m_mutex);
    return d->m_errors;
}


QT_END_NAMESPACE_ORGANIZER

#include "moc_qorganizeritemremovebyidrequest.cpp"
