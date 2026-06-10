// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QCONTACTOBSERVER_H
#define QCONTACTOBSERVER_H

#include <QtCore/qobject.h>

#include <QtContacts/qcontactid.h>
#include <QtContacts/qcontactdetail.h>

QT_BEGIN_NAMESPACE_CONTACTS

class QContactManager;

class QContactObserverPrivate;
class Q_CONTACTS_EXPORT QContactObserver : public QObject
{
    Q_OBJECT
public:
    QContactObserver(QContactManager* manager, QContactId contactId, QObject* parent = nullptr);
    ~QContactObserver();
    QContactId contactId() const;
Q_SIGNALS:
    void contactChanged(const QList<QtContacts::QContactDetail::DetailType> &typesChanged);
    void contactRemoved();

private:
    Q_DISABLE_COPY(QContactObserver)
    QContactObserverPrivate* d;
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTOBSERVER_H
