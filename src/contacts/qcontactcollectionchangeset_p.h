// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QCONTACTCOLLECTIONCHANGESET_P_H
#define QCONTACTCOLLECTIONCHANGESET_P_H

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

#include <utility>

#include <QtContacts/qcontactcollectionid.h>

QT_BEGIN_NAMESPACE_CONTACTS

class QContactCollectionChangeSetData : public QSharedData
{
public:
    QContactCollectionChangeSetData()
        : QSharedData(), m_dataChanged(false)
    {
    }

    QContactCollectionChangeSetData(const QContactCollectionChangeSetData& other)
        : QSharedData(other),
          m_dataChanged(other.m_dataChanged),
          m_addedCollections(other.m_addedCollections),
          m_changedCollections(other.m_changedCollections),
          m_removedCollections(other.m_removedCollections),
          m_modifiedCollections(other.m_modifiedCollections)
    {
    }

    ~QContactCollectionChangeSetData()
    {
    }

    bool m_dataChanged;
    QSet<QContactCollectionId> m_addedCollections;
    QSet<QContactCollectionId> m_changedCollections;
    QSet<QContactCollectionId> m_removedCollections;
    QList<std::pair<QContactCollectionId, QContactManager::Operation> > m_modifiedCollections;
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTCOLLECTIONCHANGESET_P_H
