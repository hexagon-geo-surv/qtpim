// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QDECLARATIVECONTACTCOLLECTIONFILTER_H
#define QDECLARATIVECONTACTCOLLECTIONFILTER_H

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

#include <QtContacts/qcontactcollectionfilter.h>

#include "qdeclarativecontactfilter_p.h"

QTCONTACTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE

class QDeclarativeContactCollectionFilter : public QDeclarativeContactFilter
{
    Q_OBJECT
    Q_PROPERTY(QStringList ids READ ids WRITE setIds NOTIFY valueChanged)

public:
    QDeclarativeContactCollectionFilter(QObject *parent = nullptr)
        : QDeclarativeContactFilter(parent)
    {
        connect(this, SIGNAL(valueChanged()), SIGNAL(filterChanged()));
    }

    QStringList ids() const
    {
        return m_ids;
    }

    void setIds(const QStringList &ids)
    {
        for (const QString &id : ids) {
            if (!m_ids.contains(id)) {
                m_ids = ids;
                emit valueChanged();
                return;
            }
        }

        for (const QString &id : std::as_const(m_ids)) {
            if (!ids.contains(id)) {
                m_ids = ids;
                emit valueChanged();
                return;
            }
        }
    }

    // used by model
    QContactFilter filter() const override
    {
        QContactCollectionFilter f;
        QSet<QContactCollectionId> ids;

        for (const QString &id : std::as_const(m_ids)) {
            QContactCollectionId cId = QContactCollectionId::fromString(id);
            if (!cId.isNull())
                ids << cId;
        }

        f.setCollectionIds(ids);
        return f;
    }

Q_SIGNALS:
    void valueChanged();

private:
    QStringList m_ids;
};

QT_END_NAMESPACE

QML_DECLARE_TYPE(QDeclarativeContactCollectionFilter)

#endif // QDECLARATIVECONTACTCOLLECTIONFILTER_H
