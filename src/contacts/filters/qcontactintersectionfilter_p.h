// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QCONTACTINTERSECTIONFILTER_P_H
#define QCONTACTINTERSECTIONFILTER_P_H

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

#include <QtContacts/qcontactintersectionfilter.h>
#include <QtContacts/private/qcontactfilter_p.h>

QT_BEGIN_NAMESPACE_CONTACTS

class QContactIntersectionFilterPrivate : public QContactFilterPrivate
{
public:
    QContactIntersectionFilterPrivate()
       : QContactFilterPrivate()
    {

    }

    QContactIntersectionFilterPrivate(const QContactIntersectionFilterPrivate& other)
       : QContactFilterPrivate(other),
       m_filters(other.m_filters)
    {

    }

    bool compare(const QContactFilterPrivate* other) const override
    {
        const QContactIntersectionFilterPrivate *od = static_cast<const QContactIntersectionFilterPrivate*>(other);
        if (m_filters != od->m_filters)
            return false;
        return true;
    }

    QDataStream& outputToStream(QDataStream& stream, quint8 formatVersion) const override
    {
        if (formatVersion == 1) {
            stream << m_filters;
        }
        return stream;
    }

    QDataStream& inputFromStream(QDataStream& stream, quint8 formatVersion) override
    {
        if (formatVersion == 1) {
            stream >> m_filters;
        }
        return stream;
    }

#ifndef QT_NO_DEBUG_STREAM
    QDebug& debugStreamOut(QDebug& dbg) const override
    {
        dbg.nospace() << "QContactIntersectionFilter(";
        dbg.nospace() << "filters=" << m_filters;
        dbg.nospace() << ")";
        return dbg.maybeSpace();
    }
#endif

    Q_IMPLEMENT_CONTACTFILTER_VIRTUALCTORS(QContactIntersectionFilter, QContactFilter::IntersectionFilter)

    QList<QContactFilter> m_filters;
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTINTERSECTIONFILTER_P_H
