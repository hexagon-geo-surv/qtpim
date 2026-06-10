// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QORGANIZERITEMCLASSIFICATION_H
#define QORGANIZERITEMCLASSIFICATION_H

#include <QtOrganizer/qorganizeritemdetail.h>

QT_BEGIN_NAMESPACE_ORGANIZER

/* Leaf class */

class Q_ORGANIZER_EXPORT QOrganizerItemClassification : public QOrganizerItemDetail
{
public:
#ifndef Q_QDOC
    Q_DECLARE_CUSTOM_ORGANIZER_DETAIL(QOrganizerItemClassification, QOrganizerItemDetail::TypeClassification)
#endif

    enum ClassificationField {
        FieldClassification = TypeClassification + 1
    };

    enum AccessClassification {
        AccessPublic = 0,
        AccessConfidential,
        AccessPrivate
    };

    void setClassification(AccessClassification classification);
    AccessClassification classification() const;
};

QT_END_NAMESPACE_ORGANIZER

#endif// QORGANIZERITEMCLASSIFICATION_H

