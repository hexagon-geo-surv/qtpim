// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QCONTACTDETAILRANGEFILTER_H
#define QCONTACTDETAILRANGEFILTER_H

#include <QtCore/qvariant.h>

#include <QtContacts/qcontactdetail.h>
#include <QtContacts/qcontactfilter.h>

QT_BEGIN_NAMESPACE_CONTACTS

class QContactDetailRangeFilterPrivate;
class Q_CONTACTS_EXPORT QContactDetailRangeFilter : public QContactFilter
{
public:
    QContactDetailRangeFilter();
    QContactDetailRangeFilter(const QContactFilter& other);

    enum RangeFlag {
        IncludeLower = 0, // [
        IncludeUpper = 1, // ]
        ExcludeLower = 2, // (
        ExcludeUpper = 0  // ) - Default is [)
    };
    Q_DECLARE_FLAGS(RangeFlags, RangeFlag)

    /* Mutators */
    void setDetailType(QContactDetail::DetailType type, int field = -1);
    void setMatchFlags(QContactFilter::MatchFlags flags);

    /* Filter Criterion */
    void setRange(const QVariant& min, const QVariant& max, RangeFlags flags = RangeFlags());

    /* Accessors */
    QContactDetail::DetailType detailType() const;
    int detailField() const;
    QContactFilter::MatchFlags matchFlags() const;

    QVariant minValue() const;
    QVariant maxValue() const;
    RangeFlags rangeFlags() const;

private:
    Q_DECLARE_CONTACTFILTER_PRIVATE(QContactDetailRangeFilter)
};
Q_DECLARE_OPERATORS_FOR_FLAGS(QContactDetailRangeFilter::RangeFlags)

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTDETAILRANGEFILTER_H
