// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

#ifndef tst_QVERSITCONTACTIMPORTER_H
#define tst_QVERSITCONTACTIMPORTER_H

#include <QObject>
#include <QtVersit/qversitcontactimporter.h>
#include <QtVersit/qversitdocument.h>

QT_BEGIN_NAMESPACE_VERSIT
class QVersitContactImporter;
class QVersitContactImporterPrivate;
QT_END_NAMESPACE_VERSIT

QTVERSIT_USE_NAMESPACE

class MyQVersitContactImporterPropertyHandler;
class MyQVersitResourceHandler;

class tst_QVersitContactImporter : public QObject
{
    Q_OBJECT

private slots: // Tests
    void init();
    void cleanup();

    void testName();
    void testNameWithFormatted();
    void testAddress();
    void testAddressWithoutSubTypes();
    void testTel();
    void testTelWithoutSubTypes();
    void testEmail();
    void testUrl();
    void testUid();
    void testOrganizationName();
    void testOrganizationTitle();
    void testOrganizationLogo();
    void testOrganizationAssistant();
    void testOrganizationRole();
    void testTimeStamp();
    void testVersion();
    void testVersion_data();
    void testMultipleVersions();
    void testAnniversary();
    void testBirthday();
    void testGender();
    void testNickname();
    void testAvatarUrl();
    void testAvatarInvalid();
    void testGeo();
    void testNote();
    void testDisplayLabel();
    void testOnlineAccount();
    void testFamily();
    void testFavorite();
    void testFavorite_data();
    void testMultipleFavorites();
    void testSound();
    void testTag();
    void testExtendedDetail();
    void testExtendedDetail_data();
    void testMultipleExtendedDetails();
    void testPref();
    void testPropertyHandler();
    void testInvalidDocument();
    void testEmailWithContextOther();

private: // Utilities

    QVersitDocument createDocumentWithProperty(const QVersitProperty& property);

    QVersitDocument createDocumentWithNameAndPhoto(
        const QString& name,
        QByteArray image,
        const QString& photoType);

    void addVersionPropertyToDocument(QString sequenceNumber, QString extendedVersion, QVersitDocument &document);
    void addFavoritePropertyToDocument(QString favorite, QString index, QVersitDocument &document);
    void addExtendedDetailPropertyToDocument(QString name, QString data, QVersitDocument &document);

private:
    QVersitContactImporter* mImporter;
    MyQVersitContactImporterPropertyHandler* mPropertyHandler;
    MyQVersitResourceHandler* mResourceHandler;
};

#endif // tst_QVERSITCONTACTIMPORTER_H
