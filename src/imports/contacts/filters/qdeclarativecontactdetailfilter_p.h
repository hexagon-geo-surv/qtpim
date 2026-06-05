// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QDECLARATIVECONTACTDETAILFILTER_H
#define QDECLARATIVECONTACTDETAILFILTER_H

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

#include <QtContacts/qcontactdetailfilter.h>

#include "qdeclarativecontactdetail_p.h"
#include "qdeclarativecontactfilter_p.h"

QTCONTACTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE

class QDeclarativeContactDetailFilter : public QDeclarativeContactFilter
{
    Q_OBJECT
    Q_PROPERTY(QDeclarativeContactDetail::DetailType detail READ detail WRITE setDetail NOTIFY valueChanged)
    Q_PROPERTY(int field READ field WRITE setField NOTIFY valueChanged)
    Q_PROPERTY(QVariant value READ value WRITE setValue NOTIFY valueChanged)
    Q_PROPERTY(MatchFlags matchFlags READ matchFlags WRITE setMatchFlags NOTIFY valueChanged)
public:

    QDeclarativeContactDetailFilter(QObject* parent = nullptr)
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

    QVariant value() const
    {
        return d.value();
    }
    void setValue(const QVariant& value)
    {
        if (value != d.value()) {
            d.setValue(value);
            emit valueChanged();
        }
    }

    QContactFilter filter() const
    {
        return d;
    }
signals:
    void valueChanged();


private:
    QContactDetailFilter d;
};

QT_END_NAMESPACE

QML_DECLARE_TYPE(QDeclarativeContactDetailFilter)

#endif // QDECLARATIVECONTACTDETAILFILTER_H
