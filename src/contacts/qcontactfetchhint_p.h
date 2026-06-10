// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QCONTACTFETCHHINT_P_H
#define QCONTACTFETCHHINT_P_H

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
#include <QtCore/qsize.h>
#include <QtCore/qstringlist.h>

#include <QtContacts/qcontactdetail.h>
#include <QtContacts/qcontactfetchhint.h>

QT_BEGIN_NAMESPACE_CONTACTS

class QContactFetchHintPrivate : public QSharedData
{
public:
    QContactFetchHintPrivate()
        : QSharedData(),
        m_optimizationHints(QContactFetchHint::AllRequired),
        m_maxCount(-1)
    {
    }

    QContactFetchHintPrivate(const QContactFetchHintPrivate& other)
        : QSharedData(other),
        m_typesHint(other.m_typesHint),
        m_relationshipsHint(other.m_relationshipsHint),
        m_optimizationHints(other.m_optimizationHints),
        m_maxCount(other.m_maxCount)
    {
    }

    ~QContactFetchHintPrivate()
    {
    }

    QList<QContactDetail::DetailType> m_typesHint;
    QStringList m_relationshipsHint;
    QSize m_preferredImageSize;
    QContactFetchHint::OptimizationHints m_optimizationHints;
    int m_maxCount;
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTFETCHHINT_P_H
