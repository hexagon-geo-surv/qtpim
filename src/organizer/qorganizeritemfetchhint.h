/****************************************************************************
**
** Copyright (C) 2017 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtOrganizer module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl-3.0.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or (at your option) the GNU General
** Public license version 3 or any later version approved by the KDE Free
** Qt Foundation. The licenses are as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-2.0.html and
** https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QORGANIZERITEMFETCHHINT_H
#define QORGANIZERITEMFETCHHINT_H

#include <QtCore/qlist.h>
#include <QtCore/qshareddata.h>

#include <QtOrganizer/qorganizeritemdetail.h>

QT_BEGIN_NAMESPACE_ORGANIZER

class QOrganizerItemFetchHintPrivate;
class Q_ORGANIZER_EXPORT QOrganizerItemFetchHint
{
public:
    QOrganizerItemFetchHint();
    QOrganizerItemFetchHint(const QOrganizerItemFetchHint &other);
    ~QOrganizerItemFetchHint();

    QOrganizerItemFetchHint &operator=(const QOrganizerItemFetchHint &other);

    bool operator==(const QOrganizerItemFetchHint &other) const;
    inline bool operator!=(const QOrganizerItemFetchHint &other) const { return !(other == *this); }

    QList<QOrganizerItemDetail::DetailType> detailTypesHint() const;
    void setDetailTypesHint(const QList<QOrganizerItemDetail::DetailType> &detailTypes);

    enum OptimizationHint {
        AllRequired = 0x0,
        NoActionPreferences = 0x2,
        NoBinaryBlobs = 0x4
        // any other optimization hints?
    };
    Q_DECLARE_FLAGS(OptimizationHints, OptimizationHint)

    OptimizationHints optimizationHints() const;
    void setOptimizationHints(OptimizationHints hints);

private:
    QSharedDataPointer<QOrganizerItemFetchHintPrivate> d;
};

Q_DECLARE_OPERATORS_FOR_FLAGS(QOrganizerItemFetchHint::OptimizationHints)

#ifndef QT_NO_DATASTREAM
Q_ORGANIZER_EXPORT QDataStream &operator<<(QDataStream &out, const QOrganizerItemFetchHint &hint);
Q_ORGANIZER_EXPORT QDataStream &operator>>(QDataStream &in, QOrganizerItemFetchHint &hint);
#endif // QT_NO_DATASTREAM

#ifndef QT_NO_DEBUG_STREAM
Q_ORGANIZER_EXPORT QDebug operator<<(QDebug dbg, const QOrganizerItemFetchHint &hint);
#endif // QT_NO_DEBUG_STREAM

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERITEMFETCHHINT_H
