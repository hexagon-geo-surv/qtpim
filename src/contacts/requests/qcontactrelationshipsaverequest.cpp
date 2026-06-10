// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qcontactrelationshipsaverequest.h"

#include "qcontactrequests_p.h"

QT_BEGIN_NAMESPACE_CONTACTS

/*!
  \class QContactRelationshipSaveRequest
  \brief The QContactRelationshipSaveRequest class allows a client to asynchronously
    request that certain groups be saved to a contacts store.

  For a QContactRelationshipSaveRequest, the resultsAvailable() signal will be emitted when
  either the individual item errors (which may be retrieved by calling errorMap()), or the resultant
  relationships (which may be retrieved by calling relationships()), are updated, as well as if
  the overall operation error (which may be retrieved by calling error()) is updated.

  Please see the class documentation of QContactAbstractRequest for more information about
  the usage of request classes and ownership semantics.


  \inmodule QtContacts

  \ingroup contacts-requests
 */

/*! Constructs a new relationship save request whose parent is the specified \a parent */
QContactRelationshipSaveRequest::QContactRelationshipSaveRequest(QObject* parent)
    : QContactAbstractRequest(new QContactRelationshipSaveRequestPrivate, parent)
{
}

/*! Frees any memory used by this request */
QContactRelationshipSaveRequest::~QContactRelationshipSaveRequest()
{
}

/*!
  Sets the relationship to save to be \a contactRelationship.
  Equivalent to calling:
  \code
      setRelationships(QList<QContactRelationship>() << contactRelationships);
  \endcode
 */
void QContactRelationshipSaveRequest::setRelationship(const QContactRelationship& contactRelationship)
{
    Q_D(QContactRelationshipSaveRequest);
    QMutexLocker ml(&d->m_mutex);
    d->m_relationships.clear();
    d->m_relationships.append(contactRelationship);
}

/*! Sets the relationships to save to be \a contactRelationships
*/
void QContactRelationshipSaveRequest::setRelationships(const QList<QContactRelationship>& contactRelationships)
{
    Q_D(QContactRelationshipSaveRequest);
    QMutexLocker ml(&d->m_mutex);
    d->m_relationships = contactRelationships;
}

/*! Returns the list of relationships that will be saved if called prior to calling \c start(),
    otherwise returns the list of relationships as they were saved in the contacts store
*/
QList<QContactRelationship> QContactRelationshipSaveRequest::relationships() const
{
    Q_D(const QContactRelationshipSaveRequest);
    QMutexLocker ml(&d->m_mutex);
    return d->m_relationships;
}

/*! Returns the map of input relationship list indices to errors which occurred
*/
QMap<int, QContactManager::Error> QContactRelationshipSaveRequest::errorMap() const
{
    Q_D(const QContactRelationshipSaveRequest);
    QMutexLocker ml(&d->m_mutex);
    return d->m_errors;
}


QT_END_NAMESPACE_CONTACTS

#include "moc_qcontactrelationshipsaverequest.cpp"
