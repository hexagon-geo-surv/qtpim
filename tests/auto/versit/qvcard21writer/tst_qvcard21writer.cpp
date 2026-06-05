// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

//TESTED_COMPONENT=src/versit

#include "tst_qvcard21writer.h"
#ifdef QT_BUILD_INTERNAL
#include <QtVersit/private/qvcard21writer_p.h>
#endif
#include <QtVersit/qversitproperty.h>
#include <QtVersit/qversitdocument.h>
#include <QtTest/QtTest>
#include <QByteArray>
#include <QVariant>
#include <QtCore/qstringconverter.h>

#include <QTextCodec>

// This says "NOKIA" in Katakana
const QString KATAKANA_NOKIA(QString::fromUtf8("\xe3\x83\x8e\xe3\x82\xad\xe3\x82\xa2"));

QTVERSIT_USE_NAMESPACE

Q_DECLARE_METATYPE(QVersitProperty)
Q_DECLARE_METATYPE(QStringConverter::Encoding)

// Because the QFETCH macro balks on the comma in QMultiHash<QString,QString>
typedef QMultiHash<QString,QString> StringHash;
Q_DECLARE_METATYPE(StringHash)
#ifdef QT_BUILD_INTERNAL
void tst_QVCard21Writer::init()
{
    mWriter = new QVCard21Writer(QVersitDocument::VCard21Type);
    mWriter->setEncoding(QStringConverter::Latin1);
}

void tst_QVCard21Writer::cleanup()
{
    delete mWriter;
}

void tst_QVCard21Writer::testEncodeVersitProperty()
{
    QFETCH(QVersitProperty, property);
    QFETCH(QByteArray, expectedResult);
    QFETCH(QStringConverter::Encoding, encoding);
    QByteArray encodedProperty;
    QBuffer buffer(&encodedProperty);
    mWriter->setDevice(&buffer);
    mWriter->setEncoding(encoding);
    buffer.open(QIODevice::WriteOnly);

    mWriter->encodeVersitProperty(property);
    if (encodedProperty != expectedResult) {
        qDebug() << "Encoded: " << encodedProperty;
        qDebug() << "Expected: " << expectedResult;
        QVERIFY(false);
    }
}

void tst_QVCard21Writer::testEncodeVersitProperty_data()
{
    QTest::addColumn<QVersitProperty>("property");
    QTest::addColumn<QByteArray>("expectedResult");
    QTest::addColumn<QStringConverter::Encoding>("encoding");

    QVersitProperty property;
    QByteArray expectedResult;
    QStringConverter::Encoding encoding(QStringConverter::Latin1);

    // normal case
    property.setName(QString::fromLatin1("FN"));
    property.setValue(QString::fromLatin1("John Citizen"));
    property.setValueType(QVersitProperty::PlainType);
    expectedResult = "FN:John Citizen\r\n";
    QTest::newRow("No parameters") << property << expectedResult << encoding;

    // Structured N - escaping should happen for semicolons, not for commas
    property.setName(QStringLiteral("N"));
    property.setValue(QStringList()
                      << QStringLiteral("La;st")    // needs to be backslash escaped
                      << QStringLiteral("Fi,rst")
                      << QStringLiteral("Mi:ddle")
                      << QStringLiteral("Pr\\efix") // needs to be QP encoded
                      << QStringLiteral("Suffix"));
    property.setValueType(QVersitProperty::CompoundType);
    expectedResult = "N;ENCODING=QUOTED-PRINTABLE:La\\;st;Fi,rst;Mi:ddle;Pr=5Cefix;Suffix\r\n";
    QTest::newRow("N property") << property << expectedResult << encoding;

    // Structured N - there was a bug where if two fields had to be escaped,
    // two ENCODING parameters were added
    property.setName(QStringLiteral("N"));
    property.setValue(QStringList()
                      << QStringLiteral("La\\st")
                      << QStringLiteral("Fi\\rst")
                      << QString()
                      << QString()
                      << QString());
    property.setValueType(QVersitProperty::CompoundType);
    expectedResult = "N;ENCODING=QUOTED-PRINTABLE:La=5Cst;Fi=5Crst;;;\r\n";
    QTest::newRow("N property, double-encoded") << property << expectedResult << encoding;

    // Structured N - one field needs to be encoded in UTF-8 while the other doesn't
    // correct behaviour is to encode the whole thing in UTF-8
    property.setName(QStringLiteral("N"));
    property.setValue(QStringList()
                      << QString::fromUtf8("\xE2\x82\xAC") // euro sign
                      << QString::fromLatin1("\xA3") // pound sign (upper Latin-1)
                      << QString()
                      << QString()
                      << QString());
    property.setValueType(QVersitProperty::CompoundType);
    expectedResult = "N;CHARSET=UTF-8;ENCODING=QUOTED-PRINTABLE:=E2=82=AC;=C2=A3;;;\r\n";
    QTest::newRow("N property, double-encoded") << property << expectedResult << encoding;

    // Structured CATEGORIES - escaping should happen for commas, not semicolons
    property.setName(QStringLiteral("CATEGORIES"));
    property.setValue(QStringList()
                      << QStringLiteral("re;d")
                      << QStringLiteral("gr,een")
                      << QStringLiteral("bl:ue"));
    property.setValueType(QVersitProperty::ListType);
    expectedResult = "CATEGORIES:re;d,gr\\,een,bl:ue\r\n";
    QTest::newRow("CATEGORIES property") << property << expectedResult << encoding;

    // With parameter(s). No special characters in the value.
    // -> No need to Quoted-Printable encode the value.
    expectedResult = "TEL;HOME:123\r\n";
    property.setName(QString::fromLatin1("TEL"));
    property.setValue(QString::fromLatin1("123"));
    property.insertParameter(QString::fromLatin1("TYPE"),QString::fromLatin1("HOME"));
    QTest::newRow("With parameters, plain value") << property << expectedResult << encoding;

    expectedResult = "EMAIL;ENCODING=QUOTED-PRINTABLE;HOME:john.citizen=40example.com\r\n";
    property.setName(QString::fromLatin1("EMAIL"));
    property.setValue(QString::fromLatin1("john.citizen@example.com"));
    QTest::newRow("With parameters, special value") << property << expectedResult << encoding;

    // AGENT property with parameter
    expectedResult =
"AGENT;X-PARAMETER=VALUE:\r\n\
BEGIN:VCARD\r\n\
VERSION:2.1\r\n\
FN:Secret Agent\r\n\
END:VCARD\r\n\
\r\n";
    property.setParameters(QMultiHash<QString,QString>());
    property.setName(QString::fromLatin1("AGENT"));
    property.setValue(QString());
    property.insertParameter(QString::fromLatin1("X-PARAMETER"),QString::fromLatin1("VALUE"));
    QVersitDocument document(QVersitDocument::VCard21Type);
    document.setComponentType(QStringLiteral("VCARD"));
    QVersitProperty embeddedProperty;
    embeddedProperty.setName(QString(QString::fromLatin1("FN")));
    embeddedProperty.setValue(QString::fromLatin1("Secret Agent"));
    document.addProperty(embeddedProperty);
    property.setValue(QVariant::fromValue(document));
    QTest::newRow("AGENT property") << property << expectedResult << encoding;

    // Value is base64 encoded.
    // Check that the extra folding and the line break are added
    QByteArray value("value");
    expectedResult = "Springfield.HOUSE.PHOTO;ENCODING=BASE64:\r\n " + value.toBase64() + "\r\n\r\n";
    QStringList groups(QString::fromLatin1("Springfield"));
    groups.append(QString::fromLatin1("HOUSE"));
    property.setGroups(groups);
    property.setParameters(QMultiHash<QString,QString>());
    property.setName(QString::fromLatin1("PHOTO"));
    property.setValue(value);
    QTest::newRow("base64 encoded") << property << expectedResult << encoding;

    // Characters other than ASCII:
    // Note: KATAKANA_NOKIA is defined as: QString::fromUtf8("\xe3\x83\x8e\xe3\x82\xad\xe3\x82\xa2")
    // The expected behaviour is to convert to UTF8, then encode with quoted-printable.
    // Because the result overflows one line, it should be split onto two lines using a
    // quoted-printable soft line break (EQUALS-CR-LF).  (Note: Versit soft line breaks
    // (CR-LF-SPACE) are not supported by the native Symbian vCard importers).
    expectedResult = "ORG;CHARSET=UTF-8;ENCODING=QUOTED-PRINTABLE:=E3=83=8E=E3=82=AD=E3=82=A2=E3=\r\n"
                     "=83=8E=E3=82=AD=E3=82=A2\r\n";
    property = QVersitProperty();
    property.setName(QStringLiteral("ORG"));
    property.setValue(KATAKANA_NOKIA + KATAKANA_NOKIA);
    QTest::newRow("non-ASCII 1") << property << expectedResult << encoding;

    expectedResult = "ORG;CHARSET=UTF-8;ENCODING=QUOTED-PRINTABLE:a=E3=83=8E=E3=82=AD=E3=82=A2=E3=\r\n"
                     "=83=8E=E3=82=AD=E3=82=A2\r\n";
    property = QVersitProperty();
    property.setName(QStringLiteral("ORG"));
    property.setValue("a" + KATAKANA_NOKIA + KATAKANA_NOKIA);
    QTest::newRow("non-ASCII 2") << property << expectedResult << encoding;

    expectedResult = "ORG;CHARSET=UTF-8;ENCODING=QUOTED-PRINTABLE:aa=E3=83=8E=E3=82=AD=E3=82=A2=\r\n"
                     "=E3=83=8E=E3=82=AD=E3=82=A2\r\n";
    property = QVersitProperty();
    property.setName(QStringLiteral("ORG"));
    property.setValue("aa" + KATAKANA_NOKIA + KATAKANA_NOKIA);
    QTest::newRow("non-ASCII 3") << property << expectedResult << encoding;

    // Note: Shift-JIS codec is not supported by QStringConverter; that test row is omitted.
}

