// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QDECLARATIVECONTACTDETAIL_P_H
#define QDECLARATIVECONTACTDETAIL_P_H

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

#include <QtCore/qset.h>
#include <QtCore/qstringlist.h>

#include <QtQml/qqml.h>

#include <QtContacts/qcontactdetail.h>

QTCONTACTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE

class QDeclarativeContactDetail : public QObject
{
    Q_OBJECT
    Q_PROPERTY(DetailType type READ detailType NOTIFY detailChanged)
    Q_PROPERTY(QList<int> contexts READ contexts WRITE setContexts NOTIFY detailChanged)
    Q_PROPERTY(QString detailUri READ detailUri WRITE setDetailUri NOTIFY detailChanged)
    Q_PROPERTY(QStringList linkedDetailUris READ linkedDetailUris WRITE setLinkedDetailUris NOTIFY detailChanged)
    Q_PROPERTY(QList<int> fields READ fields NOTIFY detailChanged)
    Q_PROPERTY(bool readOnly READ readOnly NOTIFY detailChanged)
    Q_PROPERTY(bool removable READ removable NOTIFY detailChanged)

    Q_ENUMS(DetailType)
    Q_ENUMS(ContextField)
public:
    QDeclarativeContactDetail(QObject* parent = Q_NULLPTR);


    enum DetailType {
        Address = QContactDetail::TypeAddress,
        Anniversary = QContactDetail::TypeAnniversary,
        Avatar = QContactDetail::TypeAvatar,
        Birthday = QContactDetail::TypeBirthday,
        DisplayLabel = QContactDetail::TypeDisplayLabel,
        Email = QContactDetail::TypeEmailAddress,
        ExtendedDetail = QContactDetail::TypeExtendedDetail,
        Family = QContactDetail::TypeFamily,
        Favorite = QContactDetail::TypeFavorite,
        Gender = QContactDetail::TypeGender,
        Geolocation = QContactDetail::TypeGeoLocation,
        GlobalPresence = QContactDetail::TypeGlobalPresence,
        Guid = QContactDetail::TypeGuid,
        Hobby = QContactDetail::TypeHobby,
        Name = QContactDetail::TypeName,
        NickName = QContactDetail::TypeNickname,
        Note = QContactDetail::TypeNote,
        OnlineAccount = QContactDetail::TypeOnlineAccount,
        Organization = QContactDetail::TypeOrganization,
        PhoneNumber = QContactDetail::TypePhoneNumber,
        Presence = QContactDetail::TypePresence,
        Ringtone = QContactDetail::TypeRingtone,
        SyncTarget = QContactDetail::TypeSyncTarget,
        Tag = QContactDetail::TypeTag,
        Timestamp = QContactDetail::TypeTimestamp,
        Type = QContactDetail::TypeType,
        Url = QContactDetail::TypeUrl,
        Version = QContactDetail::TypeVersion,
        Unknown = QContactDetail::TypeUndefined
    };

    enum ContextField {
        FieldContext = QContactDetail::FieldContext,
        ContextHome = QContactDetail::ContextHome,
        ContextWork = QContactDetail::ContextWork,
        ContextOther = QContactDetail::ContextOther
    };

    ~QDeclarativeContactDetail();

    // QML functions
    Q_INVOKABLE QVariant value(int field) const;
    Q_INVOKABLE bool setValue(int field, const QVariant& value);
    Q_INVOKABLE bool removeValue(int field);

    QContactDetail& detail();
    const QContactDetail& detail() const;
    void setDetail(const QContactDetail& detail);

    bool readOnly() const;
    bool removable() const;

    QList<int> contexts() const;
    void setContexts(const QList<int>& context);

    QString detailUri() const;
    void setDetailUri(const QString& detailUri);

    QStringList linkedDetailUris() const;
    void setLinkedDetailUris(const QStringList& linkedDetailUris);
    virtual DetailType detailType() const;

    QList<int> fields() const;
Q_SIGNALS:
    void detailChanged();

protected:
    QContactDetail m_detail;
};

class QDeclarativeContactDetailFactory
{
public:
    static QDeclarativeContactDetail *createContactDetail(const QDeclarativeContactDetail::DetailType type);
};

QT_END_NAMESPACE

QML_DECLARE_TYPE(QDeclarativeContactDetail)

#endif // QDECLARATIVECONTACTDETAIL_P_H
