// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qcontactobserver.h"

#include <QtCore/qpointer.h>

#include "qcontactmanager.h"
#include "qcontactmanager_p.h"

QT_BEGIN_NAMESPACE_CONTACTS

class QContactObserverPrivate
{
    public:
        QContactId m_contactId;
        QPointer<QContactManager> m_manager;
};

/*!
  \class QContactObserver
  \brief The QContactObserver class is a simple class that emits a signal when a single particular
  contact is updated or deleted.
  \inmodule QtContacts

  \ingroup contacts-main
 */

/*!
  Constructs a QContactObserver to observe the contact in \a manager with the
  given \a contactId and \a parent object.
 */
QContactObserver::QContactObserver(QContactManager* manager,
                                   QContactId contactId,
                                   QObject* parent)
    : QObject(parent),
      d(new QContactObserverPrivate)
{
    d->m_contactId = contactId;
    d->m_manager = manager;
    QContactManagerData::registerObserver(manager, this);
}

/*!
  Destroys this observer.
 */
QContactObserver::~QContactObserver()
{
    if (!d->m_manager.isNull()) {
        QContactManagerData::unregisterObserver(d->m_manager.data(), this);
    }
    delete d;
}

/*!
  Returns the contact id of the contact that this object observes.
 */
QContactId QContactObserver::contactId() const {
    return d->m_contactId;
}

/*!
  \fn QContactObserver::contactChanged(const QList<QContactDetail::DetailType> &typesChanged)

  This signal is emitted when the observed contact is changed in the manager.

  The set of contact detail types modified in the reported change is a subset of those listed in \a typesChanged,
  unless \a typesChanged is empty, in which case no limitation on the reported changes may be assumed.
 */

/*!
  \fn QContactObserver::contactRemoved()

  This signal is emitted when the observed contact is removed from the manager.
 */

QT_END_NAMESPACE_CONTACTS

#include "moc_qcontactobserver.cpp"
