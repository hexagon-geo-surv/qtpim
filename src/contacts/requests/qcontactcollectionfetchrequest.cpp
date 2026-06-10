// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qcontactcollectionfetchrequest.h"

#include "qcontactrequests_p.h"

QT_BEGIN_NAMESPACE_CONTACTS

/*!
    \class QContactCollectionFetchRequest
    \brief The QContactCollectionFetchRequest class allows a client to asynchronously fetch collections
           from a backend.
    \inmodule QtContacts
    \ingroup contacts-requests

    This request will fetch all the collections stored in the given backend.
 */

/*!
    Constructs a new contact fetch request whose parent is the specified \a parent.
*/
QContactCollectionFetchRequest::QContactCollectionFetchRequest(QObject *parent)
    : QContactAbstractRequest(new QContactCollectionFetchRequestPrivate, parent)
{
}

/*!
    Frees memory in use by this request.
*/
QContactCollectionFetchRequest::~QContactCollectionFetchRequest()
{
}

/*!
    Returns the collections retrieved by this request.
*/
QList<QContactCollection> QContactCollectionFetchRequest::collections() const
{
    Q_D(const QContactCollectionFetchRequest);
    QMutexLocker ml(&d->m_mutex);
    return d->m_collections;
}


QT_END_NAMESPACE_CONTACTS

#include "moc_qcontactcollectionfetchrequest.cpp"
