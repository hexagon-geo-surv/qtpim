// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qversitwriter_p.h"

#include <QtCore/qbuffer.h>
#include <QtCore/qstringconverter.h>
#include <QtCore/qstringlist.h>

#include <utility>

#include "qvcard21writer_p.h"
#include "qvcard30writer_p.h"
#include "qversitdocumentwriter_p.h"
#include "qversitutils_p.h"

QT_BEGIN_NAMESPACE_VERSIT

/*! Constructs a writer. */
QVersitWriterPrivate::QVersitWriterPrivate()
    : mIoDevice(nullptr),
    mState(QVersitWriter::InactiveState),
    mError(QVersitWriter::NoError),
    mIsCanceling(false),
    mDefaultEncoding(QStringConverter::Utf8),
    mHasDefaultEncoding(false)
{
}

/*! Destroys a writer. */
QVersitWriterPrivate::~QVersitWriterPrivate()
{
}

/*! Links the signals from this to the signals of \a writer. */
void QVersitWriterPrivate::init(QVersitWriter* writer)
{
    qRegisterMetaType<QVersitWriter::State>("QVersitWriter::State");
    connect(this, SIGNAL(stateChanged(QVersitWriter::State)),
            writer, SIGNAL(stateChanged(QVersitWriter::State)), Qt::DirectConnection);
}

/*!
 * Do the actual writing and set the error and state appropriately.
 */
void QVersitWriterPrivate::write()
{
    bool canceled = false;

    // Try to get the type from the parameter to startWriting...
    QVersitDocument::VersitType type = documentType();

    for (const QVersitDocument& document : std::as_const(mInput)) {
        if (isCanceling()) {
            canceled = true;
            break;
        }

        // Get type from the document if not specified in startWriting
        if (type == QVersitDocument::InvalidType)
            type = document.type();

        QScopedPointer<QVersitDocumentWriter> writer(writerForType(type, document));
        if (mHasDefaultEncoding) {
            writer->setEncoding(mDefaultEncoding);
        } else {
            if (type == QVersitDocument::VCard21Type) {
                writer->setEncoding(QStringConverter::Latin1);
                writer->setAsciiCodec();
            } else {
                writer->setEncoding(QStringConverter::Utf8);
            }
        }
        writer->setDevice(mIoDevice);
        if (!writer->encodeVersitDocument(document)) {
            setError(QVersitWriter::IOError);
            break;
        }
    }
    if (canceled)
        setState(QVersitWriter::CanceledState);
    else
        setState(QVersitWriter::FinishedState);
}

/*!
 * Inherited from QThread, called by QThread when the thread has been started.
 */
void QVersitWriterPrivate::run()
{
    write();
}

void QVersitWriterPrivate::setState(QVersitWriter::State state)
{
    mMutex.lock();
    mState = state;
    mMutex.unlock();
    emit stateChanged(state);
}

QVersitWriter::State QVersitWriterPrivate::state() const
{
    QMutexLocker locker(&mMutex);
    return mState;
}

void QVersitWriterPrivate::setError(QVersitWriter::Error error)
{
    QMutexLocker locker(&mMutex);
    mError = error;
}

QVersitWriter::Error QVersitWriterPrivate::error() const
{
    QMutexLocker locker(&mMutex);
    return mError;
}

/*!
 * Returns a QVersitDocumentWriter that can encode a QVersitDocument of type \a type.
 * The caller is responsible for deleting the object.
 */
QVersitDocumentWriter* QVersitWriterPrivate::writerForType(QVersitDocument::VersitType type, const QVersitDocument& document)
{
    switch (type) {
        case QVersitDocument::InvalidType:
        {
            // Neither startWriting or the document provided the type.
            // Need to infer the type from the document's componentType
            QString componentType(document.componentType());
            if (componentType == QStringLiteral("VCARD")) {
                return new QVCard30Writer(QVersitDocument::VCard30Type);
            } else if (componentType == QStringLiteral("VCALENDAR")
                    || componentType == QStringLiteral("VEVENT")
                    || componentType == QStringLiteral("VTODO")
                    || componentType == QStringLiteral("VJOURNAL")
                    || componentType == QStringLiteral("VTIMEZONE")
                    || componentType == QStringLiteral("VALARM")) {
                return new QVCard30Writer(QVersitDocument::ICalendar20Type);
            } else {
                return new QVCard30Writer(QVersitDocument::VCard30Type);
            }
        }
        case QVersitDocument::VCard21Type:
            return new QVCard21Writer(type);
        case QVersitDocument::VCard30Type:
            return new QVCard30Writer(type);
        default:
            return new QVCard30Writer(type);
    }
}

void QVersitWriterPrivate::setCanceling(bool canceling)
{
    QMutexLocker locker(&mMutex);
    mIsCanceling = canceling;
}

bool QVersitWriterPrivate::isCanceling() const
{
    QMutexLocker locker(&mMutex);
    return mIsCanceling;
}

void QVersitWriterPrivate::setDocumentType(QVersitDocument::VersitType type)
{
    QMutexLocker locker(&mMutex);
    mType = type;
}

QVersitDocument::VersitType QVersitWriterPrivate::documentType() const
{
    QMutexLocker locker(&mMutex);
    return mType;
}

#include "moc_qversitwriter_p.cpp"
QT_END_NAMESPACE_VERSIT
