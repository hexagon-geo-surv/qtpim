// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QORGANIZERCOLLECTION_H
#define QORGANIZERCOLLECTION_H

#include <QtCore/qmap.h>
#include <QtCore/qshareddata.h>
#include <QtCore/qvariant.h>

#include <QtOrganizer/qorganizercollectionid.h>
#include <QtOrganizer/qorganizeritemid.h>
#include <QtOrganizer/qorganizeritemdetail.h>
#include <QtOrganizer/qorganizeritemtype.h>

QT_BEGIN_NAMESPACE_ORGANIZER

class QOrganizerManagerEngine;

class QOrganizerCollectionData;
class Q_ORGANIZER_EXPORT QOrganizerCollection
{
public:
    enum MetaDataKey {
        KeyName = 0,
        KeyDescription,
        KeyColor,
        KeySecondaryColor,
        KeyImage,
        KeyExtended
    };

    QOrganizerCollection();
    ~QOrganizerCollection();

    QOrganizerCollection(const QOrganizerCollection &other);
    QOrganizerCollection &operator=(const QOrganizerCollection &other);

    bool operator==(const QOrganizerCollection &other) const;
    bool operator!=(const QOrganizerCollection &other) const {return !(other == *this);}

    QOrganizerCollectionId id() const;
    void setId(const QOrganizerCollectionId &id);

    void setMetaData(MetaDataKey key, const QVariant &value);
    QVariant metaData(MetaDataKey key) const;

    void setMetaData(const QMap<QOrganizerCollection::MetaDataKey, QVariant> &metaData);
    QMap<QOrganizerCollection::MetaDataKey, QVariant> metaData() const;

    void setExtendedMetaData(const QString &key, const QVariant &value);
    QVariant extendedMetaData(const QString &key) const;
    QVariantMap extendedMetaData() const;

private:
    friend Q_ORGANIZER_EXPORT size_t qHash(const QOrganizerCollection &key);
    friend class QOrganizerManagerEngine;
    QSharedDataPointer<QOrganizerCollectionData> d;
};

Q_ORGANIZER_EXPORT size_t qHash(const QOrganizerCollection &key);

#ifndef QT_NO_DEBUG_STREAM
Q_ORGANIZER_EXPORT QDebug operator<<(QDebug dbg, const QOrganizerCollection &collection);
#endif // QT_NO_DEBUG_STREAM

#ifndef QT_NO_DATASTREAM
Q_ORGANIZER_EXPORT QDataStream &operator<<(QDataStream &out, const QOrganizerCollection &collection);
Q_ORGANIZER_EXPORT QDataStream &operator>>(QDataStream &in, QOrganizerCollection &collection);
#endif // QT_NO_DATASTREAM

QT_END_NAMESPACE_ORGANIZER

QT_BEGIN_NAMESPACE
Q_DECLARE_TYPEINFO(QTORGANIZER_PREPEND_NAMESPACE(QOrganizerCollection), Q_MOVABLE_TYPE);
QT_END_NAMESPACE

#endif // QORGANIZERCOLLECTION_H
