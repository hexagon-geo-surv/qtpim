// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QORGANIZERITEMOBSERVER_H
#define QORGANIZERITEMOBSERVER_H

#include <QtCore/qobject.h>

#include <QtOrganizer/qorganizeritemdetail.h>
#include <QtOrganizer/qorganizeritemid.h>

QT_BEGIN_NAMESPACE_ORGANIZER

class QOrganizerManager;

class QOrganizerItemObserverPrivate;
class Q_ORGANIZER_EXPORT QOrganizerItemObserver : public QObject
{
    Q_OBJECT

public:
    QOrganizerItemObserver(QOrganizerManager *manager, const QOrganizerItemId &itemId, QObject *parent = Q_NULLPTR);
    ~QOrganizerItemObserver();
    QOrganizerItemId itemId() const;

Q_SIGNALS:
    void itemChanged(const QList<QtOrganizer::QOrganizerItemDetail::DetailType> &typesChanged);
    void itemRemoved();

private:
    Q_DISABLE_COPY(QOrganizerItemObserver)
    QOrganizerItemObserverPrivate *d;
};

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERITEMOBSERVER_H
