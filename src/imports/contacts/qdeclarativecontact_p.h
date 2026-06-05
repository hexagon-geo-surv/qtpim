// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QDECLARATIVECONTACT_P_H
#define QDECLARATIVECONTACT_P_H

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

#include <QtQml/qqml.h>

#include <QtContacts/qcontact.h>
#include <QtContacts/qcontactid.h>
#include <QtContacts/qcontactcollectionid.h>

#include "details/qdeclarativecontactdetails_p.h"

QTCONTACTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE

class QDeclarativeContact : public QObject
{
    Q_OBJECT

    // basic information
    Q_PROPERTY (bool modified READ modified)

    Q_PROPERTY (QDeclarativeContactType::ContactType type READ type NOTIFY contactChanged)
    Q_PROPERTY (QString contactId READ contactId NOTIFY contactIdChanged)
    Q_PROPERTY (QString manager READ manager NOTIFY managerChanged)
    Q_PROPERTY (QQmlListProperty<QDeclarativeContactDetail> contactDetails READ contactDetails NOTIFY contactChanged)
    Q_PROPERTY (QDeclarativeContactAddress* address READ address NOTIFY contactChanged)
    Q_PROPERTY (QQmlListProperty<QDeclarativeContactAddress> addresses READ addresses NOTIFY contactChanged)
    Q_PROPERTY (QDeclarativeContactAnniversary* anniversary READ anniversary NOTIFY contactChanged)
    Q_PROPERTY (QDeclarativeContactAvatar* avatar READ avatar NOTIFY contactChanged)
    Q_PROPERTY (QDeclarativeContactBirthday*  birthday READ birthday NOTIFY contactChanged)
    Q_PROPERTY (QDeclarativeContactDisplayLabel*  displayLabel READ displayLabel NOTIFY contactChanged)
    Q_PROPERTY (QDeclarativeContactEmailAddress*  email READ email NOTIFY contactChanged)
    Q_PROPERTY (QQmlListProperty<QDeclarativeContactEmailAddress> emails READ emails NOTIFY contactChanged)
    Q_PROPERTY (QDeclarativeContactExtendedDetail*  extendedDetail READ extendedDetail NOTIFY contactChanged)
    Q_PROPERTY (QQmlListProperty<QDeclarativeContactExtendedDetail> extendedDetails READ extendedDetails NOTIFY contactChanged)
    Q_PROPERTY (QDeclarativeContactFamily*  family READ family NOTIFY contactChanged)
    Q_PROPERTY (QDeclarativeContactFavorite*  favorite READ favorite NOTIFY contactChanged)
    Q_PROPERTY (QDeclarativeContactGender*  gender READ gender NOTIFY contactChanged)
    Q_PROPERTY (QDeclarativeContactGeoLocation*  geolocation READ geolocation NOTIFY contactChanged)
    Q_PROPERTY (QDeclarativeContactGlobalPresence*  globalPresence READ globalPresence NOTIFY contactChanged)
    Q_PROPERTY (QDeclarativeContactGuid*  guid READ guid NOTIFY contactChanged)
    Q_PROPERTY (QDeclarativeContactHobby*  hobby READ hobby NOTIFY contactChanged)
    Q_PROPERTY (QDeclarativeContactName*  name READ name NOTIFY contactChanged)
    Q_PROPERTY (QDeclarativeContactNickname*  nickname READ nickname  NOTIFY contactChanged)
    Q_PROPERTY (QDeclarativeContactNote*  note READ note NOTIFY contactChanged)
    Q_PROPERTY (QDeclarativeContactOnlineAccount*  onlineAccount READ onlineAccount NOTIFY contactChanged)
    Q_PROPERTY (QDeclarativeContactOrganization*  organization READ organization  NOTIFY contactChanged)
    Q_PROPERTY (QQmlListProperty<QDeclarativeContactOrganization>  organizations READ organizations  NOTIFY contactChanged)
    Q_PROPERTY (QDeclarativeContactPhoneNumber*  phoneNumber READ phoneNumber NOTIFY contactChanged)
    Q_PROPERTY (QQmlListProperty<QDeclarativeContactPhoneNumber> phoneNumbers READ phoneNumbers NOTIFY contactChanged)
    Q_PROPERTY (QDeclarativeContactPresence*  presence READ presence NOTIFY contactChanged)
    Q_PROPERTY (QDeclarativeContactRingtone*  ringtone READ ringtone NOTIFY contactChanged)
    Q_PROPERTY (QDeclarativeContactSyncTarget*  syncTarget READ syncTarget NOTIFY contactChanged)
    Q_PROPERTY (QDeclarativeContactTag*  tag READ tag NOTIFY contactChanged)
    Q_PROPERTY (QDeclarativeContactTimestamp*  timestamp READ timestamp NOTIFY contactChanged)
    Q_PROPERTY (QDeclarativeContactUrl*  url READ url NOTIFY contactChanged)
    Q_PROPERTY (QQmlListProperty<QDeclarativeContactUrl> urls READ urls NOTIFY contactChanged)
    Q_PROPERTY (QDeclarativeContactVersion*  version READ version NOTIFY contactChanged)
    Q_PROPERTY (QVariantMap preferredDetails READ preferredDetails NOTIFY contactChanged)
    Q_PROPERTY (QString collectionId READ collectionId WRITE setCollectionId NOTIFY contactChanged)
    Q_CLASSINFO("DefaultProperty", "contactDetails")

public:

