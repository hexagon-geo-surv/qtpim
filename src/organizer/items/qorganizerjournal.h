// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QORGANIZERJOURNAL_H
#define QORGANIZERJOURNAL_H

#include <QtOrganizer/qorganizeritem.h>

QT_FORWARD_DECLARE_CLASS(QDateTime)

QT_BEGIN_NAMESPACE_ORGANIZER

/* Leaf class */

class Q_ORGANIZER_EXPORT QOrganizerJournal : public QOrganizerItem
{
public:
    Q_DECLARE_CUSTOM_ORGANIZER_ITEM(QOrganizerJournal, QOrganizerItemType::TypeJournal)

    void setDateTime(const QDateTime &dateTime);
    QDateTime dateTime() const;
};

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERJOURNAL_H
