// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qorganizeritemremoverequest.h"

#include "qorganizeritemrequests_p.h"

QT_BEGIN_NAMESPACE_ORGANIZER

/*!
    \class QOrganizerItemRemoveRequest
    \brief The QOrganizerItemRemoveRequest class allows a client to asynchronously request that certain
           organizer items be removed from a backend.
    \inmodule QtOrganizer
    \ingroup organizer-requests

    This request will remove the items and all the occurrences (both generated and persisted) of the
    given items.
 */

/*!
    Constructs a new organizer item remove request whose parent is the specified \a parent.
*/
QOrganizerItemRemoveRequest::QOrganizerItemRemoveRequest(QObject *parent)
    : QOrganizerAbstractRequest(new QOrganizerItemRemoveRequestPrivate, parent)
{
}

/*!
    Frees memory in use by this request.
*/
QOrganizerItemRemoveRequest::~QOrganizerItemRemoveRequest()
{
}

/*!
  Sets the organizer item which will be removed to \a item.
  Equivalent to calling:
  \code
      setOrganizerItems(QList<QOrganizerItem>() << item);
  \endcode
 */
void QOrganizerItemRemoveRequest::setItem(const QOrganizerItem &item)
{
    Q_D(QOrganizerItemRemoveRequest);
    QMutexLocker ml(&d->m_mutex);
    d->m_organizeritems.clear();
    d->m_organizeritems.append(item);
}

/*! Sets the organizer items which will be removed to \a items
*/
void QOrganizerItemRemoveRequest::setItems(const QList<QOrganizerItem> &items)
{
    Q_D(QOrganizerItemRemoveRequest);
    QMutexLocker ml(&d->m_mutex);
    d->m_organizeritems = items;
}

/*!
    Returns the list of IDs of organizer items which will be removed.
*/
QList<QOrganizerItem> QOrganizerItemRemoveRequest::items() const
{
    Q_D(const QOrganizerItemRemoveRequest);
    QMutexLocker ml(&d->m_mutex);
    return d->m_organizeritems;
}

/*!
    Returns the map of input organizer item list indices to errors which occurred.
*/
QMap<int, QOrganizerManager::Error> QOrganizerItemRemoveRequest::errorMap() const
{
    Q_D(const QOrganizerItemRemoveRequest);
    QMutexLocker ml(&d->m_mutex);
    return d->m_errors;
}


QT_END_NAMESPACE_ORGANIZER

#include "moc_qorganizeritemremoverequest.cpp"
