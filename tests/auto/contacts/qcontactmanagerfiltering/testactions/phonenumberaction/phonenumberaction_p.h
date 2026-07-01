// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

#ifndef QCONTACTTESTPHONENUMBERACTION_P_H
#define QCONTACTTESTPHONENUMBERACTION_P_H

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

#include <QtContacts/qtcontacts.h>
#include "qserviceplugininterface.h"
#include "qservicecontext.h"
#include "qserviceinterfacedescriptor.h"

#include <QSharedData>
#include <QString>
#include <QVariantMap>

QTCONTACTS_USE_NAMESPACE

class DummyAction : public QContactAction
{
public:
    DummyAction(QObject* parent = Q_NULLPTR) { Q_UNUSED(parent) }

    QVariantMap metaData() const {return QVariantMap();}

    bool invokeAction(const QContactActionTarget&, const QVariantMap&)
    {
        // Well, do something
        emit stateChanged(QContactAction::FinishedState);
        return true;
    }

    bool invokeAction(const QList<QContactActionTarget>&, const QVariantMap&)
    {
        // Well, do something
        emit stateChanged(QContactAction::FinishedState);
        return true;
    }

    QVariantMap results() const
    {
        return QVariantMap();
    }

    State state() const {return QContactAction::FinishedState;}

};

/* Static actions for testing matching */
class QPhoneNumberAction : public DummyAction
{
    Q_OBJECT

public:
    QPhoneNumberAction(QObject *parent = Q_NULLPTR) : DummyAction(parent) {}
    ~QPhoneNumberAction() {}
};

class QPhoneNumberActionFactory : public QContactActionFactory
{
    Q_OBJECT

public:
    QPhoneNumberActionFactory(QObject* parent = Q_NULLPTR) : QContactActionFactory(parent)
    {
        m_actionDescriptor = createDescriptor("PhoneNumberAction", "tst_qcontactmanagerfiltering:phonenumberaction", "phonenumberaction", 1);
    }

    ~QPhoneNumberActionFactory()
    {

    }

    QList<QContactActionDescriptor> actionDescriptors() const
    {
        QList<QContactActionDescriptor> retn;
        retn << m_actionDescriptor;
        return retn;
    }

    QContactAction* create(const QContactActionDescriptor& which) const
    {
        Q_UNUSED(which)
        return new QPhoneNumberAction;
    }

    QSet<QContactActionTarget> supportedTargets(const QContact& contact, const QContactActionDescriptor& which) const
    {
        Q_UNUSED(which)
        QSet<QContactActionTarget> retn;
        QList<QContactDetail> pnDets = contact.details(QContactPhoneNumber::DefinitionName);
        for (const QContactDetail& det : pnDets) {
            if (!det.value(QContactPhoneNumber::FieldNumber).isEmpty()) {
                QContactActionTarget curr(contact, det);
                retn << curr;
            }
        }

        return retn;
    }

    QContactFilter contactFilter(const QContactActionDescriptor& which) const
    {
        Q_UNUSED(which)
        QContactDetailFilter df;
        // XXX TODO: find some way to pass the defAndFieldNamesForTypeForActions value for Integer to this function...
        df.setDetailDefinitionName(QContactPhoneNumber::DefinitionName, QContactPhoneNumber::FieldNumber);
        return df;
    }

    QVariant metaData(const QString& key, const QList<QContactActionTarget>& targets, const QVariantMap& parameters, const QContactActionDescriptor& which) const
    {
        Q_UNUSED(key);
        Q_UNUSED(targets);
        Q_UNUSED(parameters);
        Q_UNUSED(which);
        return QVariant();
    }

    bool supportsContact(const QContact& contact, const QContactActionDescriptor& which) const
    {
        return supportedTargets(contact, which).isEmpty();
    }

private:
    QContactActionDescriptor m_actionDescriptor;
};

class QPhoneNumberActionPlugin : public QObject, public QServicePluginInterface
{
    Q_OBJECT
    Q_INTERFACES(QtMobility::QServicePluginInterface)

public:
    QObject* createInstance(const QServiceInterfaceDescriptor& descriptor,
                            QServiceContext* context,
                            QAbstractSecuritySession* session)
    {
        Q_UNUSED(context);
        Q_UNUSED(session);

        if (descriptor.interfaceName() == QContactActionFactory::InterfaceName)
            return new QPhoneNumberActionFactory(this);
        else
            return 0;
    }
};
Q_EXPORT_PLUGIN2(contacts_phonenumberaction, QPhoneNumberActionPlugin);

#endif
