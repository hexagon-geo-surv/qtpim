// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QCONTACTBIRTHDAY_H
#define QCONTACTBIRTHDAY_H

#include <QtCore/qdatetime.h>

#include <QtContacts/qcontactdetail.h>

QT_BEGIN_NAMESPACE_CONTACTS

/* Leaf class */
class Q_CONTACTS_EXPORT QContactBirthday : public QContactDetail
{
public:
#ifndef Q_QDOC
    Q_DECLARE_CUSTOM_CONTACT_DETAIL(QContactBirthday)
#else
    static const DetailType Type;
#endif

    enum BirthdayField {
        FieldBirthday = 0,
        FieldCalendarId
    };

    void setDate(const QDate& _date);
    QDate date() const;
    void setDateTime(const QDateTime& _dateTime);
    QDateTime dateTime() const;
    void setCalendarId(const QString& _calendarId);
    QString calendarId() const;
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTBIRTHDAY_H