void tst_QVCard21Writer::testEncodeParameters()
{
    QFETCH(StringHash, parameters);
    QFETCH(QByteArray, expected);

    QByteArray encodedParameters;
    QBuffer buffer(&encodedParameters);
    mWriter->setDevice(&buffer);
    buffer.open(QIODevice::WriteOnly);

    // No parameters
    mWriter->encodeParameters(parameters);
    if (encodedParameters != expected) {
        qDebug() << "Encoded: " << encodedParameters;
        qDebug() << "Expected: " << expected;
        QVERIFY(false);
    }
}

void tst_QVCard21Writer::testEncodeParameters_data()
{
    QTest::addColumn< QMultiHash<QString, QString> >("parameters");
    QTest::addColumn<QByteArray>("expected");

    QMultiHash<QString,QString> parameters;

    QTest::newRow("No parameters") << parameters << QByteArray("");

    parameters.insert(QStringLiteral("TYPE"), QString::fromLatin1("HOME"));
    QTest::newRow("One TYPE parameter") << parameters << QByteArray(";HOME");

    // HOME should appear before VOICE because it is more "important" and some vCard
    // parsers may ignore everything after the first TYPE
    parameters.insert(QStringLiteral("TYPE"), QString::fromLatin1("VOICE"));
    QTest::newRow("Two TYPE parameters") << parameters << QByteArray(";HOME;VOICE");

    parameters.clear();
    parameters.insert(QStringLiteral("ENCODING"), QString::fromLatin1("8BIT"));
    QTest::newRow("One ENCODING parameter") << parameters << QByteArray(";ENCODING=8BIT");

    parameters.insert(QString::fromLatin1("X-PARAM"),QString::fromLatin1("VALUE"));
    QTest::newRow("Two parameters") << parameters << QByteArray(";ENCODING=8BIT;X-PARAM=VALUE");

    parameters.clear();
    parameters.insert(QStringLiteral("TYPE"), QStringLiteral("VOICE"));
    parameters.insert(QStringLiteral("TYPE"), QStringLiteral("CELL"));
    parameters.insert(QStringLiteral("TYPE"), QStringLiteral("MODEM"));
    parameters.insert(QStringLiteral("TYPE"), QStringLiteral("CAR"));
    parameters.insert(QStringLiteral("TYPE"), QStringLiteral("VIDEO"));
    parameters.insert(QStringLiteral("TYPE"), QStringLiteral("FAX"));
    parameters.insert(QStringLiteral("TYPE"), QStringLiteral("BBS"));
    parameters.insert(QStringLiteral("TYPE"), QStringLiteral("PAGER"));
    parameters.insert(QStringLiteral("TYPE"), QStringLiteral("HOME"));
    parameters.insert(QStringLiteral("TYPE"), QStringLiteral("WORK"));
    // Ensure CELL and FAX are at the front because they are "more important" and some vCard
    // parsers may ignore everything after the first TYPE
    // Ensure WORK and HOME come next.
    // Besides these conditions, there are no other ordering constraints.  The data here is simply
    // what the writer produces (as dictated by its internal data structures).
    QTest::newRow("TYPE parameters order") << parameters
        << QByteArray(";FAX;CELL;WORK;HOME;PAGER;BBS;VIDEO;CAR;MODEM;VOICE");
}

