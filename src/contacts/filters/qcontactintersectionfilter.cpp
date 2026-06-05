// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qcontactintersectionfilter.h"
#include "qcontactintersectionfilter_p.h"

QT_BEGIN_NAMESPACE_CONTACTS

/*!
  \class QContactIntersectionFilter
  \brief The QContactIntersectionFilter class provides a filter which intersects the results of other filters.

  \inmodule QtContacts

   \ingroup contacts-filters

  It may be used to select contacts which match all of the filters in the intersection
 */

Q_IMPLEMENT_CONTACTFILTER_PRIVATE(QContactIntersectionFilter);

/*!
 * \fn QContactIntersectionFilter::QContactIntersectionFilter(const QContactFilter& other)
 * Constructs a copy of \a other if possible, otherwise constructs a new intersection filter
 */

/*!
 * Constructs a new intersection filter
 */
QContactIntersectionFilter::QContactIntersectionFilter()
    : QContactFilter(new QContactIntersectionFilterPrivate)
{
}

/*!
 * Sets the filters whose criteria will be intersected to \a filters
 * \sa filters(), clear()
 */
void QContactIntersectionFilter::setFilters(const QList<QContactFilter>& filters)
{
    Q_D(QContactIntersectionFilter);
    d->m_filters = filters;
}

/*!
 * Clears the list of filters.  A cleared intersection filter will match no contacts.
 * \sa filters(), setFilters()
 */
void QContactIntersectionFilter::clear()
{
    Q_D(QContactIntersectionFilter);
    d->m_filters.clear();
}

/*!
 * Prepends the given \a filter to the list of intersected filters
 * \sa append(), filters()
 */
void QContactIntersectionFilter::prepend(const QContactFilter& filter)
{
    Q_D(QContactIntersectionFilter);
    d->m_filters.prepend(filter);
}

/*!
 * Appends the given \a filter to the list of intersected filters
 * \sa operator<<(), prepend(), filters()
 */
void QContactIntersectionFilter::append(const QContactFilter& filter)
{
    Q_D(QContactIntersectionFilter);
    d->m_filters.append(filter);
}

/*!
 * Removes the given \a filter from the intersection list
 * \sa filters(), append(), prepend(), clear()
 */
void QContactIntersectionFilter::remove(const QContactFilter& filter)
{
    Q_D(QContactIntersectionFilter);
    d->m_filters.removeAll(filter);
}

/*!
 * Appends the given \a filter to the list of intersected filters
 * \sa append()
 */
QContactIntersectionFilter& QContactIntersectionFilter::operator<<(const QContactFilter& filter)
{
    Q_D(QContactIntersectionFilter);
    d->m_filters << filter;
    return *this;
}

/*!
 * Returns the list of filters which form the intersection filter
 * \sa setFilters(), prepend(), append(), remove()
 */
QList<QContactFilter> QContactIntersectionFilter::filters() const
{
    Q_D(const QContactIntersectionFilter);
    return d->m_filters;
}

QT_END_NAMESPACE_CONTACTS
