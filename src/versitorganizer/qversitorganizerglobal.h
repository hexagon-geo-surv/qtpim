// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QVERSITORGANIZERGLOBAL_H
#define QVERSITORGANIZERGLOBAL_H

#include <QtCore/qglobal.h>

#if defined(QT_NAMESPACE)
#  define QTVERSITORGANIZER_PREPEND_NAMESPACE(name) ::QT_NAMESPACE::QtVersitOrganizer::name
#  define QT_BEGIN_NAMESPACE_VERSITORGANIZER namespace QT_NAMESPACE { namespace QtVersitOrganizer {
#  define QT_END_NAMESPACE_VERSITORGANIZER } }
#  define QTVERSITORGANIZER_USE_NAMESPACE using namespace QT_NAMESPACE; using namespace QtVersitOrganizer;
#else
#  define QTVERSITORGANIZER_PREPEND_NAMESPACE(name) ::QtVersitOrganizer::name
#  define QT_BEGIN_NAMESPACE_VERSITORGANIZER namespace QtVersitOrganizer {
#  define QT_END_NAMESPACE_VERSITORGANIZER }
#  define QTVERSITORGANIZER_USE_NAMESPACE using namespace QtVersitOrganizer;
#endif

#ifndef QT_STATIC
#  if defined(QT_BUILD_VERSITORGANIZER_LIB)
#    define Q_VERSIT_ORGANIZER_EXPORT Q_DECL_EXPORT
#  else
#    define Q_VERSIT_ORGANIZER_EXPORT Q_DECL_IMPORT
#  endif
#else
#  define Q_VERSIT_ORGANIZER_EXPORT
#endif

QT_BEGIN_NAMESPACE_VERSITORGANIZER
QT_END_NAMESPACE_VERSITORGANIZER

#endif // QVERSITORGANIZERGLOBAL_H
