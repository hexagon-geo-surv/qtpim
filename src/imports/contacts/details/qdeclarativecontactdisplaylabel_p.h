// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QDECLARATIVECONTACTDISPLAYLABEL_H
#define QDECLARATIVECONTACTDISPLAYLABEL_H

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

#include <QtContacts/qcontactdisplaylabel.h>

#include "qdeclarativecontactdetail_p.h"

QTCONTACTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE

class QDeclarativeContactDisplayLabel : public QDeclarativeContactDetail
{
    Q_OBJECT
    Q_PROPERTY(QString label READ label WRITE setLabel NOTIFY valueChanged)
    Q_ENUMS(FieldType)
    Q_CLASSINFO("DefaultProperty", "label")
public:
    enum FieldType {
        Label = QContactDisplayLabel::FieldLabel
    };
    QDeclarativeContactDisplayLabel(QObject* parent = nullptr)
        :QDeclarativeContactDetail(parent)
    {
        setDetail(QContactDisplayLabel());
        connect(this, SIGNAL(valueChanged()), SIGNAL(detailChanged()));
    }

    DetailType detailType() const override
    {
        return QDeclarativeContactDetail::DisplayLabel;
    }

    void setLabel(const QString &v)
    {
        if (!readOnly() && v != label()) {
            detail().setValue(QContactDisplayLabel::FieldLabel, v);
            emit valueChanged();
        }
    }

    QString label() const {return detail().value(QContactDisplayLabel::FieldLabel).toString();}

signals:
    void valueChanged();
};

QT_END_NAMESPACE

QML_DECLARE_TYPE(QDeclarativeContactDisplayLabel)

#endif // QDECLARATIVECONTACTDISPLAYLABEL_H
