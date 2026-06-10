// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QTORGANIZER_H
#define QTORGANIZER_H

// this file includes all of the public header files
// provided by the Qt Organizer API

#include <QtOrganizer/qorganizerglobal.h>                        // global exports

#include <QtOrganizer/qorganizerabstractrequest.h>                // asynchronous request
#include <QtOrganizer/qorganizeritemdetail.h>                     // organizer item detail
#include <QtOrganizer/qorganizeritemfetchhint.h>                  // fetch hint class
#include <QtOrganizer/qorganizeritemfilter.h>                     // organizer item filter
#include <QtOrganizer/qorganizeritem.h>                           // organizer item
#include <QtOrganizer/qorganizeritemid.h>                         // organizer item identifier
#include <QtOrganizer/qorganizeritemobserver.h>                   // organizer item observer
#include <QtOrganizer/qorganizermanager.h>                        // manager
#include <QtOrganizer/qorganizermanagerengine.h>                  // manager backend
#include <QtOrganizer/qorganizermanagerenginefactory.h>           // manage backend instantiator
#include <QtOrganizer/qorganizerrecurrencerule.h>                 // a single recurrence rule
#include <QtOrganizer/qorganizeritemsortorder.h>                  // organizer item sorting

#include <QtOrganizer/qorganizercollection.h>                     // collection of items
#include <QtOrganizer/qorganizercollectionid.h>                   // collection identifier

#include <QtOrganizer/qorganizercollectionchangeset.h>            // engine-specific collection changeset
#include <QtOrganizer/qorganizeritemchangeset.h>                  // engine-specific item changeset

#include <QtOrganizer/qorganizeritems.h>                          // item derived classes
#include <QtOrganizer/qorganizeritemdetails.h>                    // detail derived classes
#include <QtOrganizer/qorganizeritemrequests.h>                   // request derived classes
#include <QtOrganizer/qorganizeritemfilters.h>                    // detail derived classes

QT_BEGIN_NAMESPACE_ORGANIZER
QT_END_NAMESPACE_ORGANIZER

#endif // QTORGANIZER_H
