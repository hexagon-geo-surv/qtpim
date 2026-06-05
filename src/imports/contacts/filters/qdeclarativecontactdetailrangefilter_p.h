// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QDECLARATIVECONTACTDETAILRANGEFILTER_H
#define QDECLARATIVECONTACTDETAILRANGEFILTER_H

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

#include <QtContacts/qcontactdetailrangefilter.h>

#include "qdeclarativecontact_p.h"
#include "qdeclarativecontactfilter_p.h"

QTCONTACTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE

class QDeclarativeContactDetailRangeFilter : public QDeclarativeContactFilter
{
    Q_OBJECT
    Q_PROPERTY(QDeclarativeContactDetail::DetailType detail READ detail WRITE setDetail NOTIFY valueChanged)
    Q_PROPERTY(int field READ field WRITE setField NOTIFY valueChanged)
    Q_PROPERTY(QVariant min READ minValue WRITE setMinValue NOTIFY valueChanged)
    Q_PROPERTY(QVariant max READ maxValue WRITE setMaxValue NOTIFY valueChanged)
    Q_PROPERTY(MatchFlags matchFlags READ matchFlags WRITE setMatchFlags NOTIFY valueChanged)
    Q_PROPERTY(RangeFlags rangeFlags READ rangeFlags WRITE setRangeFlags NOTIFY valueChanged)
    Q_FLAGS(RangeFlags)
public:
    enum RangeFlag {
        IncludeLower = QContactDetailRangeFilter::IncludeLower,
        IncludeUpper = QContactDetailRangeFilter::IncludeUpper,
        ExcludeLower = QContactDetailRangeFilter::ExcludeLower,
        ExcludeUpper = QContactDetailRangeFilter::ExcludeUpper
    };
    Q_DECLARE_FLAGS(RangeFlags, RangeFlag)

    QDeclarativeContactDetailRangeFilter(QObject* parent = nullptr)
        : QDeclarativeContactFilter(parent)
    {
        connect(this, SIGNAL(valueChanged()), SIGNAL(filterChanged()));
    }

    void setDetail(QDeclarativeContactDetail::DetailType detail)
    {
        if (detail != static_cast<QDeclarativeContactDetail::DetailType>(d.detailType())) {
            d.setDetailType(static_cast<QContactDetail::DetailType>(detail), d.detailField());
            emit valueChanged();
        }
    }

    QDeclarativeContactDetail::DetailType detail() const
    {
        return static_cast<QDeclarativeContactDetail::DetailType>(d.detailType());
    }

    void setField(int field)
    {
        if (field != d.detailField()) {
            d.setDetailType(d.detailType(), field);
            emit valueChanged();
        }
    }

    int field() const
    {
        return d.detailField();
    }

    QDeclarativeContactFilter::MatchFlags matchFlags() const
    {
        QDeclarativeContactFilter::MatchFlags flags;
        flags = ~flags & (int)d.matchFlags();
        return flags;
    }
    void setMatchFlags(QDeclarativeContactFilter::MatchFlags flags)
    {
        QContactFilter::MatchFlags newFlags;
        newFlags = ~newFlags & (int)flags;
        if (newFlags != d.matchFlags()) {
            d.setMatchFlags(newFlags);
            emit valueChanged();
        }
    }

    QDeclarativeContactDetailRangeFilter::RangeFlags rangeFlags() const
    {
        QDeclarativeContactDetailRangeFilter::RangeFlags flags;
        flags = ~flags & (int)d.rangeFlags();
        return flags;
    }
    void setRangeFlags(QDeclarativeContactDetailRangeFilter::RangeFlags flags)
    {
        QContactDetailRangeFilter::RangeFlags newFlags;
        newFlags = ~newFlags & (int)flags;
        if (newFlags != d.rangeFlags()) {
            d.setRange(d.minValue(), d.maxValue(), newFlags);
            emit valueChanged();
        }
    }

    QVariant minValue() const
    {
        return d.minValue();
    }
    void setMinValue(const QVariant& value)
    {
        if (value != d.minValue()) {
            d.setRange(value, d.maxValue(), d.rangeFlags());
            emit valueChanged();
        }
    }

    QVariant maxValue() const
    {
        return d.maxValue();
    }
    void setMaxValue(const QVariant& value)
    {
        if (value != d.maxValue()) {
            d.setRange(d.minValue(), value, d.rangeFlags());
            emit valueChanged();
        }
    }

    QContactFilter filter() const override
    {
        return d;
    }
signals:
    void valueChanged();


private:
    QContactDetailRangeFilter d;
};

QT_END_NAMESPACE

QML_DECLARE_TYPE(QDeclarativeContactDetailRangeFilter)

#endif // QDECLARATIVECONTACTDETAILRANGEFILTER_H
