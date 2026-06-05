// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QVERSITCONTACTIMPORTER_P_H
#define QVERSITCONTACTIMPORTER_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <QtCore/qdatetime.h>
#include <QtCore/qhash.h>
#include <QtCore/qlist.h>
#include <QtCore/qmap.h>
#include <QtCore/qpair.h>

#include <QtContacts/qcontact.h>
#include <QtContacts/qcontactdetail.h>

#include <QtVersit/qversitcontactimporter.h>
#include <QtVersit/private/qvcardrestorehandler_p.h>

QT_BEGIN_NAMESPACE_CONTACTS
class QContactOrganization;
QT_END_NAMESPACE_CONTACTS

QTCONTACTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE_VERSIT

class QVersitProperty;
class QVersitDocument;
class QVersitContactHandler;

class QVersitContactImporterPrivate
{
public:
    QVersitContactImporterPrivate(const QStringList& profiles = QStringList());
    ~QVersitContactImporterPrivate();

    bool importContact(const QVersitDocument& versitDocument, int contactIndex,
                       QContact* contact, QVersitContactImporter::Error* error);

private:
    void importProperty(const QVersitDocument& document, const QVersitProperty& property, int contactIndex, QContact* contact);
    bool createName(const QVersitProperty& property, QContact* contact, QList<QContactDetail>* updatedDetails);
    bool createPhone(const QVersitProperty& property, QContact* contact, QList<QContactDetail>* updatedDetails);
    bool createAddress(const QVersitProperty& property, QContact* contact, QList<QContactDetail>* updatedDetails);
    bool createOrganization(const QVersitProperty& property, QContact* contact, QList<QContactDetail>* updatedDetails);
    void setOrganizationNames(QContactOrganization& org, const QVersitProperty& property) const;
    void setOrganizationLogo(QContactOrganization& org, const QVersitProperty& property) const;
    bool createTimeStamp(const QVersitProperty& property, QContact* contact, QList<QContactDetail>* updatedDetails);
    bool createVersion(const QVersitProperty& property, QContact* contact, QList<QContactDetail>* updatedDetails);
    bool createAnniversary(const QVersitProperty& property, QContact* contact, QList<QContactDetail>* updatedDetails);
    bool createBirthday(const QVersitProperty& property, QContact* contact, QList<QContactDetail>* updatedDetails);
    bool createDisplaylabel(const QVersitProperty& property, QContact* contact, QList<QContactDetail>* updatedDetails);
    bool createNicknames(const QVersitProperty& property, QContact* contact, QList<QContactDetail>* updatedDetails);
    bool createTags(const QVersitProperty& property, QContact* contact, QList<QContactDetail>* updatedDetails);
    bool createOnlineAccount(const QVersitProperty& property, QContact* contact, QList<QContactDetail>* updatedDetails);
    bool createRingtone(const QVersitProperty& property, QContact* contact, QList<QContactDetail>* updatedDetails);
    bool createAvatar(const QVersitProperty& property, QContact* contact, QList<QContactDetail>* updatedDetails);
    bool createGeoLocation(const QVersitProperty& property, QContact* contact, QList<QContactDetail>* updatedDetails);
    bool createFamily(const QVersitProperty& property, QContact* contact, QList<QContactDetail>* updatedDetails);
    bool createFavorite(const QVersitProperty& property, QContact* contact, QList<QContactDetail>* updatedDetails);
    bool createNameValueDetail(const QVersitProperty& property, QContact* contact, QList<QContactDetail>* updatedDetails);
    bool createGender(const QVersitProperty& property, QContact* contact, QList<QContactDetail>* updatedDetails);
    bool createExtendedDetail(const QVersitProperty& property, QContact* contact, QList<QContactDetail>* updatedDetails);
    QList<int> extractContexts(const QVersitProperty& property) const;
    QStringList extractSubTypes(const QVersitProperty& property) const;
    QString takeFirst(QList<QString>& list) const;
    QDateTime parseDateTime(QString text, bool *justDate = 0) const;
    QString saveContentToFile(const QVersitProperty& property, const QByteArray& data) const;
    bool saveDataFromProperty(const QVersitProperty& property, QString* location, QByteArray* data) const;
    void saveDetailWithContext(QList<QContactDetail>* updatedDetails, QContactDetail detail, const QList<int>& contexts);

public: // Data
    QList<QContact> mContacts;
    QMap<int, QVersitContactImporter::Error> mErrors;
    QVersitContactImporterPropertyHandler* mPropertyHandler;
    QVersitContactImporterPropertyHandlerV2* mPropertyHandler2;
    QList<QVersitContactHandler*> mPluginPropertyHandlers;
    int mPropertyHandlerVersion;
    QVersitDefaultResourceHandler* mDefaultResourceHandler;
    QVersitResourceHandler* mResourceHandler;
    QVCardRestoreHandler mRestoreHandler;

    QHash<QString, QPair<QContactDetail::DetailType, int> > mDetailMappings;
    QMultiHash<QString, QPair<QContactDetail::DetailType, int> > mSubTypeMappings;
    QHash< int ,QString> mContextMappings;
};

QT_END_NAMESPACE_VERSIT

#endif // QVERSITCONTACTIMPORTER_P_H
