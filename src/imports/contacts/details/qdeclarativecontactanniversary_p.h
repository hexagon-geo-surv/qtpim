// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QDECLARATIVECONTACTANNIVERSARY_H
#define QDECLARATIVECONTACTANNIVERSARY_H

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

#include <QtContacts/qcontactanniversary.h>

#include "qdeclarativecontactdetail_p.h"

QTCONTACTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE

class QDeclarativeContactAnniversary : public QDeclarativeContactDetail
{
    Q_OBJECT

    Q_PROPERTY(QString calendarId READ calendarId WRITE setCalendarId NOTIFY valueChanged)
    Q_PROPERTY(QDate originalDate READ originalDate WRITE setOriginalDate NOTIFY valueChanged)
    Q_PROPERTY(QDateTime originalDateTime READ originalDateTime WRITE setOriginalDateTime NOTIFY valueChanged)
    Q_PROPERTY(QString event READ event WRITE setEvent NOTIFY valueChanged)
    Q_PROPERTY(AnniversarySubType subType READ subType WRITE setSubType NOTIFY valueChanged)
    Q_ENUMS(FieldType)
    Q_ENUMS(AnniversarySubType)
public:
    enum FieldType {
        CalendarId = QContactAnniversary::FieldCalendarId,
        OriginalDate = QContactAnniversary::FieldOriginalDate,
        Event = QContactAnniversary::FieldEvent,
        SubType = QContactAnniversary::FieldSubType
    };

    enum AnniversarySubType {
        Wedding = QContactAnniversary::SubTypeWedding,
        Engagement = QContactAnniversary::SubTypeEngagement,
        House = QContactAnniversary::SubTypeHouse,
        Employment = QContactAnniversary::SubTypeEmployment,
        Memorial = QContactAnniversary::SubTypeMemorial
    };

    QDeclarativeContactAnniversary(QObject* parent = nullptr)
        :QDeclarativeContactDetail(parent)
    {
        setDetail(QContactAnniversary());
        connect(this, SIGNAL(valueChanged()), SIGNAL(detailChanged()));
    }

    DetailType detailType() const
    {
        return QDeclarativeContactDetail::Anniversary;
    }

    void setOriginalDate(const QDate& v)
    {
        if (!readOnly() && v != originalDate()) {
            detail().setValue(QContactAnniversary::FieldOriginalDate, v);
            emit valueChanged();
        }
    }
    QDate originalDate() const {return detail().value<QDate>(QContactAnniversary::FieldOriginalDate);}
    void setOriginalDateTime(const QDateTime& v)
    {
        if (!readOnly() && v != originalDateTime()) {
            detail().setValue(QContactAnniversary::FieldOriginalDate, v);
            emit valueChanged();
        }
    }
    QDateTime originalDateTime() const {return detail().value<QDateTime>(QContactAnniversary::FieldOriginalDate);}

    void setCalendarId(const QString& v)
    {
        if (!readOnly() && v != calendarId()) {
            detail().setValue(QContactAnniversary::FieldCalendarId, v);
            emit valueChanged();
        }
    }
    QString calendarId() const {return detail().value(QContactAnniversary::FieldCalendarId).toString();}
    void setEvent(const QString& v)
    {
        if (!readOnly() && v != event()) {
            detail().setValue(QContactAnniversary::FieldEvent, v);
            emit valueChanged();
        }
    }
    QString event() const {return detail().value(QContactAnniversary::FieldEvent).toString();}

    void setSubType(AnniversarySubType v)
    {
        if (!readOnly() && v != subType()) {
            detail().setValue(QContactAnniversary::FieldSubType, v);
        }
    }

    AnniversarySubType subType() const
    {
        return static_cast<AnniversarySubType>(detail().value<int>(QContactAnniversary::FieldSubType));
    }
signals:
    void valueChanged();
};

QT_END_NAMESPACE

QML_DECLARE_TYPE(QDeclarativeContactAnniversary)

#endif // QDECLARATIVECONTACTANNIVERSARY_H
