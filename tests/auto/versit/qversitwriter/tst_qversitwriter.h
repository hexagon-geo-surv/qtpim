// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

#ifndef tst_QVERSITWRITER_H
#define tst_QVERSITWRITER_H

#include <QObject>
#include <QBuffer>
#include <QtVersit/qversitwriter.h>

QT_BEGIN_NAMESPACE_VERSIT
class QVersitWriterPrivate;
QT_END_NAMESPACE_VERSIT

QTVERSIT_USE_NAMESPACE

// Poor man's QSignalSpy because I couldn't get QSignalSpy to work with the user type QVR::State.
class SignalCatcher : public QObject
{
Q_OBJECT
public slots:
    void stateChanged(QVersitWriter::State state) {
        mReceived.append(state);
    }

public:
    QList<QVersitWriter::State> mReceived;
};

class tst_QVersitWriter : public QObject
{
     Q_OBJECT

private slots: // Tests

    void init();
    void cleanup();

    void testDevice();
    void testDefaultCodec();
    void testWritingVersions();
    void testWriting21();
    void testWriting30();
    void testByteArrayOutput();
    void testWritingDocument();
    void testWritingDocument_data();

private: // Data
    QVersitWriter* mWriter;
    QBuffer* mOutputDevice;
    SignalCatcher* mSignalCatcher;
};

#endif // tst_QVERSITWRITER_H
