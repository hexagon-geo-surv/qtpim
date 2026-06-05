// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause


#ifndef REQUESTEXAMPLE_H
#define REQUESTEXAMPLE_H

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

#include <QObject>

#include <QtContacts/qcontactrequests.h>

//! [Class setup]
QTCONTACTS_USE_NAMESPACE
class AsyncRequestExample : public QObject
{
    Q_OBJECT

public:
    AsyncRequestExample();
    ~AsyncRequestExample();

public slots:
    void performRequests();

private slots:
    void contactFetchRequestStateChanged(QContactAbstractRequest::State newState);
    void contactSaveRequestStateChanged(QContactAbstractRequest::State newState);
    void contactRemoveRequestStateChanged(QContactAbstractRequest::State newState);
    void relationshipFetchRequestStateChanged(QContactAbstractRequest::State newState);
    void relationshipSaveRequestStateChanged(QContactAbstractRequest::State newState);
    void relationshipRemoveRequestStateChanged(QContactAbstractRequest::State newState);

private:
    QContactManager *m_manager;
    QContactFetchRequest m_contactFetchRequest;
    QContactSaveRequest m_contactSaveRequest;
    QContactRemoveRequest m_contactRemoveRequest;
    QContactRelationshipFetchRequest m_relationshipFetchRequest;
    QContactRelationshipSaveRequest m_relationshipSaveRequest;
    QContactRelationshipRemoveRequest m_relationshipRemoveRequest;
};
//! [Class setup]

class RequestExample : public QObject
{
    Q_OBJECT

public:
    RequestExample()
            : QObject(),
            m_previousLastIndex(-1),
            m_manager(0),
            m_fetchRequest(new QContactFetchRequest)
    {
    }

    ~RequestExample()
    {
        delete m_fetchRequest;
    }

    void setManager(QContactManager* manager)
    {
        m_manager = manager;
        m_fetchRequest->setManager(m_manager);
    }

private slots:
    void performRequest();
    void printContacts();
    void stateChanged(QContactAbstractRequest::State state);

private:
    int m_previousLastIndex;
    QContactManager *m_manager;
    QContactFetchRequest *m_fetchRequest;
};

#endif
