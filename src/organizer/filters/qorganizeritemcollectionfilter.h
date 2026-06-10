// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QORGANIZERITEMCOLLECTIONFILTER_H
#define QORGANIZERITEMCOLLECTIONFILTER_H

#include <QtCore/qset.h>

#include <QtOrganizer/qorganizercollectionid.h>
#include <QtOrganizer/qorganizeritemfilter.h>

QT_BEGIN_NAMESPACE_ORGANIZER

class QOrganizerItemCollectionFilterPrivate;

/* Leaf class */

class Q_ORGANIZER_EXPORT QOrganizerItemCollectionFilter : public QOrganizerItemFilter
{
public:
    QOrganizerItemCollectionFilter();
    QOrganizerItemCollectionFilter(const QOrganizerItemFilter &other);

    void setCollectionId(const QOrganizerCollectionId &id);
    void setCollectionIds(const QSet<QOrganizerCollectionId> &ids);
    QSet<QOrganizerCollectionId> collectionIds() const;

private:
    Q_DECLARE_ORGANIZERITEMFILTER_PRIVATE(QOrganizerItemCollectionFilter)
};

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERITEMCOLLECTIONFILTER_H
