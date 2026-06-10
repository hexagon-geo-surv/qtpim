// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QCONTACTCHANGESET_P_H
#define QCONTACTCHANGESET_P_H

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

#include <QtCore/qset.h>
#include <QtCore/qshareddata.h>

#include <utility>

#include <QtContacts/qcontactid.h>
#include <QtContacts/qcontactchangeset.h>

QT_BEGIN_NAMESPACE_CONTACTS

class QContactChangeSetData : public QSharedData
{
public:
    QContactChangeSetData()
        : QSharedData(),
        m_dataChanged(false)
    {
    }

    QContactChangeSetData(const QContactChangeSetData& other)
        : QSharedData(other),
        m_dataChanged(other.m_dataChanged),
        m_addedContacts(other.m_addedContacts),
        m_changedContacts(other.m_changedContacts),
        m_removedContacts(other.m_removedContacts),
        m_addedRelationships(other.m_addedRelationships),
        m_removedRelationships(other.m_removedRelationships),
        m_oldAndNewSelfContactId(other.m_oldAndNewSelfContactId)
    {
    }

    ~QContactChangeSetData()
    {
    }

    bool m_dataChanged;
    QSet<QContactId> m_addedContacts;
    QList<QContactChangeSet::ContactChangeList> m_changedContacts;
    QSet<QContactId> m_removedContacts;
    QSet<QContactId> m_addedRelationships;
    QSet<QContactId> m_removedRelationships;
    std::pair<QContactId, QContactId> m_oldAndNewSelfContactId;
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTCHANGESET_P_H
