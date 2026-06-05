// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qcontactactionfilter.h"
#include "qcontactactionfilter_p.h"

QT_BEGIN_NAMESPACE_CONTACTS

/*!
  \class QContactActionFilter
  \brief The QContactActionFilter class provides a filter based around an
  action availability criterion.


  \inmodule QtContacts

  \ingroup contacts-filters

  It may be used to select contacts for which a particular action is
  available, or contacts which contain a detail of a particular value for
  which the action is available.
 */

Q_IMPLEMENT_CONTACTFILTER_PRIVATE(QContactActionFilter);

/*!
 * \fn QContactActionFilter::QContactActionFilter(const QContactFilter& other)
 * Constructs a copy of \a other if possible, otherwise constructs a new action filter
 */

/*!
 * Constructs a new action filter
 */
QContactActionFilter::QContactActionFilter()
    : QContactFilter(new QContactActionFilterPrivate)
{
}

/*!
 * Sets the name of the action whose availability is required to \a action
 * \sa actionName()
 */
void QContactActionFilter::setActionName(const QString& action)
{
    Q_D(QContactActionFilter);
    d->m_action = action;
}

/*!
 * Returns the action name criterion of the filter
 * \sa setActionName()
 */
QString QContactActionFilter::actionName() const
{
    Q_D(const QContactActionFilter);
    return d->m_action;
}

QT_END_NAMESPACE_CONTACTS
