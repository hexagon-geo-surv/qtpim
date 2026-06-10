// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QORGANIZERITEMVERSION_H
#define QORGANIZERITEMVERSION_H

#include <QtOrganizer/qorganizeritemdetail.h>

QT_BEGIN_NAMESPACE_ORGANIZER

/* Leaf class */

class Q_ORGANIZER_EXPORT QOrganizerItemVersion : public QOrganizerItemDetail
{
public:
#ifndef Q_QDOC
    Q_DECLARE_CUSTOM_ORGANIZER_DETAIL(QOrganizerItemVersion, QOrganizerItemDetail::TypeVersion)
#endif

    enum VersionField {
        FieldVersion = TypeVersion + 1,
        FieldExtendedVersion
    };

    void setVersion(int version);
    int version() const;

    void setExtendedVersion(const QByteArray &extendedVersion);
    QByteArray extendedVersion() const;
};

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERITEMVERSION_H
