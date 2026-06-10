// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QORGANIZERITEMCOMMENT_H
#define QORGANIZERITEMCOMMENT_H

#include <QtOrganizer/qorganizeritemdetail.h>

QT_BEGIN_NAMESPACE_ORGANIZER

/* Leaf class */

class Q_ORGANIZER_EXPORT QOrganizerItemComment : public QOrganizerItemDetail
{
public:
#ifndef Q_QDOC
    Q_DECLARE_CUSTOM_ORGANIZER_DETAIL(QOrganizerItemComment, QOrganizerItemDetail::TypeComment)
#endif

    enum CommentField {
        FieldComment = TypeComment + 1
    };

    void setComment(const QString &comment);
    QString comment() const;
};

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERITEMCOMMENT_H
