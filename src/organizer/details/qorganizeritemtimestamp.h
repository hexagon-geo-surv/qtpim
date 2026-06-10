// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QORGANIZERITEMTIMESTAMP_H
#define QORGANIZERITEMTIMESTAMP_H

#include <QtOrganizer/qorganizeritemdetail.h>

QT_FORWARD_DECLARE_CLASS(QDateTime)

QT_BEGIN_NAMESPACE_ORGANIZER

/* Leaf class */

class Q_ORGANIZER_EXPORT QOrganizerItemTimestamp : public QOrganizerItemDetail
{
public:
#ifndef Q_QDOC
    Q_DECLARE_CUSTOM_ORGANIZER_DETAIL(QOrganizerItemTimestamp, QOrganizerItemDetail::TypeTimestamp)
#endif

    enum TimestampField {
        FieldCreated = TypeTimestamp + 1,
        FieldLastModified
    };

    void setCreated(const QDateTime &timestamp);
    QDateTime created() const;

    void setLastModified(const QDateTime &timestamp);
    QDateTime lastModified() const;
};

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERITEMTIMESTAMP_H