    explicit QDeclarativeContact(QObject *parent = nullptr);
    ~QDeclarativeContact();

    void setContact(const QContact& c);
    QContact contact() const;
    bool modified() const;

    QDeclarativeContactType::ContactType type() const;

    QString contactId() const;
    QString manager() const;
    QQmlListProperty<QDeclarativeContactDetail> contactDetails();

    // use int instead of QDeclarativeContactDetail::ContactType as a work-around for QTBUG-20639
    Q_INVOKABLE QDeclarativeContactDetail* detail(int type);
    Q_INVOKABLE QVariantList details(int type);

    Q_INVOKABLE bool removeDetail(QDeclarativeContactDetail* detail);
    Q_INVOKABLE bool addDetail(QDeclarativeContactDetail* detail);

    Q_INVOKABLE bool setPreferredDetail(const QString& actionName, QDeclarativeContactDetail* detail);
    Q_INVOKABLE bool isPreferredDetail(const QString& actionName, QDeclarativeContactDetail* detail) const;
    Q_INVOKABLE QDeclarativeContactDetail* preferredDetail(const QString& actionName) const;
    QVariantMap preferredDetails() const;

    QString collectionId() const;
    void setCollectionId(const QString& collectionId);

    QDeclarativeContactAddress* address();
    QQmlListProperty<QDeclarativeContactAddress>  addresses();
    QDeclarativeContactAnniversary* anniversary();
    QDeclarativeContactAvatar* avatar();
    QDeclarativeContactBirthday*  birthday();
    QDeclarativeContactDisplayLabel* displayLabel();
    QDeclarativeContactEmailAddress*  email();
    QQmlListProperty<QDeclarativeContactEmailAddress>  emails();
    QDeclarativeContactExtendedDetail*  extendedDetail();
    QQmlListProperty<QDeclarativeContactExtendedDetail>  extendedDetails();
    QDeclarativeContactFamily*  family();
    QDeclarativeContactFavorite*  favorite();
    QDeclarativeContactGender*  gender();
    QDeclarativeContactGeoLocation*  geolocation();
    QDeclarativeContactGlobalPresence*  globalPresence();
    QDeclarativeContactGuid*  guid();
    QDeclarativeContactHobby*  hobby();
    QDeclarativeContactName*  name();
    QDeclarativeContactNickname*  nickname();
    QDeclarativeContactNote*  note();
    QDeclarativeContactOnlineAccount*  onlineAccount();
    QDeclarativeContactOrganization*  organization();
    QQmlListProperty<QDeclarativeContactOrganization>  organizations();
    QDeclarativeContactPhoneNumber*  phoneNumber();
    QQmlListProperty<QDeclarativeContactPhoneNumber>  phoneNumbers();
    QDeclarativeContactPresence*  presence();
    QDeclarativeContactRingtone*  ringtone();
    QDeclarativeContactSyncTarget*  syncTarget();
    QDeclarativeContactTag*  tag();
    QDeclarativeContactTimestamp*  timestamp();
    QDeclarativeContactUrl*  url();
    QQmlListProperty<QDeclarativeContactUrl>  urls();
    QDeclarativeContactVersion*  version();

protected:
    bool m_modified;
    QContactId m_id;
    QContactCollectionId m_collectionId;

    // always create a copy of the detail for QML
    // however, seems the garbage collection can't delete all of them (QTBUG-20377)
    QList<QDeclarativeContactDetail *> m_details;
    QMap<QString, int> m_preferredDetails;

public slots:
    void clearDetails();
    void save();
Q_SIGNALS:
    void contactIdChanged();
    void managerChanged();
    void contactChanged();

private slots:
    void setModified();

private:
    Q_DISABLE_COPY(QDeclarativeContact)

    template<typename T> T* getDetail(const QDeclarativeContactDetail::DetailType &type)
    {
        for (QDeclarativeContactDetail *detail : std::as_const(m_details)) {
            if (type == detail->detailType())
            {
                T* tempDetail = static_cast<T *>(detail);
                return tempDetail;
            }
        }
        T* detail = new T;
        if (detail) {
            m_details.append(detail);
            emit contactChanged();
            return detail;
        }
        return 0;
    }

    void removePreferredDetail(QDeclarativeContactDetail *detail);

    // call-back functions for list property
    static void _q_detail_append(QQmlListProperty<QDeclarativeContactDetail> *property, QDeclarativeContactDetail *value);
    static QDeclarativeContactDetail *_q_detail_at(QQmlListProperty<QDeclarativeContactDetail> *property, qsizetype index);
    static void _q_detail_clear(QQmlListProperty<QDeclarativeContactDetail> *property);
    static qsizetype _q_detail_count(QQmlListProperty<QDeclarativeContactDetail> *property);
};

QT_END_NAMESPACE

QML_DECLARE_TYPE(QDeclarativeContact)

#endif // QDECLARATIVECONTACT_P_H
