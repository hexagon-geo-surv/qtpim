// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qorganizeritemdetailfieldfilter.h"
#include "qorganizeritemdetailfieldfilter_p.h"

QT_BEGIN_NAMESPACE_ORGANIZER

/*!
    \class QOrganizerItemDetailFieldFilter
    \brief The QOrganizerItemDetailFieldFilter class provides a filter based around a detail value criterion.
    \inmodule QtOrganizer
    \ingroup organizer-filters

    It may be used to select organizeritems which contain a detail of a particular type and a particular value.
 */

Q_IMPLEMENT_ORGANIZERITEMFILTER_PRIVATE(QOrganizerItemDetailFieldFilter)

/*!
    \fn QOrganizerItemDetailFieldFilter::QOrganizerItemDetailFieldFilter(const QOrganizerItemFilter &other)

    Constructs a copy of \a other if possible, otherwise constructs a new detail filter.
 */

/*!
    Constructs a new detail filter.
 */
QOrganizerItemDetailFieldFilter::QOrganizerItemDetailFieldFilter()
    : QOrganizerItemFilter(new QOrganizerItemDetailFieldFilterPrivate)
{
}

/*!
    Sets the type of detail which will be matched to \a detailType, and the field of the detail
    which will contain the value criterion to \a field.

    If \a detailType is QOrganizerItemDetail::TypeUndefined, the detail filter will match no organizer items.
    If \a field is not specified, or equal to -1, the detail filter acts like a "detail exists" filter;
    if any detail of the specified type is present in the organizer item, that organizer item will match
    the filter, regardless of what values might be stored in that detail.

    \sa detailType(), detailField()
 */
void QOrganizerItemDetailFieldFilter::setDetail(QOrganizerItemDetail::DetailType detailType, int field)
{
    Q_D(QOrganizerItemDetailFieldFilter);
    d->m_detailType = detailType;
    d->m_detailField = field;
}

/*!
    Sets the value criterion of the filter to \a value.

    \sa value()
 */
void QOrganizerItemDetailFieldFilter::setValue(const QVariant &value)
{
    Q_D(QOrganizerItemDetailFieldFilter);
    d->m_exactValue = value;
}

/*!
    Sets the semantics of the value matching criterion to those defined in \a flags.

    \sa matchFlags()
 */
void QOrganizerItemDetailFieldFilter::setMatchFlags(QOrganizerItemFilter::MatchFlags flags)
{
    Q_D(QOrganizerItemDetailFieldFilter);
    d->m_flags = flags;
}

/*!
    Returns the semantics of the value matching criterion.

    \sa setMatchFlags()
 */
QOrganizerItemFilter::MatchFlags QOrganizerItemDetailFieldFilter::matchFlags() const
{
    Q_D(const QOrganizerItemDetailFieldFilter);
    return d->m_flags;
}

/*!
    Returns the type of the detail which will be inspected for matching values.

    \sa setDetail()
 */
QOrganizerItemDetail::DetailType QOrganizerItemDetailFieldFilter::detailType() const
{
    Q_D(const QOrganizerItemDetailFieldFilter);
    return d->m_detailType;
}

/*!
    Returns the detail field containing the value which will be matched against the value criterion.

    \sa setDetail()
 */
int QOrganizerItemDetailFieldFilter::detailField() const
{
    Q_D(const QOrganizerItemDetailFieldFilter);
    return d->m_detailField;
}

/*!
    Returns the value criterion of the detail filter.

    \sa setValue()
 */
QVariant QOrganizerItemDetailFieldFilter::value() const
{
    Q_D(const QOrganizerItemDetailFieldFilter);
    return d->m_exactValue;
}

QT_END_NAMESPACE_ORGANIZER
