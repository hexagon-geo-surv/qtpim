// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QCONTACTACTIONTARGET_P_H
#define QCONTACTACTIONTARGET_P_H

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

#include <QtContacts/qcontact.h>
#include <QtContacts/qcontactdetail.h>

QT_BEGIN_NAMESPACE_CONTACTS

class QContactActionTargetPrivate : public QSharedData
{
public:
    QContactActionTargetPrivate(const QContact& contact, const QList<QContactDetail>& details)
            : QSharedData(),
            m_contact(contact),
            m_details(details)
    {
    }

    ~QContactActionTargetPrivate()
    {
    }

    QContactActionTargetPrivate(const QContactActionTargetPrivate& other)
        : QSharedData(),
        m_contact(other.m_contact),
        m_details(other.m_details)
    {
    }

    QContact m_contact;
    QList<QContactDetail> m_details;
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTACTIONTARGET_P_H
