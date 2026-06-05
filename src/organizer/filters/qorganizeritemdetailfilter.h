// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QORGANIZERITEMDETAILFILTER_H
#define QORGANIZERITEMDETAILFILTER_H

#include <QtOrganizer/qorganizeritemdetail.h>
#include <QtOrganizer/qorganizeritemfilter.h>

QT_BEGIN_NAMESPACE_ORGANIZER

class QOrganizerItemDetailFilterPrivate;

/* Leaf class */

class Q_ORGANIZER_EXPORT QOrganizerItemDetailFilter : public QOrganizerItemFilter
{
public:
    QOrganizerItemDetailFilter();
    QOrganizerItemDetailFilter(const QOrganizerItemFilter &other);

    void setDetail(const QOrganizerItemDetail &detail);
    QOrganizerItemDetail detail() const;

private:
    Q_DECLARE_ORGANIZERITEMFILTER_PRIVATE(QOrganizerItemDetailFilter)
};

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERITEMDETAILFILTER_H
