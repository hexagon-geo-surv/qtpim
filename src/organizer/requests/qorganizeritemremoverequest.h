// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QORGANIZERITEMREMOVEREQUEST_H
#define QORGANIZERITEMREMOVEREQUEST_H

#include <QtCore/qlist.h>
#include <QtCore/qmap.h>

#include <QtOrganizer/qorganizerabstractrequest.h>
#include <QtOrganizer/qorganizeritem.h>

QT_BEGIN_NAMESPACE_ORGANIZER

class QOrganizerItemRemoveRequestPrivate;

/* Leaf class */

class Q_ORGANIZER_EXPORT QOrganizerItemRemoveRequest : public QOrganizerAbstractRequest
{
    Q_OBJECT

public:
    QOrganizerItemRemoveRequest(QObject *parent = nullptr);
    ~QOrganizerItemRemoveRequest();

    void setItem(const QOrganizerItem &item);
    void setItems(const QList<QOrganizerItem> &items);
    QList<QOrganizerItem> items() const;
    QMap<int, QOrganizerManager::Error> errorMap() const;

private:
    Q_DISABLE_COPY(QOrganizerItemRemoveRequest)
    friend class QOrganizerManagerEngine;
    Q_DECLARE_PRIVATE_D(d_ptr, QOrganizerItemRemoveRequest)
};

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERITEMREMOVEREQUEST_H
