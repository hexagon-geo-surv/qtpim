// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QORGANIZERITEM_P_H
#define QORGANIZERITEM_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <QtCore/qlist.h>
#include <QtCore/qshareddata.h>

#include <QtOrganizer/qorganizercollectionid.h>
#include <QtOrganizer/qorganizeritem.h>
#include <QtOrganizer/qorganizeritemid.h>
#include <QtOrganizer/qorganizeritemdetail.h>

QT_BEGIN_NAMESPACE_ORGANIZER

class QOrganizerItemPrivate : public QSharedData
{
public:
    QOrganizerItemPrivate()
        : QSharedData()
    {
    }

    QOrganizerItemPrivate(const QOrganizerItemPrivate &other)
        : QSharedData(other)
        , m_id(other.m_id)
        , m_collectionId(other.m_collectionId)
        , m_details(other.m_details)
    {
    }

    ~QOrganizerItemPrivate() {}

    void removeOnly(QOrganizerItemDetail::DetailType detailType);
    void removeOnly(const QSet<QOrganizerItemDetail::DetailType> &detailTypes);

    // Trampoline
    static QSharedDataPointer<QOrganizerItemPrivate> &itemData(QOrganizerItem &item) {return item.d;}

    QOrganizerItemId m_id;
    QOrganizerCollectionId m_collectionId;
    QList<QOrganizerItemDetail> m_details;
};

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERITEM_P_H
