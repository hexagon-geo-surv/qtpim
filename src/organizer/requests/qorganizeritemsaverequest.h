// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QORGANIZERITEMSAVEREQUEST_H
#define QORGANIZERITEMSAVEREQUEST_H

#include <QtCore/qlist.h>
#include <QtCore/qmap.h>

#include <QtOrganizer/qorganizerabstractrequest.h>
#include <QtOrganizer/qorganizeritem.h>
#include <QtOrganizer/qorganizeritemdetail.h>

QT_BEGIN_NAMESPACE_ORGANIZER

class QOrganizerItemSaveRequestPrivate;

/* Leaf class */

class Q_ORGANIZER_EXPORT QOrganizerItemSaveRequest : public QOrganizerAbstractRequest
{
    Q_OBJECT

public:
    QOrganizerItemSaveRequest(QObject *parent = Q_NULLPTR);
    ~QOrganizerItemSaveRequest();

    void setItem(const QOrganizerItem &item);
    void setItems(const QList<QOrganizerItem> &items);
    QList<QOrganizerItem> items() const;

    void setDetailMask(const QList<QOrganizerItemDetail::DetailType> &detailMask);
    QList<QOrganizerItemDetail::DetailType> detailMask() const;

    QMap<int, QOrganizerManager::Error> errorMap() const;

private:
    Q_DISABLE_COPY(QOrganizerItemSaveRequest)
    friend class QOrganizerManagerEngine;
    Q_DECLARE_PRIVATE_D(d_ptr, QOrganizerItemSaveRequest)
};

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERITEMSAVEREQUEST_H
