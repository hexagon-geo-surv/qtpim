// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QCONTACTREQUESTS_P_H
#define QCONTACTREQUESTS_P_H

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

#ifndef QT_NO_DEBUG_STREAM
#include <QtCore/qdebug.h>
#endif
#include <QtCore/qmap.h>
#include <QtCore/qstringlist.h>

#include <QtContacts/qcontact.h>
#include <QtContacts/qcontactdetail.h>
#include <QtContacts/qcontactfetchhint.h>
#include <QtContacts/qcontactfilter.h>
#include <QtContacts/qcontactrelationshipfilter.h>
#include <QtContacts/qcontactsortorder.h>
#include <QtContacts/private/qcontactabstractrequest_p.h>

QT_BEGIN_NAMESPACE_CONTACTS

class QContactSaveRequestPrivate : public QContactAbstractRequestPrivate
{
public:
    QContactSaveRequestPrivate()
        : QContactAbstractRequestPrivate(QContactAbstractRequest::ContactSaveRequest)
    {
    }

    ~QContactSaveRequestPrivate()
    {
    }

#ifndef QT_NO_DEBUG_STREAM
    QDebug& debugStreamOut(QDebug& dbg) const override
    {
        dbg.nospace() << "QContactSaveRequest(";
        dbg.nospace() << "contacts=" << m_contacts << ","
                      << "typeMask=" << m_typeMask << ","
                      << "errorMap=" << m_errors;
        dbg.nospace() << ")";
        return dbg.maybeSpace();
    }
#endif

    QList<QContact> m_contacts;
    QMap<int, QContactManager::Error> m_errors;
    QList<QContactDetail::DetailType> m_typeMask;
};

class QContactFetchRequestPrivate : public QContactAbstractRequestPrivate
{
public:
    QContactFetchRequestPrivate()
        : QContactAbstractRequestPrivate(QContactAbstractRequest::ContactFetchRequest)
    {
    }

    ~QContactFetchRequestPrivate()
    {
    }

#ifndef QT_NO_DEBUG_STREAM
    QDebug& debugStreamOut(QDebug& dbg) const override
    {
        dbg.nospace() << "QContactFetchRequest("
                      << "filter=" << m_filter << ","
                      << "sorting=" << m_sorting << ","
                      << "fetchHint=" << m_fetchHint;
        dbg.nospace() << ")";
        return dbg.maybeSpace();
    }
#endif

    QContactFilter m_filter;
    QList<QContactSortOrder> m_sorting;
    QContactFetchHint m_fetchHint;

    QList<QContact> m_contacts;
};

class QContactFetchByIdRequestPrivate : public QContactAbstractRequestPrivate
{
public:
    QContactFetchByIdRequestPrivate()
        : QContactAbstractRequestPrivate(QContactAbstractRequest::ContactFetchByIdRequest)
    {
    }

    ~QContactFetchByIdRequestPrivate()
    {
    }

#ifndef QT_NO_DEBUG_STREAM
    QDebug& debugStreamOut(QDebug& dbg) const override
    {
        dbg.nospace() << "QContactFetchByIdRequest(\n"
                      << "* contactIds=" << m_contactIds << ",\n"
                      << "* contacts=" << m_contacts << ",\n"
                      << "* fetchHint=" << m_fetchHint << ",\n"
                      << "* errorMap=" << m_errors;
        dbg.nospace() << "\n)";
        return dbg.maybeSpace();
    }
#endif

    QList<QContactId> m_contactIds;
    QContactFetchHint m_fetchHint;

    QList<QContact> m_contacts;
    QMap<int, QContactManager::Error> m_errors;
};

class QContactRemoveRequestPrivate : public QContactAbstractRequestPrivate
{
public:
    QContactRemoveRequestPrivate()
        : QContactAbstractRequestPrivate(QContactAbstractRequest::ContactRemoveRequest)
    {
    }

    ~QContactRemoveRequestPrivate()
    {
    }

#ifndef QT_NO_DEBUG_STREAM
    QDebug& debugStreamOut(QDebug& dbg) const override
    {
        dbg.nospace() << "QContactRemoveRequest("
                      << "contactIds=" << m_contactIds << ","
                      << "errorMap=" << m_errors;
        dbg.nospace() << ")";
        return dbg.maybeSpace();
    }
#endif

    QList<QContactId> m_contactIds;
    QMap<int, QContactManager::Error> m_errors;
};

class QContactIdFetchRequestPrivate : public QContactAbstractRequestPrivate
{
public:
    QContactIdFetchRequestPrivate()
        : QContactAbstractRequestPrivate(QContactAbstractRequest::ContactIdFetchRequest)
    {
    }

    ~QContactIdFetchRequestPrivate()
    {
    }

#ifndef QT_NO_DEBUG_STREAM
    QDebug& debugStreamOut(QDebug& dbg) const override
    {
        dbg.nospace() << "QContactIdFetchRequest("
                      << "filter=" << m_filter << ","
                      << "sorting=" << m_sorting << ","
                      << "ids=" << m_ids;
        dbg.nospace() << ")";
        return dbg.maybeSpace();
    }
#endif

    QContactFilter m_filter;
    QList<QContactSortOrder> m_sorting;

    QList<QContactId> m_ids;
};

class QContactRelationshipFetchRequestPrivate : public QContactAbstractRequestPrivate
{
public:
    QContactRelationshipFetchRequestPrivate()
        : QContactAbstractRequestPrivate(QContactAbstractRequest::RelationshipFetchRequest)
    {
    }

    ~QContactRelationshipFetchRequestPrivate()
    {
    }

#ifndef QT_NO_DEBUG_STREAM
    QDebug& debugStreamOut(QDebug& dbg) const override
    {
        dbg.nospace() << "QContactRelationshipFetchRequest("
                      << "first=" << m_first << ","
                      << "second=" << m_second << ","
                      << "relationshipType=" << m_relationshipType << ","
                      << "relationships=" << m_relationships;
        dbg.nospace() << ")";
        return dbg.maybeSpace();
    }
#endif

    // selection criteria
    QContactId m_first;
    QContactId m_second;
    QString m_relationshipType;

    // results
    QList<QContactRelationship> m_relationships;
};

class QContactRelationshipSaveRequestPrivate : public QContactAbstractRequestPrivate
{
public:
    QContactRelationshipSaveRequestPrivate()
        : QContactAbstractRequestPrivate(QContactAbstractRequest::RelationshipSaveRequest)
    {
    }

    ~QContactRelationshipSaveRequestPrivate()
    {
    }

#ifndef QT_NO_DEBUG_STREAM
    QDebug& debugStreamOut(QDebug& dbg) const override
    {
        dbg.nospace() << "QContactRelationshipSaveRequest("
                      << "relationships=" << m_relationships << ","
                      << "errorMap=" << m_errors;
        dbg.nospace() << ")";
        return dbg.maybeSpace();
    }
#endif

    QList<QContactRelationship> m_relationships;
    QMap<int, QContactManager::Error> m_errors;
};

class QContactRelationshipRemoveRequestPrivate : public QContactAbstractRequestPrivate
{
public:
    QContactRelationshipRemoveRequestPrivate()
        : QContactAbstractRequestPrivate(QContactAbstractRequest::RelationshipRemoveRequest)
    {
    }

    ~QContactRelationshipRemoveRequestPrivate()
    {
    }

#ifndef QT_NO_DEBUG_STREAM
    QDebug& debugStreamOut(QDebug& dbg) const override
    {
        dbg.nospace() << "QContactRelationshipRemoveRequest("
                      << "relationships=" << m_relationships << ","
                      << "errorMap=" << m_errors;
        dbg.nospace() << ")";
        return dbg.maybeSpace();
    }
#endif

    QList<QContactRelationship> m_relationships;
    QMap<int, QContactManager::Error> m_errors;
};

class QContactCollectionFetchRequestPrivate : public QContactAbstractRequestPrivate
{
public:
    QContactCollectionFetchRequestPrivate()
        : QContactAbstractRequestPrivate(QContactAbstractRequest::CollectionFetchRequest)
    {
    }

    ~QContactCollectionFetchRequestPrivate()
    {
    }

#ifndef QT_NO_DEBUG_STREAM
    QDebug& debugStreamOut(QDebug &dbg) const override
    {
        dbg.nospace() << "QContactCollectionFetchRequestPrivate(";
        dbg.nospace() << "collections=";
        dbg.nospace() << m_collections;
        dbg.nospace() << ")";
        return dbg.maybeSpace();
    }
#endif

    QList<QContactCollection> m_collections;
};

class QContactCollectionRemoveRequestPrivate : public QContactAbstractRequestPrivate
{
public:
    QContactCollectionRemoveRequestPrivate()
        : QContactAbstractRequestPrivate(QContactAbstractRequest::CollectionRemoveRequest)
    {
    }

    ~QContactCollectionRemoveRequestPrivate()
    {
    }

#ifndef QT_NO_DEBUG_STREAM
    QDebug& debugStreamOut(QDebug &dbg) const override
    {
        dbg.nospace() << "QContactCollectionRemoveRequestPrivate(";
        dbg.nospace() << "collectionIds=";
        dbg.nospace() << m_collectionIds;
        dbg.nospace() << ",";
        dbg.nospace() << "errorMap=";
        dbg.nospace() << m_errors;
        dbg.nospace() << ")";
        return dbg.maybeSpace();
    }
#endif

    QList<QContactCollectionId> m_collectionIds;
    QMap<int, QContactManager::Error> m_errors;
};

class QContactCollectionSaveRequestPrivate : public QContactAbstractRequestPrivate
{
public:
    QContactCollectionSaveRequestPrivate()
        : QContactAbstractRequestPrivate(QContactAbstractRequest::CollectionSaveRequest)
    {
    }

    ~QContactCollectionSaveRequestPrivate()
    {
    }

#ifndef QT_NO_DEBUG_STREAM
    QDebug& debugStreamOut(QDebug &dbg) const override
    {
        dbg.nospace() << "QContactCollectionSaveRequestPrivate(";
        dbg.nospace() << "collections=";
        dbg.nospace() << m_collections;
        dbg.nospace() << ",";
        dbg.nospace() << "errorMap=";
        dbg.nospace() << m_errors;
        dbg.nospace() << ")";
        return dbg.maybeSpace();
    }
#endif

    QList<QContactCollection> m_collections;
    QMap<int, QContactManager::Error> m_errors;
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTREQUESTS_P_H
