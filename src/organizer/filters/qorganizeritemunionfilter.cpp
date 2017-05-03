/****************************************************************************
**
** Copyright (C) 2017 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtOrganizer module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl-3.0.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or (at your option) the GNU General
** Public license version 3 or any later version approved by the KDE Free
** Qt Foundation. The licenses are as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-2.0.html and
** https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

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
