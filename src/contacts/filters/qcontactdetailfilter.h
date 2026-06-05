// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QCONTACTDETAILFILTER_H
#define QCONTACTDETAILFILTER_H

#include <QtCore/qvariant.h>

#include <QtContacts/qcontactdetail.h>
#include <QtContacts/qcontactfilter.h>

QT_BEGIN_NAMESPACE_CONTACTS

class QContactDetailFilterPrivate;
class Q_CONTACTS_EXPORT QContactDetailFilter : public QContactFilter
{
public:
    QContactDetailFilter();
    QContactDetailFilter(const QContactFilter& other);

    /* Mutators */
    void setDetailType(QContactDetail::DetailType type, int field = -1);
    void setMatchFlags(QContactFilter::MatchFlags flags);

    /* Filter Criterion */
    void setValue(const QVariant& value);

    /* Accessors */
    QContactDetail::DetailType detailType() const;
    int detailField() const;
    QContactFilter::MatchFlags matchFlags() const;

    QVariant value() const;

private:
    Q_DECLARE_CONTACTFILTER_PRIVATE(QContactDetailFilter)
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTDETAILFILTER_H
