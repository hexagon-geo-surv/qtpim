// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QCONTACTFILTER_H
#define QCONTACTFILTER_H

#include <QtCore/qshareddata.h>

#include <QtContacts/qcontactsglobal.h>

QT_BEGIN_NAMESPACE_CONTACTS

/* Manual Q_DECLARE_CONTACTFILTER_PRIVATE macro */

#define Q_DECLARE_CONTACTFILTER_PRIVATE(Class) \
    inline Class##Private* d_func(); \
    inline const Class##Private* d_func() const; \
    friend class Class##Private;

class QContactFilterPrivate;
class Q_CONTACTS_EXPORT QContactFilter
{
public:
    QContactFilter();
    ~QContactFilter();
    QContactFilter(const QContactFilter& other);
    QContactFilter& operator=(const QContactFilter& other);

    enum FilterType {
        InvalidFilter,
        ContactDetailFilter,
        ContactDetailRangeFilter,
        ChangeLogFilter,
        ActionFilter,
        RelationshipFilter,
        IntersectionFilter,
        UnionFilter,
        IdFilter,
        DefaultFilter,
        CollectionFilter
    };

    FilterType type() const;

    enum MatchFlag {
        MatchExactly = 0x0000,        // 0
        MatchContains = 0x0001,       // 1
        MatchStartsWith = 0x0002,     // 2
        MatchEndsWith = 0x0004,       // 4
        MatchFixedString = 0x0008,      // 8
        MatchCaseSensitive = 0x0010,    // 16
        MatchPhoneNumber = 0x400,    //1024
        MatchKeypadCollation = 0x800 //2048
    };
    Q_DECLARE_FLAGS(MatchFlags, MatchFlag)

    bool operator==(const QContactFilter& other) const;
    bool operator!=(const QContactFilter& other) const {return !operator==(other);}

protected:
    explicit QContactFilter(QContactFilterPrivate* d);

protected:
    friend class QContactFilterPrivate;
#ifndef QT_NO_DATASTREAM
    Q_CONTACTS_EXPORT friend QDataStream& operator<<(QDataStream& out, const QContactFilter& filter);
    Q_CONTACTS_EXPORT friend QDataStream& operator>>(QDataStream& in, QContactFilter& filter);
#endif
#ifndef QT_NO_DEBUG_STREAM
    Q_CONTACTS_EXPORT friend QDebug operator<<(QDebug dbg, const QContactFilter& filter);
#endif
    QSharedDataPointer<QContactFilterPrivate> d_ptr;
};

Q_DECLARE_OPERATORS_FOR_FLAGS(QContactFilter::MatchFlags)

const Q_CONTACTS_EXPORT QContactFilter operator&(const QContactFilter& left, const QContactFilter& right);
const Q_CONTACTS_EXPORT QContactFilter operator|(const QContactFilter& left, const QContactFilter& right);

#ifndef QT_NO_DATASTREAM
Q_CONTACTS_EXPORT QDataStream& operator<<(QDataStream& out, const QContactFilter& filter);
Q_CONTACTS_EXPORT QDataStream& operator>>(QDataStream& in, QContactFilter& filter);
#endif
#ifndef QT_NO_DEBUG_STREAM
Q_CONTACTS_EXPORT QDebug operator<<(QDebug dbg, const QContactFilter& filter);
#endif

QT_END_NAMESPACE_CONTACTS

QT_BEGIN_NAMESPACE
Q_DECLARE_TYPEINFO(QTCONTACTS_PREPEND_NAMESPACE(QContactFilter), Q_MOVABLE_TYPE);
QT_END_NAMESPACE

#endif // QCONTACTFILTER_H
