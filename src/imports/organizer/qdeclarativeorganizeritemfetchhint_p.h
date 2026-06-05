// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QDECLARATIVEORGANIZERITEMFETCHHINT_H
#define QDECLARATIVEORGANIZERITEMFETCHHINT_H

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

#include <QtOrganizer/qorganizeritemfetchhint.h>

QTORGANIZER_USE_NAMESPACE

QT_BEGIN_NAMESPACE

class QDeclarativeOrganizerItemFetchHint : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QList<int> detailTypesHint READ detailTypesHint WRITE setDetailTypesHint NOTIFY fetchHintChanged )
    Q_PROPERTY(OptimizationHints optimizationHints READ optimizationHints WRITE setOptimizationHints NOTIFY fetchHintChanged)

    Q_ENUMS(OptimizationHint)
    Q_FLAGS(OptimizationHints)

public:
    QDeclarativeOrganizerItemFetchHint(QObject *parent = nullptr);

    enum OptimizationHint {
        AllRequired = QOrganizerItemFetchHint::AllRequired,
        NoActionPreferences = QOrganizerItemFetchHint::NoActionPreferences,
        NoBinaryBlobs = QOrganizerItemFetchHint::NoBinaryBlobs
    };
    Q_DECLARE_FLAGS(OptimizationHints, OptimizationHint)

    OptimizationHints optimizationHints() const;
    void setOptimizationHints(OptimizationHints hints);

    QList<int> detailTypesHint() const;
    void setDetailTypesHint(const QList<int> &detailTypes);

    QOrganizerItemFetchHint fetchHint() const;
    void setFetchHint(const QOrganizerItemFetchHint &fetchHint);

Q_SIGNALS:
    void fetchHintChanged();

private:
    QOrganizerItemFetchHint d;
};

QT_END_NAMESPACE

QML_DECLARE_TYPE(QDeclarativeOrganizerItemFetchHint)

#endif // QDECLARATIVEORGANIZERITEMFETCHHINT_H
