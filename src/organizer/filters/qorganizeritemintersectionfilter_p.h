// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QORGANIZERITEMINTERSECTIONFILTER_P_H
#define QORGANIZERITEMINTERSECTIONFILTER_P_H

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

#include <QtOrganizer/qorganizeritemintersectionfilter.h>
#include <QtOrganizer/private/qorganizeritemfilter_p.h>

QT_BEGIN_NAMESPACE_ORGANIZER

class QOrganizerItemIntersectionFilterPrivate : public QOrganizerItemFilterPrivate
{
public:
    QOrganizerItemIntersectionFilterPrivate()
       : QOrganizerItemFilterPrivate()
    {
    }

    QOrganizerItemIntersectionFilterPrivate(const QOrganizerItemIntersectionFilterPrivate &other)
       : QOrganizerItemFilterPrivate(other), m_filters(other.m_filters)
    {
    }

    bool compare(const QOrganizerItemFilterPrivate *other) const override
    {
        const QOrganizerItemIntersectionFilterPrivate *od = static_cast<const QOrganizerItemIntersectionFilterPrivate *>(other);
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
        dbg.nospace() << "QOrganizerItemIntersectionFilter(";
        dbg.nospace() << "filters=";
        dbg.nospace() << m_filters;
        dbg.nospace() << ")";
        return dbg.maybeSpace();
    }
#endif // QT_NO_DEBUG_STREAM

    Q_IMPLEMENT_ORGANIZERITEMFILTER_VIRTUALCTORS(QOrganizerItemIntersectionFilter, QOrganizerItemFilter::IntersectionFilter)

    QList<QOrganizerItemFilter> m_filters;
};

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERITEMINTERSECTIONFILTER_P_H
