// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qorganizercollectionfetchrequest.h"

#include "qorganizeritemrequests_p.h"

QT_BEGIN_NAMESPACE_ORGANIZER

/*!
    \class QOrganizerCollectionFetchRequest
    \brief The QOrganizerCollectionFetchRequest class allows a client to asynchronously fetch collections
           from a backend.
    \inmodule QtOrganizer
    \ingroup organizeritems-requests

    This request will fetch all the collections stored in the given backend.
 */

/*!
    Constructs a new organizeritem fetch request whose parent is the specified \a parent.
*/
QOrganizerCollectionFetchRequest::QOrganizerCollectionFetchRequest(QObject *parent)
    : QOrganizerAbstractRequest(new QOrganizerCollectionFetchRequestPrivate, parent)
{
}

/*!
    Frees memory in use by this request.
*/
QOrganizerCollectionFetchRequest::~QOrganizerCollectionFetchRequest()
{
}

/*!
    Returns the collections retrieved by this request.
*/
QList<QOrganizerCollection> QOrganizerCollectionFetchRequest::collections() const
{
    Q_D(const QOrganizerCollectionFetchRequest);
    QMutexLocker ml(&d->m_mutex);
    return d->m_collections;
}


QT_END_NAMESPACE_ORGANIZER

#include "moc_qorganizercollectionfetchrequest.cpp"
