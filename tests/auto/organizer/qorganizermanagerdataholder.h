// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only


#ifndef QORGANIZERITEMMANAGERDATAHOLDER_H
#define QORGANIZERITEMMANAGERDATAHOLDER_H

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

#include <QtCore/qdebug.h>
#include <QtCore/qlist.h>
#include <QtCore/qmap.h>
#include <QtCore/qstring.h>

#include <QtOrganizer/qorganizermanager.h>

QTORGANIZER_USE_NAMESPACE

class QOrganizerManagerDataHolder
{
public:
    QOrganizerManagerDataHolder()
    {
        QStringList managerNames = QOrganizerManager::availableManagers();

        for (const QString& mgr : managerNames) {
            // Don't bother with these
            if (mgr == "memory" || mgr == "invalid" || mgr == "testdummy" || mgr == "maliciousplugin" || mgr == "skeleton")
                continue;
            QMap<QString, QString> params;
            QString mgrUri = QOrganizerManager::buildUri(mgr, params);
            QOrganizerManager* cm = QOrganizerManager::fromUri(mgrUri);
            if (cm) {
                qDebug() << "Saving items for" << mgrUri;
                QList<QOrganizerItem> items = cm->itemsForExport(QDateTime(), QDateTime(), QOrganizerItemFilter());
                savedItems.insert(cm->managerName(),items);
                QList<QOrganizerItemId> ids;
                for (const QOrganizerItem& item : items)
                    ids.append(item.id());
                cm->removeItems(ids);
                delete cm;
            }
        }
    }

    ~QOrganizerManagerDataHolder()
    {
        for (const QString& mgrUri : savedItems.keys()) {
            QOrganizerManager* cm = QOrganizerManager::fromUri(mgrUri);
            if (cm) {
                qDebug() << "Restoring items for" << mgrUri;
                QList<QOrganizerItem> items = savedItems.value(mgrUri);
                cm->saveItems(&items);
                // XXX this doesn't restore relationships..
                delete cm;
            }
        }
    }
private:
    QMap<QString, QList<QOrganizerItem> > savedItems;
};

#endif

