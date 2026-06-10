// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QCONTACTVERSION_H
#define QCONTACTVERSION_H

#include <QtContacts/qcontactdetail.h>

QT_BEGIN_NAMESPACE_CONTACTS

/* Leaf class */
class Q_CONTACTS_EXPORT QContactVersion : public QContactDetail
{
public:
#ifndef Q_QDOC
    Q_DECLARE_CUSTOM_CONTACT_DETAIL(QContactVersion)
#else
    static const DetailType Type;
#endif

    enum VersionField {
        FieldSequenceNumber = 0,
        FieldExtendedVersion
    };

    void setSequenceNumber(int _sequenceNumber);
    int sequenceNumber() const;

    void setExtendedVersion(const QByteArray& _extendedVersion);
    QByteArray extendedVersion() const;
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTVERSION_H
