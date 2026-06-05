// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QORGANIZERMANAGER_H
#define QORGANIZERMANAGER_H

#include <QtCore/qdatetime.h>
#include <QtCore/qlist.h>
#include <QtCore/qmap.h>
#include <QtCore/qobject.h>
#include <utility>
#include <QtCore/qstringlist.h>

#include <QtOrganizer/qorganizercollection.h>
#include <QtOrganizer/qorganizeritem.h>
#include <QtOrganizer/qorganizeritemfilter.h>
#include <QtOrganizer/qorganizeritemfetchhint.h>
#include <QtOrganizer/qorganizeritemsortorder.h>

QT_BEGIN_NAMESPACE_ORGANIZER

class QOrganizerManagerData;

class Q_ORGANIZER_EXPORT QOrganizerManager : public QObject
{
    Q_OBJECT

public:
#ifdef Q_QDOC // qdoc's parser fails to recognize the default map argument
    explicit QOrganizerManager(const QString &managerName, const QMap<QString, QString> &parameters = 0, QObject *parent = nullptr);
#else
    explicit QOrganizerManager(const QString &managerName, const QMap<QString, QString> &parameters = (QMap<QString, QString>()), QObject *parent = nullptr);
#endif
    explicit QOrganizerManager(QObject *parent = nullptr);
    ~QOrganizerManager();

    static QOrganizerManager *fromUri(const QString &uri, QObject *parent = nullptr);
    static QStringList availableManagers();

    QString managerName() const;
    QMap<QString, QString> managerParameters() const;
    int managerVersion() const;
    QString managerUri() const;

    static bool parseUri(const QString &uri, QString *managerName, QMap<QString, QString> *params);
    static QString buildUri(const QString &managerName, const QMap<QString, QString> &params);

    // error reporting
    enum Error {
        NoError = 0,
        DoesNotExistError,
        AlreadyExistsError,
        InvalidDetailError,
        LockedError,
        DetailAccessError,
        PermissionsError,
        OutOfMemoryError,
        NotSupportedError,
        BadArgumentError,
        UnspecifiedError,
        LimitReachedError,
        InvalidItemTypeError,
        InvalidCollectionError,
        InvalidOccurrenceError,
        TimeoutError
    };

    enum Operation {
        Add,
        Change,
        Remove
    };

    /* Error reporting */
    QOrganizerManager::Error error() const;
    QMap<int, QOrganizerManager::Error> errorMap() const;

    // items
    QOrganizerItem item(const QOrganizerItemId &itemId, const QOrganizerItemFetchHint &fetchHint = QOrganizerItemFetchHint());

    QList<QOrganizerItem> items(const QList<QOrganizerItemId> &itemIds, const QOrganizerItemFetchHint &fetchHint = QOrganizerItemFetchHint());

    QList<QOrganizerItem> items(const QDateTime &startDateTime = QDateTime(), const QDateTime &endDateTime = QDateTime(),
                                const QOrganizerItemFilter &filter = QOrganizerItemFilter(), int maxCount = -1,
                                const QList<QOrganizerItemSortOrder> &sortOrders = QList<QOrganizerItemSortOrder>(),
                                const QOrganizerItemFetchHint &fetchHint = QOrganizerItemFetchHint());

    QList<QOrganizerItemId> itemIds(const QDateTime &startDateTime = QDateTime(), const QDateTime &endDateTime = QDateTime(),
                                    const QOrganizerItemFilter &filter = QOrganizerItemFilter(),
                                    const QList<QOrganizerItemSortOrder> &sortOrders = QList<QOrganizerItemSortOrder>());

    QList<QOrganizerItem> itemOccurrences(const QOrganizerItem &parentItem, const QDateTime &startDateTime = QDateTime(),
                                          const QDateTime &endDateTime = QDateTime(), int maxCount = -1,
                                          const QOrganizerItemFetchHint &fetchHint = QOrganizerItemFetchHint());

    QList<QOrganizerItem> itemsForExport(const QDateTime &startDateTime = QDateTime(), const QDateTime &endDateTime = QDateTime(),
                                         const QOrganizerItemFilter &filter = QOrganizerItemFilter(),
                                         const QList<QOrganizerItemSortOrder> &sortOrders = QList<QOrganizerItemSortOrder>(),
                                         const QOrganizerItemFetchHint &fetchHint = QOrganizerItemFetchHint());

    bool saveItem(QOrganizerItem *item, const QList<QOrganizerItemDetail::DetailType> &detailMask = QList<QOrganizerItemDetail::DetailType>());

    bool saveItems(QList<QOrganizerItem> *items,
                   const QList<QOrganizerItemDetail::DetailType> &detailMask = QList<QOrganizerItemDetail::DetailType>());

    bool removeItem(const QOrganizerItemId &itemId);

    bool removeItem(const QOrganizerItem *item);

    bool removeItems(const QList<QOrganizerItemId>& itemIds);

    bool removeItems(const QList<QOrganizerItem> *items);

    // collections
    QOrganizerCollectionId defaultCollectionId() const;
    QOrganizerCollection collection(const QOrganizerCollectionId& collectionId) const;
    QList<QOrganizerCollection> collections() const;
    bool saveCollection(QOrganizerCollection* collection);
    bool removeCollection(const QOrganizerCollectionId& collectionId);

    // functionality reporting
    QList<QOrganizerItemFilter::FilterType> supportedFilters() const;
    QList<QOrganizerItemDetail::DetailType> supportedItemDetails(QOrganizerItemType::ItemType itemType) const;
    QList<QOrganizerItemType::ItemType> supportedItemTypes() const;

    // helper
    static QList<QOrganizerItemId> extractIds(const QList<QOrganizerItem> &items);

Q_SIGNALS:
    void dataChanged();
    void itemsAdded(const QList<QOrganizerItemId> &itemIds);
    void itemsChanged(const QList<QOrganizerItemId> &itemIds, const QList<QOrganizerItemDetail::DetailType> &typesChanged);
    void itemsRemoved(const QList<QOrganizerItemId> &itemIds);
    void itemsModified(const QList<std::pair<QOrganizerItemId, QOrganizerManager::Operation>> &itemIds);
    void collectionsAdded(const QList<QOrganizerCollectionId> &collectionIds);
    void collectionsChanged(const QList<QOrganizerCollectionId> &collectionIds);
    void collectionsRemoved(const QList<QOrganizerCollectionId> &collectionIds);
    void collectionsModified(const QList<std::pair<QOrganizerCollectionId, QOrganizerManager::Operation>> &collectionIds);

private:
    friend class QOrganizerManagerData;
    Q_DISABLE_COPY(QOrganizerManager)
    QOrganizerManagerData *d;

    void createEngine(const QString &managerName, const QMap<QString, QString> &parameters);

    Q_PRIVATE_SLOT(d, void _q_itemsUpdated(const QList<QOrganizerItemId> &ids, const QList<QOrganizerItemDetail::DetailType> &typesChanged))
    Q_PRIVATE_SLOT(d, void _q_itemsDeleted(const QList<QOrganizerItemId> &ids))
};

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERMANAGER_H
