// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QCONTACTUNIONFILTER_H
#define QCONTACTUNIONFILTER_H

#include <QtCore/qlist.h>

#include <QtContacts/qcontactfilter.h>

QT_BEGIN_NAMESPACE_CONTACTS

class QContactUnionFilterPrivate;
class Q_CONTACTS_EXPORT QContactUnionFilter : public QContactFilter
{
public:

    QContactUnionFilter();
    QContactUnionFilter(const QContactFilter& other);

    void setFilters(const QList<QContactFilter>& filters);

    void prepend(const QContactFilter& filter);
    void append(const QContactFilter& filter);
    void remove(const QContactFilter& filter);
    void clear();

    QContactUnionFilter& operator<<(const QContactFilter& filter);

    /* Accessors */
    QList<QContactFilter> filters() const;

private:
    Q_DECLARE_CONTACTFILTER_PRIVATE(QContactUnionFilter)
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTUNIONFILTER_H
