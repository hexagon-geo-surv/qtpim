// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QORGANIZERITEMTYPE_H
#define QORGANIZERITEMTYPE_H

#include <QtOrganizer/qorganizeritemdetail.h>

QT_BEGIN_NAMESPACE_ORGANIZER

/* Leaf class */

class Q_ORGANIZER_EXPORT QOrganizerItemType : public QOrganizerItemDetail
{
public:
#ifndef Q_QDOC
    Q_DECLARE_CUSTOM_ORGANIZER_DETAIL(QOrganizerItemType, QOrganizerItemDetail::TypeItemType)
#endif

    enum ItemType {
        TypeUndefined = TypeItemType + 1,
        TypeEvent,
        TypeEventOccurrence,
        TypeTodo,
        TypeTodoOccurrence,
        TypeJournal,
        TypeNote
    };

    enum ItemTypeField {
        FieldType = 501
    };

    void setType(ItemType type);
    ItemType type() const;
};

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERITEMTYPE_H
