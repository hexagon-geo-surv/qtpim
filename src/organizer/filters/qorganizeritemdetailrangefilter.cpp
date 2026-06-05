// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qorganizeritemdetailrangefilter.h"
#include "qorganizeritemdetailrangefilter_p.h"

QT_BEGIN_NAMESPACE_ORGANIZER

/*!
    \class QOrganizerItemDetailRangeFilter
    \brief The QOrganizerItemDetailRangeFilter class provides a filter based around a detail value
           range criterion.
    \inmodule QtOrganizer
    \ingroup organizer-filters

    It may be used to select organizer items which contain a detail of a particular type, whose value
    falls in a particular range.
 */

Q_IMPLEMENT_ORGANIZERITEMFILTER_PRIVATE(QOrganizerItemDetailRangeFilter)

/*!
    \fn QOrganizerItemDetailRangeFilter::QOrganizerItemDetailRangeFilter(const QOrganizerItemFilter &other)

    Constructs a copy of \a other if possible, otherwise constructs a new detail range filter.
 */

/*!
    \enum QOrganizerItemDetailRangeFilter::RangeFlag

    This enumeration describes the semantics of the boundary conditions of the detail range filter.
    \value IncludeLower
    \value IncludeUpper
    \value ExcludeLower
    \value ExcludeUpper
 */

/*!
    Constructs a new detail range filter.
 */
QOrganizerItemDetailRangeFilter::QOrganizerItemDetailRangeFilter()
    : QOrganizerItemFilter(new QOrganizerItemDetailRangeFilterPrivate)
{
}

/*!
    Sets the value range criterion of the filter to within \a min and \a max, with boundary conditions
    specified in the given \a flags.

    \sa minValue(), maxValue(), rangeFlags()
 */
void QOrganizerItemDetailRangeFilter::setRange(const QVariant &min, const QVariant &max, RangeFlags flags)
{
    Q_D(QOrganizerItemDetailRangeFilter);
    d->m_minValue = min;
    d->m_maxValue = max;
    d->m_rangeflags = flags;
}

/*!
    Sets the match flags of the filter criterion to \a flags.

    Not all flags are supported by a range filter. The supported flags include:
    \list
    \li QOrganizerItemFilter::MatchExactly
    \li QOrganizerItemFilter::MatchFixedString
    \li QOrganizerItemFilter::MatchCaseSensitive
    \endlist

    Unsupported flags will be ignored.

    \sa matchFlags()
 */
void QOrganizerItemDetailRangeFilter::setMatchFlags(QOrganizerItemFilter::MatchFlags flags)
{
    Q_D(QOrganizerItemDetailRangeFilter);
    flags &= (QOrganizerItemFilter::MatchExactly | QOrganizerItemFilter::MatchFixedString | QOrganizerItemFilter::MatchCaseSensitive);
    d->m_flags = flags;
}

/*!
    Sets the type of detail which will be matched to \a detailType, and the field of the detail
    which will contain the value criterion to \a field.

    \sa detailType(), detailField()
 */
/*!
    Sets the type of detail which will be matched to \a detailType, and the field of the detail
    which will contain the value criterion to \a field.

    If \a detailType is QOrganizerItemDetail::TypeUndefined, the detail filter will match no organizer items.
    If \a field is not specified, or equal to -1, the detail filter acts like a "detail exists" filter;
    if any detail of the specified type is present in the organizer item, that organizer item will match
    the filter, regardless of what values might be stored in that detail.

    \sa detailType(), detailField()
 */
void QOrganizerItemDetailRangeFilter::setDetail(QOrganizerItemDetail::DetailType detailType, int field)
{
    Q_D(QOrganizerItemDetailRangeFilter);
    d->m_detailType = detailType;
    d->m_detailField = field;
}

/*!
    Returns the match flags of the criterion, which define semantics such as case sensitivity, prefix
    matching, exact matching, etc.

    \sa setMatchFlags()
 */
QOrganizerItemFilter::MatchFlags QOrganizerItemDetailRangeFilter::matchFlags() const
{
    Q_D(const QOrganizerItemDetailRangeFilter);
    return d->m_flags;
}

/*!
    Returns the type of the detail which will be inspected for matching values.

    \sa setDetail()
 */
QOrganizerItemDetail::DetailType QOrganizerItemDetailRangeFilter::detailType() const
{
    Q_D(const QOrganizerItemDetailRangeFilter);
    return d->m_detailType;
}

/*!
    Returns the detail field containing the value which will be matched against the value criterion.

    \sa setDetail()
 */
int QOrganizerItemDetailRangeFilter::detailField() const
{
    Q_D(const QOrganizerItemDetailRangeFilter);
    return d->m_detailField;
}

/*!
    Returns the lower bound of the value range criterion.

    \sa setRange()
 */
QVariant QOrganizerItemDetailRangeFilter::minValue() const
{
    Q_D(const QOrganizerItemDetailRangeFilter);
    return d->m_minValue;
}

/*!
    Returns the upper bound of the value range criterion.

    \sa setRange()
 */
QVariant QOrganizerItemDetailRangeFilter::maxValue() const
{
    Q_D(const QOrganizerItemDetailRangeFilter);
    return d->m_maxValue;
}

/*!
    Returns a set of flags which defines the boundary condition semantics of the value range criterion.

    \sa setRange()
 */
QOrganizerItemDetailRangeFilter::RangeFlags QOrganizerItemDetailRangeFilter::rangeFlags() const
{
    Q_D(const QOrganizerItemDetailRangeFilter);
    return d->m_rangeflags;
}

QT_END_NAMESPACE_ORGANIZER
