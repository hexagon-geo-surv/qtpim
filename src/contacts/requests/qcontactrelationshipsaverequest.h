// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QCONTACTRELATIONSHIPSAVEREQUEST_H
#define QCONTACTRELATIONSHIPSAVEREQUEST_H

#include <QtCore/qlist.h>
#include <QtCore/qmap.h>

#include <QtContacts/qcontactabstractrequest.h>
#include <QtContacts/qcontactrelationship.h>

QT_BEGIN_NAMESPACE_CONTACTS

class QContactRelationshipSaveRequestPrivate;
class Q_CONTACTS_EXPORT QContactRelationshipSaveRequest : public QContactAbstractRequest
{
    Q_OBJECT

public:
    QContactRelationshipSaveRequest(QObject* parent = Q_NULLPTR);
    ~QContactRelationshipSaveRequest();

    /* Selection */
    void setRelationship(const QContactRelationship& contactRelationship);
    void setRelationships(const QList<QContactRelationship>& contactRelationships);

    /* Results */
    QList<QContactRelationship> relationships() const;
    QMap<int, QContactManager::Error> errorMap() const;

private:
    Q_DISABLE_COPY(QContactRelationshipSaveRequest)
    friend class QContactManagerEngine;
    Q_DECLARE_PRIVATE_D(d_ptr, QContactRelationshipSaveRequest)
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTRELATIONSHIPSAVEREQUEST_H
