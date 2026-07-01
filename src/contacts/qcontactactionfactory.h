// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QCONTACTACTIONFACTORY_H
#define QCONTACTACTIONFACTORY_H

#include <QtCore/qlist.h>
#include <QtCore/qmap.h>
#include <QtCore/qobject.h>
#include <QtCore/qset.h>
#include <QtCore/qvariant.h>

#include <QtContacts/qcontactactiontarget.h>
#include <QtContacts/qcontactactiondescriptor.h>

QT_BEGIN_NAMESPACE_CONTACTS

class QContact;
class QContactAction;
class QContactFilter;

class Q_CONTACTS_EXPORT QContactActionFactory : public QObject
{
    Q_OBJECT

public:
    QContactActionFactory(QObject *parent_ = Q_NULLPTR) : QObject(parent_) {}
    virtual ~QContactActionFactory();
    virtual QList<QContactActionDescriptor> actionDescriptors() const = 0;
    virtual QContactAction* create(const QContactActionDescriptor& which) const = 0;

    // Backend functionality for QCAD
    virtual QSet<QContactActionTarget> supportedTargets(const QContact& contact, const QContactActionDescriptor& which) const = 0;
    virtual QContactFilter contactFilter(const QContactActionDescriptor& which) const = 0;
    virtual QVariant metaData(const QString& key, const QList<QContactActionTarget>& targets, const QVariantMap& parameters, const QContactActionDescriptor& which) const = 0;

    virtual bool supportsContact(const QContact& contact, const QContactActionDescriptor& which) const; // virtual but not pure virtual; default impl. calls supportedTargets.isEmpty().

    inline static const QString InterfaceName() {return QStringLiteral("org.qt-project.Qt.QContactActionFactory");};

protected:
    QContactActionDescriptor createDescriptor(const QString& actionName, const QString& serviceName, const QString& actionIdentifier, int implementationVersion) const;
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTACTIONFACTORY_H
