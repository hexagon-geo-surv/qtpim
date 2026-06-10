// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qorganizeritemfetchbyidrequest.h"

#include "qorganizeritemrequests_p.h"

QT_BEGIN_NAMESPACE_ORGANIZER

/*!
    \class QOrganizerItemFetchByIdRequest
    \brief The QOrganizerItemFetchByIdRequest class allows a client to asynchronously
           fetch items from a backend, given a list of item IDs.
    \inmodule QtOrganizer
    \ingroup organizer-requests

    The items fetched by the backend should have a one-to-one correspondence to the IDs passed into
    this class.  That is, the nth item in the returned list should have an ID which is equal to the
    nth ID in the list of IDs.  Any invalid ID should correspond to an empty QOrganizerItem.
 */

/*!
    Constructs a new item fetch by ID request whose parent is the specified \a parent.
*/
QOrganizerItemFetchByIdRequest::QOrganizerItemFetchByIdRequest(QObject *parent)
    : QOrganizerAbstractRequest(new QOrganizerItemFetchByIdRequestPrivate, parent)
{
}

/*!
    Frees any memory used by this request.
*/
QOrganizerItemFetchByIdRequest::~QOrganizerItemFetchByIdRequest()
{
}

/*!
    Sets the list of IDs of the items that the backend should retrieve to \a ids.
 */
void QOrganizerItemFetchByIdRequest::setIds(const QList<QOrganizerItemId> &ids)
{
    Q_D(QOrganizerItemFetchByIdRequest);
    QMutexLocker ml(&d->m_mutex);
    d->m_ids = ids;
}

/*!
    Sets the fetch hint which may be used by the backend to optimize item retrieval to \a fetchHint.

    A client should not make changes to a item which has been retrieved using a fetch hint other than
    the default fetch hint.  Doing so will result in information loss when saving the item back to
    the manager (as the "new" restricted item will replace the previously saved item in the backend).
 */
void QOrganizerItemFetchByIdRequest::setFetchHint(const QOrganizerItemFetchHint &fetchHint)
{
    Q_D(QOrganizerItemFetchByIdRequest);
    QMutexLocker ml(&d->m_mutex);
    d->m_fetchHint = fetchHint;
}

/*!
    Returns the list of IDs of the items that the backend should retrieve.
 */
QList<QOrganizerItemId> QOrganizerItemFetchByIdRequest::ids() const
{
    Q_D(const QOrganizerItemFetchByIdRequest);
    QMutexLocker ml(&d->m_mutex);
    return d->m_ids;
}

/*!
    Returns the fetch hint which may be used by the backend to optimize item retrieval.

    A client should not make changes to a item which has been retrieved using a fetch hint other than
    the default fetch hint.  Doing so will result in information loss when saving the item back to
    the manager (as the "new" restricted item will replace the previously saved item in the backend).
 */
QOrganizerItemFetchHint QOrganizerItemFetchByIdRequest::fetchHint() const
{
    Q_D(const QOrganizerItemFetchByIdRequest);
    QMutexLocker ml(&d->m_mutex);
    return d->m_fetchHint;
}

/*!
    Returns the list of items retrieved by this request.
*/
QList<QOrganizerItem> QOrganizerItemFetchByIdRequest::items() const
{
    Q_D(const QOrganizerItemFetchByIdRequest);
    QMutexLocker ml(&d->m_mutex);
    return d->m_items;
}

/*!
    Returns the map of input definition list indices to errors which occurred.
*/
QMap<int, QOrganizerManager::Error> QOrganizerItemFetchByIdRequest::errorMap() const
{
    Q_D(const QOrganizerItemFetchByIdRequest);
    QMutexLocker ml(&d->m_mutex);
    return d->m_errors;
}


QT_END_NAMESPACE_ORGANIZER

#include "moc_qorganizeritemfetchbyidrequest.cpp"
