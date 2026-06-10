// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QORGANIZERCOLLECTIONSAVEREQUEST_H
#define QORGANIZERCOLLECTIONSAVEREQUEST_H

#include <QtCore/qlist.h>
#include <QtCore/qmap.h>

#include <QtOrganizer/qorganizerabstractrequest.h>
#include <QtOrganizer/qorganizercollection.h>

QT_BEGIN_NAMESPACE_ORGANIZER

class QOrganizerCollectionSaveRequestPrivate;

/* Leaf class */

class Q_ORGANIZER_EXPORT QOrganizerCollectionSaveRequest : public QOrganizerAbstractRequest
{
    Q_OBJECT

public:
    QOrganizerCollectionSaveRequest(QObject *parent = nullptr);
    ~QOrganizerCollectionSaveRequest();

    void setCollection(const QOrganizerCollection &collection);
    void setCollections(const QList<QOrganizerCollection> &collections);
    QList<QOrganizerCollection> collections() const;

    QMap<int, QOrganizerManager::Error> errorMap() const;

private:
    Q_DISABLE_COPY(QOrganizerCollectionSaveRequest)
    friend class QOrganizerManagerEngine;
    Q_DECLARE_PRIVATE_D(d_ptr, QOrganizerCollectionSaveRequest)
};

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERCOLLECTIONSAVEREQUEST_H
