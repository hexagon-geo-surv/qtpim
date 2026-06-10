// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QCONTACTACTIONFILTER_P_H
#define QCONTACTACTIONFILTER_P_H

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

#include <QtContacts/qcontactactionfilter.h>
#include <QtContacts/private/qcontactfilter_p.h>

QT_BEGIN_NAMESPACE_CONTACTS

class QContactActionFilterPrivate : public QContactFilterPrivate
{
public:
    QContactActionFilterPrivate()
        : QContactFilterPrivate()
    {
    }

    QContactActionFilterPrivate(const QContactActionFilterPrivate& other)
        : QContactFilterPrivate(other),
        m_action(other.m_action)
    {
    }

    bool compare(const QContactFilterPrivate* other) const override
    {
        const QContactActionFilterPrivate *od = static_cast<const QContactActionFilterPrivate*>(other);
        if (m_action != od->m_action)
            return false;
        return true;
    }

    QDataStream& outputToStream(QDataStream& stream, quint8 formatVersion) const override
    {
        if (formatVersion == 1) {
            stream << m_action;
        }
        return stream;
    }

    QDataStream& inputFromStream(QDataStream& stream, quint8 formatVersion) override
    {
        if (formatVersion == 1) {
            stream >> m_action;
        }
        return stream;
    }

#ifndef QT_NO_DEBUG_STREAM
    QDebug& debugStreamOut(QDebug& dbg) const override
    {
        dbg.nospace() << "QContactActionFilter(";
        dbg.nospace() << "action=" << m_action;
        dbg.nospace() << ")";
        return dbg.maybeSpace();
    }
#endif

    Q_IMPLEMENT_CONTACTFILTER_VIRTUALCTORS(QContactActionFilter, QContactFilter::ActionFilter)

    QString m_action;
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTACTIONFILTER_P_H
