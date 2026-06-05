// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qorganizeritemdetailfilter.h"
#include "qorganizeritemdetailfilter_p.h"

QT_BEGIN_NAMESPACE_ORGANIZER

/*!
    \class QOrganizerItemDetailFilter
    \brief The QOrganizerItemDetailFilter class provides a filter based around a detail value criterion.
    \inmodule QtOrganizer
    \ingroup organizer-filters

    It may be used to select organizeritems which contain a detail identical to that used by
    this filter for matching.
 */

Q_IMPLEMENT_ORGANIZERITEMFILTER_PRIVATE(QOrganizerItemDetailFilter)

/*!
    \fn QOrganizerItemDetailFilter::QOrganizerItemDetailFilter(const QOrganizerItemFilter &other)

    Constructs a copy of \a other if possible, otherwise constructs a new detail filter.
 */

/*!
    Constructs a new detail filter.
 */
QOrganizerItemDetailFilter::QOrganizerItemDetailFilter()
    : QOrganizerItemFilter(new QOrganizerItemDetailFilterPrivate)
{
}

/*!
    Sets the detail that will be matched to \a detail.

    \sa detail()
 */
void QOrganizerItemDetailFilter::setDetail(const QOrganizerItemDetail &detail)
{
    Q_D(QOrganizerItemDetailFilter);
    d->m_detail = detail;
}

/*!
    Returns the detail which will be matched by this filter.

    \sa setDetail()
 */
QOrganizerItemDetail QOrganizerItemDetailFilter::detail() const
{
    Q_D(const QOrganizerItemDetailFilter);
    return d->m_detail;
}

QT_END_NAMESPACE_ORGANIZER
