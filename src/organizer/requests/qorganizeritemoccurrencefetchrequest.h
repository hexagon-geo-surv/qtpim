// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QORGANIZERITEMOCCURRENCEFETCHREQUEST_H
#define QORGANIZERITEMOCCURRENCEFETCHREQUEST_H

#include <QtCore/qlist.h>

#include <QtOrganizer/qorganizerabstractrequest.h>
#include <QtOrganizer/qorganizeritem.h>

QT_FORWARD_DECLARE_CLASS(QDateTime)

QT_BEGIN_NAMESPACE_ORGANIZER

class QOrganizerItemFetchHint;

class QOrganizerItemOccurrenceFetchRequestPrivate;

/* Leaf class */

class Q_ORGANIZER_EXPORT QOrganizerItemOccurrenceFetchRequest : public QOrganizerAbstractRequest
{
    Q_OBJECT

public:
    QOrganizerItemOccurrenceFetchRequest(QObject *parent = nullptr);
    ~QOrganizerItemOccurrenceFetchRequest();

    void setParentItem(const QOrganizerItem &item);
    QOrganizerItem parentItem() const;

    void setStartDate(const QDateTime &date);
    QDateTime startDate() const;

    void setEndDate(const QDateTime &date);
    QDateTime endDate() const;

    void setMaxOccurrences(int maxCount);
    int maxOccurrences() const;

    void setFetchHint(const QOrganizerItemFetchHint &hint);
    QOrganizerItemFetchHint fetchHint() const;

    QList<QOrganizerItem> itemOccurrences() const;

private:
    Q_DISABLE_COPY(QOrganizerItemOccurrenceFetchRequest)
    friend class QOrganizerManagerEngine;
    Q_DECLARE_PRIVATE_D(d_ptr, QOrganizerItemOccurrenceFetchRequest)
};

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERITEMOCCURRENCEFETCHREQUEST_H
