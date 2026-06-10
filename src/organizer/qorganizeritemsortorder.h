// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QORGANIZERITEMSORTORDER_H
#define QORGANIZERITEMSORTORDER_H

#include <QtCore/qlist.h>
#include <QtCore/qshareddata.h>

#include <QtOrganizer/qorganizeritemdetail.h>

QT_BEGIN_NAMESPACE_ORGANIZER

class QOrganizerItemSortOrderPrivate;
class Q_ORGANIZER_EXPORT QOrganizerItemSortOrder
{
public:
    QOrganizerItemSortOrder();
    ~QOrganizerItemSortOrder();

    QOrganizerItemSortOrder(const QOrganizerItemSortOrder &other);
    QOrganizerItemSortOrder &operator=(const QOrganizerItemSortOrder &other);

    enum BlankPolicy {
        BlanksFirst,
        BlanksLast
    };

    // mutators
    void setDetail(QOrganizerItemDetail::DetailType detailType, int field = -1);
    void setBlankPolicy(BlankPolicy blankPolicy);
    void setDirection(Qt::SortOrder direction);
    void setCaseSensitivity(Qt::CaseSensitivity sensitivity);

    // accessors
    QOrganizerItemDetail::DetailType detailType() const;
    int detailField() const;
    BlankPolicy blankPolicy() const;
    Qt::SortOrder direction() const;
    Qt::CaseSensitivity caseSensitivity() const;

    bool isValid() const;

    bool operator==(const QOrganizerItemSortOrder &other) const;
    bool operator!=(const QOrganizerItemSortOrder &other) const { return !operator==(other); }

    // convenience cast
    operator QList<QOrganizerItemSortOrder>() const { return QList<QOrganizerItemSortOrder>() << *this; }

private:
    QSharedDataPointer<QOrganizerItemSortOrderPrivate> d;
};

#ifndef QT_NO_DATASTREAM
Q_ORGANIZER_EXPORT QDataStream &operator<<(QDataStream &out, const QOrganizerItemSortOrder &sortOrder);
Q_ORGANIZER_EXPORT QDataStream &operator>>(QDataStream &in, QOrganizerItemSortOrder &sortOrder);
#endif // QT_NO_DATASTREAM

#ifndef QT_NO_DEBUG_STREAM
Q_ORGANIZER_EXPORT QDebug operator<<(QDebug dbg, const QOrganizerItemSortOrder &sortOrder);
#endif // QT_NO_DEBUG_STREAM

QT_END_NAMESPACE_ORGANIZER

QT_BEGIN_NAMESPACE
Q_DECLARE_TYPEINFO(QTORGANIZER_PREPEND_NAMESPACE(QOrganizerItemSortOrder), Q_MOVABLE_TYPE);
QT_END_NAMESPACE

#endif // QORGANIZERITEMSORTORDER_H
