// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QORGANIZERITEMDISPLAYLABEL_H
#define QORGANIZERITEMDISPLAYLABEL_H

#include <QtOrganizer/qorganizeritemdetail.h>

QT_BEGIN_NAMESPACE_ORGANIZER

/* Leaf class */

class Q_ORGANIZER_EXPORT QOrganizerItemDisplayLabel : public QOrganizerItemDetail
{
public:
#ifndef Q_QDOC
    Q_DECLARE_CUSTOM_ORGANIZER_DETAIL(QOrganizerItemDisplayLabel, QOrganizerItemDetail::TypeDisplayLabel)
#endif

    enum DisplayLabelField {
        FieldLabel = TypeDisplayLabel + 1
    };

    void setLabel(const QString &label);
    QString label() const;
};

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERITEMDISPLAYLABEL_H
