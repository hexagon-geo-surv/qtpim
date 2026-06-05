// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qorganizeritemidfilter.h"
#include "qorganizeritemidfilter_p.h"

QT_BEGIN_NAMESPACE_ORGANIZER

/*!
    \class QOrganizerItemIdFilter
    \brief The QOrganizerItemIdFilter class provides a filter based around a list of organizer item IDs.
    \inmodule QtOrganizer
    \ingroup organizer-filters

    It may be used to select organizer items whose IDs are contained in the given list.

    Note: a QOrganizerItemIdFilter will not be preserved if streamed to a QDataStream.
 */

Q_IMPLEMENT_ORGANIZERITEMFILTER_PRIVATE(QOrganizerItemIdFilter)

/*!
    \fn QOrganizerItemIdFilter::QOrganizerItemIdFilter(const QOrganizerItemFilter &other)

    Constructs a copy of \a other if possible, otherwise constructs a new organizer item ID filter.
 */

/*!
    Constructs a new organizer item ID filter.
 */
QOrganizerItemIdFilter::QOrganizerItemIdFilter()
    : QOrganizerItemFilter(new QOrganizerItemIdFilterPrivate)
{
}

/*!
    Sets the list which contains the IDs of possible matching organizer items to \a ids.

    \sa ids()
 */
void QOrganizerItemIdFilter::setIds(const QList<QOrganizerItemId> &ids)
{
    Q_D(QOrganizerItemIdFilter);
    d->m_ids = ids;
}

/*!
    Inserts the \a id into the list which contains the IDs of possible matching items.

    \sa setIds()
 */
void QOrganizerItemIdFilter::insert(const QOrganizerItemId &id)
{
    Q_D(QOrganizerItemIdFilter);
    if (!d->m_ids.contains(id))
        d->m_ids.append(id);
}

/*!
    Removes the id \a id from the list which contains the IDs of possible matching items.

    \sa clear()
 */
void QOrganizerItemIdFilter::remove(const QOrganizerItemId &id)
{
    Q_D(QOrganizerItemIdFilter);
    d->m_ids.removeAll(id);
}

/*!
    Clears the list which contains the IDs of possible matching items. Note that an item ID filter
    with an empty list will match no items.

    \sa setIds()
 */
void QOrganizerItemIdFilter::clear()
{
    Q_D(QOrganizerItemIdFilter);
    d->m_ids.clear();
}

/*!
    Returns the list of IDs of organizer items which match this filter.

    \sa setIds()
 */
QList<QOrganizerItemId> QOrganizerItemIdFilter::ids() const
{
    Q_D(const QOrganizerItemIdFilter);
    return d->m_ids;
}

QT_END_NAMESPACE_ORGANIZER
