// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QCONTACTDISPLAYLABEL_H
#define QCONTACTDISPLAYLABEL_H

#include <QtContacts/qcontactdetail.h>

QT_BEGIN_NAMESPACE_CONTACTS

class QContactFilter;

/* Leaf class */
class Q_CONTACTS_EXPORT QContactDisplayLabel : public QContactDetail
{
public:
#ifndef Q_QDOC
    Q_DECLARE_CUSTOM_CONTACT_DETAIL(QContactDisplayLabel)
#else
    static const DetailType Type;
#endif

    enum DisplayLabelField {
        FieldLabel = 0
    };

    void setLabel(const QString& displayLabel);
    QString label() const;

    static QContactFilter match(const QString& label);
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTDISPLAYLABEL_H
