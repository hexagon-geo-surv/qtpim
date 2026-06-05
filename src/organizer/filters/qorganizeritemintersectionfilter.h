// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QORGANIZERITEMINTERSECTIONFILTER_H
#define QORGANIZERITEMINTERSECTIONFILTER_H

#include <QtCore/qlist.h>

#include <QtOrganizer/qorganizeritemfilter.h>

QT_BEGIN_NAMESPACE_ORGANIZER

class QOrganizerItemIntersectionFilterPrivate;

/* Leaf class */

class Q_ORGANIZER_EXPORT QOrganizerItemIntersectionFilter : public QOrganizerItemFilter
{
public:
    QOrganizerItemIntersectionFilter();
    QOrganizerItemIntersectionFilter(const QOrganizerItemFilter &other);

    void setFilters(const QList<QOrganizerItemFilter> &filters);
    void prepend(const QOrganizerItemFilter & filter);
    void append(const QOrganizerItemFilter & filter);
    void remove(const QOrganizerItemFilter & filter);
    void clear();

    QOrganizerItemIntersectionFilter &operator<<(const QOrganizerItemFilter &filter);

    QList<QOrganizerItemFilter> filters() const;

private:
    Q_DECLARE_ORGANIZERITEMFILTER_PRIVATE(QOrganizerItemIntersectionFilter)
};

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERITEMINTERSECTIONFILTER_H
