/****************************************************************************
**
** Copyright (C) 2017 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtContacts module of the Qt Toolkit.
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

#include "qcontactunionfilter.h"
#include "qcontactunionfilter_p.h"

QT_BEGIN_NAMESPACE_CONTACTS

/*!
   \class QContactUnionFilter
   \brief The QContactUnionFilter class provides a filter which unions the
    results of other filters.


   \inmodule QtContacts

   \ingroup contacts-filters

   It may be used to select contacts which match all of the filters in the union
 */

Q_IMPLEMENT_CONTACTFILTER_PRIVATE(QContactUnionFilter);

/*!
 * \fn QContactUnionFilter::QContactUnionFilter(const QContactFilter& other)
 * Constructs a copy of \a other if possible, otherwise constructs a new union filter
 */

/*!
 * Constructs a new intersection filter
 */
QContactUnionFilter::QContactUnionFilter()
    : QContactFilter(new QContactUnionFilterPrivate)
{
}

/*!
 * Sets the filters whose criteria will be unioned to \a filters
 * \sa filters()
 */
void QContactUnionFilter::setFilters(const QList<QContactFilter>& filters)
{
    Q_D(QContactUnionFilter);
    d->m_filters = filters;
}

/*!
 * Clears the list of filters.  A cleared union filter will match no contacts.
 * \sa filters(), remove()
 */
void QContactUnionFilter::clear()
{
    Q_D(QContactUnionFilter);
    d->m_filters.clear();
}

/*!
 * Prepends the given \a filter to the list of unioned filters
 * \sa append(), filters()
 */
void QContactUnionFilter::prepend(const QContactFilter& filter)
{
    Q_D(QContactUnionFilter);
    d->m_filters.prepend(filter);
}

/*!
 * Appends the given \a filter to the list of unioned filters
 * \sa operator<<(), prepend(), filters()
 */
void QContactUnionFilter::append(const QContactFilter& filter)
{
    Q_D(QContactUnionFilter);
    d->m_filters.append(filter);
}

/*!
 * Removes the given \a filter from the union list
 * \sa filters(), append(), prepend(), clear()
 */
void QContactUnionFilter::remove(const QContactFilter& filter)
{
    Q_D(QContactUnionFilter);
    d->m_filters.removeAll(filter);
}

/*!
 * Appends the given \a filter to the list of unioned filters
 * \sa append()
 */
QContactUnionFilter& QContactUnionFilter::operator<<(const QContactFilter& filter)
{
    Q_D(QContactUnionFilter);
    d->m_filters << filter;
    return *this;
}

/*!
 * Returns the list of filters which form the union filter
 * \sa setFilters(), prepend(), append(), remove()
 */
QList<QContactFilter> QContactUnionFilter::filters() const
{
    Q_D(const QContactUnionFilter);
    return d->m_filters;
}

QT_END_NAMESPACE_CONTACTS
