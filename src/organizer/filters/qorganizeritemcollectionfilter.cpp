// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qorganizeritemcollectionfilter.h"
#include "qorganizeritemcollectionfilter_p.h"

QT_BEGIN_NAMESPACE_ORGANIZER

/*!
    \class QOrganizerItemCollectionFilter
    \brief The QOrganizerItemCollectionFilter class provides a filter based around the collection one
           organizer item belongs to.
    \inmodule QtOrganizer
    \ingroup organizeritems-filters

    It may be used to select organizer items belonging to certain collections.
 */

Q_IMPLEMENT_ORGANIZERITEMFILTER_PRIVATE(QOrganizerItemCollectionFilter)

/*!
    \fn QOrganizerItemCollectionFilter::QOrganizerItemCollectionFilter(const QOrganizerItemFilter &other)

    Constructs a copy of \a other if possible, otherwise constructs a new organizeritem collection filter.
 */

/*!
    Constructs a new organizeritem collection filter.
 */
QOrganizerItemCollectionFilter::QOrganizerItemCollectionFilter()
    : QOrganizerItemFilter(new QOrganizerItemCollectionFilterPrivate)
{
}

/*!
    Sets the \a id of the collection, which the organizer items should belong to.
 */
void QOrganizerItemCollectionFilter::setCollectionId(const QOrganizerCollectionId &id)
{
    Q_D(QOrganizerItemCollectionFilter);
    d->m_ids.clear();
    d->m_ids.insert(id);
}

/*!
    Sets the list of collection \a ids, which the organizer items should belong to.
 */
void QOrganizerItemCollectionFilter::setCollectionIds(const QSet<QOrganizerCollectionId> &ids)
{
    Q_D(QOrganizerItemCollectionFilter);
    d->m_ids = ids;
}

/*!
    Returns the list of collection IDs of organizeritems should belong to.
 */
QSet<QOrganizerCollectionId> QOrganizerItemCollectionFilter::collectionIds() const
{
    Q_D(const QOrganizerItemCollectionFilter);
    return d->m_ids;
}

QT_END_NAMESPACE_ORGANIZER
