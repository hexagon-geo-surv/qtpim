// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QDECLARATIVEORGANIZERITEMSORTORDER_H
#define QDECLARATIVEORGANIZERITEMSORTORDER_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.
// This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <QtQml/qqml.h>

#include <QtOrganizer/qorganizeritemsortorder.h>

#include "qdeclarativeorganizeritemdetail_p.h"

QTORGANIZER_USE_NAMESPACE

QT_BEGIN_NAMESPACE

class QDeclarativeOrganizerItemSortOrder : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QDeclarativeOrganizerItemDetail::DetailType detail READ detail WRITE setDetail NOTIFY sortOrderChanged)
    Q_PROPERTY(int field READ field WRITE setField NOTIFY sortOrderChanged)
    Q_PROPERTY(BlankPolicy blankPolicy READ blankPolicy WRITE setBlankPolicy NOTIFY sortOrderChanged)
    Q_PROPERTY(Qt::SortOrder direction READ direction WRITE setDirection NOTIFY sortOrderChanged)
    Q_PROPERTY(Qt::CaseSensitivity sensitivity READ caseSensitivity WRITE setCaseSensitivity NOTIFY sortOrderChanged)
    Q_ENUMS(BlankPolicy)

public:
    enum BlankPolicy {
        BlanksFirst = QOrganizerItemSortOrder::BlanksFirst,
        BlanksLast = QOrganizerItemSortOrder::BlanksLast
    };

    QDeclarativeOrganizerItemSortOrder(QObject *parent = Q_NULLPTR);

    void setDetail(QDeclarativeOrganizerItemDetail::DetailType detail);
    QDeclarativeOrganizerItemDetail::DetailType detail() const;

    void setField(int field);
    int field() const;

    void setBlankPolicy(BlankPolicy policy);
    BlankPolicy blankPolicy() const;

    void setDirection(Qt::SortOrder newDirection);
    Qt::SortOrder direction() const;

    void setCaseSensitivity(Qt::CaseSensitivity newSensitivity);
    Qt::CaseSensitivity caseSensitivity() const;

    // used by organizer model
    QOrganizerItemSortOrder sortOrder();

Q_SIGNALS:
    void sortOrderChanged();

private:
    QOrganizerItemSortOrder d;
};

QT_END_NAMESPACE

QML_DECLARE_TYPE(QDeclarativeOrganizerItemSortOrder)

#endif // QDECLARATIVEORGANIZERITEMSORTORDER_H
