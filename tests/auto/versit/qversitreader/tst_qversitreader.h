// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

#ifndef tst_QVERSITREADER_H
#define tst_QVERSITREADER_H

#include <QObject>
#include <QBuffer>
#include <QtVersit/qversitreader.h>
#include <QtCore/qstringconverter.h>

QT_BEGIN_NAMESPACE_VERSIT
class QVersitReaderPrivate;
class LineReader;
QT_END_NAMESPACE_VERSIT

QTVERSIT_USE_NAMESPACE

// Poor man's QSignalSpy because I couldn't get QSignalSpy to work with the user type QVR::State.
class SignalCatcher : public QObject
{
Q_OBJECT
public:
    SignalCatcher() : mResultsCount(0) {}
public slots:
    void stateChanged(QVersitReader::State state) {
        mStateChanges.append(state);
    }
    void resultsAvailable() {
        mResultsCount += 1;
    }

public:
    QList<QVersitReader::State> mStateChanges;
    int mResultsCount;
};

class tst_QVersitReader : public QObject
{
     Q_OBJECT

private slots: // Tests
    void init();
    void cleanup();

    void testDevice();
    void testNullDevice();
    void testDefaultCodec();
    void testValidateUtf8();
    void testValidateUtf8_data();
    void testDetectCodec();
    void testDetectCodec_data();
    void testReading();
    void testResult();
    void testParseNextVersitProperty();
    void testParseNextVersitProperty_data();
    void testParseVersitDocument();
    void testParseVersitDocument_data();
    void testDecodeQuotedPrintable();
    void testDecodeQuotedPrintable_data();
    void testParamName();
    void testParamValue();
    void testExtractPart();
    void testExtractParts();
    void testExtractPropertyGroupsAndName();
    void testExtractVCard21PropertyParams();
    void testExtractVCard30PropertyParams();
    void testExtractParams();
    void testReadLine();
    void testReadLine_data();
    void testByteArrayInput();
    void testRemoveBackSlashEscaping();

private: // Data
    QVersitReader* mReader;
#ifdef QT_BUILD_INTERNAL
    QVersitReaderPrivate* mReaderPrivate;
#endif
    QBuffer* mInputDevice;
    QStringConverter::Encoding mAsciiCodec;
    SignalCatcher* mSignalCatcher;
};

#endif // tst_VERSITREADER_H
