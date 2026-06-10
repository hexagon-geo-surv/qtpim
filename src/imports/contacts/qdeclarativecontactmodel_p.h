// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QDECLARATIVECONTACTMODEL_P_H
#define QDECLARATIVECONTACTMODEL_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.
// This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <QtCore/qabstractitemmodel.h>

#include <QtQml/qqml.h>

#include <QtContacts/qcontact.h>
#include <QtContacts/qcontactrequests.h>

#include <QtVersit/qversitreader.h>
#include <QtVersit/qversitwriter.h>

#include "qdeclarativecontact_p.h"
#include "qdeclarativecontactcollection_p.h"
#include "qdeclarativecontactfetchhint_p.h"
#include "qdeclarativecontactfilter_p.h"
#include "qdeclarativecontactsortorder_p.h"

QTCONTACTS_USE_NAMESPACE
QTVERSIT_USE_NAMESPACE

QT_BEGIN_NAMESPACE

class QDeclarativeContactModelPrivate;
class QDeclarativeContactModel : public QAbstractListModel, public QQmlParserStatus
{
    Q_OBJECT
    Q_PROPERTY(QString manager READ manager WRITE setManager NOTIFY managerChanged)
    Q_PROPERTY(QStringList availableManagers READ availableManagers)
    Q_PROPERTY(QString error READ error NOTIFY errorChanged)
    Q_PROPERTY(bool autoUpdate READ autoUpdate WRITE setAutoUpdate NOTIFY autoUpdateChanged)
    Q_PROPERTY(QDeclarativeContactFilter* filter READ filter WRITE setFilter NOTIFY filterChanged)
    Q_PROPERTY(QDeclarativeContactFetchHint* fetchHint READ fetchHint WRITE setFetchHint NOTIFY fetchHintChanged)
    Q_PROPERTY(QQmlListProperty<QDeclarativeContact> contacts READ contacts NOTIFY contactsChanged)
    Q_PROPERTY(QQmlListProperty<QDeclarativeContactCollection> collections READ collections NOTIFY collectionsChanged)
    Q_PROPERTY(QQmlListProperty<QDeclarativeContactSortOrder> sortOrders READ sortOrders NOTIFY sortOrdersChanged)
    Q_ENUMS(ExportError)
    Q_ENUMS(ImportError)
    Q_INTERFACES(QQmlParserStatus)

public:
    explicit QDeclarativeContactModel(QObject *parent = Q_NULLPTR);
    ~QDeclarativeContactModel();

    enum {
        ContactRole =  Qt::UserRole + 500
    };

    enum ExportError {
        ExportNoError          = QVersitWriter::NoError,
        ExportUnspecifiedError = QVersitWriter::UnspecifiedError,
        ExportIOError          = QVersitWriter::IOError,
        ExportOutOfMemoryError = QVersitWriter::OutOfMemoryError,
        ExportNotReadyError    = QVersitWriter::NotReadyError
    };

    enum ImportError {
        ImportNoError          = QVersitReader::NoError,
        ImportUnspecifiedError = QVersitReader::UnspecifiedError,
        ImportIOError          = QVersitReader::IOError,
        ImportOutOfMemoryError = QVersitReader::OutOfMemoryError,
        ImportNotReadyError    = QVersitReader::NotReadyError,
        ImportParseError       = QVersitReader::ParseError
    };

    QString manager() const;
    void setManager(const QString& manager);

    QStringList availableManagers() const;

    QString error() const;

    QDeclarativeContactFilter* filter() const;
    void setFilter(QDeclarativeContactFilter* filter);

    QDeclarativeContactFetchHint* fetchHint() const;
    void setFetchHint(QDeclarativeContactFetchHint* fetchHint);

    // From QQmlParserStatus
    void classBegin() override {}
    void componentComplete() override;

    // From QAbstractListModel
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

    bool autoUpdate() const;
    void setAutoUpdate(bool autoUpdate);

