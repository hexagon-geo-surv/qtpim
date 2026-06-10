// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QORGANIZERITEMFILTER_H
#define QORGANIZERITEMFILTER_H

#include <QtCore/qnamespace.h>
#include <QtCore/qshareddata.h>

#include <QtOrganizer/qorganizerglobal.h>

QT_BEGIN_NAMESPACE_ORGANIZER

class QOrganizerItemFilterPrivate;
class Q_ORGANIZER_EXPORT QOrganizerItemFilter
{
public:
    enum FilterType {
        InvalidFilter = 0,
        DetailFilter,
        DetailFieldFilter,
        DetailRangeFilter,
        IntersectionFilter,
        UnionFilter,
        IdFilter,
        CollectionFilter,
        DefaultFilter
    };

    QOrganizerItemFilter();
    QOrganizerItemFilter(const QOrganizerItemFilter &other);
    ~QOrganizerItemFilter();

    QOrganizerItemFilter &operator=(const QOrganizerItemFilter &other);

    FilterType type() const;

    // Qt::MatchFlags don't quite match here
    enum MatchFlag {
        MatchExactly = Qt::MatchExactly,    // 0
        MatchContains = Qt::MatchContains,  // 1
        MatchStartsWith = Qt::MatchStartsWith,  // 2
        MatchEndsWith = Qt::MatchEndsWith, // 3
        MatchFixedString = Qt::MatchFixedString, // 8
        MatchCaseSensitive = Qt::MatchCaseSensitive // 16
    };
    Q_DECLARE_FLAGS(MatchFlags, MatchFlag)

    bool operator==(const QOrganizerItemFilter &other) const;
    bool operator!=(const QOrganizerItemFilter &other) const { return !operator==(other); }

protected:
    explicit QOrganizerItemFilter(QOrganizerItemFilterPrivate *d);
    QSharedDataPointer<QOrganizerItemFilterPrivate> d_ptr;

protected:
    friend class QOrganizerItemFilterPrivate;

#ifndef QT_NO_DATASTREAM
    Q_ORGANIZER_EXPORT friend QDataStream &operator<<(QDataStream &out, const QOrganizerItemFilter &filter);
    Q_ORGANIZER_EXPORT friend QDataStream &operator>>(QDataStream &in, QOrganizerItemFilter &filter);
#endif // QT_NO_DATASTREAM

#ifndef QT_NO_DEBUG_STREAM
    Q_ORGANIZER_EXPORT friend QDebug operator<<(QDebug dbg, const QOrganizerItemFilter &filter);
#endif // QT_NO_DEBUG_STREAM
};

#define Q_DECLARE_ORGANIZERITEMFILTER_PRIVATE(Class) \
    inline Class##Private* d_func(); \
    inline const Class##Private* d_func() const; \
    friend class Class##Private;

const Q_ORGANIZER_EXPORT QOrganizerItemFilter operator&(const QOrganizerItemFilter &left, const QOrganizerItemFilter &right);
const Q_ORGANIZER_EXPORT QOrganizerItemFilter operator|(const QOrganizerItemFilter &left, const QOrganizerItemFilter &right);

#ifndef QT_NO_DATASTREAM
Q_ORGANIZER_EXPORT QDataStream &operator<<(QDataStream &out, const QOrganizerItemFilter &filter);
Q_ORGANIZER_EXPORT QDataStream &operator>>(QDataStream &in, QOrganizerItemFilter &filter);
#endif // QT_NO_DATASTREAM
#ifndef QT_NO_DEBUG_STREAM
Q_ORGANIZER_EXPORT QDebug operator<<(QDebug dbg, const QOrganizerItemFilter &filter);
#endif // QT_NO_DEBUG_STREAM

QT_END_NAMESPACE_ORGANIZER

QT_BEGIN_NAMESPACE
Q_DECLARE_TYPEINFO(QTORGANIZER_PREPEND_NAMESPACE(QOrganizerItemFilter), Q_MOVABLE_TYPE);
Q_DECLARE_OPERATORS_FOR_FLAGS(QTORGANIZER_PREPEND_NAMESPACE(QOrganizerItemFilter::MatchFlags))
QT_END_NAMESPACE

#endif // QORGANIZERITEMFILTER_H
