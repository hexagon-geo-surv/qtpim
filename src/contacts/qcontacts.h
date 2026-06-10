// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QTCONTACTS_H
#define QTCONTACTS_H

// this file includes all of the public header files
// provided by the Qt Contacts API

#include <QtContacts/qcontactsglobal.h>                    // global exports
#include <QtContacts/qcontactmanager.h>                    // manager
#include <QtContacts/qcontactmanagerengine.h>              // manager backend
#include <QtContacts/qcontactmanagerenginefactory.h>       // manage backend instantiator
#include <QtContacts/qcontact.h>                           // contact
#include <QtContacts/qcontactid.h>                         // contact identifier
#include <QtContacts/qcontactobserver.h>                   // contact observer
#include <QtContacts/qcontactdetail.h>                     // contact detail
#include <QtContacts/qcontactdetails.h>                    // leaf detail classes
#include <QtContacts/qcontactfetchhint.h>                  // backend optimization hint class
#include <QtContacts/qcontactfilter.h>                     // contact filter
#include <QtContacts/qcontactfilters.h>                    // leaf filter classes
#include <QtContacts/qcontactsortorder.h>                  // contact sorting
#include <QtContacts/qcontactaction.h>                     // actions
#include <QtContacts/qcontactactiondescriptor.h>           // action descriptors
#include <QtContacts/qcontactactionfactory.h>              // action factory
#include <QtContacts/qcontactactiontarget.h>               // action target (contact + detail(s))
#include <QtContacts/qcontactabstractrequest.h>            // asynchronous request
#include <QtContacts/qcontactrequests.h>                   // request leaf classes
#include <QtContacts/qcontactrelationship.h>               // contact relationships

QT_BEGIN_NAMESPACE_CONTACTS
QT_END_NAMESPACE_CONTACTS

#endif // QTCONTACTS_H
