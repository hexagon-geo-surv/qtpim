// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QCONTACTCOLLECTION_H
#define QCONTACTCOLLECTION_H

#include <QtCore/qmap.h>
#include <QtCore/qshareddata.h>
#include <QtCore/qvariant.h>

#include <QtContacts/qcontactcollectionid.h>
#include <QtContacts/qcontactid.h>
#include <QtContacts/qcontactdetail.h>
#include <QtContacts/qcontacttype.h>

QT_BEGIN_NAMESPACE_CONTACTS

class QContactManagerEngine;

class QContactCollectionData;
class Q_CONTACTS_EXPORT QContactCollection
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

    QContactCollection();
    ~QContactCollection();

    QContactCollection(const QContactCollection &other);
    QContactCollection &operator=(const QContactCollection &other);

    bool operator==(const QContactCollection &other) const;
    bool operator!=(const QContactCollection &other) const {return !(other == *this);}

    QContactCollectionId id() const;
    void setId(const QContactCollectionId &id);

    void setMetaData(MetaDataKey key, const QVariant &value);
    QVariant metaData(MetaDataKey key) const;

    void setMetaData(const QMap<QContactCollection::MetaDataKey, QVariant> &metaData);
    QMap<QContactCollection::MetaDataKey, QVariant> metaData() const;

    void setExtendedMetaData(const QString &key, const QVariant &value);
    QVariant extendedMetaData(const QString &key) const;
    QVariantMap extendedMetaData() const;

private:
    friend Q_CONTACTS_EXPORT size_t qHash(const QContactCollection &key);
    friend class QContactManagerEngine;
    QSharedDataPointer<QContactCollectionData> d;
};

Q_CONTACTS_EXPORT size_t qHash(const QContactCollection &key);

#ifndef QT_NO_DEBUG_STREAM
Q_CONTACTS_EXPORT QDebug operator<<(QDebug dbg, const QContactCollection &collection);
#endif // QT_NO_DEBUG_STREAM

#ifndef QT_NO_DATASTREAM
Q_CONTACTS_EXPORT QDataStream &operator<<(QDataStream &out, const QContactCollection &collection);
Q_CONTACTS_EXPORT QDataStream &operator>>(QDataStream &in, QContactCollection &collection);
#endif // QT_NO_DATASTREAM

QT_END_NAMESPACE_CONTACTS

QT_BEGIN_NAMESPACE
Q_DECLARE_TYPEINFO(QTCONTACTS_PREPEND_NAMESPACE(QContactCollection), Q_MOVABLE_TYPE);
QT_END_NAMESPACE

#endif // QCONTACTCOLLECTION_H
