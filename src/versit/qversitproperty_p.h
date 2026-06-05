// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QVERSITPROPERTY_P_H
#define QVERSITPROPERTY_P_H

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

#include <QtCore/qhash.h>
#include <QtCore/qshareddata.h>
#include <QtCore/qstringlist.h>
#include <QtCore/qvariant.h>

#include <QtVersit/qversitproperty.h>

QT_BEGIN_NAMESPACE_VERSIT

class QVersitPropertyPrivate : public QSharedData
{
public:
    QVersitPropertyPrivate() : QSharedData(), mValueType(QVersitProperty::PlainType)
    {
    }

    QVersitPropertyPrivate(const QVersitPropertyPrivate& other)
        : QSharedData(other),
        mGroups(other.mGroups),
        mName(other.mName),
        mParameters(other.mParameters),
        mValue(other.mValue),
        mValueType(other.mValueType)
    {
    }

    ~QVersitPropertyPrivate() {}

    QStringList mGroups;
    QString mName;
    QMultiHash<QString,QString> mParameters;
    QVariant mValue;
    QVersitProperty::ValueType mValueType;
};

QT_END_NAMESPACE_VERSIT

#endif // QVERSITPROPERTY_P_H
