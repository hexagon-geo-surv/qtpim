// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qorganizerjournal.h"

#include <QtCore/qdatetime.h>

#include "qorganizerjournaltime.h"

QT_BEGIN_NAMESPACE_ORGANIZER

/*!
    \class QOrganizerJournal
    \brief The QOrganizerJournal class supplies a journal which is associated with a particular point in time
    \inmodule QtOrganizer
    \ingroup organizer-items

    A journal consists of personal data which is associated with a particular point in time.
 */

/*!
    Sets the date time which this journal is associated with to \a dateTime.
 */
void QOrganizerJournal::setDateTime(const QDateTime &dateTime)
{
    QOrganizerJournalTime jtr = detail(QOrganizerItemDetail::TypeJournalTime);
    jtr.setEntryDateTime(dateTime);
    saveDetail(&jtr);
}

/*!
    Returns the date time associated with this journal.
 */
QDateTime QOrganizerJournal::dateTime() const
{
    QOrganizerJournalTime jtr = detail(QOrganizerItemDetail::TypeJournalTime);
    return jtr.entryDateTime();
}

QT_END_NAMESPACE_ORGANIZER
