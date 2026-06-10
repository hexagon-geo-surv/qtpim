// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QCONTACT_P_H
#define QCONTACT_P_H

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
#include <QtCore/qmap.h>
#include <QtCore/qshareddata.h>

#include <QtContacts/qcontact.h>
#include <QtContacts/qcontactdetail.h>
#include <QtContacts/qcontactid.h>
#include <QtContacts/qcontactrelationship.h>
#include <QtContacts/qcontactcollectionid.h>

QT_BEGIN_NAMESPACE_CONTACTS

class QContactData : public QSharedData
{
public:
    QContactData()
        : QSharedData()
    {
    }

    QContactData(const QContactData& other)
        : QSharedData(other),
        m_id(other.m_id),
        m_collectionId(other.m_collectionId),
        m_details(other.m_details),
        m_relationshipsCache(other.m_relationshipsCache),
        m_preferences(other.m_preferences)
    {
    }

    ~QContactData() {}

    QContactId m_id;
    QContactCollectionId m_collectionId;
    QList<QContactDetail> m_details;
    QList<QContactRelationship> m_relationshipsCache;
    QMap<QString, int> m_preferences;

    // Helper function
    void removeOnly(QContactDetail::DetailType type);
    void removeOnly(const QSet<QContactDetail::DetailType>& types);

    // Trampoline
    static QSharedDataPointer<QContactData>& contactData(QContact& contact) {return contact.d;}
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACT_P_H
