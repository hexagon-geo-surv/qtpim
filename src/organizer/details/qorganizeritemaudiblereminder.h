// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QORGANIZERITEMAUDIBLEREMINDER_H
#define QORGANIZERITEMAUDIBLEREMINDER_H

#include <QtOrganizer/qorganizeritemreminder.h>

QT_FORWARD_DECLARE_CLASS(QUrl)

QT_BEGIN_NAMESPACE_ORGANIZER

/* Leaf class */

class Q_ORGANIZER_EXPORT QOrganizerItemAudibleReminder : public QOrganizerItemReminder
{
public:
#ifndef Q_QDOC
    Q_DECLARE_CUSTOM_ORGANIZER_REMINDER_DETAIL(QOrganizerItemAudibleReminder, QOrganizerItemDetail::TypeAudibleReminder)
#endif

    enum AudibleReminderField {
        FieldDataUrl = TypeAudibleReminder + 1
    };

    void setDataUrl(const QUrl &dataUrl);
    QUrl dataUrl() const;
};

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERITEMAUDIBLEREMINDER_H
