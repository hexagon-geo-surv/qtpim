// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QORGANIZERITEM_H
#define QORGANIZERITEM_H

#include <QtCore/qshareddata.h>
#include <QtCore/qstringlist.h>
#include <QtCore/qvariant.h>

#include <QtOrganizer/qorganizercollectionid.h>
#include <QtOrganizer/qorganizeritemid.h>
#include <QtOrganizer/qorganizeritemdetail.h>
#include <QtOrganizer/qorganizeritemtype.h>

QT_BEGIN_NAMESPACE_ORGANIZER

class QOrganizerItemData;
class Q_ORGANIZER_EXPORT QOrganizerItem
{
public:
    QOrganizerItem();
    QOrganizerItem(const QOrganizerItem &other);
    ~QOrganizerItem();

    QOrganizerItem &operator=(const QOrganizerItem &other);

    bool operator==(const QOrganizerItem &other) const;
    bool operator!=(const QOrganizerItem &other) const {return !(other == *this);}

    QOrganizerItemId id() const;
    void setId(const QOrganizerItemId &id);

    QOrganizerCollectionId collectionId() const;
    void setCollectionId(const QOrganizerCollectionId &collectionId);

    bool isEmpty() const;
    void clearDetails();

    QOrganizerItemDetail detail(QOrganizerItemDetail::DetailType detailType = QOrganizerItemDetail::TypeUndefined) const;
    QList<QOrganizerItemDetail> details(QOrganizerItemDetail::DetailType detailType = QOrganizerItemDetail::TypeUndefined) const;

    bool saveDetail(QOrganizerItemDetail *detail);
    bool removeDetail(QOrganizerItemDetail *detail);

    QOrganizerItemType::ItemType type() const;
    void setType(QOrganizerItemType::ItemType type);

    QString displayLabel() const;
    void setDisplayLabel(const QString &label);

    QString description() const;
    void setDescription(const QString &description);

    QStringList comments() const;
    void clearComments();
    void setComments(const QStringList &comments);
    void addComment(const QString &comment);

    QStringList tags() const;
    void clearTags();
    void addTag(const QString &tag);
    void setTags(const QStringList &tags);

    QString guid() const;
    void setGuid(const QString &guid);

    QVariant data(const QString &name) const;
    void setData(const QString &name, const QVariant &data);

protected:
    explicit QOrganizerItem(QOrganizerItemType::ItemType type);
    QOrganizerItem(const QOrganizerItem &other, QOrganizerItemType::ItemType expectedType);
    QOrganizerItem &assign(const QOrganizerItem &other, QOrganizerItemType::ItemType expectedType);

protected:
    friend class QOrganizerItemData;
    friend class QOrganizerManager;
    friend class QOrganizerManagerData;
    friend class QOrganizerManagerEngine;

#ifndef QT_NO_DATASTREAM
    Q_ORGANIZER_EXPORT friend QDataStream &operator<<(QDataStream &out, const QOrganizerItem &item);
    Q_ORGANIZER_EXPORT friend QDataStream &operator>>(QDataStream &in, QOrganizerItem &item);
#endif // QT_NO_DATASTREAM

    QSharedDataPointer<QOrganizerItemData> d;
};

Q_ORGANIZER_EXPORT size_t qHash(const QOrganizerItem &key);

#ifndef QT_NO_DATASTREAM
Q_ORGANIZER_EXPORT QDataStream &operator<<(QDataStream &out, const QOrganizerItem &item);
Q_ORGANIZER_EXPORT QDataStream &operator>>(QDataStream &in, QOrganizerItem &item);
#endif // QT_NO_DATASTREAM
#ifndef QT_NO_DEBUG_STREAM
Q_ORGANIZER_EXPORT QDebug operator<<(QDebug dbg, const QOrganizerItem &item);
#endif // QT_NO_DEBUG_STREAM

#define Q_DECLARE_CUSTOM_ORGANIZER_ITEM(className, typeConstant) \
    className() : QOrganizerItem(typeConstant) {} \
    className(const QOrganizerItem &other) : QOrganizerItem(other, typeConstant) {} \
    className& operator=(const QOrganizerItem &other) {assign(other, typeConstant); return *this;}

QT_END_NAMESPACE_ORGANIZER

QT_BEGIN_NAMESPACE
Q_DECLARE_TYPEINFO(QTORGANIZER_PREPEND_NAMESPACE(QOrganizerItem), Q_MOVABLE_TYPE);
QT_END_NAMESPACE

#endif // QORGANIZERITEM_H
