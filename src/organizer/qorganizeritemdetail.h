// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QORGANIZERITEMDETAIL_H
#define QORGANIZERITEMDETAIL_H

#include <QtCore/qmap.h>
#include <QtCore/qshareddata.h>
#include <QtCore/qstringlist.h>
#include <QtCore/qvariant.h>

#include <QtOrganizer/qorganizerglobal.h>

QT_BEGIN_NAMESPACE_ORGANIZER

class QOrganizerItemDetailPrivate;
class Q_ORGANIZER_EXPORT QOrganizerItemDetail
{
public:
    enum DetailType {
        TypeUndefined = 0,
        TypeClassification = 100,
        TypeComment = 200,
        TypeDescription = 300,
        TypeDisplayLabel = 400,
        TypeItemType = 500,
        TypeGuid = 600,
        TypeLocation = 700,
        TypeParent = 800,
        TypePriority = 900,
        TypeRecurrence = 1000,
        TypeTag = 1100,
        TypeTimestamp = 1200,
        TypeVersion = 1300,
        TypeReminder = 1400,
        TypeAudibleReminder = 1500,
        TypeEmailReminder = 1600,
        TypeVisualReminder = 1700,
        TypeExtendedDetail = 1800,
        TypeEventAttendee = 1900,
        TypeEventRsvp = 2000,
        TypeEventTime = 2100,
        TypeJournalTime = 2200,
        TypeTodoProgress = 2300,
        TypeTodoTime = 2400
    };

    QOrganizerItemDetail(DetailType detailType = TypeUndefined);
    QOrganizerItemDetail(const QOrganizerItemDetail &other);
    ~QOrganizerItemDetail();

    QOrganizerItemDetail &operator=(const QOrganizerItemDetail &other);

    bool operator==(const QOrganizerItemDetail &other) const;
    bool operator!=(const QOrganizerItemDetail &other) const {return !(other == *this);}

    DetailType type() const;
    bool isEmpty() const;

    int key() const;
    void resetKey();

    bool setValue(int field, const QVariant &value);
    bool removeValue(int field);
    bool hasValue(int field) const;

    QMap<int, QVariant> values() const;
    QVariant value(int field) const;
    template <typename T> T value(int field) const
    {
        return value(field).value<T>();
    }

protected:
    QOrganizerItemDetail(const QOrganizerItemDetail &other, DetailType expectedDetailType);
    QOrganizerItemDetail &assign(const QOrganizerItemDetail &other, DetailType expectedDetailType);

private:
    friend Q_ORGANIZER_EXPORT size_t qHash(const QOrganizerItemDetail &key, size_t seed) noexcept;
    friend class QOrganizerItem;
    friend class QOrganizerItemDetailPrivate;

#ifndef QT_NO_DATASTREAM
    friend Q_ORGANIZER_EXPORT QDataStream &operator>>(QDataStream &in, QOrganizerItemDetail &detail);
#endif // QT_NO_DATASTREAM

    QSharedDataPointer<QOrganizerItemDetailPrivate> d;
};

Q_ORGANIZER_EXPORT size_t qHash(const QOrganizerItemDetail &key, size_t seed = 0) noexcept;

inline size_t qHash(QOrganizerItemDetail::DetailType key, size_t seed = 0) noexcept
{ return ::qHash(static_cast<int>(key), seed); }

#ifndef QT_NO_DATASTREAM
Q_ORGANIZER_EXPORT QDataStream &operator<<(QDataStream &out, const QOrganizerItemDetail &detail);
Q_ORGANIZER_EXPORT QDataStream &operator>>(QDataStream &in, QOrganizerItemDetail &detail);
#endif // QT_NO_DATASTREAM
#ifndef QT_NO_DEBUG_STREAM
Q_ORGANIZER_EXPORT QDebug operator<<(QDebug dbg, const QOrganizerItemDetail &detail);
#endif // QT_NO_DEBUG_STREAM

#define Q_DECLARE_CUSTOM_ORGANIZER_DETAIL(className, detailType) \
    className() : QOrganizerItemDetail(detailType) {} \
    className(const QOrganizerItemDetail &other) : QOrganizerItemDetail(other, detailType) {} \
    className &operator=(const QOrganizerItemDetail &other) {assign(other, detailType); return *this;}

QT_END_NAMESPACE_ORGANIZER

QT_BEGIN_NAMESPACE
Q_DECLARE_TYPEINFO(QTORGANIZER_PREPEND_NAMESPACE(QOrganizerItemDetail), Q_MOVABLE_TYPE);
QT_END_NAMESPACE

#endif // QORGANIZERITEMDETAIL_H
