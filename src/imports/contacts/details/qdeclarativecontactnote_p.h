// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QDECLARATIVECONTACTNOTE_H
#define QDECLARATIVECONTACTNOTE_H

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

#include <QtContacts/qcontactnote.h>

#include "qdeclarativecontactdetail_p.h"

QTCONTACTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE

class QDeclarativeContactNote : public QDeclarativeContactDetail
{
    Q_OBJECT
    Q_PROPERTY(QString note READ note WRITE setNote NOTIFY valueChanged)
    Q_ENUMS(FieldType)
    Q_CLASSINFO("DefaultProperty", "note")
public:
    enum FieldType {
        Note = QContactNote::FieldNote
    };

    QDeclarativeContactNote(QObject* parent = nullptr)
        :QDeclarativeContactDetail(parent)
    {
        setDetail(QContactNote());
        connect(this, SIGNAL(valueChanged()), SIGNAL(detailChanged()));
    }

    DetailType detailType() const
    {
        return QDeclarativeContactDetail::Note;
    }

    void setNote(const QString& v)
    {
        if (!readOnly() && v != note()) {
            detail().setValue(QContactNote::FieldNote, v);
            emit valueChanged();
        }
    }
    QString note() const {return detail().value(QContactNote::FieldNote).toString();}
signals:
    void valueChanged();
};

QT_END_NAMESPACE

QML_DECLARE_TYPE(QDeclarativeContactNote)

#endif // QDECLARATIVECONTACTNOTE_H
