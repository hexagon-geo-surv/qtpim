// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QCONTACTCHANGELOGFILTER_H
#define QCONTACTCHANGELOGFILTER_H

#include <QtCore/qdatetime.h>

#include <QtContacts/qcontactfilter.h>

QT_BEGIN_NAMESPACE_CONTACTS

class QContactChangeLogFilterPrivate;
class Q_CONTACTS_EXPORT QContactChangeLogFilter: public QContactFilter
{
public:
    enum EventType {
        EventAdded,
        EventChanged,
        EventRemoved
    };

    explicit QContactChangeLogFilter(QContactChangeLogFilter::EventType type = QContactChangeLogFilter::EventAdded);
    QContactChangeLogFilter(const QContactFilter& other);

    void setEventType(QContactChangeLogFilter::EventType type);
    void setSince(const QDateTime& since);

    QDateTime since() const;
    QContactChangeLogFilter::EventType eventType() const;

private:
    Q_DECLARE_CONTACTFILTER_PRIVATE(QContactChangeLogFilter)
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTCHANGELOGFILTER_H
