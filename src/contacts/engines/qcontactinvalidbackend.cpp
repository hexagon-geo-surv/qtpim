// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qcontactinvalidbackend_p.h"

/*!
  \class QContactInvalidEngine

  \inmodule QtContacts

  \brief The QContactInvalidEngine class provides an implementation of
  QContactManagerEngine whose functions always return an error.

  The invalid engine may be used as a reference or test engine, but does nothing.
 */

QT_BEGIN_NAMESPACE_CONTACTS

/*! Constructs a new invalid contacts backend. */
QContactInvalidEngine::QContactInvalidEngine()
{
}

/*! \reimp
*/
QString QContactInvalidEngine::managerName() const
{
    return QString(QStringLiteral("invalid"));
}

QT_END_NAMESPACE_CONTACTS
