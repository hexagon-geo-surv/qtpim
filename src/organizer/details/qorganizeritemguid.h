// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QORGANIZERITEMGUID_H
#define QORGANIZERITEMGUID_H

#include <QtOrganizer/qorganizeritemdetail.h>

QT_BEGIN_NAMESPACE_ORGANIZER

/* Leaf class */

class Q_ORGANIZER_EXPORT QOrganizerItemGuid : public QOrganizerItemDetail
{
public:
#ifndef Q_QDOC
    Q_DECLARE_CUSTOM_ORGANIZER_DETAIL(QOrganizerItemGuid, QOrganizerItemDetail::TypeGuid)
#endif

    enum GuidField {
        FieldGuid = TypeGuid + 1
    };

    void setGuid(const QString &guid);
    QString guid() const;
};

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERITEMGUID_H
