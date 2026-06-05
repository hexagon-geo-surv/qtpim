// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QORGANIZERITEMVISUALREMINDER_H
#define QORGANIZERITEMVISUALREMINDER_H

#include <QtOrganizer/qorganizeritemreminder.h>

QT_FORWARD_DECLARE_CLASS(QUrl)

QT_BEGIN_NAMESPACE_ORGANIZER

/* Leaf class */

class Q_ORGANIZER_EXPORT QOrganizerItemVisualReminder : public QOrganizerItemReminder
{
public:
#ifndef Q_QDOC
    Q_DECLARE_CUSTOM_ORGANIZER_REMINDER_DETAIL(QOrganizerItemVisualReminder, QOrganizerItemDetail::TypeVisualReminder)
#endif

    enum VisualReminderField {
        FieldMessage = TypeVisualReminder + 1,
        FieldDataUrl
    };

    void setMessage(const QString &message);
    QString message() const;

    void setDataUrl(const QUrl &dataUrl);
    QUrl dataUrl() const;
};

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERITEMVISUALREMINDER_H
