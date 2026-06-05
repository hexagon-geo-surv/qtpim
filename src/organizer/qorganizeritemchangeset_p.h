// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QORGANIZERITEMCHANGESET_P_H
#define QORGANIZERITEMCHANGESET_P_H

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
#include <QtCore/qset.h>
#include <QtCore/qshareddata.h>

#include <QtOrganizer/qorganizeritemchangeset.h>
#include <QtOrganizer/qorganizeritemid.h>

QT_BEGIN_NAMESPACE_ORGANIZER

class QOrganizerItemChangeSetData : public QSharedData
{
public:
    QOrganizerItemChangeSetData()
        : QSharedData(), m_dataChanged(false)
    {
    }

    QOrganizerItemChangeSetData(const QOrganizerItemChangeSetData& other)
        : QSharedData(other),
          m_dataChanged(other.m_dataChanged),
          m_addedItems(other.m_addedItems),
          m_changedItems(other.m_changedItems),
          m_removedItems(other.m_removedItems),
          m_modifiedItems(other.m_modifiedItems)
    {
    }

    ~QOrganizerItemChangeSetData()
    {
    }

    bool m_dataChanged;
    QSet<QOrganizerItemId> m_addedItems;
    QList<QOrganizerItemChangeSet::ItemChangeList> m_changedItems;
    QSet<QOrganizerItemId> m_removedItems;
    QList<QPair<QOrganizerItemId, QOrganizerManager::Operation> > m_modifiedItems;
};

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERITEMCHANGESET_P_H
