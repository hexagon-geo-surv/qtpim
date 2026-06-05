// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QORGANIZERITEMDETAILFILTER_P_H
#define QORGANIZERITEMDETAILFILTER_P_H

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

#include <QtOrganizer/qorganizeritemdetailfilter.h>
#include <QtOrganizer/private/qorganizeritemfilter_p.h>

QT_BEGIN_NAMESPACE_ORGANIZER

class QOrganizerItemDetailFilterPrivate : public QOrganizerItemFilterPrivate
{
public:
    QOrganizerItemDetailFilterPrivate()
        : QOrganizerItemFilterPrivate(), m_detailType(QOrganizerItemDetail::TypeUndefined), m_detailFields(QList<int>()), m_flags(0)
    {
    }

    QOrganizerItemDetailFilterPrivate(const QOrganizerItemDetailFilterPrivate& other)
        : QOrganizerItemFilterPrivate(other), m_detailType(other.m_detailType), m_detailFields(other.m_detailFields),
          m_exactValues(other.m_exactValues), m_flags(other.m_flags)
    {
    }

    virtual bool compare(const QOrganizerItemFilterPrivate *other) const override
    {
        const QOrganizerItemDetailFilterPrivate *od = static_cast<const QOrganizerItemDetailFilterPrivate *>(other);
        if (od) {
            return (m_detailType == od->m_detailType) && (m_detailFields == od->m_detailFields)
                   && (m_exactValues == od->m_exactValues) && (m_flags == od->m_flags);
        }
        return false;
    }

#ifndef QT_NO_DATASTREAM
    QDataStream &outputToStream(QDataStream &stream, quint8 formatVersion) const override
    {
        if (formatVersion == 1)
            stream << quint32(m_detailType) << m_detailFields << m_exactValues << static_cast<quint32>(m_flags);
        return stream;
    }

    QDataStream &inputFromStream(QDataStream &stream, quint8 formatVersion) override
    {
        if (formatVersion == 1) {
            quint32 flags;
            quint32 defId;
            stream >> defId >> m_detailFields >> m_exactValues >> flags;
            m_detailType = static_cast<QOrganizerItemDetail::DetailType>(defId);
            m_flags = static_cast<QOrganizerItemFilter::MatchFlags>(flags);
        }
        return stream;
    }
#endif // QT_NO_DATASTREAM

#ifndef QT_NO_DEBUG_STREAM
    QDebug &debugStreamOut(QDebug &dbg) const override
    {
        dbg.nospace() << "QOrganizerItemDetailFilter(";
        dbg.nospace() << "detailType=";
        dbg.nospace() << m_detailType;
        dbg.nospace() << ",";
        dbg.nospace() << "detailFields=";
        dbg.nospace() << m_detailFields;
        dbg.nospace() << ",";
        dbg.nospace() << "values=";
        dbg.nospace() << m_exactValues;
        dbg.nospace() << ",";
        dbg.nospace() << "matchFlags=";
        dbg.nospace() << static_cast<quint32>(m_flags);
        dbg.nospace() << ")";
        return dbg.maybeSpace();
    }
#endif // QT_NO_DEBUG_STREAM

    Q_IMPLEMENT_ORGANIZERITEMFILTER_VIRTUALCTORS(QOrganizerItemDetailFilter, QOrganizerItemFilter::DetailFilter)

    QOrganizerItemDetail m_detail;
    QOrganizerItemDetail::DetailType m_detailType;
    QList<int> m_detailFields;
    QVariantList m_exactValues;
    QOrganizerItemFilter::MatchFlags m_flags;
};

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERITEMDETAILFILTER_P_H
