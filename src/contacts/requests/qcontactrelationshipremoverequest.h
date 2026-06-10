// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QCONTACTRELATIONSHIPREMOVEREQUEST_H
#define QCONTACTRELATIONSHIPREMOVEREQUEST_H

#include <QtCore/qlist.h>
#include <QtCore/qmap.h>

#include <QtContacts/qcontactabstractrequest.h>
#include <QtContacts/qcontactrelationship.h>

QT_BEGIN_NAMESPACE_CONTACTS

class QContactRelationshipRemoveRequestPrivate;
class Q_CONTACTS_EXPORT QContactRelationshipRemoveRequest : public QContactAbstractRequest
{
    Q_OBJECT

public:
    QContactRelationshipRemoveRequest(QObject* parent = nullptr);
    ~QContactRelationshipRemoveRequest();

    /* Selection */
    void setRelationship(const QContactRelationship& relationship);
    void setRelationships(const QList<QContactRelationship>& relationships);
    QList<QContactRelationship> relationships() const;

    /* Results */
    QMap<int, QContactManager::Error> errorMap() const;

private:
    Q_DISABLE_COPY(QContactRelationshipRemoveRequest)
    friend class QContactManagerEngine;
    Q_DECLARE_PRIVATE_D(d_ptr, QContactRelationshipRemoveRequest)
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTRELATIONSHIPREMOVEREQUEST_H
