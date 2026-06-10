// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QCONTACTNAME_H
#define QCONTACTNAME_H

#include <QtContacts/qcontactdetail.h>

QT_BEGIN_NAMESPACE_CONTACTS

class QContactFilter;

/* Leaf class */
class Q_CONTACTS_EXPORT QContactName : public QContactDetail
{
public:
#ifndef Q_QDOC
    Q_DECLARE_CUSTOM_CONTACT_DETAIL(QContactName)
#else
    static const DetailType Type;
#endif

    enum NameField {
        FieldPrefix = 0,
        FieldFirstName,
        FieldMiddleName,
        FieldLastName,
        FieldSuffix,
        FieldCustomLabel
    };

    QString prefix() const;
    QString firstName() const;
    QString middleName() const;
    QString lastName() const;
    QString suffix() const;
    QString customLabel() const;

    void setPrefix(const QString& _prefix);
    void setFirstName(const QString& _firstName);
    void setMiddleName(const QString& _middleName);
    void setLastName(const QString& _lastName);
    void setSuffix(const QString& _suffix);
    void setCustomLabel(const QString& _customLabel);

    // Convenience filter
    static QContactFilter match(const QString& name);
    static QContactFilter match(const QString& firstName, const QString& lastName);
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTNAME_H
