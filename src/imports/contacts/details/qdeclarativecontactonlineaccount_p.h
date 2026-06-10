// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QDECLARATIVECONTACTONLINEACCOUNT_H
#define QDECLARATIVECONTACTONLINEACCOUNT_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.
// This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <QtContacts/qcontactonlineaccount.h>

#include "qdeclarativecontactdetail_p.h"

QTCONTACTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE

class QDeclarativeContactOnlineAccount : public QDeclarativeContactDetail
{
    Q_OBJECT
    Q_PROPERTY(QString accountUri READ accountUri WRITE setAccountUri NOTIFY valueChanged)
    Q_PROPERTY(QString serviceProvider READ serviceProvider WRITE  setServiceProvider NOTIFY valueChanged)
    Q_PROPERTY(QStringList capabilities READ capabilities WRITE  setCapabilities NOTIFY valueChanged)
    Q_PROPERTY(QList<int> subTypes READ subTypes WRITE  setSubTypes NOTIFY valueChanged)
    Q_PROPERTY(OnlineAccountProtocol protocol READ protocol WRITE setProtocol NOTIFY valueChanged)
    Q_ENUMS(FieldType)
    Q_ENUMS(OnlineAccountSubType)
    Q_ENUMS(OnlineAccountProtocol)

    Q_CLASSINFO("DefaultProperty", "accountUri")
public:
    enum FieldType {
        AccountUri = QContactOnlineAccount::FieldAccountUri,
        ServiceProvider = QContactOnlineAccount::FieldServiceProvider,
        Protocol = QContactOnlineAccount::FieldProtocol,
        Capabilities = QContactOnlineAccount::FieldCapabilities,
        SubTypes = QContactOnlineAccount::FieldSubTypes
    };

    enum OnlineAccountSubType {
        Sip = QContactOnlineAccount::SubTypeSip,
        SipVoip = QContactOnlineAccount::SubTypeSipVoip,
        Impp = QContactOnlineAccount::SubTypeImpp,
        VideoShare= QContactOnlineAccount::SubTypeVideoShare
    };

    enum OnlineAccountProtocol {
        Unknown =  QContactOnlineAccount::ProtocolUnknown,
        Aim = QContactOnlineAccount::ProtocolAim,
        Icq = QContactOnlineAccount::ProtocolIcq,
        Irc = QContactOnlineAccount::ProtocolIrc,
        Jabber = QContactOnlineAccount::ProtocolJabber,
        Msn = QContactOnlineAccount::ProtocolMsn,
        Qq = QContactOnlineAccount::ProtocolQq,
        Skype = QContactOnlineAccount::ProtocolSkype,
        Yahoo = QContactOnlineAccount::ProtocolYahoo
    };

    QDeclarativeContactOnlineAccount(QObject* parent = Q_NULLPTR)
        :QDeclarativeContactDetail(parent)
    {
        setDetail(QContactOnlineAccount());
        connect(this, SIGNAL(valueChanged()), SIGNAL(detailChanged()));
    }

    DetailType detailType() const override
    {
        return QDeclarativeContactDetail::OnlineAccount;
    }

    void setAccountUri(const QString& v)
    {
        if (!readOnly() && v != accountUri()) {
            detail().setValue(QContactOnlineAccount::FieldAccountUri, v);
            emit valueChanged();
        }
    }
    QString accountUri() const {return detail().value(QContactOnlineAccount::FieldAccountUri).toString();}

    void setServiceProvider(const QString& v)
    {
        if (!readOnly() && v != serviceProvider()) {
            detail().setValue(QContactOnlineAccount::FieldServiceProvider, v);
            emit valueChanged();
        }
    }
    QString serviceProvider() const {return detail().value(QContactOnlineAccount::FieldServiceProvider).toString();}

    void setCapabilities(const QStringList& v)
    {
        if (!readOnly() && QSet<QString>(v.cbegin(), v.cend()) != QSet<QString>(capabilities().cbegin(), capabilities().cend())) {
            detail().setValue(QContactOnlineAccount::FieldCapabilities, v);
            emit valueChanged();
        }
    }
    QStringList capabilities() const {return detail().value<QStringList>(QContactOnlineAccount::FieldCapabilities);}

    void setSubTypes(const QList<int>& subTypes)
    {
        QList<int> oldList = detail().value< QList<int> >(QContactOnlineAccount::FieldSubTypes);

        if (!readOnly() && QSet<int>(subTypes.cbegin(), subTypes.cend()) != QSet<int>(oldList.cbegin(), oldList.cend())) {
            detail().setValue(QContactOnlineAccount::FieldSubTypes, QVariant::fromValue(subTypes));
            emit valueChanged();
        }
    }

    QList<int> subTypes() const
    {
        return detail().value< QList<int> >(QContactOnlineAccount::FieldSubTypes);
    }

    void setProtocol(OnlineAccountProtocol v) {
        if (!readOnly() && v != protocol()) {
            detail().setValue(QContactOnlineAccount::FieldProtocol, static_cast<int>(v));
            emit valueChanged();
        }
    }

    OnlineAccountProtocol protocol() const
    {
        return static_cast<OnlineAccountProtocol>(detail().value<int>(QContactOnlineAccount::FieldProtocol));
    }

signals:
    void valueChanged();
};

QT_END_NAMESPACE

QML_DECLARE_TYPE(QDeclarativeContactOnlineAccount)

#endif // QDECLARATIVECONTACTONLINEACCOUNT_H
