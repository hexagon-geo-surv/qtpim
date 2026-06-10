// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qcontactrelationshipfetchrequest.h"

#include "qcontactrequests_p.h"

QT_BEGIN_NAMESPACE_CONTACTS

/*!
  \class QContactRelationshipFetchRequest

  \brief The QContactRelationshipFetchRequest class allows a client to
  asynchronously request relationships from a contacts store manager.

  For a QContactRelationshipFetchRequest, the resultsAvailable() signal will be emitted when the resultant
  relationships (which may be retrieved by calling relationships()), are updated, as well as if
  the overall operation error (which may be retrieved by calling error()) is updated.

  Please see the class documentation of QContactAbstractRequest for more information about
  the usage of request classes and ownership semantics.


  \inmodule QtContacts

  \ingroup contacts-requests
 */

/*! Constructs a new relationship fetch request whose parent is the specified \a parent
 */
QContactRelationshipFetchRequest::QContactRelationshipFetchRequest(QObject* parent)
    : QContactAbstractRequest(new QContactRelationshipFetchRequestPrivate, parent)
{
}

/*! Frees any memory used by this request */
QContactRelationshipFetchRequest::~QContactRelationshipFetchRequest()
{
}

/*! Sets the source contact criterion of the fetch request to \a firstContactId.
    If \a firstContactId is default-constructed, or the first contact is not set,
    the request will fetch relationships involving any first contact.
*/
void QContactRelationshipFetchRequest::setFirst(const QContactId& firstContactId)
{
    Q_D(QContactRelationshipFetchRequest);
    QMutexLocker ml(&d->m_mutex);
    d->m_first = firstContactId;
}

/*! Returns the ID of the source contact criterion of the fetch request
 */
QContactId QContactRelationshipFetchRequest::first() const
{
    Q_D(const QContactRelationshipFetchRequest);
    QMutexLocker ml(&d->m_mutex);
    return d->m_first;
}

/*! Sets the relationship type criterion of the fetch request to \a relationshipType.
    If \a relationshipType is empty, or the relationship type is not set,
    the request will fetch relationships of any type.
*/
void QContactRelationshipFetchRequest::setRelationshipType(const QString& relationshipType)
{
    Q_D(QContactRelationshipFetchRequest);
    QMutexLocker ml(&d->m_mutex);
    d->m_relationshipType = relationshipType;
}

/*! Returns the relationship type criterion of the fetch request
 */
QString QContactRelationshipFetchRequest::relationshipType() const
{
    Q_D(const QContactRelationshipFetchRequest);
    QMutexLocker ml(&d->m_mutex);
    return d->m_relationshipType;
}

/*! Sets the destination contact criterion of the fetch request to \a secondContactId.
    If \a secondContactId is default-constructed or the second contact is not set,
    the request will fetch relationships involving any second contact.
*/
void QContactRelationshipFetchRequest::setSecond(const QContactId& secondContactId)
{
    Q_D(QContactRelationshipFetchRequest);
    QMutexLocker ml(&d->m_mutex);
    d->m_second = secondContactId;
}

/*! Returns the ID of the destination contact criterion of the fetch request
 */
QContactId QContactRelationshipFetchRequest::second() const
{
    Q_D(const QContactRelationshipFetchRequest);
    QMutexLocker ml(&d->m_mutex);
    return d->m_second;
}


/*! Returns the list of relationships that was the result of the request
 */
QList<QContactRelationship> QContactRelationshipFetchRequest::relationships() const
{
    Q_D(const QContactRelationshipFetchRequest);
    QMutexLocker ml(&d->m_mutex);
    return d->m_relationships;
}


QT_END_NAMESPACE_CONTACTS

#include "moc_qcontactrelationshipfetchrequest.cpp"
