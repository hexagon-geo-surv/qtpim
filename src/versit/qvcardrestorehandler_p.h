// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QVCARDRESTOREHANDLER_P_H
#define QVCARDRESTOREHANDLER_P_H

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
#include <QtCore/qlist.h>

#include <QtVersit/qversitglobal.h>

#include <QtContacts/qcontactdetail.h>

QTCONTACTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE_VERSIT

class QVersitProperty;

// This is a map from Versit group names to the details that were generated from properties with the
// said groups.  Multiple details can be associated with a single group.
class DetailGroupMap
{
public:
    QList<QContactDetail> detailsInGroup(const QString& groupName) const;
    void insert(const QString& groupName, const QContactDetail& detail);
    void update(const QContactDetail& detail);
    void clear();

private:
    QHash<int, QString> mDetailGroupName; // detailid -> group name
    QHash<int, QContactDetail> mDetailById; // detailid -> detail
};

class QVCardRestoreHandler
{
public:
    bool propertyProcessed(const QVersitProperty& property,
                           QList<QContactDetail>* updatedDetails);
    void documentProcessed();

    const static QString PropertyName;
    const static QString DetailTypeParameter;
    const static QString FieldParameter;
    const static QString DatatypeParameter;
    const static QString DatatypeParameterVariant;
    const static QString DatatypeParameterDate;
    const static QString DatatypeParameterDateTime;
    const static QString DatatypeParameterTime;
    const static QString DatatypeParameterBool;
    const static QString DatatypeParameterInt;
    const static QString DatatypeParameterUInt;
    const static QString DatatypeParameterUrl;
    const static QString GroupPrefix;

private:
    static QVariant deserializeValue(const QVersitProperty& property);
    DetailGroupMap mDetailGroupMap; // remembers which details came from which groups
};

QT_END_NAMESPACE_VERSIT

#endif // QVCARDRESTOREHANDLER_P_H
