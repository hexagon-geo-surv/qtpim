// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QDECLARATIVECONTACTCOLLECTION_H
#define QDECLARATIVECONTACTCOLLECTION_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.
// This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <QtCore/qurl.h>

#include <QtGui/qcolor.h>

#include <QtQml/qqml.h>

#include <QtContacts/qcontactcollection.h>

QTCONTACTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE

class QDeclarativeContactCollection : public QObject
{
    Q_OBJECT

    Q_ENUMS(MetaDataKey)
    Q_PROPERTY(QString collectionId READ id WRITE setId NOTIFY valueChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY valueChanged)
    Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY valueChanged)
    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY valueChanged)
    Q_PROPERTY(QColor secondaryColor READ secondaryColor WRITE setSecondaryColor NOTIFY valueChanged)
    Q_PROPERTY(QUrl image READ image WRITE setImage NOTIFY valueChanged)

public:
    enum MetaDataKey {
        KeyName = QContactCollection::KeyName,
        KeyDescription = QContactCollection::KeyDescription,
        KeyColor = QContactCollection::KeyColor,
        KeySecondaryColor = QContactCollection::KeySecondaryColor,
        KeyImage = QContactCollection::KeyImage,
        KeyExtended = QContactCollection::KeyExtended
    };

    QDeclarativeContactCollection(QObject *parent = nullptr);

    QString id() const;
    void setId(const QString &id);

    QString name() const;
    void setName(const QString &name);

    QString description() const;
    void setDescription(const QString &description);

    QColor color() const;
    void setColor(const QColor &color);

    QColor secondaryColor() const;
    void setSecondaryColor(const QColor &secondaryColor);

    QUrl image() const;
    void setImage(const QUrl &url);

    Q_INVOKABLE void setMetaData(QContactCollection::MetaDataKey key, const QVariant &value);
    Q_INVOKABLE QVariant metaData(QContactCollection::MetaDataKey key) const;

    Q_INVOKABLE void setExtendedMetaData(const QString &key, const QVariant &value);
    Q_INVOKABLE QVariant extendedMetaData(const QString &key) const;

    // used by model
    QContactCollection collection() const;
    void setCollection(const QContactCollection & collection);

Q_SIGNALS:
    void valueChanged();

private:
    QContactCollection d;
};

QT_END_NAMESPACE

QML_DECLARE_TYPE(QDeclarativeContactCollection)

#endif // QDECLARATIVECONTACTCOLLECTION_H
