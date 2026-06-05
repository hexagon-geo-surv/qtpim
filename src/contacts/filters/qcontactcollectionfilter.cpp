// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qcontactcollectionfilter.h"
#include "qcontactcollectionfilter_p.h"

QT_BEGIN_NAMESPACE_CONTACTS

/*!
    \class QContactCollectionFilter
    \brief The QContactCollectionFilter class provides a filter based around the collection one
           contact belongs to.
    \inmodule QtContacts
    \ingroup contacts-filters

    It may be used to select contacts belonging to certain collections.
 */

Q_IMPLEMENT_CONTACTFILTER_PRIVATE(QContactCollectionFilter)

/*!
    \fn QContactCollectionFilter::QContactCollectionFilter(const QContactCollectionFilter &other)

    Constructs a copy of \a other if possible, otherwise constructs a new contact collection filter.
 */

/*!
    Constructs a new contact collection filter.
 */
QContactCollectionFilter::QContactCollectionFilter()
    : QContactFilter(new QContactCollectionFilterPrivate)
{
}

/*!
    Sets the \a id of the collection, which the contacts should belong to.
 */
void QContactCollectionFilter::setCollectionId(const QContactCollectionId &id)
{
    Q_D(QContactCollectionFilter);
    d->m_ids.clear();
    d->m_ids.insert(id);
}

/*!
    Sets the list of collection \a ids, which the contacts should belong to.
 */
void QContactCollectionFilter::setCollectionIds(const QSet<QContactCollectionId> &ids)
{
    Q_D(QContactCollectionFilter);
    d->m_ids = ids;
}

/*!
    Returns the list of collection IDs of contacts should belong to.
 */
QSet<QContactCollectionId> QContactCollectionFilter::collectionIds() const
{
    Q_D(const QContactCollectionFilter);
    return d->m_ids;
}

QT_END_NAMESPACE_CONTACTS
