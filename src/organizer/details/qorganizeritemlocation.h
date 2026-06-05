// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QORGANIZERITEMLOCATION_H
#define QORGANIZERITEMLOCATION_H

#include <QtOrganizer/qorganizeritemdetail.h>

QT_BEGIN_NAMESPACE_ORGANIZER

/* Leaf class */

class Q_ORGANIZER_EXPORT QOrganizerItemLocation : public QOrganizerItemDetail
{
public:
#ifndef Q_QDOC
    Q_DECLARE_CUSTOM_ORGANIZER_DETAIL(QOrganizerItemLocation, QOrganizerItemDetail::TypeLocation)
#endif

    enum LocationField {
        FieldLatitude = TypeLocation + 1,
        FieldLongitude,
        FieldLabel
    };

    void setLatitude(double latitude);
    double latitude() const;

    void setLongitude(double longitude);
    double longitude() const;

    void setLabel(const QString &label);
    QString label() const;
};

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERITEMLOCATION_H
