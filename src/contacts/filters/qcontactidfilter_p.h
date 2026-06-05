// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QCONTACTIDLISTFILTER_P_H
#define QCONTACTIDLISTFILTER_P_H

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

#include <QtContacts/qcontactidfilter.h>
#include <QtContacts/private/qcontactfilter_p.h>

QT_BEGIN_NAMESPACE_CONTACTS

class QContactIdFilterPrivate : public QContactFilterPrivate
{
public:
    QContactIdFilterPrivate()
        : QContactFilterPrivate()
    {
    }

    QContactIdFilterPrivate(const QContactIdFilterPrivate& other)
        : QContactFilterPrivate(other),
        m_ids(other.m_ids)
    {
    }

    bool compare(const QContactFilterPrivate* other) const override
    {
        const QContactIdFilterPrivate *od = static_cast<const QContactIdFilterPrivate*>(other);
        if (m_ids != od->m_ids)
            return false;
        return true;
    }

    QDataStream& outputToStream(QDataStream& stream, quint8 formatVersion) const override
    {
        if (formatVersion == 1) {
            stream << m_ids;
        }
        return stream;
    }

    QDataStream& inputFromStream(QDataStream& stream, quint8 formatVersion) override
    {
        if (formatVersion == 1) {
            stream >> m_ids;
        }
        return stream;
    }

#ifndef QT_NO_DEBUG_STREAM
    QDebug& debugStreamOut(QDebug& dbg) const override
    {
        dbg.nospace() << "QContactIdFilter(";
        dbg.nospace() << "ids=" << m_ids;
        dbg.nospace() << ")";
        return dbg.maybeSpace();
    }
#endif

    Q_IMPLEMENT_CONTACTFILTER_VIRTUALCTORS(QContactIdFilter, QContactFilter::IdFilter)

    QList<QContactId> m_ids;
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTIDLISTFILTER_P_H
