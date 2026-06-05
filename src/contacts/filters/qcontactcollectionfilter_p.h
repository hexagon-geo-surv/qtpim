// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QCONTACTCOLLECTIONFILTER_P_H
#define QCONTACTCOLLECTIONFILTER_P_H

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

#include <QtContacts/qcontactcollectionfilter.h>
#include <QtContacts/private/qcontactfilter_p.h>

#include <algorithm>

QT_BEGIN_NAMESPACE_CONTACTS

class QContactCollectionFilterPrivate : public QContactFilterPrivate
{
public:
    QContactCollectionFilterPrivate()
        : QContactFilterPrivate()
    {
    }

    QContactCollectionFilterPrivate(const QContactCollectionFilterPrivate &other)
        : QContactFilterPrivate(other), m_ids(other.m_ids)
    {
    }

    bool compare(const QContactFilterPrivate *other) const override
    {
        const QContactCollectionFilterPrivate *od = static_cast<const QContactCollectionFilterPrivate *>(other);
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
        dbg.nospace() << "QContactCollectionFilter(collectionIds=";
        QList<QContactCollectionId> ids(m_ids.begin(), m_ids.end());
        std::sort(ids.begin(), ids.end());
        dbg.nospace() << ids;
        dbg.nospace() << ")";
        return dbg.maybeSpace();
    }
#endif // QT_NO_DEBUG_STREAM

    Q_IMPLEMENT_CONTACTFILTER_VIRTUALCTORS(QContactCollectionFilter, QContactFilter::CollectionFilter)

    QSet<QContactCollectionId> m_ids;
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTCOLLECTIONFILTER_P_H
