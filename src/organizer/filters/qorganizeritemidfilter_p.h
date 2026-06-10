// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QORGANIZERITEMIDFILTER_P_H
#define QORGANIZERITEMIDFILTER_P_H

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

#include <QtOrganizer/qorganizeritemidfilter.h>
#include <QtOrganizer/private/qorganizeritemfilter_p.h>

QT_BEGIN_NAMESPACE_ORGANIZER

class QOrganizerItemIdFilterPrivate : public QOrganizerItemFilterPrivate
{
public:
    QOrganizerItemIdFilterPrivate()
        : QOrganizerItemFilterPrivate()
    {
    }

    QOrganizerItemIdFilterPrivate(const QOrganizerItemIdFilterPrivate &other)
        : QOrganizerItemFilterPrivate(other), m_ids(other.m_ids)
    {
    }

    bool compare(const QOrganizerItemFilterPrivate *other) const override
    {
        const QOrganizerItemIdFilterPrivate *od = static_cast<const QOrganizerItemIdFilterPrivate *>(other);
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
        dbg.nospace() << "QOrganizerItemIdFilter(";
        dbg.nospace() << "ids=";
        dbg.nospace() << m_ids;
        dbg.nospace() << ")";
        return dbg.maybeSpace();
    }
#endif // QT_NO_DEBUG_STREAM

    Q_IMPLEMENT_ORGANIZERITEMFILTER_VIRTUALCTORS(QOrganizerItemIdFilter, QOrganizerItemFilter::IdFilter)

    QList<QOrganizerItemId> m_ids;
};

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERITEMIDFILTER_P_H
