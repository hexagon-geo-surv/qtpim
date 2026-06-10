// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QORGANIZERCOLLECTIONREMOVEREQUEST_H
#define QORGANIZERCOLLECTIONREMOVEREQUEST_H

#include <QtCore/qlist.h>
#include <QtCore/qmap.h>

#include <QtOrganizer/qorganizerabstractrequest.h>
#include <QtOrganizer/qorganizercollectionid.h>

QT_BEGIN_NAMESPACE_ORGANIZER

class QOrganizerCollectionRemoveRequestPrivate;

/* Leaf class */

class Q_ORGANIZER_EXPORT QOrganizerCollectionRemoveRequest : public QOrganizerAbstractRequest
{
    Q_OBJECT

public:
    QOrganizerCollectionRemoveRequest(QObject *parent = nullptr);
    ~QOrganizerCollectionRemoveRequest();

    void setCollectionId(const QOrganizerCollectionId &collectionId);
    void setCollectionIds(const QList<QOrganizerCollectionId> &collectionIds);
    QList<QOrganizerCollectionId> collectionIds() const;

    QMap<int, QOrganizerManager::Error> errorMap() const;

private:
    Q_DISABLE_COPY(QOrganizerCollectionRemoveRequest)
    friend class QOrganizerManagerEngine;
    Q_DECLARE_PRIVATE_D(d_ptr, QOrganizerCollectionRemoveRequest)
};

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERCOLLECTIONREMOVEREQUEST_H
