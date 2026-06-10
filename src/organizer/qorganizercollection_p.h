// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QORGANIZERCOLLECTION_P_H
#define QORGANIZERCOLLECTION_P_H

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

#include <QtCore/qmap.h>
#include <QtCore/qshareddata.h>
#include <QtCore/qvariant.h>

#include <QtOrganizer/qorganizercollection.h>
#include <QtOrganizer/qorganizercollectionid.h>

QT_BEGIN_NAMESPACE_ORGANIZER

class QOrganizerCollectionData : public QSharedData
{
public:
    QOrganizerCollectionData()
        : QSharedData()
    {
    }

    QOrganizerCollectionData(const QOrganizerCollectionData &other)
        : QSharedData(other), m_metaData(other.m_metaData), m_id(other.m_id)
    {
    }

    ~QOrganizerCollectionData()
    {
    }

    QMap<QOrganizerCollection::MetaDataKey, QVariant> m_metaData;
    QOrganizerCollectionId m_id;
};

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERCOLLECTION_P_H
