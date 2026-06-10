// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QORGANIZERNOTE_H
#define QORGANIZERNOTE_H

#include <QtOrganizer/qorganizeritem.h>

QT_BEGIN_NAMESPACE_ORGANIZER

/* Leaf class */

class Q_ORGANIZER_EXPORT QOrganizerNote : public QOrganizerItem
{
public:
    Q_DECLARE_CUSTOM_ORGANIZER_ITEM(QOrganizerNote, QOrganizerItemType::TypeNote)
};

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERNOTE_H
