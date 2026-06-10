// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QORGANIZERCOLLECTIONFETCHREQUEST_H
#define QORGANIZERCOLLECTIONFETCHREQUEST_H

#include <QtCore/qlist.h>

#include <QtOrganizer/qorganizerabstractrequest.h>
#include <QtOrganizer/qorganizercollection.h>

QT_BEGIN_NAMESPACE_ORGANIZER

class QOrganizerCollectionFetchRequestPrivate;

/* Leaf class */

class Q_ORGANIZER_EXPORT QOrganizerCollectionFetchRequest : public QOrganizerAbstractRequest
{
    Q_OBJECT

public:
    QOrganizerCollectionFetchRequest(QObject *parent = nullptr);
    ~QOrganizerCollectionFetchRequest();

    QList<QOrganizerCollection> collections() const;

private:
    Q_DISABLE_COPY(QOrganizerCollectionFetchRequest)
    friend class QOrganizerManagerEngine;
    Q_DECLARE_PRIVATE_D(d_ptr, QOrganizerCollectionFetchRequest)
};

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERCOLLECTIONFETCHREQUEST_H
