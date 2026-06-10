// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QCONTACTSORTORDER_H
#define QCONTACTSORTORDER_H

#include <QtCore/qlist.h>
#include <QtCore/qshareddata.h>

#include <QtContacts/qcontactdetail.h>

QT_BEGIN_NAMESPACE_CONTACTS

class QContactSortOrderPrivate;
class Q_CONTACTS_EXPORT QContactSortOrder
{
public:
    QContactSortOrder();
    ~QContactSortOrder();

    QContactSortOrder(const QContactSortOrder& other);
    QContactSortOrder& operator=(const QContactSortOrder& other);

    enum BlankPolicy {
        BlanksFirst,
        BlanksLast
    };

    /* Mutators */
    void setDetailType(QContactDetail::DetailType type, int field = -1);
    void setBlankPolicy(BlankPolicy blankPolicy);
    void setDirection(Qt::SortOrder direction);
    void setCaseSensitivity(Qt::CaseSensitivity sensitivity);

    /* Accessors */
    QContactDetail::DetailType detailType() const;
    int detailField() const;
    BlankPolicy blankPolicy() const;
    Qt::SortOrder direction() const;
    Qt::CaseSensitivity caseSensitivity() const;

    bool isValid() const;

    bool operator==(const QContactSortOrder& other) const;
    bool operator!=(const QContactSortOrder& other) const {return !operator==(other);}

    /* Convenience cast */
    operator QList<QContactSortOrder>() const {return QList<QContactSortOrder>() << *this;}

private:
    QSharedDataPointer<QContactSortOrderPrivate> d;
};

#ifndef QT_NO_DATASTREAM
Q_CONTACTS_EXPORT QDataStream& operator<<(QDataStream& out, const QContactSortOrder& sortOrder);
Q_CONTACTS_EXPORT QDataStream& operator>>(QDataStream& in, QContactSortOrder& sortOrder);
#endif

#ifndef QT_NO_DEBUG_STREAM
Q_CONTACTS_EXPORT QDebug operator<<(QDebug dbg, const QContactSortOrder& sortOrder);
#endif

QT_END_NAMESPACE_CONTACTS

QT_BEGIN_NAMESPACE
Q_DECLARE_TYPEINFO(QTCONTACTS_PREPEND_NAMESPACE(QContactSortOrder), Q_MOVABLE_TYPE);
QT_END_NAMESPACE

#endif // QCONTACTSORTORDER_H
