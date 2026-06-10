// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QTORGANIZERGLOBAL_H
#define QTORGANIZERGLOBAL_H

#include <QtCore/qglobal.h>

#if defined(QT_NAMESPACE)
#  define QTORGANIZER_PREPEND_NAMESPACE(name) ::QT_NAMESPACE::QtOrganizer::name
#  define QT_BEGIN_NAMESPACE_ORGANIZER namespace QT_NAMESPACE { namespace QtOrganizer {
#  define QT_END_NAMESPACE_ORGANIZER } }
#  define QTORGANIZER_USE_NAMESPACE using namespace QT_NAMESPACE; using namespace QtOrganizer;
#else
#  define QTORGANIZER_PREPEND_NAMESPACE(name) ::QtOrganizer::name
#  define QT_BEGIN_NAMESPACE_ORGANIZER namespace QtOrganizer {
#  define QT_END_NAMESPACE_ORGANIZER }
#  define QTORGANIZER_USE_NAMESPACE using namespace QtOrganizer;
#endif

#ifndef QT_STATIC
#  if defined(QT_BUILD_ORGANIZER_LIB)
#    define Q_ORGANIZER_EXPORT Q_DECL_EXPORT
#  else
#    define Q_ORGANIZER_EXPORT Q_DECL_IMPORT
#  endif
#else
#  define Q_ORGANIZER_EXPORT
#endif

#define QTORGANIZER_BACKEND_VERSION QString(QStringLiteral("org.qt-project.Qt.organizer.backendVersion"))

QT_BEGIN_NAMESPACE_ORGANIZER
QT_END_NAMESPACE_ORGANIZER

#endif // QTORGANIZERGLOBAL_H
