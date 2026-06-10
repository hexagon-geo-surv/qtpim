// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QORGANIZERITEMINVALIDFILTER_H
#define QORGANIZERITEMINVALIDFILTER_H

#include <QtOrganizer/qorganizeritemfilter.h>

QT_BEGIN_NAMESPACE_ORGANIZER

class QOrganizerItemInvalidFilterPrivate;

/* Leaf class */

class Q_ORGANIZER_EXPORT QOrganizerItemInvalidFilter : public QOrganizerItemFilter
{
public:
    QOrganizerItemInvalidFilter();
    QOrganizerItemInvalidFilter(const QOrganizerItemFilter &other);
};

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERITEMINVALIDFILTER_H
