// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QORGANIZERITEMID_H
#define QORGANIZERITEMID_H

#include <QtCore/qvariant.h>

#include <QtOrganizer/qorganizerglobal.h>

QT_BEGIN_NAMESPACE_ORGANIZER

class QOrganizerManagerEngine;

class Q_ORGANIZER_EXPORT QOrganizerItemId
{
public:
    inline QOrganizerItemId() {}
    inline QOrganizerItemId(const QString &_managerUri, const QByteArray &_localId)
        : m_managerUri(_localId.isEmpty() ? QString() : _managerUri),
          m_localId(m_managerUri.isEmpty() ? QByteArray() : _localId)
    {}
    // compiler-generated dtor and copy/move ctors/assignment operators are fine!

    inline bool operator==(const QOrganizerItemId &other) const
    { return localId() == other.localId() && managerUri() == other.managerUri(); }
    inline bool operator!=(const QOrganizerItemId &other) const
    { return !operator==(other); }

    inline bool isNull() const { return m_localId.isEmpty(); }

    inline QString managerUri() const { return m_managerUri; }
    inline QByteArray localId() const { return m_localId; }

    QString toString() const;
    static QOrganizerItemId fromString(const QString &idString);

    QByteArray toByteArray() const;
    static QOrganizerItemId fromByteArray(const QByteArray &idData);

private:
    QString m_managerUri;
    QByteArray m_localId;
};

inline bool operator<(const QOrganizerItemId &id1, const QOrganizerItemId &id2)
{ return id1.managerUri() != id2.managerUri() ? id1.managerUri() < id2.managerUri() : id1.localId() < id2.localId(); }

inline size_t qHash(const QOrganizerItemId &id)
{ return qHash(id.localId()); }

#ifndef QT_NO_DATASTREAM
Q_ORGANIZER_EXPORT QDataStream &operator<<(QDataStream &out, const QOrganizerItemId &id);
Q_ORGANIZER_EXPORT QDataStream &operator>>(QDataStream &in, QOrganizerItemId &id);
#endif

#ifndef QT_NO_DEBUG_STREAM
Q_ORGANIZER_EXPORT QDebug operator<<(QDebug dbg, const QOrganizerItemId &id);
#endif

QT_END_NAMESPACE_ORGANIZER

QT_BEGIN_NAMESPACE
Q_DECLARE_TYPEINFO(QTORGANIZER_PREPEND_NAMESPACE(QOrganizerItemId), Q_MOVABLE_TYPE);
QT_END_NAMESPACE

Q_DECLARE_METATYPE(QTORGANIZER_PREPEND_NAMESPACE(QOrganizerItemId))

#endif // QORGANIZERITEMID_H
