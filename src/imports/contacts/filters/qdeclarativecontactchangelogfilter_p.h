// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QDECLARATIVECONTACTCHANGELOGFILTER_H
#define QDECLARATIVECONTACTCHANGELOGFILTER_H

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

#include <QtContacts/qcontactchangelogfilter.h>

#include "qdeclarativecontactfilter_p.h"

QTCONTACTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE

class QDeclarativeContactChangeLogFilter: public QDeclarativeContactFilter
{
    Q_OBJECT
    Q_PROPERTY(QDateTime since READ since WRITE setSince NOTIFY valueChanged)
    Q_PROPERTY(EventType eventType READ eventType WRITE setEventType NOTIFY valueChanged)

    Q_ENUMS(EventType)
public:
    enum EventType {
        EventAdded = QContactChangeLogFilter::EventAdded,
        EventChanged = QContactChangeLogFilter::EventChanged,
        EventRemoved = QContactChangeLogFilter::EventRemoved
    };
    QDeclarativeContactChangeLogFilter(QObject* parent = nullptr)
        :QDeclarativeContactFilter(parent)
    {
        connect(this, SIGNAL(valueChanged()), SIGNAL(filterChanged()));
    }

    void setEventType(EventType type)
    {
       if (type != eventType()) {
           d.setEventType(static_cast<QContactChangeLogFilter::EventType>(type));
           emit valueChanged();
       }
    }

    EventType eventType() const
    {
        return static_cast<EventType>(d.eventType());
    }

    void setSince(const QDateTime& since)
    {
        if (since != d.since()) {
            d.setSince(since);
            emit valueChanged();
        }
    }

    QDateTime since() const
    {
        return d.since();
    }

    QContactFilter filter() const override
    {
        return d;
    }
signals:
    void valueChanged();


private:
    QContactChangeLogFilter d;
};

QT_END_NAMESPACE

QML_DECLARE_TYPE(QDeclarativeContactChangeLogFilter)

#endif // QDECLARATIVECONTACTCHANGELOGFILTER_H
