// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QCONTACTRELATIONSHIP_P_H
#define QCONTACTRELATIONSHIP_P_H

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

#include <QtCore/qlist.h>
#include <QtCore/qshareddata.h>
#include <QtCore/qstring.h>

#include <QtContacts/qcontactid.h>

QT_BEGIN_NAMESPACE_CONTACTS

class QContactRelationshipPrivate : public QSharedData
{
public:
    QContactRelationshipPrivate()
            : QSharedData()
    {
    }

    QContactRelationshipPrivate(const QContactRelationshipPrivate& other)
            : QSharedData(other),
            m_first(other.m_first),
            m_second(other.m_second),
            m_relationshipType(other.m_relationshipType)
    {
    }

    ~QContactRelationshipPrivate()
    {
    }

    QContactId m_first;
    QContactId m_second;
    QString m_relationshipType;
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTRELATIONSHIP_P_H
