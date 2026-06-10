// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QORGANIZERITEMEMAILREMINDER_H
#define QORGANIZERITEMEMAILREMINDER_H

#include <QtOrganizer/qorganizeritemreminder.h>

QT_BEGIN_NAMESPACE_ORGANIZER

/* Leaf class */

class Q_ORGANIZER_EXPORT QOrganizerItemEmailReminder : public QOrganizerItemReminder
{
public:
#ifndef Q_QDOC
    Q_DECLARE_CUSTOM_ORGANIZER_REMINDER_DETAIL(QOrganizerItemEmailReminder, QOrganizerItemDetail::TypeEmailReminder)
#endif

    enum EmailReminderField {
        FieldSubject = TypeEmailReminder + 1,
        FieldBody,
        FieldAttachments,
        FieldRecipients
    };

    void setContents(const QString &subject, const QString &body, const QVariantList &attachments);
    QString subject() const;
    QString body() const;
    QVariantList attachments() const;

    void setRecipients(const QStringList &recipients);
    QStringList recipients() const;
};

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERITEMEMAILREMINDER_H
