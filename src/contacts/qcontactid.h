// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QCONTACTID_H
#define QCONTACTID_H

#include <QtCore/qvariant.h>

#include <QtContacts/qcontactsglobal.h>

QT_BEGIN_NAMESPACE_CONTACTS

class QContactManagerEngine;

class Q_CONTACTS_EXPORT QContactId
{
public:
    inline QContactId() {}
    inline QContactId(const QString &_managerUri, const QByteArray &_localId)
        : m_managerUri(_localId.isEmpty() ? QString() : _managerUri),
          m_localId(m_managerUri.isEmpty() ? QByteArray() : _localId)
    {}
    // compiler-generated dtor and copy/move ctors/assignment operators are fine!

    inline bool operator==(const QContactId &other) const
    { return localId() == other.localId() && managerUri() == other.managerUri(); }
    inline bool operator!=(const QContactId &other) const
    { return !operator==(other); }

    inline bool isNull() const { return m_localId.isEmpty(); }

    inline QString managerUri() const { return m_managerUri; }
    inline QByteArray localId() const { return m_localId; }

    QString toString() const;
    static QContactId fromString(const QString &idString);

    QByteArray toByteArray() const;
    static QContactId fromByteArray(const QByteArray &idData);

private:
    QString m_managerUri;
    QByteArray m_localId;
};

inline bool operator<(const QContactId &id1, const QContactId &id2)
{ return id1.managerUri() != id2.managerUri() ? id1.managerUri() < id2.managerUri() : id1.localId() < id2.localId(); }

inline size_t qHash(const QContactId &id, size_t seed = 0) noexcept
{ return qHash(id.localId(), seed); }

#ifndef QT_NO_DEBUG_STREAM
Q_CONTACTS_EXPORT QDebug operator<<(QDebug dbg, const QContactId &id);
#endif

#ifndef QT_NO_DATASTREAM
Q_CONTACTS_EXPORT QDataStream& operator<<(QDataStream &out, const QContactId &id);
Q_CONTACTS_EXPORT QDataStream& operator>>(QDataStream &in, QContactId &id);
#endif

QT_END_NAMESPACE_CONTACTS

QT_BEGIN_NAMESPACE
Q_DECLARE_TYPEINFO(QTCONTACTS_PREPEND_NAMESPACE(QContactId), Q_MOVABLE_TYPE);
QT_END_NAMESPACE

Q_DECLARE_METATYPE(QTCONTACTS_PREPEND_NAMESPACE(QContactId))

#endif // QCONTACTID_H
