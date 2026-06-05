// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QORGANIZERITEMFETCHFOREXPORTREQUEST_H
#define QORGANIZERITEMFETCHFOREXPORTREQUEST_H

#include <QtCore/qlist.h>

#include <QtOrganizer/qorganizerabstractrequest.h>
#include <QtOrganizer/qorganizeritem.h>
#include <QtOrganizer/qorganizeritemsortorder.h>

QT_FORWARD_DECLARE_CLASS(QDateTime)

QT_BEGIN_NAMESPACE_ORGANIZER

class QOrganizerItemFetchHint;
class QOrganizerItemFilter;

class QOrganizerItemFetchForExportRequestPrivate;

/* Leaf class */

class Q_ORGANIZER_EXPORT QOrganizerItemFetchForExportRequest : public QOrganizerAbstractRequest
{
    Q_OBJECT

public:
    QOrganizerItemFetchForExportRequest(QObject *parent = nullptr);
    ~QOrganizerItemFetchForExportRequest();

    void setFilter(const QOrganizerItemFilter &filter);
    QOrganizerItemFilter filter() const;

    void setSorting(const QList<QOrganizerItemSortOrder> &sorting);
    QList<QOrganizerItemSortOrder> sorting() const;

    void setFetchHint(const QOrganizerItemFetchHint &fetchHint);
    QOrganizerItemFetchHint fetchHint() const;

    void setStartDate(const QDateTime &date);
    QDateTime startDate() const;

    void setEndDate(const QDateTime &date);
    QDateTime endDate() const;

    QList<QOrganizerItem> items() const;

private:
    Q_DISABLE_COPY(QOrganizerItemFetchForExportRequest)
    friend class QOrganizerManagerEngine;
    Q_DECLARE_PRIVATE_D(d_ptr, QOrganizerItemFetchForExportRequest)
};

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERITEMFETCHFOREXPORTREQUEST_H
