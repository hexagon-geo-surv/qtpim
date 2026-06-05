// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

#ifndef QCONTACTMANAGERDATAHOLDER_H
#define QCONTACTMANAGERDATAHOLDER_H

#include <QtCore/qdebug.h>
#include <QtCore/qlist.h>
#include <QtCore/qmap.h>
#include <QtCore/qstring.h>

#include <QtContacts/qcontactmanager.h>

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

QT_BEGIN_NAMESPACE_CONTACTS
class QContact;
QT_END_NAMESPACE_CONTACTS

QTCONTACTS_USE_NAMESPACE

class QContactManagerDataHolder
{
public:
    QContactManagerDataHolder()
    {
        QStringList managerNames = QContactManager::availableManagers();

        for (const QString& mgr : managerNames) {
            // Don't bother with these
            if (mgr == "memory" || mgr == "invalid" || mgr == "testdummy" || mgr == "maliciousplugin" || mgr == "testlazy")
                continue;
            QMap<QString, QString> params;
            QString mgrUri = QContactManager::buildUri(mgr, params);
            QContactManager* cm = QContactManager::fromUri(mgrUri);
            if (cm) {
                qDebug() << "Saving contacts for" << mgrUri;
                QList<QContact> contacts = cm->contacts();
                savedContacts.insert(cm->managerName(),contacts);
                QList<QContactId> ids;
                for (const QContact& contact : contacts)
                    ids.append(contact.id());
                cm->removeContacts(ids, 0);
                delete cm;
            }
        }
    }

    ~QContactManagerDataHolder()
    {
        for (const QString& mgrUri : savedContacts.keys()) {
            QContactManager* cm = QContactManager::fromUri(mgrUri);
            if (cm) {
                qDebug() << "Restoring contacts for" << mgrUri;
                QList<QContact> contacts = savedContacts.value(mgrUri);
                cm->saveContacts(&contacts, 0);
                // XXX this doesn't restore relationships..
                delete cm;
            }
        }
    }
private:
    QMap<QString, QList<QContact> > savedContacts;
};

#endif // QCONTACTMANAGERDATAHOLDER_H
