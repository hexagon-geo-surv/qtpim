// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qcontactcollectionsaverequest.h"

#include "qcontactrequests_p.h"

QT_BEGIN_NAMESPACE_CONTACTS

/*!
    \class QContactCollectionSaveRequest
    \brief The QContactCollectionSaveRequest class allows a client to asynchronously save collections
           to a backend.
    \inmodule QtContacts
    \ingroup contact-requests
 */

/*!
    Constructs a new collection save request whose parent is the specified \a parent.
*/
QContactCollectionSaveRequest::QContactCollectionSaveRequest(QObject *parent)
    : QContactAbstractRequest(new QContactCollectionSaveRequestPrivate, parent)
{
}

/*!
    Frees memory in use by this request.
*/
QContactCollectionSaveRequest::~QContactCollectionSaveRequest()
{
}

/*!
    Sets the collection which will be saved to \a collection.
*/
void QContactCollectionSaveRequest::setCollection(const QContactCollection &collection)
{
    Q_D(QContactCollectionSaveRequest);
    QMutexLocker ml(&d->m_mutex);
    d->m_collections.clear();
    d->m_collections.append(collection);
}

/*!
    Sets the list of collections which will be saved to \a collections.
*/
void QContactCollectionSaveRequest::setCollections(const QList<QContactCollection> &collections)
{
    Q_D(QContactCollectionSaveRequest);
    QMutexLocker ml(&d->m_mutex);
    d->m_collections = collections;
}

/*!
    Returns the collections which will be saved by this request if called prior to calling start(),
    otherwise returns the (possibly updated) collections which have been saved.
*/
QList<QContactCollection> QContactCollectionSaveRequest::collections() const
{
    Q_D(const QContactCollectionSaveRequest);
    QMutexLocker ml(&d->m_mutex);
    return d->m_collections;
}

/*!
    Returns the map of input definition list indices to errors which occurred.
*/
QMap<int, QContactManager::Error> QContactCollectionSaveRequest::errorMap() const
{
    Q_D(const QContactCollectionSaveRequest);
    QMutexLocker ml(&d->m_mutex);
    return d->m_errors;
}


QT_END_NAMESPACE_CONTACTS

#include "moc_qcontactcollectionsaverequest.cpp"
