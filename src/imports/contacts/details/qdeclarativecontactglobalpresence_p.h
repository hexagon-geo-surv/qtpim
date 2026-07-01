// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QDECLARATIVECONTACTGLOBALPRESENCE_H
#define QDECLARATIVECONTACTGLOBALPRESENCE_H

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

#include <QtContacts/qcontactglobalpresence.h>
#include <QtCore/qurl.h>

#include "qdeclarativecontactdetail_p.h"
#include "qdeclarativecontactpresence_p.h"

QTCONTACTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE

class QDeclarativeContactGlobalPresence : public QDeclarativeContactDetail
{
    Q_OBJECT
    Q_PROPERTY(QDateTime timestamp READ timestamp WRITE setTimestamp NOTIFY valueChanged)
    Q_PROPERTY(QString nickname READ nickname WRITE setNickname NOTIFY valueChanged)
    Q_PROPERTY(QDeclarativeContactPresence::PresenceStateType state READ presenceState WRITE setPresenceState NOTIFY valueChanged)
    Q_PROPERTY(QString stateText READ presenceStateText WRITE setPresenceStateText NOTIFY valueChanged)
    Q_PROPERTY(QUrl imageUrl READ presenceStateImageUrl WRITE setPresenceStateImageUrl NOTIFY valueChanged)
    Q_PROPERTY(QString customMessage READ customMessage WRITE setCustomMessage NOTIFY valueChanged)
    Q_CLASSINFO("DefaultProperty", "state")
    Q_ENUMS(FieldType)
public:
    enum FieldType {
        Timestamp = QContactGlobalPresence::FieldTimestamp,
        Nickname = QContactGlobalPresence::FieldNickname,
        State = QContactGlobalPresence::FieldPresenceState,
        StateText = QContactGlobalPresence::FieldPresenceStateText,
        ImageUrl = QContactGlobalPresence::FieldPresenceStateImageUrl,
        CustomMessage = QContactGlobalPresence::FieldCustomMessage
    };

    QDeclarativeContactGlobalPresence(QObject* parent = Q_NULLPTR)
        :QDeclarativeContactDetail(parent)
    {
        setDetail(QContactGlobalPresence());
        connect(this, SIGNAL(valueChanged()), SIGNAL(detailChanged()));
    }
    DetailType detailType() const override
    {
        return QDeclarativeContactDetail::GlobalPresence;
    }

    void setTimestamp(const QDateTime& v)
    {
        if (!readOnly() && v != timestamp()) {
            detail().setValue(QContactGlobalPresence::FieldTimestamp, v);
            emit valueChanged();
        }
    }
    QDateTime timestamp() const {return detail().value<QDateTime>(QContactGlobalPresence::FieldTimestamp);}
    void setNickname(const QString& v)
    {
        if (!readOnly() && v != nickname()) {
            detail().setValue(QContactGlobalPresence::FieldNickname, v);
            emit valueChanged();
        }
    }
    QString nickname() const {return detail().value(QContactGlobalPresence::FieldNickname).toString();}
    void setPresenceState(QDeclarativeContactPresence::PresenceStateType v)
    {
        if (!readOnly() && v != presenceState()) {
            detail().setValue(QContactGlobalPresence::FieldPresenceState, static_cast<int>(v));
            emit valueChanged();
        }
    }

    QDeclarativeContactPresence::PresenceStateType presenceState() const
    {
        return static_cast<QDeclarativeContactPresence::PresenceStateType>(detail().value<int>(QContactGlobalPresence::FieldPresenceState));

    }
    void setPresenceStateText(const QString& v)
    {
        if (!readOnly() && v != presenceStateText()) {
            detail().setValue(QContactGlobalPresence::FieldPresenceStateText, v);
            emit valueChanged();
        }
    }
    QString presenceStateText() const {return detail().value(QContactGlobalPresence::FieldPresenceStateText).toString();}
    void setPresenceStateImageUrl(const QUrl& v)
    {
        if (!readOnly() && v != presenceStateImageUrl())  {
            detail().setValue(QContactGlobalPresence::FieldPresenceStateImageUrl, v);
            emit valueChanged();
        }
    }
    QUrl presenceStateImageUrl() const {return detail().value<QUrl>(QContactGlobalPresence::FieldPresenceStateImageUrl);}
    void setCustomMessage(const QString& v)
    {
        if (!readOnly() && v != customMessage()) {
            detail().setValue(QContactGlobalPresence::FieldCustomMessage, v);
            emit valueChanged();
        }
    }
    QString customMessage() const {return detail().value(QContactGlobalPresence::FieldCustomMessage).toString();}
signals:
    void valueChanged();
};

QT_END_NAMESPACE

QML_DECLARE_TYPE(QDeclarativeContactGlobalPresence)

#endif // QDECLARATIVECONTACTGLOBALPRESENCE_H
