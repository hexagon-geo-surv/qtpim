// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QORGANIZERITEMTAG_H
#define QORGANIZERITEMTAG_H

#include <QtOrganizer/qorganizeritemdetail.h>

QT_BEGIN_NAMESPACE_ORGANIZER

/* Leaf class */

class Q_ORGANIZER_EXPORT QOrganizerItemTag : public QOrganizerItemDetail
{
public:
#ifndef Q_QDOC
    Q_DECLARE_CUSTOM_ORGANIZER_DETAIL(QOrganizerItemTag, QOrganizerItemDetail::TypeTag)
#endif

    enum TagField {
        FieldTag = TypeTag + 1
    };

    void setTag(const QString &tag);
    QString tag() const;
};

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERITEMTAG_H
