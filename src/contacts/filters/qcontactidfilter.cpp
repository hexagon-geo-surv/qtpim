// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qcontactidfilter.h"
#include "qcontactidfilter_p.h"

QT_BEGIN_NAMESPACE_CONTACTS

/*!
  \class QContactIdFilter
  \brief The QContactIdFilter class provides a filter based around a list of contact ids


  \inmodule QtContacts

  \ingroup contacts-filters

  It may be used to select contacts whose ids are contained in the given list of ids.
 */

Q_IMPLEMENT_CONTACTFILTER_PRIVATE(QContactIdFilter);

/*!
 * \fn QContactIdFilter::QContactIdFilter(const QContactFilter& other)
 * Constructs a copy of \a other if possible, otherwise constructs a new contact id filter
 */

/*!
 * Constructs a new contact id filter
 */
QContactIdFilter::QContactIdFilter()
    : QContactFilter(new QContactIdFilterPrivate)
{
}

/*!
 * Sets the list which contains the ids of possible matching contacts to \a ids
 * \sa ids()
 */
void QContactIdFilter::setIds(const QList<QContactId>& ids)
{
    Q_D(QContactIdFilter);
    d->m_ids = ids;
}

/*!
 * Adds the id \a id into the list which contains the ids of possible matching contacts
 * \sa setIds()
 */
void QContactIdFilter::add(const QContactId& id)
{
    Q_D(QContactIdFilter);
    if (!d->m_ids.contains(id))
        d->m_ids.append(id);
}

/*!
 * Removes the id \a id from the list which contains the ids of possible matching contacts,
 * if it is contained in the list, otherwise has no effect.
 * \sa clear()
 */
void QContactIdFilter::remove(const QContactId& id)
{
    Q_D(QContactIdFilter);
    d->m_ids.removeAll(id);
}

/*!
 * Clears the list which contains the ids of possible matching contacts.
 * An id filter with a cleared list will match no contacts.
 * \sa setIds()
 */
void QContactIdFilter::clear()
{
    Q_D(QContactIdFilter);
    d->m_ids.clear();
}

/*!
 * Returns the list of ids of contacts which match this filter
 * \sa setIds()
 */
QList<QContactId> QContactIdFilter::ids() const
{
    Q_D(const QContactIdFilter);
    return d->m_ids;
}

QT_END_NAMESPACE_CONTACTS
