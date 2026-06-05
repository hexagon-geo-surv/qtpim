// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QVERSITGLOBAL_H
#define QVERSITGLOBAL_H

#include <QtCore/qglobal.h>

#if defined(QT_NAMESPACE)
#  define QTVERSIT_PREPEND_NAMESPACE(name) ::QT_NAMESPACE::QtVersit::name
#  define QT_BEGIN_NAMESPACE_VERSIT namespace QT_NAMESPACE { namespace QtVersit {
#  define QT_END_NAMESPACE_VERSIT } }
#  define QTVERSIT_USE_NAMESPACE using namespace QT_NAMESPACE; using namespace QtVersit;
#else
#  define QTVERSIT_PREPEND_NAMESPACE(name) ::QtVersit::name
#  define QT_BEGIN_NAMESPACE_VERSIT namespace QtVersit {
#  define QT_END_NAMESPACE_VERSIT }
#  define QTVERSIT_USE_NAMESPACE using namespace QtVersit;
#endif

#ifndef QT_STATIC
#  if defined(QT_BUILD_VERSIT_LIB)
#    define Q_VERSIT_EXPORT Q_DECL_EXPORT
#  else
#    define Q_VERSIT_EXPORT Q_DECL_IMPORT
#  endif
#else
#  define Q_VERSIT_EXPORT
#endif

QT_BEGIN_NAMESPACE_VERSIT
QT_END_NAMESPACE_VERSIT

#endif // QVERSITGLOBAL_H
