// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QCONTACTACTION_H
#define QCONTACTACTION_H

#include <QtCore/qmap.h>
#include <QtCore/qobject.h>
#include <QtCore/qstringlist.h>
#include <QtCore/qvariant.h>

#include <QtContacts/qcontact.h>
#include <QtContacts/qcontactactiontarget.h>
#include <QtContacts/qcontactactiondescriptor.h>
#include <QtContacts/qcontactdetail.h>
#include <QtContacts/qcontactfilter.h>

QT_BEGIN_NAMESPACE_CONTACTS

class QContactActionPrivate;
class Q_CONTACTS_EXPORT QContactAction : public QObject
{
    Q_OBJECT

public:
    virtual ~QContactAction() = 0;

    /* Initiate the asynchronous action on the given list of contacts (and optionally, per-contact-details) with the given parameters */
    virtual bool invokeAction(const QList<QContactActionTarget>& targets, const QVariantMap& parameters = QVariantMap()) = 0;

    /* The possible states of an action */
    enum State {
        InactiveState = 0,      // operation not yet started
        ActiveState,            // operation started, not yet finished
        FinishedState,          // operation successfully completed
        FinishedDetachedState,  // operation started, no further information available - name under discussion.
        FinishedWithErrorState  // operation finished, but error occurred
    };

    virtual State state() const = 0;

    /* Returns the most recently received result, or an empty QVariantMap if no results received */
    virtual QVariantMap results() const = 0;

    /* Convenience functions */
    bool invokeAction(const QContactActionTarget& target, const QVariantMap& parameters = QVariantMap())
    {
        return invokeAction(QList<QContactActionTarget>() << target, parameters);
    }
    bool invokeAction(const QContact& contact, const QContactDetail& detail = QContactDetail(), const QVariantMap& parameters = QVariantMap())
    {
        return invokeAction(QList<QContactActionTarget>() << QContactActionTarget(contact, detail), parameters);
    }

    // common actions
    inline static const QString ActionCall() {return QStringLiteral("call");};
    inline static const QString ActionEmail() {return QStringLiteral("email");};
    inline static const QString ActionSms() {return QStringLiteral("sms");};
    inline static const QString ActionMms() {return QStringLiteral("mms");};
    inline static const QString ActionChat() {return QStringLiteral("chat");};
    inline static const QString ActionVideoCall() {return QStringLiteral("videocall");};
    inline static const QString ActionOpenInEditor() {return QStringLiteral("edit");};
    inline static const QString ActionOpenInViewer() {return QStringLiteral("view");};

Q_SIGNALS:
    void stateChanged(QtContacts::QContactAction::State);
    void resultsAvailable();

public:
    /* return a list of names of actions which are available */
    static QStringList availableActions(const QString& serviceName = QString());

    /* return a list of descriptors for action implementations matching the given criteria */
    static QList<QContactActionDescriptor> actionDescriptors(const QString& actionName = QString());

    /* return a pointer to an implementation of the action identified by the given descriptor */
    static QContactAction* action(const QContactActionDescriptor& descriptor);
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTACTION_H
