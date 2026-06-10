// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qorganizercollectionsaverequest.h"

#include "qorganizeritemrequests_p.h"

QT_BEGIN_NAMESPACE_ORGANIZER

/*!
    \class QOrganizerCollectionSaveRequest
    \brief The QOrganizerCollectionSaveRequest class allows a client to asynchronously save collections
           to a backend.
    \inmodule QtOrganizer
    \ingroup organizeritems-requests
 */

/*!
    Constructs a new collection save request whose parent is the specified \a parent.
*/
QOrganizerCollectionSaveRequest::QOrganizerCollectionSaveRequest(QObject *parent)
    : QOrganizerAbstractRequest(new QOrganizerCollectionSaveRequestPrivate, parent)
{
}

/*!
    Frees memory in use by this request.
*/
QOrganizerCollectionSaveRequest::~QOrganizerCollectionSaveRequest()
{
}

/*!
    Sets the collection which will be saved to \a collection.
*/
void QOrganizerCollectionSaveRequest::setCollection(const QOrganizerCollection &collection)
{
    Q_D(QOrganizerCollectionSaveRequest);
    QMutexLocker ml(&d->m_mutex);
    d->m_collections.clear();
    d->m_collections.append(collection);
}

/*!
    Sets the list of collections which will be saved to \a collections.
*/
void QOrganizerCollectionSaveRequest::setCollections(const QList<QOrganizerCollection> &collections)
{
    Q_D(QOrganizerCollectionSaveRequest);
    QMutexLocker ml(&d->m_mutex);
    d->m_collections = collections;
}

/*!
    Returns the collections which will be saved by this request if called prior to calling start(),
    otherwise returns the (possibly updated) collections which have been saved.
*/
QList<QOrganizerCollection> QOrganizerCollectionSaveRequest::collections() const
{
    Q_D(const QOrganizerCollectionSaveRequest);
    QMutexLocker ml(&d->m_mutex);
    return d->m_collections;
}

/*!
    Returns the map of input definition list indices to errors which occurred.
*/
QMap<int, QOrganizerManager::Error> QOrganizerCollectionSaveRequest::errorMap() const
{
    Q_D(const QOrganizerCollectionSaveRequest);
    QMutexLocker ml(&d->m_mutex);
    return d->m_errors;
}


QT_END_NAMESPACE_ORGANIZER

#include "moc_qorganizercollectionsaverequest.cpp"
