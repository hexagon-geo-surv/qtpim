// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QORGANIZERITEMCOLLECTIONFILTER_P_H
#define QORGANIZERITEMCOLLECTIONFILTER_P_H

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

#include <QtOrganizer/qorganizeritemcollectionfilter.h>
#include <QtOrganizer/private/qorganizeritemfilter_p.h>

#include <algorithm>

QT_BEGIN_NAMESPACE_ORGANIZER

class QOrganizerItemCollectionFilterPrivate : public QOrganizerItemFilterPrivate
{
public:
    QOrganizerItemCollectionFilterPrivate()
        : QOrganizerItemFilterPrivate()
    {
    }

    QOrganizerItemCollectionFilterPrivate(const QOrganizerItemCollectionFilterPrivate &other)
        : QOrganizerItemFilterPrivate(other), m_ids(other.m_ids)
    {
    }

    virtual bool compare(const QOrganizerItemFilterPrivate *other) const override
    {
        const QOrganizerItemCollectionFilterPrivate *od = static_cast<const QOrganizerItemCollectionFilterPrivate *>(other);
        if (od)
            return m_ids == od->m_ids;
        return false;
    }

#ifndef QT_NO_DATASTREAM
    QDataStream &outputToStream(QDataStream &stream, quint8 formatVersion) const override
    {
        if (formatVersion == 1)
            stream << m_ids;
        return stream;
    }

    QDataStream &inputFromStream(QDataStream &stream, quint8 formatVersion) override
    {
        if (formatVersion == 1)
            stream >> m_ids;
        return stream;
    }
#endif // QT_NO_DATASTREAM

#ifndef QT_NO_DEBUG_STREAM
    QDebug &debugStreamOut(QDebug &dbg) const override
    {
        dbg.nospace() << "QOrganizerItemCollectionFilter(collectionIds=";
        QList<QOrganizerCollectionId> ids(m_ids.values());
        std::sort(ids.begin(), ids.end());
        dbg.nospace() << ids;
        dbg.nospace() << ")";
        return dbg.maybeSpace();
    }
#endif // QT_NO_DEBUG_STREAM

    Q_IMPLEMENT_ORGANIZERITEMFILTER_VIRTUALCTORS(QOrganizerItemCollectionFilter, QOrganizerItemFilter::CollectionFilter)

    QSet<QOrganizerCollectionId> m_ids;
};

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERITEMCOLLECTIONFILTER_P_H
