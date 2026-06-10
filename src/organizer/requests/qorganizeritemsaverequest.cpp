// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qorganizeritemsaverequest.h"

#include "qorganizeritemrequests_p.h"

QT_BEGIN_NAMESPACE_ORGANIZER

/*!
    \class QOrganizerItemSaveRequest
    \brief The QOrganizerItemSaveRequest class allows a client to asynchronously request that certain
           organizer items be saved to a backend.
    \inmodule QtOrganizer
    \ingroup organizer-requests
 */

/*!
    Constructs a new organizer item save request whose parent is the specified \a parent.
*/
QOrganizerItemSaveRequest::QOrganizerItemSaveRequest(QObject *parent)
    : QOrganizerAbstractRequest(new QOrganizerItemSaveRequestPrivate, parent)
{
}

/*!
    Frees memory in use by this request.
*/
QOrganizerItemSaveRequest::~QOrganizerItemSaveRequest()
{
}

/*!
    Sets the organizer item to be saved to \a item.
    Equivalent to calling:
    \code
    setItems(QList<QOrganizerItem>() << item);
    \endcode
 */
void QOrganizerItemSaveRequest::setItem(const QOrganizerItem &item)
{
    Q_D(QOrganizerItemSaveRequest);
    QMutexLocker ml(&d->m_mutex);
    d->m_organizeritems.clear();
    d->m_organizeritems.append(item);
}

/*!
    Sets the list of organizer items to be saved to \a items.
*/
void QOrganizerItemSaveRequest::setItems(const QList<QOrganizerItem> &items)
{
    Q_D(QOrganizerItemSaveRequest);
    QMutexLocker ml(&d->m_mutex);
    d->m_organizeritems = items;
}

/*!
    Returns the list of organizer items which will be saved if called prior to calling start(),
    otherwise returns the list of organizer items as they were saved in the organizer item store.
*/
QList<QOrganizerItem> QOrganizerItemSaveRequest::items() const
{
    Q_D(const QOrganizerItemSaveRequest);
    QMutexLocker ml(&d->m_mutex);
    return d->m_organizeritems;
}

/*!
    Returns the map of input definition list indices to errors which occurred.
*/
QMap<int, QOrganizerManager::Error> QOrganizerItemSaveRequest::errorMap() const
{
    Q_D(const QOrganizerItemSaveRequest);
    QMutexLocker ml(&d->m_mutex);
    return d->m_errors;
}

/*!
    Set the list of detail types to restrict saving to \a detailMask.  This allows you to perform
    partial save (and remove) operations on existing items.

    If \a detailMask is empty (the default), no restrictions will apply, and the passed
    in items will be saved as is.  Otherwise, only details whose types are in
    the list will be saved.  If a detail type is present in the list, but there are no
    corresponding details in the item passed into this request, any existing details in
    the manager for that item will be removed.

    This is useful if you've used a fetch hint to fetch a partial item from a manager
    so that you can save changes to the details you actually fetched without removing
    the details you didn't.

    Additionally, when performing synchronization operations with other managers that don't
    support the full range of details, you can restrict the update operation to only those
    details so that you don't lose the extra details that are supported in this manager.

    \note Some managers do not support partial updates natively, in which case the QtOrganizer
    framework will emulate the functionality (fetching the whole item, applying the
    new restricted details, and saving the item back).
*/
void QOrganizerItemSaveRequest::setDetailMask(const QList<QOrganizerItemDetail::DetailType> &detailMask)
{
    Q_D(QOrganizerItemSaveRequest);
    QMutexLocker ml(&d->m_mutex);
    d->m_detailMask = detailMask;
}

/*!
    Returns the list of definitions that this request will operate on.

    If the list is empty, the request will operate on all details.
 */
QList<QOrganizerItemDetail::DetailType> QOrganizerItemSaveRequest::detailMask() const
{
    Q_D(const QOrganizerItemSaveRequest);
    QMutexLocker ml(&d->m_mutex);
    return d->m_detailMask;
}


QT_END_NAMESPACE_ORGANIZER

#include "moc_qorganizeritemsaverequest.cpp"
