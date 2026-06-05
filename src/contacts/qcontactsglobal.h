// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QTCONTACTSGLOBAL_H
#define QTCONTACTSGLOBAL_H

#include <QtCore/qglobal.h>

#if defined(QT_NAMESPACE)
#  define QTCONTACTS_PREPEND_NAMESPACE(name) ::QT_NAMESPACE::QtContacts::name
#  define QT_BEGIN_NAMESPACE_CONTACTS namespace QT_NAMESPACE { namespace QtContacts {
#  define QT_END_NAMESPACE_CONTACTS } }
#  define QTCONTACTS_USE_NAMESPACE using namespace QT_NAMESPACE; using namespace QtContacts;
#else
#  define QTCONTACTS_PREPEND_NAMESPACE(name) ::QtContacts::name
#  define QT_BEGIN_NAMESPACE_CONTACTS namespace QtContacts {
#  define QT_END_NAMESPACE_CONTACTS }
#  define QTCONTACTS_USE_NAMESPACE using namespace QtContacts;
#endif

#ifndef QT_STATIC
#  if defined(QT_BUILD_CONTACTS_LIB)
#    define Q_CONTACTS_EXPORT Q_DECL_EXPORT
#  else
#    define Q_CONTACTS_EXPORT Q_DECL_IMPORT
#  endif
#else
#  define Q_CONTACTS_EXPORT
#endif

#define QTCONTACTS_VERSION_NAME "org.qt-project.Qt.contacts.api.version"
#define QTCONTACTS_IMPLEMENTATION_VERSION_NAME "org.qt-project.Qt.contacts.implementation.version"

QT_BEGIN_NAMESPACE_CONTACTS
QT_END_NAMESPACE_CONTACTS

#endif // QTCONTACTSGLOBAL_H
