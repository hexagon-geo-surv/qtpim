// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QORGANIZERTODOOCCURRENCE_H
#define QORGANIZERTODOOCCURRENCE_H

#include <QtOrganizer/qorganizeritem.h>
#include <QtOrganizer/qorganizeritempriority.h>
#include <QtOrganizer/qorganizertodoprogress.h>

QT_FORWARD_DECLARE_CLASS(QDate)
QT_FORWARD_DECLARE_CLASS(QDateTime)

QT_BEGIN_NAMESPACE_ORGANIZER

class QOrganizerItemId;

/* Leaf class */

class Q_ORGANIZER_EXPORT QOrganizerTodoOccurrence : public QOrganizerItem
{
public:
    Q_DECLARE_CUSTOM_ORGANIZER_ITEM(QOrganizerTodoOccurrence, QOrganizerItemType::TypeTodoOccurrence)

    void setStartDateTime(const QDateTime &startDateTime);
    QDateTime startDateTime() const;

    void setDueDateTime(const QDateTime &dueDateTime);
    QDateTime dueDateTime() const;

    void setParentId(const QOrganizerItemId &parentId);
    QOrganizerItemId parentId() const;

    void setOriginalDate(const QDate &date);
    QDate originalDate() const;

    void setPriority(QOrganizerItemPriority::Priority priority);
    QOrganizerItemPriority::Priority priority() const;

    void setProgressPercentage(int percentage);
    int progressPercentage() const;

    void setStatus(QOrganizerTodoProgress::Status status);
    QOrganizerTodoProgress::Status status() const;

    void setFinishedDateTime(const QDateTime &finishedDateTime);
    QDateTime finishedDateTime() const;
};

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERTODOOCCURRENCE_H
