// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QCONTACTIDFILTER_H
#define QCONTACTIDFILTER_H

#include <QtCore/qlist.h>

#include <QtContacts/qcontactfilter.h>
#include <QtContacts/qcontactid.h>

QT_BEGIN_NAMESPACE_CONTACTS

class QContactIdFilterPrivate;
class Q_CONTACTS_EXPORT QContactIdFilter : public QContactFilter
{
public:
    QContactIdFilter();
    QContactIdFilter(const QContactFilter& other);

    /* Mutators */
    void setIds(const QList<QContactId>& ids);
    void add(const QContactId& id);
    void remove(const QContactId& id);
    void clear();

    /* Accessors */
    QList<QContactId> ids() const;

private:
    Q_DECLARE_CONTACTFILTER_PRIVATE(QContactIdFilter)
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTIDFILTER_H
