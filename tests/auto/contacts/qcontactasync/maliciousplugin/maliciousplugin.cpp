// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

#ifndef MALICIOUSPLUGINTARGET
#define MALICIOUSPLUGINTARGET contacts_maliciousplugin
#endif

#ifndef MALICIOUSPLUGINNAME
#define MALICIOUSPLUGINNAME maliciousplugin
#endif

#define makestr(x) (#x)
#define makename(x) makestr(x)

#include "maliciousplugin_p.h"
#include <QtContacts/qcontactmanager.h>

#include <QThread>
#include <QMutex>
#include <QSet>
#include <QDebug>

QTCONTACTS_USE_NAMESPACE

class MaliciousThreadObject : public QObject
{
    Q_OBJECT
public:
    MaliciousThreadObject() {}

public slots:
    void activateRequest(QContactAbstractRequest* req)
    {
        mutex.lock();
        if (activeRequests.contains(req)) {
            QContactManagerEngine::updateRequestState(req, QContactAbstractRequest::ActiveState);
        }
        mutex.unlock();
    }

    void finishRequest(QContactAbstractRequest* req)
    {
        QContactManager::Error errorResult = QContactManager::NoError;
        QMap<int, QContactManager::Error> errorsResult;
        QList<QContactId> idResult;
        QList<QContact> contactResult;
        QList<QContactRelationship> relResult;

        mutex.lock();
        if (activeRequests.contains(req)) {
            switch (req->type()) {
                case QContactAbstractRequest::ContactIdFetchRequest:
                    QContactManagerEngine::updateContactIdFetchRequest(static_cast<QContactIdFetchRequest*>(req), idResult, errorResult, QContactAbstractRequest::FinishedState);
                    break;

                case QContactAbstractRequest::ContactFetchRequest:
                    QContactManagerEngine::updateContactFetchRequest(static_cast<QContactFetchRequest*>(req), contactResult, errorResult, QContactAbstractRequest::FinishedState);
                    break;

                default:
                    QContactManagerEngine::updateRequestState(req, QContactAbstractRequest::FinishedState);
                    break;
            }
        }
        activeRequests.remove(req);
        mutex.unlock();
    }
public:
    QMutex mutex;

    QSet<QContactAbstractRequest*> activeRequests;
};

class MaliciousThread : public QThread
{
    Q_OBJECT;
public:
    MaliciousThread();
    ~MaliciousThread();
    QObject* eventLoopQuitHack;
};

MaliciousThread::MaliciousThread()
{
    eventLoopQuitHack = new QObject;
    eventLoopQuitHack->moveToThread(this);
    connect(eventLoopQuitHack, SIGNAL(destroyed(QObject*)), SLOT(quit()), Qt::DirectConnection);
}

MaliciousThread::~MaliciousThread()
{
    eventLoopQuitHack->deleteLater();
    wait();
}

MaliciousAsyncManagerEngine::MaliciousAsyncManagerEngine()
        : QContactManagerEngine()
{
    thread = new MaliciousThread();
    threadObject = new MaliciousThreadObject();
    threadObject->moveToThread(thread);

    connect(this, SIGNAL(doStartRequest(QContactAbstractRequest*)), threadObject, SLOT(activateRequest(QContactAbstractRequest*)), Qt::BlockingQueuedConnection);
    connect(this, SIGNAL(doFinishRequest(QContactAbstractRequest*)), threadObject, SLOT(finishRequest(QContactAbstractRequest*)), Qt::BlockingQueuedConnection);

    thread->start();
}

MaliciousAsyncManagerEngine::~MaliciousAsyncManagerEngine()
{
    delete thread;
    delete threadObject;
}

QString MaliciousAsyncManagerEngine::managerName() const
{
    return QString(makename(MALICIOUSPLUGINNAME));
}

bool MaliciousAsyncManagerEngine::startRequest(QContactAbstractRequest* req)
{
    threadObject->mutex.lock();
    threadObject->activeRequests.insert(req);
    threadObject->mutex.unlock();

    // Spawn a thread to do stuff on another thread
    emit doStartRequest(req);
    emit doFinishRequest(req);

    return true;
}

bool MaliciousAsyncManagerEngine::cancelRequest(QContactAbstractRequest *req)
{
    updateRequestState(req, QContactAbstractRequest::CanceledState);
    QContactManagerEngine::cancelRequest(req);
    return true;
}

void MaliciousAsyncManagerEngine::requestDestroyed(QContactAbstractRequest *req)
{
    threadObject->mutex.lock();
    threadObject->activeRequests.remove(req);
    threadObject->mutex.unlock();
    QContactManagerEngine::requestDestroyed(req);
}

QString MaliciousEngineFactory::managerName() const
{
    return QString(makename(MALICIOUSPLUGINNAME));
}

QContactManagerEngine* MaliciousEngineFactory::engine(const QMap<QString, QString>& parameters, QContactManager::Error* error)
{
    Q_UNUSED(parameters);
    *error = QContactManager::NoError;
    return new MaliciousAsyncManagerEngine();
}

#include "maliciousplugin.moc"
