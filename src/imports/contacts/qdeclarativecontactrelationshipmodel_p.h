// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QDECLARATIVECONTACTRELATIONSHIPMODEL_P_H
#define QDECLARATIVECONTACTRELATIONSHIPMODEL_P_H

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

#include "qdeclarativecontactrelationship_p.h"

QTCONTACTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE

class QDeclarativeContactRelationshipModelPrivate;
class QDeclarativeContactRelationshipModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(QString manager READ manager WRITE setManager NOTIFY managerChanged)
    Q_PROPERTY(bool autoUpdate READ autoUpdate WRITE setAutoUpdate NOTIFY autoUpdateChanged)
    Q_PROPERTY(QDeclarativeContact* participant READ participant WRITE setParticipant NOTIFY participantChanged)
    Q_PROPERTY(QVariant relationshipType READ relationshipType WRITE setRelationshipType NOTIFY relationshipTypeChanged)
    Q_PROPERTY(QDeclarativeContactRelationship::RelationshipRole role READ role WRITE setRole NOTIFY roleChanged)
    Q_PROPERTY(QQmlListProperty<QDeclarativeContactRelationship> relationships READ relationships NOTIFY relationshipsChanged)
    Q_PROPERTY(QString error READ error)

public:
    QDeclarativeContactRelationshipModel(QObject *parent = Q_NULLPTR);
    ~QDeclarativeContactRelationshipModel();
    enum {
        RelationshipRole = Qt::UserRole + 500

    };

    QString manager() const;
    void setManager(const QString& manager);
    bool autoUpdate() const;
    void setAutoUpdate(bool autoUpdate);
    QString error() const;
    QDeclarativeContact* participant() const;
    void setParticipant(QDeclarativeContact* participant);

    QVariant relationshipType() const;
    void setRelationshipType(const QVariant& type);

    QDeclarativeContactRelationship::RelationshipRole role() const;
    void setRole(QDeclarativeContactRelationship::RelationshipRole role);

    QQmlListProperty<QDeclarativeContactRelationship> relationships();
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE void removeRelationship(QDeclarativeContactRelationship* dcr);
    Q_INVOKABLE void addRelationship(QDeclarativeContactRelationship* dcr);
signals:
    void managerChanged();
    void participantChanged();
    void relationshipTypeChanged();
    void roleChanged();
    void relationshipsChanged();
    void autoUpdateChanged();
private slots:
    void fetchAgain();
    void requestUpdated();

    void relationshipsSaved();

    void relationshipsRemoved();

private:
    QDeclarativeContactRelationshipModelPrivate* d;
};

QT_END_NAMESPACE

QML_DECLARE_TYPE(QDeclarativeContactRelationshipModel)

#endif // QDECLARATIVECONTACTRELATIONSHIPMODEL_P_H
