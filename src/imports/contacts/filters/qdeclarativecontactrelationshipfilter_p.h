// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QDECLARATIVECONTACTRELATIONSHIPFILTER_H
#define QDECLARATIVECONTACTRELATIONSHIPFILTER_H

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

#include <QtContacts/qcontactrelationshipfilter.h>

#include "qdeclarativecontact_p.h"
#include "qdeclarativecontactfilter_p.h"
#include "qdeclarativecontactrelationship_p.h"

QTCONTACTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE

class QDeclarativeContactRelationshipFilter : public QDeclarativeContactFilter
{
    Q_OBJECT
    Q_PROPERTY(QVariant relationshipType READ relationshipType WRITE setRelationshipType NOTIFY valueChanged)
    Q_PROPERTY(QString relatedContactId READ relatedContactId WRITE setRelatedContactId NOTIFY valueChanged)
    Q_PROPERTY(QDeclarativeContactRelationship::RelationshipRole relatedContactRole READ relatedContactRole WRITE setRelatedContactRole NOTIFY valueChanged)

public:

    QDeclarativeContactRelationshipFilter(QObject* parent = Q_NULLPTR)
        :QDeclarativeContactFilter(parent)
    {
        connect(this, SIGNAL(valueChanged()), SIGNAL(filterChanged()));
    }

    QVariant relationshipType() const
    {
        return d.relationshipType();
    }
    void setRelationshipType(const QVariant& v)
    {
        QString rt;
        if (v.typeId() != QMetaType::QString) {
            switch (v.toInt()) {
            case QDeclarativeContactRelationship::HasMember:
                rt = QContactRelationship::HasMember();
                break;
            case QDeclarativeContactRelationship::Aggregates:
                rt = QContactRelationship::Aggregates();
                break;
            case QDeclarativeContactRelationship::IsSameAs:
                rt = QContactRelationship::IsSameAs();
                break;
            case QDeclarativeContactRelationship::HasAssistant:
                rt = QContactRelationship::HasAssistant();
                break;
            case QDeclarativeContactRelationship::HasManager:
                rt = QContactRelationship::HasManager();
                break;
            case QDeclarativeContactRelationship::HasSpouse:
                rt = QContactRelationship::HasSpouse();
                break;
           default:
                break;
            }
        } else {
            rt = v.toString();
        }

        if (rt != relationshipType()) {
            d.setRelationshipType(rt);
            emit valueChanged();
        }
    }

    QString relatedContactId() const
    {
        const QContactId contactId(d.relatedContactId());
        if (!contactId.isNull())
            return contactId.toString();
        return QString();
    }

    void setRelatedContactId(const QString& id)
    {
        const QContactId contactId(QContactId::fromString(id));
        if (contactId != d.relatedContactId()) {
            d.setRelatedContactId(contactId);
            emit valueChanged();
        }
    }

    QDeclarativeContactRelationship::RelationshipRole relatedContactRole() const
    {
        switch (d.relatedContactRole()) {
        case QContactRelationship::First:
            return QDeclarativeContactRelationship::First;
        case QContactRelationship::Second:
            return QDeclarativeContactRelationship::Second;
        default:
            break;
        }
        return QDeclarativeContactRelationship::Either;
    }

    void setRelatedContactRole(QDeclarativeContactRelationship::RelationshipRole v)
    {
        if (v != relatedContactRole()) {
            switch (v) {
            case QDeclarativeContactRelationship::First:
                d.setRelatedContactRole(QContactRelationship::First);
                break;
            case QDeclarativeContactRelationship::Second:
                d.setRelatedContactRole(QContactRelationship::Second);
                break;
            case QDeclarativeContactRelationship::Either:
                d.setRelatedContactRole(QContactRelationship::Either);
                break;
            }
            emit valueChanged();
        }
    }
    QContactFilter filter() const override
    {
        return d;
    }
signals:
    void valueChanged();
private:
    QContactRelationshipFilter d;
};

QT_END_NAMESPACE

QML_DECLARE_TYPE(QDeclarativeContactRelationshipFilter)

#endif // QDECLARATIVECONTACTRELATIONSHIPFILTER_H
