// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QORGANIZERABSTRACTREQUEST_H
#define QORGANIZERABSTRACTREQUEST_H

#include <QtOrganizer/qorganizermanager.h>

QT_BEGIN_NAMESPACE_ORGANIZER

class QOrganizerManagerEngine;

class QOrganizerAbstractRequestPrivate;
class Q_ORGANIZER_EXPORT QOrganizerAbstractRequest : public QObject
{
    Q_OBJECT

public:
    ~QOrganizerAbstractRequest();

    Q_ENUMS(State)
    enum State {
        InactiveState = 0,
        ActiveState,
        CanceledState,
        FinishedState
    };

    State state() const;
    inline bool isInactive() const { return state() == QOrganizerAbstractRequest::InactiveState; }
    inline bool isActive() const { return state() == QOrganizerAbstractRequest::ActiveState; }
    inline bool isCanceled() const { return state() == QOrganizerAbstractRequest::CanceledState; }
    inline bool isFinished() const { return state() == QOrganizerAbstractRequest::FinishedState; }

    QOrganizerManager::Error error() const;

    enum RequestType {
        InvalidRequest = 0,
        ItemOccurrenceFetchRequest,
        ItemFetchRequest,
        ItemFetchForExportRequest,
        ItemIdFetchRequest,
        ItemFetchByIdRequest,
        ItemRemoveRequest,
        ItemRemoveByIdRequest,
        ItemSaveRequest,
        CollectionFetchRequest,
        CollectionRemoveRequest,
        CollectionSaveRequest
    };

    RequestType type() const;

    QOrganizerManager* manager() const;
    void setManager(QOrganizerManager *manager);

public Q_SLOTS:
    bool start();
    bool cancel();
    bool waitForFinished(int msecs = 0);

Q_SIGNALS:
    void stateChanged(QtOrganizer::QOrganizerAbstractRequest::State newState);
    void resultsAvailable();

protected:
    QOrganizerAbstractRequest(QOrganizerAbstractRequestPrivate *other, QObject *parent = Q_NULLPTR);
    QOrganizerAbstractRequestPrivate *d_ptr;

private:
    QOrganizerAbstractRequest(QObject *_parent = Q_NULLPTR) : QObject(_parent), d_ptr(Q_NULLPTR) {}
    Q_DISABLE_COPY(QOrganizerAbstractRequest)
    friend class QOrganizerManagerEngine;
    friend class QOrganizerAbstractRequestPrivate;

#ifndef QT_NO_DEBUG_STREAM
    friend Q_ORGANIZER_EXPORT QDebug operator<<(QDebug dbg, const QOrganizerAbstractRequest &request);
#endif
};

#ifndef QT_NO_DEBUG_STREAM
Q_ORGANIZER_EXPORT QDebug operator<<(QDebug dbg, const QOrganizerAbstractRequest &request);
#endif

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERABSTRACTREQUEST_H
