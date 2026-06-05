// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qcontactchangelogfilter.h"
#include "qcontactchangelogfilter_p.h"

QT_BEGIN_NAMESPACE_CONTACTS

/*!
  \class QContactChangeLogFilter
  \brief The QContactChangeLogFilter class provides a filter based around a
  contact timestamp criterion.

  \inmodule QtContacts

   \ingroup contacts-filters

  It may be used to select contacts which have been updated or created
  within a certain period of time.
 */

/*!
 * \enum QContactChangeLogFilter::EventType
 * Enumerates the type of changes which a changelog filter can match against
 * \value EventAdded
 * \value EventChanged
 * \value EventRemoved
 */

Q_IMPLEMENT_CONTACTFILTER_PRIVATE(QContactChangeLogFilter);

/*!
 * \fn QContactChangeLogFilter::QContactChangeLogFilter(const QContactFilter& other)
 * Constructs a copy of \a other if possible, otherwise constructs a new changelog filter
 */

/*!
 * Constructs a new changelog filter which matches changes of the specified \a type
 */
QContactChangeLogFilter::QContactChangeLogFilter(QContactChangeLogFilter::EventType type)
    : QContactFilter(new QContactChangeLogFilterPrivate(type))
{
}

/*!
 * Sets the type of change that this filter will match against to \a type
 * \sa eventType()
 */
void QContactChangeLogFilter::setEventType(QContactChangeLogFilter::EventType type)
{
    Q_D(QContactChangeLogFilter);
    d->m_eventType = type;
}

/*!
 * Sets the date and time lower-bound criterion of the filter to \a since
 * \sa since()
 */
void QContactChangeLogFilter::setSince(const QDateTime& since)
{
    Q_D(QContactChangeLogFilter);
    d->m_since = since;
}

/*!
 * Returns the date and time lower-bound criterion of the filter
 * \sa setSince()
 */
QDateTime QContactChangeLogFilter::since() const
{
    Q_D(const QContactChangeLogFilter);
    return d->m_since;
}

/*!
 * Returns the type of change that this filter will match against
 * \sa setEventType()
 */
QContactChangeLogFilter::EventType QContactChangeLogFilter::eventType() const
{
    Q_D(const QContactChangeLogFilter);
    return d->m_eventType;
}

QT_END_NAMESPACE_CONTACTS
