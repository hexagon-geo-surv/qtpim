// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QCONTACTRELATIONSHIPFILTER_H
#define QCONTACTRELATIONSHIPFILTER_H

#include <QtContacts/qcontactid.h>
#include <QtContacts/qcontactfilter.h>
#include <QtContacts/qcontactrelationship.h>

QT_BEGIN_NAMESPACE_CONTACTS

class QContactRelationshipFilterPrivate;
class Q_CONTACTS_EXPORT QContactRelationshipFilter : public QContactFilter
{
public:
    QContactRelationshipFilter();
    QContactRelationshipFilter(const QContactFilter& other);

    void setRelationshipType(const QString& relationshipType);
    void setRelatedContactId(const QContactId& relatedContactId);
    void setRelatedContactRole(QContactRelationship::Role relatedContactRole);

    QString relationshipType() const;
    QContactId relatedContactId() const;
    QContactRelationship::Role relatedContactRole() const;

private:
    Q_DECLARE_CONTACTFILTER_PRIVATE(QContactRelationshipFilter)
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTRELATIONSHIPFILTER_H
