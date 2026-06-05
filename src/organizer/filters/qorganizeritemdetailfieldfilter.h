// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QORGANIZERITEMDETAILFIELDFILTER_H
#define QORGANIZERITEMDETAILFIELDFILTER_H

#include <QtOrganizer/qorganizeritemdetail.h>
#include <QtOrganizer/qorganizeritemfilter.h>

QT_BEGIN_NAMESPACE_ORGANIZER

class QOrganizerItemDetailFieldFilterPrivate;

/* Leaf class */

class Q_ORGANIZER_EXPORT QOrganizerItemDetailFieldFilter : public QOrganizerItemFilter
{
public:
    QOrganizerItemDetailFieldFilter();
    QOrganizerItemDetailFieldFilter(const QOrganizerItemFilter &other);

    void setDetail(QOrganizerItemDetail::DetailType detailType, int field = -1);
    QOrganizerItemDetail::DetailType detailType() const;
    int detailField() const;

    void setMatchFlags(QOrganizerItemFilter::MatchFlags flags);
    QOrganizerItemFilter::MatchFlags matchFlags() const;

    void setValue(const QVariant &value);
    QVariant value() const;

private:
    Q_DECLARE_ORGANIZERITEMFILTER_PRIVATE(QOrganizerItemDetailFieldFilter)
};

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERITEMDETAILFIELDFILTER_H
