// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QCONTACTACTIONDESCRIPTOR_H
#define QCONTACTACTIONDESCRIPTOR_H

#include <QtCore/qmap.h>
#include <QtCore/qset.h>
#include <QtCore/qshareddata.h>
#include <QtCore/qstringlist.h>
#include <QtCore/qvariant.h>

#include <QtContacts/qcontactactiontarget.h>
#include <QtContacts/qcontactdetail.h>
#include <QtContacts/qcontactfilter.h>

QT_BEGIN_NAMESPACE_CONTACTS

class QContact;
class QContactActionFactory;

class QContactActionDescriptorPrivate;
class Q_CONTACTS_EXPORT QContactActionDescriptor
{
public:
    QContactActionDescriptor();
    QContactActionDescriptor(const QContactActionDescriptor& other);
    QContactActionDescriptor& operator=(const QContactActionDescriptor& other);
    ~QContactActionDescriptor();

    bool isValid() const;
    bool operator==(const QContactActionDescriptor& other) const;
    bool operator!=(const QContactActionDescriptor& other) const;

    QString actionName() const;
    QString serviceName() const;
    QString actionIdentifier() const;
    int implementationVersion() const;

    /* The descriptor provides the client with all information required in UI. */
    QSet<QContactActionTarget> supportedTargets(const QContact& contact) const;
    QContactFilter contactFilter() const;
    bool supportsContact(const QContact& contact) const;
    QVariant metaData(const QString& key, const QList<QContactActionTarget>& targets, const QVariantMap& parameters = QVariantMap()) const;

    /* Convenience meta data accessors */
    QVariant metaData(const QString& key, const QVariantMap& parameters = QVariantMap()) const;
    QVariant metaData(const QString& key, const QContactActionTarget& target, const QVariantMap& parameters = QVariantMap()) const;
    QVariant metaData(const QString& key, const QContact& contact, const QContactDetail& detail = QContactDetail(), const QVariantMap& parameters = QVariantMap()) const;

    // default meta-data keys
    static const QString MetaDataIcon;
    static const QString MetaDataLabel;
    static const QString MetaDataSecondLabel;
    static const QString MetaDataOptionalParameterKeys;
    static const QString MetaDataMandatoryParameterKeys;

private:
    QSharedDataPointer<QContactActionDescriptorPrivate> d;
    friend class QContactActionFactory;
    friend class QContactActionServiceManager;
#ifndef QT_NO_DEBUG_STREAM
    Q_CONTACTS_EXPORT friend QDebug& operator<<(QDebug dbg, const QContactActionDescriptor& descriptor);
#endif
    Q_CONTACTS_EXPORT friend size_t qHash(const QContactActionDescriptor& key, size_t seed) noexcept;
};

Q_CONTACTS_EXPORT size_t qHash(const QContactActionDescriptor& key, size_t seed = 0) noexcept;
#ifndef QT_NO_DEBUG_STREAM
Q_CONTACTS_EXPORT QDebug& operator<<(QDebug dbg, const QContactActionDescriptor& descriptor);
#endif

QT_END_NAMESPACE_CONTACTS

QT_BEGIN_NAMESPACE
Q_DECLARE_TYPEINFO(QTCONTACTS_PREPEND_NAMESPACE(QContactActionDescriptor), Q_MOVABLE_TYPE);
QT_END_NAMESPACE

#endif // QCONTACTACTIONDESCRIPTOR_H
