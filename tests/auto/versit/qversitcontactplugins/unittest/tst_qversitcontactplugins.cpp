// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

#include <QtVersit/qversitcontacthandler.h>
#include <QtVersit/qversitproperty.h>
#include <QtContacts/qcontactname.h>

#include <QObject>
#include <QtTest/QtTest>

QTCONTACTS_USE_NAMESPACE
QTVERSIT_USE_NAMESPACE

class TestFactory1 : public QVersitContactHandlerFactory
{
    public:
        QString name() const override { return "factory1"; }
        QVersitContactHandler* createHandler() const override { return NULL; }
};

class tst_QVersitContactPlugins : public QObject
{
    Q_OBJECT

public slots:
    void init();

private slots:
    void testDefaultFactory();
    void testImporterPlugins();
    void testExporterPlugins();
};

void tst_QVersitContactPlugins::init() {
    // on windows, depending on how the unit test is invoked, we need these
    QCoreApplication::addLibraryPath("./debug/plugins/");
    QCoreApplication::addLibraryPath("./release/plugins/");
    QCoreApplication::addLibraryPath("./plugins/");
}

void tst_QVersitContactPlugins::testDefaultFactory() {
    TestFactory1 factory;
    QCOMPARE(factory.profiles(), QSet<QString>());
    QCOMPARE(factory.index(), 0);
}

void tst_QVersitContactPlugins::testImporterPlugins() {
    QVersitContactImporter importer("Test");
    QVersitDocument document;
    document.setComponentType("VCARD");
    QVersitProperty property;
    property.setName("FN");
    property.setValue("Bob");
    document.addProperty(property);
    QVERIFY(importer.importDocuments(QList<QVersitDocument>() << document));
    QCOMPARE(importer.contacts().size(), 1);
    QList<QContactDetail> details(importer.contacts().first().details(QContactDetail::TypeExtendedDetail));
    QCOMPARE(details.size(), 5);
    int pluginField = 0;
    // The plugins have had their index set such that they should be executed in reverse order
    // Check that they are all loaded, and run in the correct order
    QCOMPARE(details.at(0).value<int>(pluginField), 5);
    QCOMPARE(details.at(1).value<int>(pluginField), 4);
    QCOMPARE(details.at(2).value<int>(pluginField), 3);
    QCOMPARE(details.at(3).value<int>(pluginField), 2);
    QCOMPARE(details.at(4).value<int>(pluginField), 1);
}

void tst_QVersitContactPlugins::testExporterPlugins() {
    QVersitContactExporter exporter("Test");
    QContact contact;
    QContactName name;
    name.setFirstName("first name");
    contact.saveDetail(&name);
    QVERIFY(exporter.exportContacts(QList<QContact>() << contact));
    QCOMPARE(exporter.documents().size(), 1);
    QList<QVersitProperty> properties(exporter.documents().first().properties());

    // The plugins have had their index set such that they should be executed in reverse order
    // Check that they are all loaded, and run in the correct order
    int n = 0;
    for (QVersitProperty property : properties) {
        if (property.name() == "TEST-PROPERTY") {
            switch (n) {
                case 0: QCOMPARE(property.value(), QStringLiteral("5")); break;
                case 1: QCOMPARE(property.value(), QStringLiteral("4")); break;
                case 2: QCOMPARE(property.value(), QStringLiteral("3")); break;
                case 3: QCOMPARE(property.value(), QStringLiteral("2")); break;
                case 4: QCOMPARE(property.value(), QStringLiteral("1")); break;
            }
            n++;
        }
    }
    QCOMPARE(n, 5);
}

QTEST_MAIN(tst_QVersitContactPlugins)

#include "tst_qversitcontactplugins.moc"
