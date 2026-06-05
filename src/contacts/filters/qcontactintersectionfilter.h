// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QCONTACTINTERSECTIONFILTER_H
#define QCONTACTINTERSECTIONFILTER_H

#include <QtCore/qlist.h>

#include <QtContacts/qcontactfilter.h>

QT_BEGIN_NAMESPACE_CONTACTS

class QContactIntersectionFilterPrivate;
class Q_CONTACTS_EXPORT QContactIntersectionFilter : public QContactFilter
{
public:

    QContactIntersectionFilter();
    QContactIntersectionFilter(const QContactFilter& other);

    void setFilters(const QList<QContactFilter>& filters);

    void prepend(const QContactFilter& filter);
    void append(const QContactFilter& filter);
    void remove(const QContactFilter& filter);
    void clear();

    QContactIntersectionFilter& operator<<(const QContactFilter& filter);

    /* Accessors */
    QList<QContactFilter> filters() const;

private:
    Q_DECLARE_CONTACTFILTER_PRIVATE(QContactIntersectionFilter)
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTINTERSECTIONFILTER_H
