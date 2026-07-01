// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QCONTACTABSTRACTREQUEST_H
#define QCONTACTABSTRACTREQUEST_H

#include <QtCore/qobject.h>

#include <QtContacts/qcontactmanager.h>

QT_BEGIN_NAMESPACE_CONTACTS

class QContactManagerEngine;

class QContactAbstractRequestPrivate;
class Q_CONTACTS_EXPORT QContactAbstractRequest : public QObject
{
    Q_OBJECT

public:
    ~QContactAbstractRequest();

    Q_ENUMS(State)
    enum State {
        InactiveState = 0,   // operation not yet started
        ActiveState,         // operation started, not yet finished
        CanceledState,       // operation is finished due to cancellation
        FinishedState        // operation either completed successfully or failed.  No further results will become available.
    };

    State state() const; // replaces status()
    inline bool isInactive() const { return state() == QContactAbstractRequest::InactiveState; }
    inline bool isActive() const { return state() == QContactAbstractRequest::ActiveState; }
    inline bool isFinished() const { return state() == QContactAbstractRequest::FinishedState; }
    inline bool isCanceled() const { return state() == QContactAbstractRequest::CanceledState; }

    QContactManager::Error error() const;

    Q_ENUMS(RequestType)
    enum RequestType {
        InvalidRequest = 0,
        ContactFetchRequest,
        ContactIdFetchRequest,
        ContactRemoveRequest,
        ContactSaveRequest,
        RelationshipFetchRequest,
        RelationshipRemoveRequest,
        RelationshipSaveRequest,
        ContactFetchByIdRequest,
        CollectionFetchRequest,
        CollectionRemoveRequest,
        CollectionSaveRequest
    };

    RequestType type() const;

    /* Which manager we want to perform the asynchronous request */
    QContactManager* manager() const;
    void setManager(QContactManager* manager);

public Q_SLOTS:
    /* Verbs */
    bool start();
    bool cancel();

    /* waiting for stuff */
    bool waitForFinished(int msecs = 0);

Q_SIGNALS:
    void stateChanged(QtContacts::QContactAbstractRequest::State newState);
    void resultsAvailable();

protected:
    QContactAbstractRequest(QContactAbstractRequestPrivate* otherd, QObject* parent = Q_NULLPTR);
    QContactAbstractRequestPrivate* d_ptr;

private:
    QContactAbstractRequest(QObject* parent_ = Q_NULLPTR) : QObject(parent_), d_ptr(Q_NULLPTR) {}
    Q_DISABLE_COPY(QContactAbstractRequest)
    friend class QContactManagerEngine;
    friend class QContactAbstractRequestPrivate;

#ifndef QT_NO_DEBUG_STREAM
    Q_CONTACTS_EXPORT friend QDebug operator<<(QDebug dbg, const QContactAbstractRequest& request);
#endif

};

#ifndef QT_NO_DEBUG_STREAM
Q_CONTACTS_EXPORT QDebug operator<<(QDebug dbg, const QContactAbstractRequest& request);
#endif

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTABSTRACTREQUEST_H
