// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QDECLARATIVECONTACTORGANIZATION_H
#define QDECLARATIVECONTACTORGANIZATION_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.
// This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <QtContacts/qcontactorganization.h>
#include <QtCore/qurl.h>

#include "qdeclarativecontactdetail_p.h"

QTCONTACTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE

class QDeclarativeContactOrganization : public QDeclarativeContactDetail
{
    Q_OBJECT

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY valueChanged)
    Q_PROPERTY(QUrl logoUrl READ logoUrl WRITE setLogoUrl NOTIFY valueChanged)
    Q_PROPERTY(QStringList department READ department WRITE setDepartment NOTIFY valueChanged)
    Q_PROPERTY(QString location READ location WRITE setLocation NOTIFY valueChanged)
    Q_PROPERTY(QString role READ role WRITE setRole NOTIFY valueChanged)
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY valueChanged)
    Q_PROPERTY(QString assistantName READ assistantName WRITE setAssistantName NOTIFY valueChanged)
    Q_CLASSINFO("DefaultProperty", "name")
    Q_ENUMS(FieldType)
public:
    enum FieldType {
        Name = QContactOrganization::FieldName,
        LogoUrl = QContactOrganization::FieldLogoUrl,
        Department = QContactOrganization::FieldDepartment,
        Location = QContactOrganization::FieldLocation,
        Role = QContactOrganization::FieldRole,
        Title = QContactOrganization::FieldTitle,
        AssistantName = QContactOrganization::FieldAssistantName
    };

    QDeclarativeContactOrganization(QObject* parent = Q_NULLPTR)
        :QDeclarativeContactDetail(parent)
    {
        setDetail(QContactOrganization());
        connect(this, SIGNAL(valueChanged()), SIGNAL(detailChanged()));
    }
    DetailType detailType() const override
    {
        return QDeclarativeContactDetail::Organization;
    }

    void setName(const QString& v)
    {
        if (!readOnly() && v != name()) {
            detail().setValue(QContactOrganization::FieldName, v);
            emit valueChanged();
        }
    }
    QString name() const {return detail().value(QContactOrganization::FieldName).toString();}
    void setLogoUrl(const QUrl& v)
    {
        if (!readOnly() && v != logoUrl()) {
            detail().setValue(QContactOrganization::FieldLogoUrl, v);
            emit valueChanged();
        }
    }
    QUrl logoUrl() const {return QUrl(detail().value(QContactOrganization::FieldLogoUrl).toString());}
    void setDepartment(const QStringList& v)
    {
        if (!readOnly() && QSet<QString>(v.cbegin(), v.cend()) != QSet<QString>(department().cbegin(), department().cend())) {
            detail().setValue(QContactOrganization::FieldDepartment, v);
            emit valueChanged();
        }
    }
    QStringList department() const {return detail().value<QStringList>(QContactOrganization::FieldDepartment);}
    void setLocation(const QString& v)
    {
        if (!readOnly() && v != location()) {
            detail().setValue(QContactOrganization::FieldLocation, v);
            emit valueChanged();
        }
    }
    QString location() const {return detail().value(QContactOrganization::FieldLocation).toString();}
    void setRole(const QString& v)
    {
        if (!readOnly() && v != role()) {
            detail().setValue(QContactOrganization::FieldRole, v);
            emit valueChanged();
        }
    }
    QString role() const {return detail().value(QContactOrganization::FieldRole).toString();}
    void setTitle(const QString& v)
    {
        if (!readOnly() && v != title()) {
            detail().setValue(QContactOrganization::FieldTitle, v);
            emit valueChanged();
        }
    }
    QString title() const {return detail().value(QContactOrganization::FieldTitle).toString();}
    void setAssistantName(const QString& v)
    {
        if (!readOnly() && v != assistantName()) {
            detail().setValue(QContactOrganization::FieldAssistantName, v);
            emit valueChanged();
        }
    }
    QString assistantName() const {return detail().value(QContactOrganization::FieldAssistantName).toString();}

signals:
    void valueChanged();

};

QT_END_NAMESPACE

QML_DECLARE_TYPE(QDeclarativeContactOrganization)

#endif // QDECLARATIVECONTACTORGANIZATION_H
