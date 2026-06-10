// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QCONTACTANNIVERSARY_H
#define QCONTACTANNIVERSARY_H

#include <QtCore/qdatetime.h>

#include <QtContacts/qcontactdetail.h>

QT_BEGIN_NAMESPACE_CONTACTS

/* Leaf class */
class Q_CONTACTS_EXPORT QContactAnniversary : public QContactDetail
{
public:
#ifndef Q_QDOC
    Q_DECLARE_CUSTOM_CONTACT_DETAIL(QContactAnniversary)
#else
    static const DetailType Type;
#endif

    enum AnniversaryField {
        FieldCalendarId = 0,
        FieldOriginalDate,
        FieldEvent,
        FieldSubType
    };

    enum SubType {
        SubTypeWedding = 0,
        SubTypeEngagement,
        SubTypeHouse,
        SubTypeEmployment,
        SubTypeMemorial
    };

    void setOriginalDate(const QDate& date);
    QDate originalDate() const;
    void setOriginalDateTime(const QDateTime& dateTime);
    QDateTime originalDateTime() const;

    void setCalendarId(const QString& _calendarId);
    QString calendarId() const;
    void setEvent(const QString& _event);
    QString event() const;

    void setSubType(QContactAnniversary::SubType _subType);
    QContactAnniversary::SubType subType() const;
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTANNIVERSARY_H
