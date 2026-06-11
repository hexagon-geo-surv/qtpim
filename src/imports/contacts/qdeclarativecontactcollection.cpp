// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qdeclarativecontactcollection_p.h"

#include <QtCore/qurl.h>

QTCONTACTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE

/*!
    \qmltype Collection
    \instantiates QDeclarativeContactCollection
    \brief The Collection element represents a collection of items in a contacts manager.
    \ingroup qml-contacts-main
    \inqmlmodule QtContacts
 */

/*!
    \internal
 */
QDeclarativeContactCollection::QDeclarativeContactCollection(QObject *parent)
    : QObject(parent)
{
}

/*!
    \qmlproperty string Collection::collectionId

    This property holds the ID of the collection.
 */
QString QDeclarativeContactCollection::id() const
{
    return d.id().toString();
}

void QDeclarativeContactCollection::setId(const QString &id)
{
    if (d.id().toString() != id) {
        d.setId(QContactCollectionId::fromString(id));
        emit valueChanged();
    }
}

/*!
    \qmlproperty string Collection::name

    This property holds the name meta data of a collection.
 */
QString QDeclarativeContactCollection::name() const
{
    return metaData(QContactCollection::KeyName).toString();
}

void QDeclarativeContactCollection::setName(const QString &name)
{
    setMetaData(QContactCollection::KeyName, name);
}

/*!
    \qmlproperty string Collection::description

    This property holds the description meta data of a collection.
 */
QString QDeclarativeContactCollection::description() const
{
    return metaData(QContactCollection::KeyDescription).toString();
}

void QDeclarativeContactCollection::setDescription(const QString &description)
{
    setMetaData(QContactCollection::KeyDescription, description);
}

/*!
    \qmlproperty color Collection::secondaryColor

    This property holds the secondary color meta data of a collection.
 */
QColor QDeclarativeContactCollection::secondaryColor() const
{
    return metaData(QContactCollection::KeySecondaryColor).value<QColor>();
}

void QDeclarativeContactCollection::setSecondaryColor(const QColor &secondaryColor)
{
    setMetaData(QContactCollection::KeySecondaryColor, secondaryColor);
}

/*!
    \qmlproperty color Collection::color

    This property holds the color meta data of a collection.
 */
QColor QDeclarativeContactCollection::color() const
{
    return metaData(QContactCollection::KeyColor).value<QColor>();
}

void QDeclarativeContactCollection::setColor(const QColor &color)
{
    setMetaData(QContactCollection::KeyColor, color);
}

/*!
    \qmlproperty url Collection::image

    This property holds the image url meta data of a collection.
 */
QUrl QDeclarativeContactCollection::image() const
{
    return QUrl(metaData(QContactCollection::KeyImage).toString());
}

void QDeclarativeContactCollection::setImage(const QUrl &url)
{
    setMetaData(QContactCollection::KeyImage, url);
}

/*!
    \qmlmethod Collection::setMetaData(key, value)

    Sets the meta data of the collection for the given \a key to the given \a value. Possible keys
    include:
    \list
    \li Collection.KeyName
    \li Collection.KeyDescription
    \li Collection.KeyColor
    \li Collection.KeySecondaryColor
    \li Collection.KeyImage
    \li Collection.KeyExtended
    \endlist
 */
void QDeclarativeContactCollection::setMetaData(QContactCollection::MetaDataKey key, const QVariant &value)
{
    if (metaData(key) != value) {
        d.setMetaData(key, value);
        emit valueChanged();
    }
}

/*!
    \qmlmethod var Collection::metaData(key)

    Returns the meta data stored in this collection for the given \a key. Possible keys include:
    \list
    \li Collection.KeyName
    \li Collection.KeyDescription
    \li Collection.KeyColor
    \li Collection.KeyImage
    \li Collection.KeyExtended
    \endlist
 */
QVariant QDeclarativeContactCollection::metaData(QContactCollection::MetaDataKey key) const
{
    return d.metaData(key);
}

/*!
    \qmlmethod Collection::setExtendedMetaData(key, value)

    Sets the value of the extended metadata with the given \a key to \a value.
 */
void QDeclarativeContactCollection::setExtendedMetaData(const QString &key, const QVariant &value)
{
    if (extendedMetaData(key) != value) {
        d.setExtendedMetaData(key, value);
        emit valueChanged();
    }
}

/*!
    \qmlmethod var Collection::extendedMetaData(key)

    Returns the value of extended metadata with the given \a key.
 */
QVariant QDeclarativeContactCollection::extendedMetaData(const QString &key) const
{
    return d.extendedMetaData(key);
}

/*!
    \internal
 */
QContactCollection QDeclarativeContactCollection::collection() const
{
    return d;
}

/*!
    \internal
 */
void QDeclarativeContactCollection::setCollection(const QContactCollection &collection)
{
    d = collection;
}


QT_END_NAMESPACE

#include "moc_qdeclarativecontactcollection_p.cpp"
