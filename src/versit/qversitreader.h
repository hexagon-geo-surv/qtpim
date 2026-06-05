// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QVERSITREADER_H
#define QVERSITREADER_H

#include <QtCore/qlist.h>
#include <QtCore/qobject.h>

#include <QtVersit/qversitdocument.h>

QT_FORWARD_DECLARE_CLASS(QByteArray)
QT_FORWARD_DECLARE_CLASS(QIODevice)
QT_FORWARD_DECLARE_CLASS(QTextCodec)

QT_BEGIN_NAMESPACE_VERSIT

class QVersitReaderPrivate;

// reads a QVersitDocument from i/o device
class Q_VERSIT_EXPORT QVersitReader : public QObject
{
    Q_OBJECT
public:
    enum Error {
        NoError = 0,
        UnspecifiedError,
        IOError,
        OutOfMemoryError,
        NotReadyError,
        ParseError
    };

    enum State {
        InactiveState = 0,
        ActiveState,
        CanceledState,
        FinishedState
    };

    QVersitReader();
    QVersitReader(QIODevice* inputDevice);
    QVersitReader(const QByteArray& inputData);
    ~QVersitReader();

    // input:
    void setDevice(QIODevice* inputDevice);
    QIODevice* device() const;
    void setData(const QByteArray& inputData);

    void setDefaultCodec(QTextCodec* codec);
    QTextCodec* defaultCodec() const;

    // output:
    QList<QVersitDocument> results() const;

    State state() const;
    Error error() const;

    // reading:
public Q_SLOTS:
    bool startReading();
    void cancel();
public:
    Q_INVOKABLE bool waitForFinished(int msec = -1);

Q_SIGNALS:
    void stateChanged(QVersitReader::State state);
    void resultsAvailable();

private: // data
    QVersitReaderPrivate* d;
};

QT_END_NAMESPACE_VERSIT

Q_DECLARE_METATYPE(QTVERSIT_PREPEND_NAMESPACE(QVersitReader::State))

#endif // QVERSITREADER_H
