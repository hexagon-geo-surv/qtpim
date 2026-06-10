// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QCONTACTACTIONDESCRIPTOR_P_H
#define QCONTACTACTIONDESCRIPTOR_P_H

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

#include <QtCore/qshareddata.h>

#include <QtContacts/qcontactsglobal.h>

QT_BEGIN_NAMESPACE_CONTACTS

class QContactActionFactory;
class QContactActionDescriptorPrivate : public QSharedData
{
public:

    QContactActionDescriptorPrivate()
        : QSharedData(),
        m_implementationVersion(-1),
        m_factory(0)
    {
    }

    QContactActionDescriptorPrivate(const QContactActionDescriptorPrivate& other)
            : QSharedData(),
            m_actionName(other.m_actionName),
            m_serviceName(other.m_serviceName),
            m_identifier(other.m_identifier),
            m_implementationVersion(other.m_implementationVersion),
            m_factory(other.m_factory)
    {
    }

    ~QContactActionDescriptorPrivate()
    {
    }

    QString m_actionName;
    QString m_serviceName;
    QString m_identifier;
    int m_implementationVersion;
    const QContactActionFactory* m_factory;
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTACTIONDESCRIPTOR_P_H
