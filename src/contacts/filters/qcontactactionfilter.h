// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QCONTACTACTIONFILTER_H
#define QCONTACTACTIONFILTER_H

#include <QtContacts/qcontactfilter.h>

QT_BEGIN_NAMESPACE_CONTACTS

class QContactActionFilterPrivate;
class Q_CONTACTS_EXPORT QContactActionFilter : public QContactFilter
{
public:
    QContactActionFilter();
    QContactActionFilter(const QContactFilter& other);

    void setActionName(const QString& action);

    /* Accessors */
    QString actionName() const;

private:
    Q_DECLARE_CONTACTFILTER_PRIVATE(QContactActionFilter)
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTACTIONFILTER_H