void tst_QVCard21Writer::testEncodeGroupsAndName()
{
    QVersitProperty property;
    QByteArray result;
    QBuffer buffer(&result);
    mWriter->setDevice(&buffer);
    buffer.open(QIODevice::WriteOnly);

    // No groups

    property.setName(QString::fromLatin1("name"));
    QByteArray expected("NAME");
    mWriter->encodeGroupsAndName(property);
    QCOMPARE(result, expected);

    // One group
    mWriter->writeCrlf(); // so it doesn't start folding
    buffer.close();
    result.clear();
    buffer.open(QIODevice::WriteOnly);
    property.setGroups(QStringList(QString::fromLatin1("group")));
    expected = "group.NAME";
    mWriter->encodeGroupsAndName(property);
    QCOMPARE(result, expected);

    // Two groups
    mWriter->writeCrlf(); // so it doesn't start folding
    buffer.close();
    result.clear();
    buffer.open(QIODevice::WriteOnly);
    QStringList groups(QString::fromLatin1("group1"));
    groups.append(QString::fromLatin1("group2"));
    property.setGroups(groups);
    expected = "group1.group2.NAME";
    mWriter->encodeGroupsAndName(property);
    QCOMPARE(result, expected);
}


void tst_QVCard21Writer::testQuotedPrintableEncode()
{
    QByteArray encodedBytes;

    // Nothing to encode
    QString nothingToEncode(QStringLiteral("nothing to encode"));
    QVERIFY(!mWriter->quotedPrintableEncode(nothingToEncode));

    // Special characters
    QString inputOutput(QStringLiteral("\n"));
    QVERIFY(mWriter->quotedPrintableEncode(inputOutput));
    QCOMPARE(inputOutput, QStringLiteral("=0A"));
    inputOutput = QStringLiteral("\r");
    QVERIFY(mWriter->quotedPrintableEncode(inputOutput));
    QCOMPARE(inputOutput, QStringLiteral("=0D"));
    inputOutput = QStringLiteral("!");
    QVERIFY(mWriter->quotedPrintableEncode(inputOutput));
    QCOMPARE(inputOutput, QStringLiteral("=21"));
    inputOutput = QStringLiteral("\"");
    QVERIFY(mWriter->quotedPrintableEncode(inputOutput));
    QCOMPARE(inputOutput, QStringLiteral("=22"));
    inputOutput = QStringLiteral("#");
    QVERIFY(mWriter->quotedPrintableEncode(inputOutput));
    QCOMPARE(inputOutput, QStringLiteral("=23"));
    inputOutput = QStringLiteral("$");
    QVERIFY(mWriter->quotedPrintableEncode(inputOutput));
    QCOMPARE(inputOutput, QStringLiteral("=24"));
    inputOutput = QStringLiteral("=");
    QVERIFY(mWriter->quotedPrintableEncode(inputOutput));
    QCOMPARE(inputOutput, QStringLiteral("=3D"));
    inputOutput = QStringLiteral("@");
    QVERIFY(mWriter->quotedPrintableEncode(inputOutput));
    QCOMPARE(inputOutput, QStringLiteral("=40"));
    inputOutput = QStringLiteral("[");
    QVERIFY(mWriter->quotedPrintableEncode(inputOutput));
    QCOMPARE(inputOutput, QStringLiteral("=5B"));
    inputOutput = QStringLiteral("\\");
    QVERIFY(mWriter->quotedPrintableEncode(inputOutput));
    QCOMPARE(inputOutput, QStringLiteral("=5C"));
    inputOutput = QStringLiteral("]");
    QVERIFY(mWriter->quotedPrintableEncode(inputOutput));
    QCOMPARE(inputOutput, QStringLiteral("=5D"));
    inputOutput = QStringLiteral("^");
    QVERIFY(mWriter->quotedPrintableEncode(inputOutput));
    QCOMPARE(inputOutput, QStringLiteral("=5E"));
    inputOutput = QStringLiteral("`");
    QVERIFY(mWriter->quotedPrintableEncode(inputOutput));
    QCOMPARE(inputOutput, QStringLiteral("=60"));
    inputOutput = QStringLiteral("{");
    QVERIFY(mWriter->quotedPrintableEncode(inputOutput));
    QCOMPARE(inputOutput, QStringLiteral("=7B"));
    inputOutput = QStringLiteral("|");
    QVERIFY(mWriter->quotedPrintableEncode(inputOutput));
    QCOMPARE(inputOutput, QStringLiteral("=7C"));
    inputOutput = QStringLiteral("}");
    QVERIFY(mWriter->quotedPrintableEncode(inputOutput));
    QCOMPARE(inputOutput, QStringLiteral("=7D"));
    inputOutput = QStringLiteral("~");
    QVERIFY(mWriter->quotedPrintableEncode(inputOutput));
    QCOMPARE(inputOutput, QStringLiteral("=7E"));
}
#endif

QTEST_MAIN(tst_QVCard21Writer)
