// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

#ifndef QORGANIZERMALICIOUSPLUGIN_P_H
#define QORGANIZERMALICIOUSPLUGIN_P_H

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

#include <QtOrganizer/qorganizermanager.h>
#include <QtOrganizer/qorganizermanagerengine.h>
#include <QtOrganizer/qorganizermanagerenginefactory.h>

QT_FORWARD_DECLARE_CLASS(QThread)

QTORGANIZER_USE_NAMESPACE

class MaliciousThreadObject;
class MaliciousAsyncManagerEngine : public QOrganizerManagerEngine
{
    Q_OBJECT

public:
    MaliciousAsyncManagerEngine();
    ~MaliciousAsyncManagerEngine();

    QString managerName() const override;
    bool startRequest(QOrganizerAbstractRequest *req) override;
    bool cancelRequest(QOrganizerAbstractRequest *req) override;

    QMap<QString, QString> managerParameters() const override { return QMap<QString, QString>(); }
    int managerVersion() const { return 0; }

    // items
    QList<QOrganizerItem> items(const QList<QOrganizerItemId> &itemIds, const QOrganizerItemFetchHint &fetchHint,
                                           QMap<int, QOrganizerManager::Error> *errorMap, QOrganizerManager::Error *error) override
    {
        return QOrganizerManagerEngine::items(itemIds, fetchHint, errorMap, error);
    }

    QList<QOrganizerItem> items(const QOrganizerItemFilter &filter, const QDateTime &startDateTime,
                                           const QDateTime &endDateTime, int maxCount,
                                           const QList<QOrganizerItemSortOrder> &sortOrders,
                                           const QOrganizerItemFetchHint &fetchHint, QOrganizerManager::Error *error) override
    {
        return QOrganizerManagerEngine::items(filter, startDateTime, endDateTime, maxCount, sortOrders, fetchHint, error);
    }

    QList<QOrganizerItemId> itemIds(const QOrganizerItemFilter &filter, const QDateTime &startDateTime,
                                               const QDateTime &endDateTime, const QList<QOrganizerItemSortOrder> &sortOrders,
                                               QOrganizerManager::Error *error) override
    {
        return QOrganizerManagerEngine::itemIds(filter, startDateTime, endDateTime, sortOrders, error);
    }

    QList<QOrganizerItem> itemOccurrences(const QOrganizerItem &parentItem, const QDateTime &startDateTime,
                                                     const QDateTime &endDateTime, int maxCount,
                                                     const QOrganizerItemFetchHint &fetchHint, QOrganizerManager::Error *error) override
    {
        return QOrganizerManagerEngine::itemOccurrences(parentItem, startDateTime, endDateTime, maxCount, fetchHint, error);
    }

    QList<QOrganizerItem> itemsForExport(const QDateTime &startDateTime, const QDateTime &endDateTime,
                                                    const QOrganizerItemFilter &filter,
                                                    const QList<QOrganizerItemSortOrder> &sortOrders,
                                                    const QOrganizerItemFetchHint &fetchHint, QOrganizerManager::Error *error) override
    {
        return QOrganizerManagerEngine::itemsForExport(startDateTime, endDateTime, filter, sortOrders, fetchHint, error);
    }

    bool saveItems(QList<QOrganizerItem> *items, const QList<QOrganizerItemDetail::DetailType> &detailMask,
                              QMap<int, QOrganizerManager::Error> *errorMap, QOrganizerManager::Error *error) override
    {
        return QOrganizerManagerEngine::saveItems(items, detailMask, errorMap, error);
    }

    bool removeItems(const QList<QOrganizerItemId> &itemIds, QMap<int, QOrganizerManager::Error> *errorMap, QOrganizerManager::Error *error) override
    {
        return QOrganizerManagerEngine::removeItems(itemIds, errorMap, error);
    }

    bool removeItems(const QList<QOrganizerItem> *items, QMap<int, QOrganizerManager::Error> *errorMap, QOrganizerManager::Error *error) override
    {
        return QOrganizerManagerEngine::removeItems(items, errorMap, error);
    }

    // collections
    QOrganizerCollectionId defaultCollectionId() const override
    {
        return QOrganizerManagerEngine::defaultCollectionId();
    }

    QOrganizerCollection collection(const QOrganizerCollectionId &collectionId, QOrganizerManager::Error *error) override
    {
        return QOrganizerManagerEngine::collection(collectionId, error);
    }

    QList<QOrganizerCollection> collections(QOrganizerManager::Error *error) override
    {
        return QOrganizerManagerEngine::collections(error);
    }

    bool saveCollection(QOrganizerCollection *collection, QOrganizerManager::Error *error) override
    {
        return QOrganizerManagerEngine::saveCollection(collection, error);
    }

    bool removeCollection(const QOrganizerCollectionId &collectionId, QOrganizerManager::Error *error) override
    {
        return QOrganizerManagerEngine::removeCollection(collectionId, error);
    }

    /* Asynchronous Request Support */
    void requestDestroyed(QOrganizerAbstractRequest *req) override;
    bool waitForRequestFinished(QOrganizerAbstractRequest *req, int msecs) override { return QOrganizerManagerEngine::waitForRequestFinished(req, msecs); }

    QList<QOrganizerItemFilter::FilterType> supportedFilters() const override
    {
        return QOrganizerManagerEngine::supportedFilters();
    }

    QList<QOrganizerItemType::ItemType> supportedItemTypes() const override
    {
        return QOrganizerManagerEngine::supportedItemTypes();
    }
    QList<QOrganizerItemDetail::DetailType> supportedItemDetails(QOrganizerItemType::ItemType itemType) const override
    {
        return QOrganizerManagerEngine::supportedItemDetails(itemType);
    }

signals:
    void doStartRequest(QOrganizerAbstractRequest *req);
    void doFinishRequest(QOrganizerAbstractRequest *req);

private:
    QThread *thread;
    MaliciousThreadObject *threadObject;
};


class MaliciousEngineFactory : public QOrganizerManagerEngineFactory
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QOrganizerManagerEngineFactoryInterface" FILE "malicious.json")

public:
    QString managerName() const override;
    QOrganizerManagerEngine *engine(const QMap<QString, QString> &parameters, QOrganizerManager::Error *error) override;

private:
    MaliciousAsyncManagerEngine mame;
};

#endif // QORGANIZERMALICIOUSPLUGIN_P_H
