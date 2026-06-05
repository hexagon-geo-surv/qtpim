// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QORGANIZERITEMDESCRIPTION_H
#define QORGANIZERITEMDESCRIPTION_H

#include <QtOrganizer/qorganizeritemdetail.h>

QT_BEGIN_NAMESPACE_ORGANIZER

/* Leaf class */

class Q_ORGANIZER_EXPORT QOrganizerItemDescription : public QOrganizerItemDetail
{
public:
#ifndef Q_QDOC
    Q_DECLARE_CUSTOM_ORGANIZER_DETAIL(QOrganizerItemDescription, QOrganizerItemDetail::TypeDescription)
#endif

    enum DescriptionField {
        FieldDescription = TypeDescription + 1
    };

    void setDescription(const QString &description);
    QString description() const;
};

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERITEMDESCRIPTION_H
