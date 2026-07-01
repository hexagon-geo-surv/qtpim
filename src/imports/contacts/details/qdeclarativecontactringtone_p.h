// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QDECLARATIVECONTACTRINGTONE_H
#define QDECLARATIVECONTACTRINGTONE_H

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

#include <QtContacts/qcontactringtone.h>
#include <QtCore/qurl.h>

#include "qdeclarativecontactdetail_p.h"

QTCONTACTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE

class QDeclarativeContactRingtone : public QDeclarativeContactDetail
{
    Q_OBJECT

    Q_PROPERTY(QUrl audioRingtoneUrl READ audioRingtoneUrl WRITE setAudioRingtoneUrl NOTIFY valueChanged)
    Q_PROPERTY(QUrl videoRingtoneUrl READ videoRingtoneUrl WRITE setVideoRingtoneUrl NOTIFY valueChanged)
    Q_PROPERTY(QUrl vibrationRingtoneUrl READ vibrationRingtoneUrl WRITE setVibrationRingtoneUrl NOTIFY valueChanged)
    Q_ENUMS(FieldType)
    Q_CLASSINFO("DefaultProperty", "audioRingtoneUrl")
public:
    enum FieldType {
        AudioRingtoneUrl = QContactRingtone::FieldAudioRingtoneUrl,
        VideoRingtoneUrl = QContactRingtone::FieldVideoRingtoneUrl,
        VibrationRingtoneUrl = QContactRingtone::FieldVibrationRingtoneUrl
    };

    QDeclarativeContactRingtone(QObject* parent = Q_NULLPTR)
        :QDeclarativeContactDetail(parent)
    {
        setDetail(QContactRingtone());
        connect(this, SIGNAL(valueChanged()), SIGNAL(detailChanged()));
    }
    DetailType detailType() const override
    {
        return QDeclarativeContactDetail::Ringtone;
    }

    void setAudioRingtoneUrl(const QUrl& v)
    {
        if (!readOnly() && v != audioRingtoneUrl()) {
            detail().setValue(QContactRingtone::FieldAudioRingtoneUrl, v);
            emit valueChanged();
        }
    }
    QUrl audioRingtoneUrl() const {return detail().value<QUrl>(QContactRingtone::FieldAudioRingtoneUrl);}

    void setVideoRingtoneUrl(const QUrl& v)
    {
        if (!readOnly() && v != videoRingtoneUrl()) {
            detail().setValue(QContactRingtone::FieldVideoRingtoneUrl, v);
            emit valueChanged();
        }
    }
    QUrl videoRingtoneUrl() const {return detail().value<QUrl>(QContactRingtone::FieldVideoRingtoneUrl);}

    void setVibrationRingtoneUrl(const QUrl& v)
    {
        if (!readOnly() && v != vibrationRingtoneUrl()) {
            detail().setValue(QContactRingtone::FieldVibrationRingtoneUrl, v);
            emit valueChanged();
        }
    }
    QUrl vibrationRingtoneUrl() const {return detail().value<QUrl>(QContactRingtone::FieldVibrationRingtoneUrl);}
signals:
    void valueChanged();

};

QT_END_NAMESPACE

QML_DECLARE_TYPE(QDeclarativeContactRingtone)

#endif // QDECLARATIVECONTACTRINGTONE_H
