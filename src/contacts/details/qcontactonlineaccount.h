// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QCONTACTONLINEACCOUNT_H
#define QCONTACTONLINEACCOUNT_H

#include <QtContacts/qcontactdetail.h>

QT_BEGIN_NAMESPACE_CONTACTS

/* Leaf class */
class Q_CONTACTS_EXPORT QContactOnlineAccount : public QContactDetail
{
public:
#ifndef Q_QDOC
    Q_DECLARE_CUSTOM_CONTACT_DETAIL(QContactOnlineAccount)
#else
    static const DetailType Type;
#endif

    enum OnlineAccountField {
        FieldAccountUri = 0,
        FieldServiceProvider,
        FieldProtocol,
        FieldCapabilities,
        FieldSubTypes
    };

    enum SubType {
        SubTypeSip = 0,
        SubTypeSipVoip,
        SubTypeImpp,
        SubTypeVideoShare
    };

    enum Protocol {
        ProtocolUnknown = 0,
        ProtocolAim,
        ProtocolIcq,
        ProtocolIrc,
        ProtocolJabber,
        ProtocolMsn,
        ProtocolQq,
        ProtocolSkype,
        ProtocolYahoo
    };

    void setAccountUri(const QString& _accountUri);
    QString accountUri() const;

    void setServiceProvider(const QString& _serviceProvider);
    QString serviceProvider() const;

    void setProtocol(Protocol _protocol);
    Protocol protocol() const;

    void setCapabilities(const QStringList& _capabilities);
    QStringList capabilities() const;

    void setSubTypes(const QList<int> &_subTypes);
    QList<int> subTypes() const;
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTONLINEACCOUNT_H
