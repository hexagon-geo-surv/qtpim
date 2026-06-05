// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QCONTACTCOLLECTIONFILTER_H
#define QCONTACTCOLLECTIONFILTER_H

#include <QtCore/qset.h>

#include <QtContacts/qcontactcollectionid.h>
#include <QtContacts/qcontactfilter.h>

QT_BEGIN_NAMESPACE_CONTACTS

class QContactCollectionFilterPrivate;

/* Leaf class */

class Q_CONTACTS_EXPORT QContactCollectionFilter : public QContactFilter
{
public:
    QContactCollectionFilter();
    QContactCollectionFilter(const QContactFilter &other);

    void setCollectionId(const QContactCollectionId &id);
    void setCollectionIds(const QSet<QContactCollectionId> &ids);
    QSet<QContactCollectionId> collectionIds() const;

private:
    Q_DECLARE_CONTACTFILTER_PRIVATE(QContactCollectionFilter)
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTCOLLECTIONFILTER_H
