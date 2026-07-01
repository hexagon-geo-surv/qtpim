
// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QDECLARATIVECONTACTTAG_H
#define QDECLARATIVECONTACTTAG_H

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

#include <QtContacts/qcontacttag.h>

#include "qdeclarativecontactdetail_p.h"

QTCONTACTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE

class QDeclarativeContactTag : public QDeclarativeContactDetail
{
    Q_OBJECT
    Q_PROPERTY(QString tag READ tag WRITE setTag NOTIFY valueChanged)
    Q_ENUMS(FieldType)
    Q_CLASSINFO("DefaultProperty", "tag")
public:
    enum FieldType {
        Tag = QContactTag::FieldTag
    };

    QDeclarativeContactTag(QObject* parent = Q_NULLPTR)
        :QDeclarativeContactDetail(parent)
    {
        setDetail(QContactTag());
        connect(this, SIGNAL(valueChanged()), SIGNAL(detailChanged()));
    }
    DetailType detailType() const override
    {
        return QDeclarativeContactDetail::Tag;
    }

    void setTag(const QString& v)
    {
        if (!readOnly() && v != tag()) {
            detail().setValue(QContactTag::FieldTag, v);
            emit valueChanged();
        }
    }
    QString tag() const {return detail().value(QContactTag::FieldTag).toString();}
signals:
    void valueChanged();
};

QT_END_NAMESPACE

QML_DECLARE_TYPE(QDeclarativeContactTag)

#endif // QDECLARATIVECONTACTTAG_H
