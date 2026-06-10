// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QVERSITWRITER_P_H
#define QVERSITWRITER_P_H

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

#include <QtCore/qmutex.h>
#include <QtCore/qscopedpointer.h>
#include <QtCore/qstringconverter.h>
#include <QtCore/qthread.h>

#include <QtVersit/qversitwriter.h>
#include <QtVersit/qversitdocument.h>

QT_FORWARD_DECLARE_CLASS(QBuffer)

QT_BEGIN_NAMESPACE_VERSIT

class QVersitDocumentWriter;

class QVersitWriterPrivate : public QThread
{
    Q_OBJECT

signals:
    void stateChanged(QtVersit::QVersitWriter::State state);

public:
    QVersitWriterPrivate();
    virtual ~QVersitWriterPrivate();
    void init(QVersitWriter* writer);
    void write();

    // mutexed getters and setters.
    void setState(QVersitWriter::State);
    QVersitWriter::State state() const;
    void setError(QVersitWriter::Error);
    QVersitWriter::Error error() const;
    void setCanceling(bool cancelling);
    bool isCanceling() const;
    void setDocumentType(QVersitDocument::VersitType type);
    QVersitDocument::VersitType documentType() const;

    void run() override;

    static QVersitDocumentWriter* writerForType(QVersitDocument::VersitType type, const QVersitDocument& document);

    QIODevice* mIoDevice;
    QScopedPointer<QBuffer> mOutputBytes; // Holds the data set by setData()
    QList<QVersitDocument> mInput;
    QVersitWriter::State mState;
    QVersitWriter::Error mError;
    bool mIsCanceling;
    mutable QMutex mMutex;
    QStringConverter::Encoding mDefaultEncoding;
    bool mHasDefaultEncoding;
    QVersitDocument::VersitType mType;
};

QT_END_NAMESPACE_VERSIT

#endif // QVERSITWRITER_P_H
