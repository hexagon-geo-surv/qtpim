// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QVERSITWRITER_H
#define QVERSITWRITER_H

#include <QtCore/qlist.h>
#include <QtCore/qobject.h>

#include <QtVersit/qversitdocument.h>

QT_FORWARD_DECLARE_CLASS(QByteArray)
QT_FORWARD_DECLARE_CLASS(QIODevice)
QT_FORWARD_DECLARE_CLASS(QTextCodec)

QT_BEGIN_NAMESPACE_VERSIT

class QVersitWriterPrivate;

// writes a QVersitDocument to i/o device
class Q_VERSIT_EXPORT QVersitWriter : public QObject
{
    Q_OBJECT

public:
    enum Error {
        NoError = 0,
        UnspecifiedError,
        IOError,
        OutOfMemoryError,
        NotReadyError
    };

    enum State {
        InactiveState = 0,
        ActiveState,
        CanceledState,
        FinishedState
    };

    QVersitWriter();
    QVersitWriter(QIODevice* outputDevice);
    QVersitWriter(QByteArray* outputBytes);
    ~QVersitWriter();

    // output device
    void setDevice(QIODevice* outputDevice);
    QIODevice* device() const;

    void setDefaultCodec(QTextCodec* codec);
    QTextCodec* defaultCodec() const;

    State state() const;
    Error error() const;

    // writing:
public Q_SLOTS:
    bool startWriting(const QList<QVersitDocument>& input);
    bool startWriting(const QList<QVersitDocument>& input, QVersitDocument::VersitType type);
    bool startWriting(const QVersitDocument& input);
    bool startWriting(const QVersitDocument& input, QVersitDocument::VersitType type);
    void cancel();
public:
    Q_INVOKABLE bool waitForFinished(int msec = -1);

Q_SIGNALS:
    void stateChanged(QVersitWriter::State state);

private: // data
    QVersitWriterPrivate* d;
};

QT_END_NAMESPACE_VERSIT

Q_DECLARE_METATYPE(QTVERSIT_PREPEND_NAMESPACE(QVersitWriter::State))

#endif // QVERSITWRITER_H
