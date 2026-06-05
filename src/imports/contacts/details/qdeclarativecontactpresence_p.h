// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QDECLARATIVECONTACTPRESENCE_H
#define QDECLARATIVECONTACTPRESENCE_H

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

#include <QtContacts/qcontactpresence.h>

#include "qdeclarativecontactdetail_p.h"

QTCONTACTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE

class QDeclarativeContactPresence : public QDeclarativeContactDetail
{
    Q_OBJECT
    Q_PROPERTY(QDateTime timestamp READ timestamp WRITE setTimestamp NOTIFY valueChanged)
    Q_PROPERTY(QString nickname READ nickname WRITE setNickname NOTIFY valueChanged)
    Q_PROPERTY(PresenceStateType state READ presenceState WRITE setPresenceState NOTIFY valueChanged)
    Q_PROPERTY(QString stateText READ presenceStateText WRITE setPresenceStateText NOTIFY valueChanged)
    Q_PROPERTY(QUrl imageUrl READ presenceStateImageUrl WRITE setPresenceStateImageUrl NOTIFY valueChanged)
    Q_PROPERTY(QString customMessage READ customMessage WRITE setCustomMessage NOTIFY valueChanged)
    Q_ENUMS(FieldType)
    Q_ENUMS(PresenceStateType)
    Q_CLASSINFO("DefaultProperty", "state")
public:
    enum FieldType {
        Timestamp = QContactPresence::FieldTimestamp,
        Nickname = QContactPresence::FieldNickname,
        State = QContactPresence::FieldPresenceState,
        StateText = QContactPresence::FieldPresenceStateText,
        ImageUrl = QContactPresence::FieldPresenceStateImageUrl,
        CustomMessage = QContactPresence::FieldCustomMessage
    };

    enum PresenceStateType {
        Unknown = QContactPresence::PresenceUnknown,
        Available = QContactPresence::PresenceAvailable,
        Hidden = QContactPresence::PresenceHidden,
        Busy = QContactPresence::PresenceBusy,
        Away = QContactPresence::PresenceAway,
        ExtendedAway = QContactPresence::PresenceExtendedAway,
        Offline = QContactPresence::PresenceOffline
    };

    QDeclarativeContactPresence(QObject* parent = nullptr)
        :QDeclarativeContactDetail(parent)
    {
        setDetail(QContactPresence());
        connect(this, SIGNAL(valueChanged()), SIGNAL(detailChanged()));
    }
    DetailType detailType() const
    {
        return QDeclarativeContactDetail::Presence;
    }

    void setTimestamp(const QDateTime& v)
    {
        if (!readOnly() && v != timestamp()) {
            detail().setValue(QContactPresence::FieldTimestamp, v);
            emit valueChanged();
        }
    }
    QDateTime timestamp() const {return detail().value<QDateTime>(QContactPresence::FieldTimestamp);}
    void setNickname(const QString& v)
    {
        if (!readOnly() && v != nickname()) {
            detail().setValue(QContactPresence::FieldNickname, v);
            emit valueChanged();
        }
    }
    QString nickname() const {return detail().value(QContactPresence::FieldNickname).toString();}

    void setPresenceState(PresenceStateType v)
    {
        if (!readOnly() && v != presenceState()) {
            detail().setValue(QContactPresence::FieldPresenceState, static_cast<int>(v));
            emit valueChanged();
        }
    }

    PresenceStateType presenceState() const
    {
        return static_cast<PresenceStateType>(detail().value<int>(QContactPresence::FieldPresenceState));

    }

    void setPresenceStateText(const QString& v)
    {
        if (!readOnly() && v != presenceStateText()) {
            detail().setValue(QContactPresence::FieldPresenceStateText, v);
            emit valueChanged();
        }
    }
    QString presenceStateText() const {return detail().value(QContactPresence::FieldPresenceStateText).toString();}
    void setPresenceStateImageUrl(const QUrl& v)
    {
        if (!readOnly() && v != presenceStateImageUrl())  {
            detail().setValue(QContactPresence::FieldPresenceStateImageUrl, v);
            emit valueChanged();
        }
    }
    QUrl presenceStateImageUrl() const {return detail().value<QUrl>(QContactPresence::FieldPresenceStateImageUrl);}
    void setCustomMessage(const QString& v)
    {
        if (!readOnly() && v != customMessage()) {
            detail().setValue(QContactPresence::FieldCustomMessage, v);
            emit valueChanged();
        }
    }
    QString customMessage() const {return detail().value(QContactPresence::FieldCustomMessage).toString();}
signals:
    void valueChanged();
};

QT_END_NAMESPACE

QML_DECLARE_TYPE(QDeclarativeContactPresence)

#endif // QDECLARATIVECONTACTPRESENCE_H
