// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QCONTACTPRESENCE_H
#define QCONTACTPRESENCE_H

#include <QtCore/qdatetime.h>
#include <QtCore/qurl.h>

#include <QtContacts/qcontactdetail.h>

QT_BEGIN_NAMESPACE_CONTACTS

/* Leaf class */
class Q_CONTACTS_EXPORT QContactPresence : public QContactDetail
{
public:
#ifndef Q_QDOC
    Q_DECLARE_CUSTOM_CONTACT_DETAIL(QContactPresence)
#else
    static const DetailType Type;
#endif

    enum PresenceField {
        FieldTimestamp = 0,
        FieldNickname,
        FieldPresenceState,
        FieldPresenceStateText,
        FieldPresenceStateImageUrl,
        FieldCustomMessage
    };

    enum PresenceState {
        PresenceUnknown = 0,
        PresenceAvailable,
        PresenceHidden,
        PresenceBusy,
        PresenceAway,
        PresenceExtendedAway,
        PresenceOffline
    };

    void setTimestamp(const QDateTime& _timestamp);
    QDateTime timestamp() const;
    void setNickname(const QString& _nickname);
    QString nickname() const;
    void setPresenceState(PresenceState presence);
    PresenceState presenceState() const;
    void setPresenceStateText(const QString& _presenceStateText);
    QString presenceStateText() const;
    void setPresenceStateImageUrl(const QUrl& _presenceStateImageUrl);
    QUrl presenceStateImageUrl() const;
    void setCustomMessage(const QString& _customMessage);
    QString customMessage() const;
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTPRESENCE_H
