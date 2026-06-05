// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qorganizeritemobserver.h"

#include <QtCore/qpointer.h>

#include "qorganizermanager.h"
#include "qorganizermanager_p.h"

QT_BEGIN_NAMESPACE_ORGANIZER

class QOrganizerItemObserverPrivate
{
public:
    QOrganizerItemId m_id;
    QPointer<QOrganizerManager> m_manager;
    QOrganizerManagerData *m_managerPrivate;
};

/*!
    \class QOrganizerItemObserver
    \brief The QOrganizerItemObserver class is a simple class that emits a signal when a single
           particular item is updated or deleted.
    \inmodule QtOrganizer
    \ingroup organizer-main
 */

/*!
    Constructs a QOrganizerItemObserver to observe the item in \a manager with the given \a itemId
    and a \a parent object.
 */
QOrganizerItemObserver::QOrganizerItemObserver(QOrganizerManager *manager, const QOrganizerItemId &itemId, QObject *parent)
    : QObject(parent), d(new QOrganizerItemObserverPrivate)
{
    d->m_id = itemId;
    d->m_manager = manager;
    d->m_managerPrivate = QOrganizerManagerData::get(manager);
    d->m_managerPrivate->registerObserver(this);
}

/*!
    Destroys this observer.
 */
QOrganizerItemObserver::~QOrganizerItemObserver()
{
    if (d->m_manager.data())
        d->m_managerPrivate->unregisterObserver(this);
    delete d;
}

/*!
    Returns the ID of the item that this object observes.
 */
QOrganizerItemId QOrganizerItemObserver::itemId() const
{
    return d->m_id;
}

/*!
    \fn void QOrganizerItemObserver::itemChanged(const QList<QOrganizerItemDetail::DetailType> &typesChanged)

    This signal is emitted when the observed item is changed in the manager.

    The set of item detail types modified in the reported change is a subset of those listed in \a typesChanged,
    unless \a typesChanged is empty, in which case no limitation on the reported changes may be assumed.
 */

/*!
    \fn void QOrganizerItemObserver::itemRemoved()

    This signal is emitted when the observed item is removed from the manager.
 */

QT_END_NAMESPACE_ORGANIZER

#include "moc_qorganizeritemobserver.cpp"
