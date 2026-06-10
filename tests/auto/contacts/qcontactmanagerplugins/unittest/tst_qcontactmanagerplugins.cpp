// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

//TESTED_COMPONENT=src/contacts

/* Force a static plugin */
#define QT_STATICPLUGIN

#include <QtTest/QtTest>

#include <QtContacts/qcontacts.h>

#include <QApplication>
QTCONTACTS_USE_NAMESPACE

class tst_QContactManagerPlugins : public QObject
{
Q_OBJECT

public:
    tst_QContactManagerPlugins();
    virtual ~tst_QContactManagerPlugins();

public slots:
    void init();
    void cleanup();
private slots:
    void testDummy();
};

/* Test a static factory as well */
class DummyStaticEngineFactory : public QContactManagerEngineFactory
{
    Q_OBJECT
    Q_INTERFACES(QtContacts::QContactManagerEngineFactoryInterface)
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QContactManagerEngineFactoryInterface")
    public:
        QContactManagerEngine* engine(const QMap<QString, QString>& parameters, QContactManager::Error* error) override;
        QString managerName() const override {return "teststaticdummy";}
};

QContactManagerEngine* DummyStaticEngineFactory::engine(const QMap<QString, QString>& parameters, QContactManager::Error* error)
{
    Q_UNUSED(parameters);
    *error = QContactManager::LockedError; // random unlikely error
    return 0; // always fail, haha
}

Q_IMPORT_PLUGIN(DummyStaticEngineFactory)

/* And test an impostor as well */
class ImpostorEngineFactory : public QContactManagerEngineFactory
{
    Q_OBJECT
    Q_INTERFACES(QtContacts::QContactManagerEngineFactoryInterface)
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QContactManagerEngineFactoryInterface")
    public:
        QContactManagerEngine* engine(const QMap<QString, QString>& , QContactManager::Error* ) override {return 0;}
        QString managerName() const override {return "memory";}
};

Q_IMPORT_PLUGIN(ImpostorEngineFactory)

/* And test another impostor as well */
class ImpostorEngineFactory2 : public QContactManagerEngineFactory
{
    Q_OBJECT
    Q_INTERFACES(QtContacts::QContactManagerEngineFactoryInterface)
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QContactManagerEngineFactoryInterface")
    public:
        QContactManagerEngine* engine(const QMap<QString, QString>& , QContactManager::Error* ) override {return 0;}
        QString managerName() const override {return "invalid";}
};

Q_IMPORT_PLUGIN(ImpostorEngineFactory2)

/* An empty interface name */
class EmptyEngineFactory : public QContactManagerEngineFactory
{
    Q_OBJECT
    Q_INTERFACES(QtContacts::QContactManagerEngineFactoryInterface)
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QContactManagerEngineFactoryInterface")
    public:
        QContactManagerEngine* engine(const QMap<QString, QString>& , QContactManager::Error* ) override {return 0;}
        QString managerName() const override {return QString();}
};

Q_IMPORT_PLUGIN(EmptyEngineFactory)

/* And a different interface one too */

class BoringInterface
{
    public:
        void doNothing() {}

};

QT_BEGIN_NAMESPACE
Q_DECLARE_INTERFACE(BoringInterface, "REALLYBORING!")
QT_END_NAMESPACE

class BoringFactory : public QObject, public BoringInterface
{
    Q_OBJECT
    Q_INTERFACES(BoringInterface)
    Q_PLUGIN_METADATA(IID "REALLYBORING!")
};

Q_IMPORT_PLUGIN(BoringFactory)


tst_QContactManagerPlugins::tst_QContactManagerPlugins()
{
}

tst_QContactManagerPlugins::~tst_QContactManagerPlugins()
{
}

void tst_QContactManagerPlugins::init()
{
    /* Add a path to our plugin path */
    QString path = QApplication::applicationDirPath() + "/dummyplugin/plugins";
    QApplication::addLibraryPath(path);
    QApplication::addLibraryPath(path); // Test the plugin path deduplication code
    path = QApplication::applicationDirPath() + "/dummyplugin";
    QApplication::addLibraryPath(path);
    QApplication::addLibraryPath("/"); // strictly to test a cdUp :/
}

void tst_QContactManagerPlugins::cleanup()
{
}

void tst_QContactManagerPlugins::testDummy()
{
    QVERIFY(QContactManager::availableManagers().contains("testdummy"));
    QVERIFY(QContactManager::availableManagers().contains("teststaticdummy"));

    QContactManager m1("teststaticdummy"); // should fail
    QVERIFY(m1.managerName() == "invalid");
    QVERIFY(m1.error() == QContactManager::LockedError);

    QContactManager m2("testdummy");
    QVERIFY(m2.managerName() == "testdummy");
}

QTEST_MAIN(tst_QContactManagerPlugins)
#include "tst_qcontactmanagerplugins.moc"
