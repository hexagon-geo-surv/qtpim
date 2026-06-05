// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qorganizeritemunionfilter.h"
#include "qorganizeritemunionfilter_p.h"

QT_BEGIN_NAMESPACE_ORGANIZER

/*!
    \class QOrganizerItemUnionFilter
    \brief The QOrganizerItemUnionFilter class provides a filter which unions the results of other filters.
    \inmodule QtOrganizer
    \ingroup organizer-filters

    It may be used to select organizer items which match any of the filters in the union.
 */

Q_IMPLEMENT_ORGANIZERITEMFILTER_PRIVATE(QOrganizerItemUnionFilter)

/*!
    \fn QOrganizerItemUnionFilter::QOrganizerItemUnionFilter(const QOrganizerItemFilter &other)

    Constructs a copy of \a other if possible, otherwise constructs a new union filter.
 */

/*!
     Constructs a new intersection filter.
 */
QOrganizerItemUnionFilter::QOrganizerItemUnionFilter()
    : QOrganizerItemFilter(new QOrganizerItemUnionFilterPrivate)
{
}

/*!
    Sets the filters whose criteria will be unioned to \a filters.

    \sa filters()
 */
void QOrganizerItemUnionFilter::setFilters(const QList<QOrganizerItemFilter> &filters)
{
    Q_D(QOrganizerItemUnionFilter);
    d->m_filters = filters;
}

/*!
    Prepends the given \a filter to the list of unioned filters.

    \sa append(), filters()
 */
void QOrganizerItemUnionFilter::prepend(const QOrganizerItemFilter &filter)
{
    Q_D(QOrganizerItemUnionFilter);
    d->m_filters.prepend(filter);
}

/*!
    Appends the given \a filter to the list of unioned filters.

    \sa operator<<(), prepend(), filters()
 */
void QOrganizerItemUnionFilter::append(const QOrganizerItemFilter &filter)
{
    Q_D(QOrganizerItemUnionFilter);
    d->m_filters.append(filter);
}

/*!
    Removes the given \a filter from the union list.

    \sa filters(), append(), prepend(), clear()
 */
void QOrganizerItemUnionFilter::remove(const QOrganizerItemFilter &filter)
{
    Q_D(QOrganizerItemUnionFilter);
    d->m_filters.removeAll(filter);
}

/*!
    Clears the list of filters. Note that an empty union filter will match no items.

    \sa filters(), remove()
 */
void QOrganizerItemUnionFilter::clear()
{
    Q_D(QOrganizerItemUnionFilter);
    d->m_filters.clear();
}

/*!
    Appends the given \a filter to the list of unioned filters.

    \sa append()
 */
QOrganizerItemUnionFilter &QOrganizerItemUnionFilter::operator<<(const QOrganizerItemFilter &filter)
{
    Q_D(QOrganizerItemUnionFilter);
    d->m_filters << filter;
    return *this;
}

/*!
    Returns the list of filters which form the union filter.

    \sa setFilters(), prepend(), append(), remove()
 */
QList<QOrganizerItemFilter> QOrganizerItemUnionFilter::filters() const
{
    Q_D(const QOrganizerItemUnionFilter);
    return d->m_filters;
}

QT_END_NAMESPACE_ORGANIZER
