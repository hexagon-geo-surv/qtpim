// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QDECLARATIVECONTACTACTIONFILTER_H
#define QDECLARATIVECONTACTACTIONFILTER_H

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

#include <QtContacts/qcontactactionfilter.h>

#include "qdeclarativecontactfilter_p.h"

QTCONTACTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE

class QDeclarativeContactActionFilter : public QDeclarativeContactFilter
{
    Q_OBJECT
    Q_PROPERTY(QString actionName READ actionName WRITE setActionName NOTIFY valueChanged)
public:
    QDeclarativeContactActionFilter(QObject* parent=0)
        :QDeclarativeContactFilter(parent)
    {
        connect(this, SIGNAL(valueChanged()), SIGNAL(filterChanged()));
    }
    void setActionName(const QString& action)
    {
        if (action != d.actionName()) {
            d.setActionName(action);
            emit valueChanged();
        }
    }

    QString actionName() const
    {
        return d.actionName();
    }
    QContactFilter filter() const
    {
        return d;
    }

signals:
    void valueChanged();

private:
    QContactActionFilter d;
};

QT_END_NAMESPACE

QML_DECLARE_TYPE(QDeclarativeContactActionFilter)

#endif // QDECLARATIVECONTACTACTIONFILTER_H
