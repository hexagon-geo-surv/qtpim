// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QDECLARATIVECONTACTRELATIONSHIP_P_H
#define QDECLARATIVECONTACTRELATIONSHIP_P_H

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

#include <QtQml/qqml.h>

#include <QtContacts/qcontactrelationship.h>

#include "qdeclarativecontact_p.h"

QTCONTACTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE

class QDeclarativeContactRelationship : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString first READ first WRITE setFirst NOTIFY valueChanged)
    Q_PROPERTY(QString second READ second WRITE setSecond NOTIFY valueChanged)
    Q_PROPERTY(QVariant type READ relationshipType WRITE setRelationshipType NOTIFY valueChanged)
    Q_ENUMS(RelationshipRole)
    Q_ENUMS(RelationshipType)
public:
    enum RelationshipRole {
        First = QContactRelationship::First,
        Second = QContactRelationship::Second,
        Either = QContactRelationship::Either
    };

    enum RelationshipType {
        Unknown = 0,
        HasMember,
        Aggregates,
        IsSameAs,
        HasAssistant,
        HasManager,
        HasSpouse
    };

    QDeclarativeContactRelationship(QObject* parent = nullptr);

    QString first() const;
    QString second() const;
    QVariant relationshipType() const;

    void setFirst(const QString& firstContactId);
    void setSecond(const QString& secondContactId);
    void setRelationshipType(const QVariant& relationshipType);

    QContactRelationship relationship() const;
    void setRelationship(const QContactRelationship& relationship);

signals:
    void valueChanged();
private:
    QContactRelationship m_relationship;
};

QT_END_NAMESPACE

QML_DECLARE_TYPE(QDeclarativeContactRelationship)

#endif // QDECLARATIVECONTACTRELATIONSHIP_P_H
