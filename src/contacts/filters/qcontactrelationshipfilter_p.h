// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QCONTACTRELATIONSHIPFILTER_P_H
#define QCONTACTRELATIONSHIPFILTER_P_H

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

#include <QtContacts/qcontactrelationshipfilter.h>
#include <QtContacts/private/qcontactfilter_p.h>

QT_BEGIN_NAMESPACE_CONTACTS

class QContactRelationshipFilterPrivate : public QContactFilterPrivate
{
public:
    QContactRelationshipFilterPrivate()
        : QContactFilterPrivate(),
        m_relatedContactRole(QContactRelationship::Either)
    {
    }

    QContactRelationshipFilterPrivate(const QContactRelationshipFilterPrivate& other)
        : QContactFilterPrivate(other),
        m_relationshipType(other.m_relationshipType),
        m_relatedContactId(other.m_relatedContactId),
        m_relatedContactRole(other.m_relatedContactRole)
    {
    }

    bool compare(const QContactFilterPrivate* other) const override
    {
        const QContactRelationshipFilterPrivate *od = static_cast<const QContactRelationshipFilterPrivate*>(other);
        if (m_relatedContactRole != od->m_relatedContactRole)
            return false;
        if (m_relatedContactId != od->m_relatedContactId)
            return false;
        if (m_relationshipType != od->m_relationshipType)
            return false;
        return true;
    }

    QDataStream& outputToStream(QDataStream& stream, quint8 formatVersion) const override
    {
        if (formatVersion == 1) {
            stream << m_relationshipType << m_relatedContactId << static_cast<quint32>(m_relatedContactRole);
        }
        return stream;
    }

    QDataStream& inputFromStream(QDataStream& stream, quint8 formatVersion) override
    {
        if (formatVersion == 1) {
            quint32 role;
            stream >> m_relationshipType >> m_relatedContactId >> role;
            m_relatedContactRole = QContactRelationship::Role(role);
        }
        return stream;
    }

#ifndef QT_NO_DEBUG_STREAM
    QDebug& debugStreamOut(QDebug& dbg) const override
    {
        dbg.nospace() << "QContactRelationshipFilter(";
        dbg.nospace() << "relationshipType=" << m_relationshipType << ","
                      << "relatedContactId=" << m_relatedContactId << ","
                      << "relatedContactRole=" << static_cast<quint32>(m_relatedContactRole);
        dbg.nospace() << ")";
        return dbg.maybeSpace();
    }
#endif

    Q_IMPLEMENT_CONTACTFILTER_VIRTUALCTORS(QContactRelationshipFilter, QContactFilter::RelationshipFilter)

    QString m_relationshipType;
    QContactId m_relatedContactId;
    QContactRelationship::Role m_relatedContactRole;
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTRELATIONSHIPFILTER_P_H
