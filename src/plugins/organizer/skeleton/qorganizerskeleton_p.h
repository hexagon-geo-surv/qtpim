// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QORGANIZERSKELETON_P_H
#define QORGANIZERSKELETON_P_H

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

#include <QtCore/qdatetime.h>
#include <QtCore/qlist.h>
#include <QtCore/qmap.h>
#include <QtCore/qobject.h>
#include <QtCore/qpair.h>
#include <QtCore/qqueue.h>
#include <QtCore/qset.h>
#include <QtCore/qshareddata.h>
#include <QtCore/qstring.h>

#include <QtOrganizer/qorganizeritem.h>
#include <QtOrganizer/qorganizermanager.h>
#include <QtOrganizer/qorganizermanagerengine.h>
#include <QtOrganizer/qorganizermanagerenginefactory.h>
#include <QtOrganizer/qorganizerabstractrequest.h>

QT_BEGIN_NAMESPACE_ORGANIZER

class QOrganizerItemSkeletonFactory : public QOrganizerManagerEngineFactory
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QOrganizerManagerEngineFactoryInterface" FILE "skeleton.json")

public:
    QOrganizerManagerEngine* engine(const QMap<QString, QString>& parameters, QOrganizerManager::Error*) override;
    QString managerName() const override;
};


class QOrganizerItemSkeletonEngineData : public QSharedData
{
public:
    QOrganizerItemSkeletonEngineData()
        : QSharedData()
    {
    }

    QOrganizerItemSkeletonEngineData(const QOrganizerItemSkeletonEngineData& other)
        : QSharedData(other)
    {
    }

    ~QOrganizerItemSkeletonEngineData()
    {
    }
};

class QOrganizerItemSkeletonEngine : public QOrganizerManagerEngine
{
    Q_OBJECT

public:
    static QOrganizerItemSkeletonEngine *createSkeletonEngine(const QMap<QString, QString>& parameters);

    ~QOrganizerItemSkeletonEngine();

    /* URI reporting */
    QString managerName() const override;
    QMap<QString, QString> managerParameters() const override;

    // items
    QList<QOrganizerItem> items(const QList<QOrganizerItemId> &itemIds, const QOrganizerItemFetchHint &fetchHint,
                                QMap<int, QOrganizerManager::Error> *errorMap, QOrganizerManager::Error* error) override;

    QList<QOrganizerItem> items(const QOrganizerItemFilter &filter, const QDateTime &startDateTime,
                                const QDateTime &endDateTime, int maxCount,
                                const QList<QOrganizerItemSortOrder> &sortOrders,
                                const QOrganizerItemFetchHint &fetchHint, QOrganizerManager::Error *error) override;

    QList<QOrganizerItemId> itemIds(const QOrganizerItemFilter &filter, const QDateTime &startDateTime,
                                    const QDateTime &endDateTime, const QList<QOrganizerItemSortOrder> &sortOrders,
                                    QOrganizerManager::Error *error) override;

    QList<QOrganizerItem> itemOccurrences(const QOrganizerItem &parentItem, const QDateTime &startDateTime,
                                          const QDateTime &endDateTime, int maxCount,
                                          const QOrganizerItemFetchHint &fetchHint, QOrganizerManager::Error *error) override;

    QList<QOrganizerItem> itemsForExport(const QDateTime &startDateTime, const QDateTime &endDateTime,
                                         const QOrganizerItemFilter &filter,
                                         const QList<QOrganizerItemSortOrder> &sortOrders,
                                         const QOrganizerItemFetchHint &fetchHint, QOrganizerManager::Error *error) override;

    bool saveItems(QList<QOrganizerItem> *items, const QList<QOrganizerItemDetail::DetailType> &detailMask,
                   QMap<int, QOrganizerManager::Error> *errorMap, QOrganizerManager::Error *error) override;

    bool removeItems(const QList<QOrganizerItemId> &itemIds, QMap<int, QOrganizerManager::Error> *errorMap,
                     QOrganizerManager::Error *error) override;

    // collections
    QOrganizerCollectionId defaultCollectionId() const override;
    QOrganizerCollection collection(const QOrganizerCollectionId& collectionId, QOrganizerManager::Error* error) const override;
    QList<QOrganizerCollection> collections(QOrganizerManager::Error* error) const override;
    bool saveCollection(QOrganizerCollection* collection, QOrganizerManager::Error* error) override;
    bool removeCollection(const QOrganizerCollectionId& collectionId, QOrganizerManager::Error* error) override;

    /* Capabilities reporting */
    QList<QOrganizerItemFilter::FilterType> supportedFilters() const override;
    QList<QOrganizerItemDetail::DetailType> supportedItemDetails(QOrganizerItemType::ItemType itemType) const override;
    QList<QOrganizerItemType::ItemType> supportedItemTypes() const override;

    /* Asynchronous Request Support */
    void requestDestroyed(QOrganizerAbstractRequest* req) override;
    bool startRequest(QOrganizerAbstractRequest* req) override;
    bool cancelRequest(QOrganizerAbstractRequest* req) override;
    bool waitForRequestFinished(QOrganizerAbstractRequest* req, int msecs) override;

private:
    QOrganizerItemSkeletonEngineData* d;

    friend class QOrganizerItemSkeletonFactory;
};

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERSKELETON_P_H
