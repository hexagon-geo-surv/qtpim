// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QORGANIZERITEMPARENT_H
#define QORGANIZERITEMPARENT_H

#include <QtOrganizer/qorganizeritemdetail.h>
#include <QtOrganizer/qorganizeritemid.h>

QT_FORWARD_DECLARE_CLASS(QDate)

QT_BEGIN_NAMESPACE_ORGANIZER

class QOrganizerItemId;

/* Leaf class */

class Q_ORGANIZER_EXPORT QOrganizerItemParent : public QOrganizerItemDetail
{
public:
#ifndef Q_QDOC
    Q_DECLARE_CUSTOM_ORGANIZER_DETAIL(QOrganizerItemParent, QOrganizerItemDetail::TypeParent)
#endif

    enum ParentField {
        FieldParentId = TypeParent + 1,
        FieldOriginalDate
    };

    void setParentId(const QOrganizerItemId &parentId);
    QOrganizerItemId parentId() const;

    void setOriginalDate(const QDate &date);
    QDate originalDate() const;
};

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERITEMPARENT_H
