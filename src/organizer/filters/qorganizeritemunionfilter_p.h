// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QORGANIZERITEMUNIONFILTER_P_H
#define QORGANIZERITEMUNIONFILTER_P_H

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

#include <QtOrganizer/qorganizeritemunionfilter.h>
#include <QtOrganizer/private/qorganizeritemfilter_p.h>

QT_BEGIN_NAMESPACE_ORGANIZER

class QOrganizerItemUnionFilterPrivate : public QOrganizerItemFilterPrivate
{
public:
    QOrganizerItemUnionFilterPrivate()
       : QOrganizerItemFilterPrivate()
    {
    }

    QOrganizerItemUnionFilterPrivate(const QOrganizerItemUnionFilterPrivate &other)
       : QOrganizerItemFilterPrivate(other), m_filters(other.m_filters)
    {
    }

    bool compare(const QOrganizerItemFilterPrivate *other) const override
    {
        const QOrganizerItemUnionFilterPrivate *od = static_cast<const QOrganizerItemUnionFilterPrivate *>(other);
        if (od)
            return m_filters == od->m_filters;
        return false;
    }

#ifndef QT_NO_DATASTREAM
    QDataStream &outputToStream(QDataStream &stream, quint8 formatVersion) const override
    {
        if (formatVersion == 1)
            stream << m_filters;
        return stream;
    }

    QDataStream &inputFromStream(QDataStream &stream, quint8 formatVersion) override
    {
        if (formatVersion == 1)
            stream >> m_filters;
        return stream;
    }
#endif // QT_NO_DATASTREAM

#ifndef QT_NO_DEBUG_STREAM
    QDebug &debugStreamOut(QDebug &dbg) const override
    {
        dbg.nospace() << "QOrganizerItemUnionFilter(";
        dbg.nospace() << "filters=";
        dbg.nospace() << m_filters;
        dbg.nospace() << ")";
        return dbg.maybeSpace();
    }
#endif // QT_NO_DEBUG_STREAM

    Q_IMPLEMENT_ORGANIZERITEMFILTER_VIRTUALCTORS(QOrganizerItemUnionFilter, QOrganizerItemFilter::UnionFilter)

    QList<QOrganizerItemFilter> m_filters;
};

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERITEMUNIONFILTER_P_H
