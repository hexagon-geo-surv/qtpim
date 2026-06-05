// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QORGANIZERTODOPROGRESS_H
#define QORGANIZERTODOPROGRESS_H

#include <QtOrganizer/qorganizeritemdetail.h>

QT_FORWARD_DECLARE_CLASS(QDateTime)

QT_BEGIN_NAMESPACE_ORGANIZER

/* Leaf class */

class Q_ORGANIZER_EXPORT QOrganizerTodoProgress : public QOrganizerItemDetail
{
public:
#ifndef Q_QDOC
    Q_DECLARE_CUSTOM_ORGANIZER_DETAIL(QOrganizerTodoProgress, QOrganizerItemDetail::TypeTodoProgress)
#endif

    enum TodoProgressField {
        FieldFinishedDateTime = TypeTodoProgress + 1,
        FieldPercentageComplete,
        FieldStatus
    };

    enum Status {
        // what about: waited/blocked, and deferred?
        StatusNotStarted,
        StatusInProgress,
        StatusComplete
    };

    void setFinishedDateTime(const QDateTime &finishedDateTime);
    QDateTime finishedDateTime() const;

    void setPercentageComplete(int percentage);
    int percentageComplete() const;

    void setStatus(Status status);
    Status status() const;
};

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERTODOPROGRESS_H
