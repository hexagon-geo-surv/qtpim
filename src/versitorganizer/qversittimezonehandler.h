// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QVERSITTIMEZONEHANDLER_H
#define QVERSITTIMEZONEHANDLER_H

#include <QtCore/qobject.h>
#include <QtCore/qdatetime.h>

#include <QtVersitOrganizer/qversitorganizerglobal.h>

QT_BEGIN_NAMESPACE_VERSITORGANIZER

class Q_VERSIT_ORGANIZER_EXPORT QVersitTimeZoneHandler
{
public:
    virtual ~QVersitTimeZoneHandler() {}

    /*!
      \fn QDateTime QVersitTimeZoneHandler::convertTimeZoneToUtc(const QDateTime& datetime, const QString& timeZoneName);
      Converts \a datetime to the local time for the time zone identified by \a timeZoneName.  The UTC
      offset of the time zone should be calculated taking into account the daylight savings rules that
      might apply at \a datetime.

      \a datetime must be specified with Qt::UTC.  The returned QDateTime will be specified with
      Qt::LocalTime.  Note that unlike the usual semantic of Qt::LocalTime, it does not represent a time
      in the system's local time zone.

      An invalid QDateTime is returned on failure (eg. if \a timeZoneName is unknown).
     */
    virtual QDateTime convertTimeZoneToUtc(const QDateTime& datetime, const QString& timeZoneName) = 0;

    /*!
      \fn QDateTime QVersitTimeZoneHandler::convertUtcToTimeZone(const QDateTime& datetime, const QString& timeZoneName);
      Converts \a datetime to UTC, treating \a datetime as if it were a local time for a time zone
      identified by \a timeZoneName.  The UTC offset of the time zone should be calculated taking into
      account the daylight savings rules that might apply at \a datetime.

      \a datetime must be specified with Qt::LocalTime.  Note that unlike the usual semantic of
      Qt::LocalTime, \a datetime does not represent a time in the system's local time zone.
      The returned QDateTime will be specified with Qt::UTC.

      An invalid QDateTime is returned on failure (eg. if \a timeZoneName is unknown).
     */
    virtual QDateTime convertUtcToTimeZone(const QDateTime& datetime, const QString& timeZoneName) = 0;
};

QT_END_NAMESPACE_VERSITORGANIZER

#define QT_VERSIT_TIMEZONE_HANDLER_INTERFACE "org.qt-project.Qt.QVersitTimeZoneHandler"
QT_BEGIN_NAMESPACE
Q_DECLARE_INTERFACE(QtVersitOrganizer::QVersitTimeZoneHandler, QT_VERSIT_TIMEZONE_HANDLER_INTERFACE)
QT_END_NAMESPACE
#endif
