// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QORGANIZERITEMIDFETCHREQUEST_H
#define QORGANIZERITEMIDFETCHREQUEST_H

#include <QtCore/qlist.h>

#include <QtOrganizer/qorganizerabstractrequest.h>
#include <QtOrganizer/qorganizeritemid.h>
#include <QtOrganizer/qorganizeritemsortorder.h>

QT_FORWARD_DECLARE_CLASS(QDateTime)

QT_BEGIN_NAMESPACE_ORGANIZER

class QOrganizerItemFilter;

class QOrganizerItemIdFetchRequestPrivate;

/* Leaf class */

class Q_ORGANIZER_EXPORT QOrganizerItemIdFetchRequest : public QOrganizerAbstractRequest
{
    Q_OBJECT

public:
    QOrganizerItemIdFetchRequest(QObject *parent = nullptr);
    ~QOrganizerItemIdFetchRequest();

    void setFilter(const QOrganizerItemFilter &filter);
    QOrganizerItemFilter filter() const;

    void setSorting(const QList<QOrganizerItemSortOrder> &sorting);
    QList<QOrganizerItemSortOrder> sorting() const;

    void setStartDate(const QDateTime &date);
    QDateTime startDate() const;

    void setEndDate(const QDateTime &date);
    QDateTime endDate() const;

    QList<QOrganizerItemId> itemIds() const;

private:
    Q_DISABLE_COPY(QOrganizerItemIdFetchRequest)
    friend class QOrganizerManagerEngine;
    Q_DECLARE_PRIVATE_D(d_ptr, QOrganizerItemIdFetchRequest)
};

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERITEMIDFETCHREQUEST_H
