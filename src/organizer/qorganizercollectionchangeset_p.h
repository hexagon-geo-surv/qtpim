// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QORGANIZERCOLLECTIONCHANGESET_P_H
#define QORGANIZERCOLLECTIONCHANGESET_P_H

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

#include <QtOrganizer/qorganizercollectionid.h>

QT_BEGIN_NAMESPACE_ORGANIZER

class QOrganizerCollectionChangeSetData : public QSharedData
{
public:
    QOrganizerCollectionChangeSetData()
        : QSharedData(), m_dataChanged(false)
    {
    }

    QOrganizerCollectionChangeSetData(const QOrganizerCollectionChangeSetData& other)
        : QSharedData(other),
          m_dataChanged(other.m_dataChanged),
          m_addedCollections(other.m_addedCollections),
          m_changedCollections(other.m_changedCollections),
          m_removedCollections(other.m_removedCollections),
          m_modifiedCollections(other.m_modifiedCollections)
    {
    }

    ~QOrganizerCollectionChangeSetData()
    {
    }

    bool m_dataChanged;
    QSet<QOrganizerCollectionId> m_addedCollections;
    QSet<QOrganizerCollectionId> m_changedCollections;
    QSet<QOrganizerCollectionId> m_removedCollections;
    QList<QPair<QOrganizerCollectionId, QOrganizerManager::Operation> > m_modifiedCollections;
};

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERCOLLECTIONCHANGESET_P_H
