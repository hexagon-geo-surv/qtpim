// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QORGANIZERITEMREMOVEBYIDREQUEST_H
#define QORGANIZERITEMREMOVEBYIDREQUEST_H

#include <QtCore/qlist.h>
#include <QtCore/qmap.h>

#include <QtOrganizer/qorganizerabstractrequest.h>
#include <QtOrganizer/qorganizeritemid.h>

QT_BEGIN_NAMESPACE_ORGANIZER

class QOrganizerItemRemoveByIdRequestPrivate;

/* Leaf class */

class Q_ORGANIZER_EXPORT QOrganizerItemRemoveByIdRequest : public QOrganizerAbstractRequest
{
    Q_OBJECT

public:
    QOrganizerItemRemoveByIdRequest(QObject* parent = Q_NULLPTR);
    ~QOrganizerItemRemoveByIdRequest();

    /* Selection */
    void setItemId(const QOrganizerItemId& organizeritemId);
    void setItemIds(const QList<QOrganizerItemId>& organizeritemIds);
    QList<QOrganizerItemId> itemIds() const;

    /* Results */
    QMap<int, QOrganizerManager::Error> errorMap() const;

private:
    Q_DISABLE_COPY(QOrganizerItemRemoveByIdRequest)
    friend class QOrganizerManagerEngine;
    Q_DECLARE_PRIVATE_D(d_ptr, QOrganizerItemRemoveByIdRequest)
};

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERITEMREMOVEBYIDREQUEST_H
