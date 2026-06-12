// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QCONTACTMEMORYBACKEND_P_H
#define QCONTACTMEMORYBACKEND_P_H

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

#include <QtOrganizer/qorganizermanagerengine.h>
#include <QtOrganizer/qorganizermanagerenginefactory.h>
#include <QtOrganizer/qorganizercollectionchangeset.h>
#include <QtOrganizer/qorganizeritemchangeset.h>
#include <QtOrganizer/qorganizerrecurrencerule.h>

QT_BEGIN_NAMESPACE_ORGANIZER

class QOrganizerItemMemoryFactory : public QOrganizerManagerEngineFactory
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QOrganizerManagerEngineFactoryInterface" FILE "memory.json")

public:
    QOrganizerManagerEngine* engine(const QMap<QString, QString>& parameters, QOrganizerManager::Error*) override;
    QString managerName() const override;
};


class QOrganizerAbstractRequest;
class QOrganizerManagerEngine;
class QOrganizerItemMemoryEnginePrivate : public QSharedData
{
public:
    enum { DefaultCollectionLocalId = 1 }; // default collection has id of 1.

    QOrganizerItemMemoryEnginePrivate();
    ~QOrganizerItemMemoryEnginePrivate()
    {
    }

    QString m_id;                                  // the id parameter value

    QHash<QOrganizerItemId, QOrganizerItem> m_idToItemHash; // hash of id to the item identified by that id
    QMultiHash<QOrganizerItemId, QOrganizerItemId> m_parentIdToChildIdHash; // hash of id to that item's children's ids
    QHash<QOrganizerCollectionId, QOrganizerCollection> m_idToCollectionHash; // hash of id to the collection identified by that id
    QMultiHash<QOrganizerCollectionId, QOrganizerItemId> m_itemsInCollectionsHash; // hash of collection ids to the ids of items the collection contains.
    quint32 m_nextOrganizerItemId; // the localId() portion of a QOrganizerItemId
    quint32 m_nextOrganizerCollectionId; // the localId() portion of a QOrganizerCollectionId
    QString m_managerUri;                        // for faster lookup.

    void emitSharedSignals(QOrganizerCollectionChangeSet *cs)
    {
        for (QOrganizerManagerEngine *engine : std::as_const(m_sharedEngines))
            cs->emitSignals(engine);
    }
    void emitSharedSignals(QOrganizerItemChangeSet* cs)
    {
        for (QOrganizerManagerEngine *engine : std::as_const(m_sharedEngines))
            cs->emitSignals(engine);
    }

    QList<QOrganizerManagerEngine*> m_sharedEngines;   // The list of engines that share this data
};

class QOrganizerItemMemoryEngine : public QOrganizerManagerEngine
{
    Q_OBJECT

public:
    static QOrganizerItemMemoryEngine *createMemoryEngine(const QMap<QString, QString>& parameters);

    ~QOrganizerItemMemoryEngine();

    /* URI reporting */
    QString managerName() const override;
    QMap<QString, QString> managerParameters() const override;
    QMap<QString, QString> idInterpretationParameters() const override;

    // items
    QList<QOrganizerItem> items(const QList<QOrganizerItemId> &itemIds, const QOrganizerItemFetchHint &fetchHint,
                                QMap<int, QOrganizerManager::Error> *errorMap, QOrganizerManager::Error *error) override;

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

    bool removeItems(const QList<QOrganizerItem> *items, QMap<int, QOrganizerManager::Error>* errorMap,
                     QOrganizerManager::Error* error) override;

    // collections
    QOrganizerCollectionId defaultCollectionId() const override;
    QOrganizerCollection collection(const QOrganizerCollectionId &collectionId, QOrganizerManager::Error *error) const override;
    QList<QOrganizerCollection> collections(QOrganizerManager::Error* error) const override;
    bool saveCollection(QOrganizerCollection* collection, QOrganizerManager::Error* error) override;
    bool removeCollection(const QOrganizerCollectionId& collectionId, QOrganizerManager::Error* error) override;

    /* Asynchronous Request Support */
    void requestDestroyed(QOrganizerAbstractRequest* req) override;
    bool startRequest(QOrganizerAbstractRequest* req) override;
    bool cancelRequest(QOrganizerAbstractRequest* req) override;
    bool waitForRequestFinished(QOrganizerAbstractRequest* req, int msecs) override;

    /* Capabilities reporting */
    /*! \reimp */
    QList<QOrganizerItemFilter::FilterType> supportedFilters() const override
    {
        QList<QOrganizerItemFilter::FilterType> supported;

        supported << QOrganizerItemFilter::InvalidFilter
                  << QOrganizerItemFilter::DetailFilter
                  << QOrganizerItemFilter::DetailFieldFilter
                  << QOrganizerItemFilter::DetailRangeFilter
                  << QOrganizerItemFilter::IntersectionFilter
                  << QOrganizerItemFilter::UnionFilter
                  << QOrganizerItemFilter::IdFilter
                  << QOrganizerItemFilter::CollectionFilter
                  << QOrganizerItemFilter::DefaultFilter;

        return supported;
    }
    /*! \reimp */
    QList<QOrganizerItemDetail::DetailType> supportedItemDetails(QOrganizerItemType::ItemType itemType) const override;

    /*! \reimp */
    QList<QOrganizerItemType::ItemType> supportedItemTypes() const override
    {
        return QList<QOrganizerItemType::ItemType>() << QOrganizerItemType::TypeEvent
                             << QOrganizerItemType::TypeEventOccurrence
                             << QOrganizerItemType::TypeJournal
                             << QOrganizerItemType::TypeNote
                             << QOrganizerItemType::TypeTodo
                             << QOrganizerItemType::TypeTodoOccurrence;
    }

protected:
    QOrganizerItemMemoryEngine(QOrganizerItemMemoryEnginePrivate* data);

protected:
    /* Implement "signal coalescing" for batch functions via change set */
    virtual bool storeItem(QOrganizerItem* theOrganizerItem, QOrganizerItemChangeSet& changeSet, const QList<QOrganizerItemDetail::DetailType> &detailMask, QOrganizerManager::Error* error);
    virtual bool removeItem(const QOrganizerItemId& organizeritemId, QOrganizerItemChangeSet& changeSet, QOrganizerManager::Error* error);
    virtual bool removeOccurrence(const QOrganizerItem& organizeritem, QOrganizerItemChangeSet& changeSet, QOrganizerManager::Error* error);

private:
    QOrganizerItem item(const QOrganizerItemId& organizeritemId) const;
    bool storeItems(QList<QOrganizerItem>* organizeritems, const QList<QOrganizerItemDetail::DetailType> &detailMask, QMap<int, QOrganizerManager::Error>* errorMap, QOrganizerManager::Error* error);
    QList<QOrganizerItem> itemsForExport(const QList<QOrganizerItemId> &ids, const QOrganizerItemFetchHint &fetchHint, QMap<int, QOrganizerManager::Error> *errorMap, QOrganizerManager::Error *error);
    QList<QOrganizerItem> internalItems(const QDateTime& startDate, const QDateTime& endDate, const QOrganizerItemFilter& filter, const QList<QOrganizerItemSortOrder>& sortOrders, const QOrganizerItemFetchHint& fetchHint, QOrganizerManager::Error* error, bool forExport) const;
    QList<QOrganizerItem> internalItemOccurrences(const QOrganizerItem& parentItem, const QDateTime& periodStart, const QDateTime& periodEnd, int maxCount, bool includeExceptions, bool sortItems, QList<QDate> *exceptionDates, QOrganizerManager::Error* error) const;
    void addItemRecurrences(QList<QOrganizerItem>& sorted, const QOrganizerItem& c, const QDateTime& startDate, const QDateTime& endDate, const QOrganizerItemFilter& filter, const QList<QOrganizerItemSortOrder>& sortOrders, bool forExport, QSet<QOrganizerItemId>* parentsAdded) const;

    bool fixOccurrenceReferences(QOrganizerItem* item, QOrganizerManager::Error* error);
    bool typesAreRelated(QOrganizerItemType::ItemType occurrenceType, QOrganizerItemType::ItemType parentType);

    void performAsynchronousOperation(QOrganizerAbstractRequest* request);

    QOrganizerItemMemoryEnginePrivate* d;
};

QT_END_NAMESPACE_ORGANIZER

#endif // QCONTACTMEMORYBACKEND_P_H
