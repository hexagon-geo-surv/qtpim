// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QORGANIZERITEMFETCHBYIDREQUEST_H
#define QORGANIZERITEMFETCHBYIDREQUEST_H

#include <QtCore/qlist.h>
#include <QtCore/qmap.h>

#include <QtOrganizer/qorganizerabstractrequest.h>
#include <QtOrganizer/qorganizeritem.h>
#include <QtOrganizer/qorganizeritemid.h>

QT_BEGIN_NAMESPACE_ORGANIZER

class QOrganizerItemFetchHint;

class QOrganizerItemFetchByIdRequestPrivate;

/* Leaf class */

class Q_ORGANIZER_EXPORT QOrganizerItemFetchByIdRequest : public QOrganizerAbstractRequest
{
    Q_OBJECT

public:
    QOrganizerItemFetchByIdRequest(QObject *parent = nullptr);
    ~QOrganizerItemFetchByIdRequest();

    void setIds(const QList<QOrganizerItemId> &ids);
    QList<QOrganizerItemId> ids() const;

    void setFetchHint(const QOrganizerItemFetchHint &fetchHint);
    QOrganizerItemFetchHint fetchHint() const;

    QList<QOrganizerItem> items() const;
    QMap<int, QOrganizerManager::Error> errorMap() const;

private:
    Q_DISABLE_COPY(QOrganizerItemFetchByIdRequest)
    friend class QOrganizerManagerEngine;
    Q_DECLARE_PRIVATE_D(d_ptr, QOrganizerItemFetchByIdRequest)
};

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERITEMFETCHBYIDREQUEST_H
