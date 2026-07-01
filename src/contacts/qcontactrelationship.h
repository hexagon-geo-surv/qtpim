// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QCONTACTRELATIONSHIP_H
#define QCONTACTRELATIONSHIP_H

#include <QtCore/qshareddata.h>
#include <QtCore/qstring.h>

#include <QtContacts/qcontactsglobal.h>

QT_BEGIN_NAMESPACE_CONTACTS

class QContactId;

class QContactRelationshipPrivate;
class Q_CONTACTS_EXPORT QContactRelationship
{
public:
    inline static const QString HasMember() {return QStringLiteral("HasMember");}
    inline static const QString Aggregates() {return QStringLiteral("Aggregates");}
    inline static const QString IsSameAs() {return QStringLiteral("IsSameAs");}
    inline static const QString HasAssistant() {return QStringLiteral("HasAssistant");}
    inline static const QString HasManager() {return QStringLiteral("HasManager");}
    inline static const QString HasSpouse() {return QStringLiteral("HasSpouse");}

    QContactRelationship();
    ~QContactRelationship();

    QContactRelationship(const QContactRelationship& other);
    QContactRelationship& operator=(const QContactRelationship& other);
    bool operator==(const QContactRelationship &other) const;
    bool operator!=(const QContactRelationship &other) const { return !(*this==other); }

    QContactId first() const;
    QContactId second() const;
    QString relationshipType() const;

    void setFirst(const QContactId& firstContact);
    void setSecond(const QContactId& secondContact);
    void setRelationshipType(const QString& relationshipType);

    enum Role {
        First = 0,
        Second,
        Either
    };

private:
    QSharedDataPointer<QContactRelationshipPrivate> d;
};

Q_CONTACTS_EXPORT uint qHash(const QContactRelationship& key);
#ifndef QT_NO_DEBUG_STREAM
Q_CONTACTS_EXPORT QDebug operator<<(QDebug dbg, const QContactRelationship& rel);
#endif
#ifndef QT_NO_DATASTREAM
Q_CONTACTS_EXPORT QDataStream& operator<<(QDataStream& out, const QContactRelationship& rel);
Q_CONTACTS_EXPORT QDataStream& operator>>(QDataStream& in, QContactRelationship& rel);
#endif

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTRELATIONSHIP_H
