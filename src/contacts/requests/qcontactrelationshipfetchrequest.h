// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QCONTACTRELATIONSHIPFETCHREQUEST_H
#define QCONTACTRELATIONSHIPFETCHREQUEST_H

#include <QtCore/qlist.h>

#include <QtContacts/qcontactabstractrequest.h>
#include <QtContacts/qcontactrelationship.h>

QT_BEGIN_NAMESPACE_CONTACTS

class QContact;

class QContactRelationshipFetchRequestPrivate;
class Q_CONTACTS_EXPORT QContactRelationshipFetchRequest : public QContactAbstractRequest
{
    Q_OBJECT

public:
    QContactRelationshipFetchRequest(QObject* parent = nullptr);
    ~QContactRelationshipFetchRequest();

    /* Selection */
    void setFirst(const QContactId& firstContactId);
    QContactId first() const;

    void setRelationshipType(const QString& relationshipType);
    QString relationshipType() const;

    void setSecond(const QContactId& secondContactId);
    QContactId second() const;

    /* Results */
    QList<QContactRelationship> relationships() const;

private:
    Q_DISABLE_COPY(QContactRelationshipFetchRequest)
    friend class QContactManagerEngine;
    Q_DECLARE_PRIVATE_D(d_ptr, QContactRelationshipFetchRequest)
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTRELATIONSHIPFETCHREQUEST_H
