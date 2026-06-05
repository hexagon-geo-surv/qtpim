// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

#ifndef tst_QVERSITCONTACTEXPORTER_H
#define tst_QVERSITCONTACTEXPORTER_H

#include <QObject>
#include <QtContacts/qcontact.h>
#include <QtContacts/qcontactdetail.h>
#include <QtVersit/qversitproperty.h>

QT_BEGIN_NAMESPACE_VERSIT
class QVersitContactExporter;
class QVersitContactExporterPrivate;
class QVersitDocument;
class QVersitProperty;
QT_END_NAMESPACE_VERSIT

QTCONTACTS_USE_NAMESPACE
QTVERSIT_USE_NAMESPACE

class MyQVersitResourceHandler;
class MyQVersitContactExporterDetailHandler;

class tst_QVersitContactExporter : public QObject
{
    Q_OBJECT

private slots:
    void init();
    void cleanup();

    void testConvertContact();
    void testEmptyContact();
    void testContactDetailHandler();
    void testContactDetailHandlerV2();
    void testEncodeName();
    void testEncodePhoneNumber();
    void testEncodeEmailAddress();
    void testEncodeStreetAddress();
    void testEncodeUrl();
    void testEncodeParameters();
    void testEncodeUid();
    void testEncodeRev();
    void testEncodeVersion();
    void testEncodeBirthDay();
    void testEncodeNote();
    void testEncodeGeoLocation();
    void testEncodeOrganization();
    void testEncodeEmbeddedContent();
    void testEncodeRingtone();
    void testEncodeGender();
    void testEncodeNickName();
    void testEncodeTag();
    void testEncodeAnniversary();
    void testEncodeOnlineAccount();
    void testEncodeFamily();
    void testEncodeFavorite();
    void testEncodeExtendedDetail();
    void testEncodeExtendedDetail_data();
    void testEncodeMultipleExtendedDetails();
    void testEncodeAvatar();
    void testDefaultResourceHandler();
    void testEncodeEmailWithContextOther();

private:
    // Test Utility Functions
    QContact createContactWithName(QString name);
    int countProperties(const QVersitDocument& document);
    QContactDetail findDetailByType(QList<QContactDetail> details, QContactDetail::DetailType search);
    QVersitProperty findPropertyByName(const QVersitDocument& document,const QString& propertyName);

private: // Data
    QVersitContactExporter* mExporter;
    MyQVersitResourceHandler* mResourceHandler;
};

#endif // tst_QVERSITCONTACTEXPORTER_H
