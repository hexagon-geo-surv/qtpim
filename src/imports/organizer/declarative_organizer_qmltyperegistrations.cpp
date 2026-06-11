// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
#include <QtQml/qqml.h>
#include <QtQml/qqmlmoduleregistration.h>
#if !defined(QT_STATIC)
#define Q_QMLTYPE_EXPORT Q_DECL_EXPORT
#else
#define Q_QMLTYPE_EXPORT
#endif

QT_BEGIN_NAMESPACE
void qtorganizer_qml_register_types(const char *uri);

Q_QMLTYPE_EXPORT void qml_register_types_QtOrganizer()
{
    qtorganizer_qml_register_types("QtOrganizer");
    qmlRegisterModule("QtOrganizer", 5, 0);
}

static const QQmlModuleRegistration QtOrganizerRegistration("QtOrganizer", qml_register_types_QtOrganizer);
QT_END_NAMESPACE
