// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qdeclarativecontactrelationship_p.h"

#include <QtQml/qqmlinfo.h>

QTCONTACTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE

/*!
   \qmltype Relationship
    \instantiates QDeclarativeContactRelationship
   \brief The Relationship element describes a one-to-one relationship
  between a locally-stored contact and another (possibly remote) contact.

   \ingroup qml-contacts-main
   \inqmlmodule QtContacts
   This element is part of the \b{QtContacts} module.

   \sa QContactRelationship
   \sa RelationshipModel
 */

QDeclarativeContactRelationship::QDeclarativeContactRelationship(QObject* parent)
    :QObject(parent)
{

}


/*!
  \qmlproperty int Relationship::first

  This property holds the locally-stored contact which has a relationship of the given type with the second contact.
  */
QString QDeclarativeContactRelationship::first() const
{
    const QContactId contactId(m_relationship.first());
    if (!contactId.isNull())
        return contactId.toString();
    return QString();
}

/*!
  \qmlproperty int Relationship::second

  This property holds the contact with which the first contact has a relationship of the given type.
  */
QString QDeclarativeContactRelationship::second() const
{
    const QContactId contactId(m_relationship.second());
    if (!contactId.isNull())
        return contactId.toString();
    return QString();
}

/*!
  \qmlproperty string Relationship::type

  This property holds the type of relationship which the source contact has with the destination contacts.
  The value for this property can be one of:
  \list
  \li HasMember
  \li Aggregates
  \li IsSameAs
  \li HasAssistant
  \li HasManager
  \li HasSpouse
  \endlist
  or any other customized relationship type string.
  */

QVariant QDeclarativeContactRelationship::relationshipType() const
{
    return m_relationship.relationshipType();
}

void QDeclarativeContactRelationship::setFirst(const QString& firstContactId)
{
    m_relationship.setFirst(QContactId::fromString(firstContactId));
}

void QDeclarativeContactRelationship::setSecond(const QString& secondContactId)
{
    m_relationship.setSecond(QContactId::fromString(secondContactId));
}

void QDeclarativeContactRelationship::setRelationshipType(const QVariant& relationshipType)
{
    if (relationshipType.typeId() == QMetaType::Int) {
        switch (relationshipType.toInt()) {
        case QDeclarativeContactRelationship::HasMember:
            m_relationship.setRelationshipType(QContactRelationship::HasMember());
            break;
        case QDeclarativeContactRelationship::Aggregates:
            m_relationship.setRelationshipType(QContactRelationship::Aggregates());
            break;
        case QDeclarativeContactRelationship::IsSameAs:
            m_relationship.setRelationshipType(QContactRelationship::IsSameAs());
            break;
        case QDeclarativeContactRelationship::HasAssistant:
            m_relationship.setRelationshipType(QContactRelationship::HasAssistant());
            break;
        case QDeclarativeContactRelationship::HasManager:
            m_relationship.setRelationshipType(QContactRelationship::HasManager());
            break;
        case QDeclarativeContactRelationship::HasSpouse:
            m_relationship.setRelationshipType(QContactRelationship::HasSpouse());
            break;
        default:
            //unknown type
            qmlInfo(this) << tr("unknown relationship type:") << relationshipType;
            break;
        }
    } else {
        m_relationship.setRelationshipType(relationshipType.toString());
    }

}


QContactRelationship QDeclarativeContactRelationship::relationship() const
{
    return m_relationship;
}
void QDeclarativeContactRelationship::setRelationship(const QContactRelationship& relationship)
{
    m_relationship = relationship;
    emit valueChanged();
}

#include "moc_qdeclarativecontactrelationship_p.cpp"

QT_END_NAMESPACE