    QQmlListProperty<QDeclarativeContact> contacts() ;
    static void contacts_append(QQmlListProperty<QDeclarativeContact>* prop, QDeclarativeContact* contact);
    static qsizetype contacts_count(QQmlListProperty<QDeclarativeContact>* prop);
    static QDeclarativeContact* contacts_at(QQmlListProperty<QDeclarativeContact>* prop, qsizetype index);
    static void contacts_clear(QQmlListProperty<QDeclarativeContact>* prop);

    QQmlListProperty<QDeclarativeContactSortOrder> sortOrders();
    static void sortOrder_append(QQmlListProperty<QDeclarativeContactSortOrder> *p, QDeclarativeContactSortOrder *sortOrder);
    static qsizetype sortOrder_count(QQmlListProperty<QDeclarativeContactSortOrder> *p);
    static QDeclarativeContactSortOrder * sortOrder_at(QQmlListProperty<QDeclarativeContactSortOrder> *p, qsizetype idx);
    static void  sortOrder_clear(QQmlListProperty<QDeclarativeContactSortOrder> *p);

    QQmlListProperty<QDeclarativeContactCollection> collections();
    static qsizetype collection_count(QQmlListProperty<QDeclarativeContactCollection> *p);
    static QDeclarativeContactCollection* collection_at(QQmlListProperty<QDeclarativeContactCollection> *p, qsizetype idx);

    Q_INVOKABLE void removeContact(QString id);
    Q_INVOKABLE void removeContacts(const QStringList& ids);
    Q_INVOKABLE void saveContact(QDeclarativeContact* dc);
    Q_INVOKABLE int fetchContacts(const QStringList& contactIds);
    Q_INVOKABLE void removeCollection(const QString& collectionId);
    Q_INVOKABLE void saveCollection(QDeclarativeContactCollection* collection);
    // FIXME : Naming indicates fetch from database
    Q_INVOKABLE void fetchCollections();
    Q_INVOKABLE void importContacts(const QUrl& url, const QStringList& profiles = QStringList());
    Q_INVOKABLE void exportContacts(const QUrl& url, const QStringList& profiles = QStringList(), const QVariantList &declarativeContacts = QVariantList());

signals:
    void managerChanged();
    void filterChanged();
    void errorChanged();
    void fetchHintChanged();
    void contactsChanged();
    void collectionsChanged();
    void sortOrdersChanged();
    void autoUpdateChanged();
    void exportCompleted(ExportError error, QUrl url);
    void importCompleted(ImportError error, QUrl url, const QStringList &ids);
    void contactsFetched(int requestId, const QVariantList &fetchedContacts);

public slots:
    void update();
    void updateContacts();
    void updateCollections();
    void cancelUpdate();

private slots:
    void clearContacts();
    void fetchAgain();
    void requestUpdated();
    void fetchRequestStateChanged(QContactAbstractRequest::State newState);
    void doUpdate();
    void doContactUpdate();
    void onRequestStateChanged(QContactAbstractRequest::State newState);
    void onContactsAdded(const QList<QContactId>& ids);
    void onContactsRemoved(const QList<QContactId>& ids);
    void onContactsChanged(const QList<QContactId>& ids);
    void startImport(QVersitReader::State state);
    void contactsExported(QVersitWriter::State state);
    void onFetchedContactDestroyed(QObject *obj);

    // handle fetch request from onContactsAdded()
    void onContactsAddedFetchRequestStateChanged(QContactAbstractRequest::State state);

    // handle fetch request from onContactsChanged()
    void onContactsChangedFetchRequestStateChanged(QContactAbstractRequest::State state);

    // handle fetch request from fetchContacts()
    void onFetchContactsRequestStateChanged(QContactAbstractRequest::State state);

    void collectionsFetched();

private:
    QContactFetchRequest *createContactFetchRequest(const QList<QContactId> &ids);
    void checkError(const QContactAbstractRequest *request);
    void updateError(QContactManager::Error error);
    int contactIndex(const QDeclarativeContact* contact);

private:
    QScopedPointer<QDeclarativeContactModelPrivate> d;
};

QT_END_NAMESPACE

QML_DECLARE_TYPE(QDeclarativeContactModel)

#endif // QDECLARATIVECONTACTMODEL_P_H
