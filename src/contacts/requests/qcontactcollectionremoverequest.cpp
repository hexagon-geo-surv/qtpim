// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qcontactcollectionremoverequest.h"

#include "qcontactrequests_p.h"

QT_BEGIN_NAMESPACE_CONTACTS

/*!
    \class QContactCollectionRemoveRequest
    \brief The QContactCollectionRemoveRequest class allows a client to asynchronously remove
           collections from a backend.
    \inmodule QtContacts
    \ingroup contact-requests
 */

/*!
    Constructs a new collection remove request whose parent is the specified \a parent.
*/
QContactCollectionRemoveRequest::QContactCollectionRemoveRequest(QObject *parent)
    : QContactAbstractRequest(new QContactCollectionRemoveRequestPrivate, parent)
{
}

/*!
    Frees memory in use by this request.
*/
QContactCollectionRemoveRequest::~QContactCollectionRemoveRequest()
{
}

/*!
    Sets the ID of collection which will be removed by this request to  \a collectionId.
*/
void QContactCollectionRemoveRequest::setCollectionId(const QContactCollectionId &collectionId)
{
    Q_D(QContactCollectionRemoveRequest);
    QMutexLocker ml(&d->m_mutex);
    d->m_collectionIds.clear();
    d->m_collectionIds.append(collectionId);
}

/*!
    Sets the list of IDs of collections which will be removed by this request to \a collectionIds.
*/
void QContactCollectionRemoveRequest::setCollectionIds(const QList<QContactCollectionId> &collectionIds)
{
    Q_D(QContactCollectionRemoveRequest);
    QMutexLocker ml(&d->m_mutex);
    d->m_collectionIds = collectionIds;
}

/*!
    Returns the list of IDs of collections which will be removed by this request.
*/
QList<QContactCollectionId> QContactCollectionRemoveRequest::collectionIds() const
{
    Q_D(const QContactCollectionRemoveRequest);
    QMutexLocker ml(&d->m_mutex);
    return d->m_collectionIds;
}

/*!
    Returns any errors which occurred during the request.
*/
QMap<int, QContactManager::Error> QContactCollectionRemoveRequest::errorMap() const
{
    Q_D(const QContactCollectionRemoveRequest);
    QMutexLocker ml(&d->m_mutex);
    return d->m_errors;
}

QT_END_NAMESPACE_CONTACTS

#include "moc_qcontactcollectionremoverequest.cpp"
