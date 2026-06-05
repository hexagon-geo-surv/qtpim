// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QCONTACTRINGTONE_H
#define QCONTACTRINGTONE_H

#include <QtCore/qurl.h>

#include <QtContacts/qcontactdetail.h>

QT_BEGIN_NAMESPACE_CONTACTS

/* Leaf class */
class Q_CONTACTS_EXPORT QContactRingtone : public QContactDetail
{
public:
#ifndef Q_QDOC
    Q_DECLARE_CUSTOM_CONTACT_DETAIL(QContactRingtone)
#else
    static const DetailType Type;
#endif

    enum RingtoneField {
        FieldAudioRingtoneUrl = 0,
        FieldVideoRingtoneUrl,
        FieldVibrationRingtoneUrl
    };

    void setAudioRingtoneUrl(const QUrl& _audioRingtoneUrl);
    QUrl audioRingtoneUrl() const;

    void setVideoRingtoneUrl(const QUrl& _videoRingtoneUrl);
    QUrl videoRingtoneUrl() const;

    void setVibrationRingtoneUrl(const QUrl& _vibrationRingtoneUrl);
    QUrl vibrationRingtoneUrl() const;
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTRINGTONE_H
