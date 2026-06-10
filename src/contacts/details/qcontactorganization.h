// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QCONTACTORGANIZATION_H
#define QCONTACTORGANIZATION_H

#include <QtCore/qurl.h>

#include <QtContacts/qcontactdetail.h>

QT_BEGIN_NAMESPACE_CONTACTS

/* Leaf class */
class Q_CONTACTS_EXPORT QContactOrganization : public QContactDetail
{
public:
#ifndef Q_QDOC
    Q_DECLARE_CUSTOM_CONTACT_DETAIL(QContactOrganization)
#else
    static const DetailType Type;
#endif

    enum OrganizationField {
        FieldName = 0,
        FieldLogoUrl,
        FieldDepartment,
        FieldLocation,
        FieldRole,
        FieldTitle,
        FieldAssistantName
    };

    void setName(const QString& _name);
    QString name() const;
    void setLogoUrl(const QUrl& logo);
    QUrl logoUrl() const;
    void setDepartment(const QStringList& _department);
    QStringList department() const;
    void setLocation(const QString& _location);
    QString location() const;
    void setRole(const QString& _role);
    QString role() const;
    void setTitle(const QString& _title);
    QString title() const;
    void setAssistantName(const QString& _assistantName);
    QString assistantName() const;
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTORGANIZATION_H
