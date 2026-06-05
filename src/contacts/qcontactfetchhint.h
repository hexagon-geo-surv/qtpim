// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QCONTACTFETCHHINT_H
#define QCONTACTFETCHHINT_H

#include <QtCore/qshareddata.h>
#include <QtCore/qsize.h>
#include <QtCore/qstringlist.h>

#include <QtContacts/qcontactdetail.h>

QT_BEGIN_NAMESPACE_CONTACTS

class QContactFetchHintPrivate;
class Q_CONTACTS_EXPORT QContactFetchHint {
public:
    QContactFetchHint();
    QContactFetchHint(const QContactFetchHint& other);
    ~QContactFetchHint();
    QContactFetchHint& operator=(const QContactFetchHint& other);

    QList<QContactDetail::DetailType> detailTypesHint() const;
    void setDetailTypesHint(const QList<QContactDetail::DetailType> &types);

    QStringList relationshipTypesHint() const;
    void setRelationshipTypesHint(const QStringList& relationshipTypes);

    QSize preferredImageSize() const;
    void setPreferredImageSize(const QSize& size);

    enum OptimizationHint {
        AllRequired = 0x0,
        NoRelationships = 0x1,
        NoActionPreferences = 0x2,
        NoBinaryBlobs = 0x4
        // any other optimization hints?
    };
    Q_DECLARE_FLAGS(OptimizationHints, OptimizationHint)

    OptimizationHints optimizationHints() const;
    void setOptimizationHints(OptimizationHints hints);

    int maxCountHint() const;
    void setMaxCountHint(int count);

private:
    QSharedDataPointer<QContactFetchHintPrivate> d;
};

#ifndef QT_NO_DATASTREAM
Q_CONTACTS_EXPORT QDataStream& operator<<(QDataStream& out, const QContactFetchHint& hint);
Q_CONTACTS_EXPORT QDataStream& operator>>(QDataStream& in, QContactFetchHint& hint);
#endif

#ifndef QT_NO_DEBUG_STREAM
Q_CONTACTS_EXPORT QDebug operator<<(QDebug dbg, const QContactFetchHint& hint);
#endif

Q_DECLARE_OPERATORS_FOR_FLAGS(QContactFetchHint::OptimizationHints)

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTFETCHHINT_H
