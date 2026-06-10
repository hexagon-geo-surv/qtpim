// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qcontactremoverequest.h"

#include "qcontactrequests_p.h"

QT_BEGIN_NAMESPACE_CONTACTS

/*!
  \class QContactRemoveRequest
  \brief The QContactRemoveRequest class allows a client to asynchronously
    request that certain contacts be removed from a contacts store.

  For a QContactRemoveRequest, the resultsUpdated() signal will be emitted when
  the individual item errors (which may be retrieved by calling errorMap()) are updated, or if the overall
  operation error (which may be retrieved by calling error()) is updated.

  Please see the class documentation of QContactAbstractRequest for more information about
  the usage of request classes and ownership semantics.


  \inmodule QtContacts

  \ingroup contacts-requests
 */

/*! Constructs a new contact remove request whose parent is the specified \a parent */
QContactRemoveRequest::QContactRemoveRequest(QObject* parent)
    : QContactAbstractRequest(new QContactRemoveRequestPrivate, parent)
{
}

/*! Frees any memory used by this request */
QContactRemoveRequest::~QContactRemoveRequest()
{
}

/*!
  Sets the id of the contact which will be removed to \a contactId.
  Equivalent to calling:
  \code
      setContactIds(QList<QContactId>() << contactIds);
  \endcode
 */
void QContactRemoveRequest::setContactId(const QContactId& contactId)
{
    Q_D(QContactRemoveRequest);
    QMutexLocker ml(&d->m_mutex);
    d->m_contactIds.clear();
    d->m_contactIds.append(contactId);
}

/*! Sets the list of ids of contacts which will be removed to \a contactIds
*/
void QContactRemoveRequest::setContactIds(const QList<QContactId>& contactIds)
{
    Q_D(QContactRemoveRequest);
    QMutexLocker ml(&d->m_mutex);
    d->m_contactIds = contactIds;
}

/*! Returns the list of ids of contacts which will be removed
*/
QList<QContactId> QContactRemoveRequest::contactIds() const
{
    Q_D(const QContactRemoveRequest);
    QMutexLocker ml(&d->m_mutex);
    return d->m_contactIds;
}

/*! Returns the map of input contact list indices to errors which occurred
*/
QMap<int, QContactManager::Error> QContactRemoveRequest::errorMap() const
{
    Q_D(const QContactRemoveRequest);
    QMutexLocker ml(&d->m_mutex);
    return d->m_errors;
}


QT_END_NAMESPACE_CONTACTS

#include "moc_qcontactremoverequest.cpp"
