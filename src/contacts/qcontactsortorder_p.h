// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QCONTACTSORTORDER_P_H
#define QCONTACTSORTORDER_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <QtCore/qshareddata.h>

#include <QtContacts/qcontactdetail.h>
#include <QtContacts/qcontactsortorder.h>

QT_BEGIN_NAMESPACE_CONTACTS

class QContactSortOrderPrivate : public QSharedData
{
public:
    QContactSortOrderPrivate()
            : QSharedData()
            , m_blankPolicy(QContactSortOrder::BlanksLast)
            , m_direction(Qt::AscendingOrder)
            , m_sensitivity(Qt::CaseSensitive)
            , m_type(QContactDetail::TypeUndefined)
            , m_field(-1)
    {
    }

    ~QContactSortOrderPrivate()
    {
    }

    QContactSortOrder::BlankPolicy m_blankPolicy;
    Qt::SortOrder m_direction;
    Qt::CaseSensitivity m_sensitivity;
    QContactDetail::DetailType m_type;
    int m_field;
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTSORTORDER_P_H
