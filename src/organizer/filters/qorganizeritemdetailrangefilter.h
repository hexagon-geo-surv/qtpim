// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QORGANIZERITEMDETAILRANGEFILTER_H
#define QORGANIZERITEMDETAILRANGEFILTER_H

#include <QtOrganizer/qorganizeritemdetail.h>
#include <QtOrganizer/qorganizeritemfilter.h>

QT_BEGIN_NAMESPACE_ORGANIZER

class QOrganizerItemDetailRangeFilterPrivate;

/* Leaf class */

class Q_ORGANIZER_EXPORT QOrganizerItemDetailRangeFilter : public QOrganizerItemFilter
{
public:
    QOrganizerItemDetailRangeFilter();
    QOrganizerItemDetailRangeFilter(const QOrganizerItemFilter &other);

    enum RangeFlag {
        IncludeLower = 0,
        IncludeUpper = 1,
        ExcludeLower = 2,
        ExcludeUpper = 0
    };
    Q_DECLARE_FLAGS(RangeFlags, RangeFlag)

    void setDetail(QOrganizerItemDetail::DetailType detailType, int field = -1);
    QOrganizerItemDetail::DetailType detailType() const;
    int detailField() const;

    void setMatchFlags(QOrganizerItemFilter::MatchFlags flags);
    QOrganizerItemFilter::MatchFlags matchFlags() const;

    void setRange(const QVariant &min, const QVariant &max, RangeFlags flags = RangeFlags());
    QVariant minValue() const;
    QVariant maxValue() const;
    RangeFlags rangeFlags() const;

private:
    Q_DECLARE_ORGANIZERITEMFILTER_PRIVATE(QOrganizerItemDetailRangeFilter)
};
Q_DECLARE_OPERATORS_FOR_FLAGS(QOrganizerItemDetailRangeFilter::RangeFlags)

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERITEMDETAILRANGEFILTER_H
