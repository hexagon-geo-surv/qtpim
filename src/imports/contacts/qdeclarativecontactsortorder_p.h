// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QDECLARATIVECONTACTSORTORDER_P_H
#define QDECLARATIVECONTACTSORTORDER_P_H

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

#include <QtContacts/qcontactsortorder.h>

#include "qdeclarativecontactdetail_p.h"

QTCONTACTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE

class QDeclarativeContactSortOrder : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int detail READ detail WRITE setDetail NOTIFY sortOrderChanged)
    Q_PROPERTY(int field READ field WRITE setField NOTIFY sortOrderChanged)
    Q_PROPERTY(Qt::SortOrder direction READ direction WRITE setDirection NOTIFY sortOrderChanged)
    Q_PROPERTY(BlankPolicy blankPolicy READ blankPolicy WRITE setBlankPolicy NOTIFY sortOrderChanged)
    Q_PROPERTY(Qt::CaseSensitivity caseSensitivity READ caseSensitivity WRITE setCaseSensitivity NOTIFY sortOrderChanged)
    Q_ENUMS(BlankPolicy)
public:

    enum BlankPolicy {
        BlanksFirst = QContactSortOrder::BlanksFirst,
        BlanksLast = QContactSortOrder::BlanksLast
    };


    QDeclarativeContactSortOrder(QObject* parent = Q_NULLPTR);

    void setDetail(const int detailType);

    int detail() const;

    void setField(const int fieldType);

    int field() const;

    BlankPolicy blankPolicy() const;
    void setBlankPolicy(BlankPolicy blankPolicy);
    Qt::SortOrder direction() const;
    void setDirection(Qt::SortOrder direction);
    Qt::CaseSensitivity caseSensitivity() const;
    void setCaseSensitivity(Qt::CaseSensitivity sensitivity);
    QContactSortOrder sortOrder();
    void setSortOrder(const QContactSortOrder& sortOrder);

signals:
    void sortOrderChanged();
private:
    QContactSortOrder m_sortOrder;
};

QT_END_NAMESPACE

QML_DECLARE_TYPE(QDeclarativeContactSortOrder)

#endif // QDECLARATIVECONTACTSORTORDER_P_H
