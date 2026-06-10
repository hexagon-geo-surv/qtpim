// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QCONTACTACTIONTARGET_H
#define QCONTACTACTIONTARGET_H

#include <QtCore/qlist.h>
#include <QtCore/qshareddata.h>

#include <QtContacts/qcontact.h>
#include <QtContacts/qcontactdetail.h>

QT_BEGIN_NAMESPACE_CONTACTS

class QContact;

class QContactActionTargetPrivate;
class Q_CONTACTS_EXPORT QContactActionTarget
{
public:
    explicit QContactActionTarget(const QContact& contact = QContact(), const QList<QContactDetail>& details = QList<QContactDetail>());
    QContactActionTarget(const QContact& contact, const QContactDetail& detail);

    QContactActionTarget(const QContactActionTarget& other);

    QContactActionTarget& operator=(const QContactActionTarget& other);
    ~QContactActionTarget();

    enum Type {
        Invalid, // no contact
        WholeContact, // no details
        SingleDetail, // a single detail
        MultipleDetails
    };

    Type type() const; // No setter
    bool isValid() const;
    bool operator==(const QContactActionTarget& other) const;
    bool operator!=(const QContactActionTarget& other) const;

    void setContact(const QContact& contact);
    void setDetails(const QList<QContactDetail>& details);

    QContact contact() const;
    QList<QContactDetail> details() const;

private:
#ifndef QT_NO_DATASTREAM
    Q_CONTACTS_EXPORT friend QDataStream& operator<<(QDataStream& out, const QContactActionTarget& target);
    Q_CONTACTS_EXPORT friend QDataStream& operator>>(QDataStream& in, QContactActionTarget& target);
#endif
    QSharedDataPointer<QContactActionTargetPrivate> d;
};

Q_CONTACTS_EXPORT size_t qHash(const QContactActionTarget& key);
#ifndef QT_NO_DATASTREAM
Q_CONTACTS_EXPORT QDataStream& operator<<(QDataStream& out, const QContactActionTarget& target);
Q_CONTACTS_EXPORT QDataStream& operator>>(QDataStream& in, QContactActionTarget& target);
#endif
#ifndef QT_NO_DEBUG_STREAM
Q_CONTACTS_EXPORT QDebug& operator<<(QDebug dbg, const QContactActionTarget& target);
#endif

QT_END_NAMESPACE_CONTACTS

QT_BEGIN_NAMESPACE
Q_DECLARE_TYPEINFO(QTCONTACTS_PREPEND_NAMESPACE(QContactActionTarget), Q_MOVABLE_TYPE);
QT_END_NAMESPACE

#endif // QCONTACTACTIONTARGET_H
