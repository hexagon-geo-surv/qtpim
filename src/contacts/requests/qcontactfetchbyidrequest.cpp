// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qcontactfetchbyidrequest.h"

#include "qcontactrequests_p.h"

QT_BEGIN_NAMESPACE_CONTACTS

/*!
  \class QContactFetchByIdRequest
  \brief The QContactFetchByIdRequest class allows a client to asynchronously
    request contacts from a contacts store manager, given a list of contact IDs.

  The contacts fetched by the backend should have a one-to-one correspondence to the
  IDs passed into this class.  That is, the nth contact in the returned list should
  have an ID which is equal to the nth ID in the list of IDs.  Any invalid ID should
  correspond to an empty QContact.

  For a QContactFetchByIdRequest, the resultsAvailable() signal will be emitted when the
  resultant contacts (which may be retrieved by calling contacts()), are updated, as well
  as if the overall operation error (which may be retrieved by calling error()) is
  updated.

  Please see the class documentation of QContactAbstractRequest for more information about
  the usage of request classes and ownership semantics.


  \inmodule QtContacts

  \ingroup contacts-requests
 */

/*! Constructs a new contact fetch request whose parent is the specified \a parent */
QContactFetchByIdRequest::QContactFetchByIdRequest(QObject* parent)
    : QContactAbstractRequest(new QContactFetchByIdRequestPrivate, parent)
{
}

/*! Frees any memory used by this request */
QContactFetchByIdRequest::~QContactFetchByIdRequest()
{
}

/*!
  Sets the list of ids of the contacts that the backend should retrieve to \a ids.
 */
void QContactFetchByIdRequest::setIds(const QList<QContactId>& ids)
{
    Q_D(QContactFetchByIdRequest);
    QMutexLocker ml(&d->m_mutex);
    d->m_contactIds = ids;
}

/*!
  Sets the fetch hint which may be used by the backend to optimize contact retrieval
  to \a fetchHint.  A client should not make changes to a contact which has been retrieved
  using a fetch hint other than the default fetch hint.  Doing so will result in information
  loss when saving the contact back to the manager (as the "new" restricted contact will
  replace the previously saved contact in the backend).
  \sa QContactFetchHint
 */
void QContactFetchByIdRequest::setFetchHint(const QContactFetchHint &fetchHint)
{
    Q_D(QContactFetchByIdRequest);
    QMutexLocker ml(&d->m_mutex);
    d->m_fetchHint = fetchHint;
}

/*!
  Returns the list of ids of the contacts that the backend should retrieve.
 */
QList<QContactId> QContactFetchByIdRequest::contactIds() const
{
    Q_D(const QContactFetchByIdRequest);
    QMutexLocker ml(&d->m_mutex);
    return d->m_contactIds;
}

/*!
  Returns the fetch hint which may be used by the backend to optimize contact retrieval.
  A client should not make changes to a contact which has been retrieved
  using a fetch hint other than the default fetch hint.  Doing so will result in information
  loss when saving the contact back to the manager (as the "new" restricted contact will
  replace the previously saved contact in the backend).
  \sa QContactFetchHint
 */
QContactFetchHint QContactFetchByIdRequest::fetchHint() const
{
    Q_D(const QContactFetchByIdRequest);
    QMutexLocker ml(&d->m_mutex);
    return d->m_fetchHint;
}

/*! Returns the list of contacts retrieved by this request */
QList<QContact> QContactFetchByIdRequest::contacts() const
{
    Q_D(const QContactFetchByIdRequest);
    QMutexLocker ml(&d->m_mutex);
    return d->m_contacts;
}

/*!
  Returns the map of input definition list indices to errors which occurred.
  In case of global errors like QContactManager::TimeoutError affecting to
  all items in the input definitions the error map may be empty.
*/
QMap<int, QContactManager::Error> QContactFetchByIdRequest::errorMap() const
{
    Q_D(const QContactFetchByIdRequest);
    QMutexLocker ml(&d->m_mutex);
    return d->m_errors;
}

QT_END_NAMESPACE_CONTACTS

#include "moc_qcontactfetchbyidrequest.cpp"
