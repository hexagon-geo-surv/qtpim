// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QCONTACTINVALIDFILTER_H
#define QCONTACTINVALIDFILTER_H

#include <QtContacts/qcontactfilter.h>

QT_BEGIN_NAMESPACE_CONTACTS

class QContactInvalidFilterPrivate;
class Q_CONTACTS_EXPORT QContactInvalidFilter : public QContactFilter
{
public:
    QContactInvalidFilter();
    QContactInvalidFilter(const QContactFilter& other);
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTINVALIDFILTER_H
