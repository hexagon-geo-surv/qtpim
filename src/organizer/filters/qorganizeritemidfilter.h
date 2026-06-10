// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QORGANIZERITEMIDFILTER_H
#define QORGANIZERITEMIDFILTER_H

#include <QtCore/qlist.h>

#include <QtOrganizer/qorganizeritemfilter.h>
#include <QtOrganizer/qorganizeritemid.h>

QT_BEGIN_NAMESPACE_ORGANIZER

class QOrganizerItemIdFilterPrivate;

/* Leaf class */

class Q_ORGANIZER_EXPORT QOrganizerItemIdFilter : public QOrganizerItemFilter
{
public:
    QOrganizerItemIdFilter();
    QOrganizerItemIdFilter(const QOrganizerItemFilter &other);

    void setIds(const QList<QOrganizerItemId> &ids);
    void insert(const QOrganizerItemId &id);
    void remove(const QOrganizerItemId &id);
    void clear();

    QList<QOrganizerItemId> ids() const;

private:
    Q_DECLARE_ORGANIZERITEMFILTER_PRIVATE(QOrganizerItemIdFilter)
};

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERITEMIDFILTER_H
