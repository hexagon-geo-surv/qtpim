// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

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
