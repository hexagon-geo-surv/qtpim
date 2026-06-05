// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QDECLARATIVECONTACTVERSION_H
#define QDECLARATIVECONTACTVERSION_H

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

#include <QtContacts/qcontactversion.h>

#include "qdeclarativecontactdetail_p.h"

QTCONTACTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE

class QDeclarativeContactVersion : public QDeclarativeContactDetail
{
    Q_OBJECT

    Q_PROPERTY(int sequenceNumber READ sequenceNumber WRITE setSequenceNumber NOTIFY valueChanged)
    Q_PROPERTY(QString extendedVersion READ extendedVersion WRITE setExtendedVersion NOTIFY valueChanged)

    Q_ENUMS(FieldType)
public:
    enum FieldType {
        SequenceNumber = QContactVersion::FieldSequenceNumber,
        ExtendedVersion = QContactVersion::FieldExtendedVersion
    };

    QDeclarativeContactVersion(QObject* parent = nullptr)
        :QDeclarativeContactDetail(parent)
    {
        setDetail(QContactVersion());
        connect(this, SIGNAL(valueChanged()), SIGNAL(detailChanged()));
    }

    DetailType detailType() const
    {
        return QDeclarativeContactDetail::Version;
    }

    void setSequenceNumber(int newSequenceNumber)
    {
        if (!readOnly() && newSequenceNumber != sequenceNumber()) {
            detail().setValue(QContactVersion::FieldSequenceNumber, newSequenceNumber);
            emit valueChanged();
        }
    }
    int sequenceNumber() const {return detail().value(QContactVersion::FieldSequenceNumber).toInt();}

    void setExtendedVersion(const QString &newExtendedVersion)
    {
        if (extendedVersion() != newExtendedVersion) {
            detail().setValue(QContactVersion::FieldExtendedVersion, newExtendedVersion.toUtf8());
            emit valueChanged();
        }
    }
    QString extendedVersion() const
    {
        return QString::fromUtf8(detail().value(QContactVersion::FieldExtendedVersion).toByteArray());
    }
signals:
    void valueChanged();
};

QT_END_NAMESPACE

QML_DECLARE_TYPE(QDeclarativeContactVersion)

#endif // QDECLARATIVECONTACTVERSION_H
