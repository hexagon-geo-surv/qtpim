// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QVERSITORGANIZEREXPORTER_P_H
#define QVERSITORGANIZEREXPORTER_P_H

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

#include <utility>

#include <QtOrganizer/qorganizeritemdetail.h>

#include <QtVersit/qversitdocument.h>
#include <QtVersit/qversitproperty.h>

#include <QtVersitOrganizer/qversitorganizerexporter.h>
#include <QtVersitOrganizer/qversitorganizerhandler.h>
#include <QtVersitOrganizer/qversittimezonehandler.h>

QT_BEGIN_NAMESPACE_ORGANIZER
class QOrganizerItem;
class QOrganizerItemReminder;
class QOrganizerRecurrenceRule;
QT_END_NAMESPACE_ORGANIZER

QTORGANIZER_USE_NAMESPACE
QTVERSIT_USE_NAMESPACE

QT_BEGIN_NAMESPACE_VERSITORGANIZER

class QVersitOrganizerExporterPrivate
{
public:
    QVersitOrganizerExporterPrivate(const QString& profile = QString());
    ~QVersitOrganizerExporterPrivate();

    bool exportItem(const QOrganizerItem& item,
                    QVersitDocument* document,
                    QVersitOrganizerExporter::Error* error);

    QVersitDocument mResult;
    QMap<int, QVersitOrganizerExporter::Error> mErrors;
    QVersitOrganizerExporterDetailHandler* mDetailHandler;
    QList<QVersitOrganizerHandler*> mPluginDetailHandlers;
    QVersitTimeZoneHandler* mTimeZoneHandler;

private:
    void exportDetail(
            const QOrganizerItem& item,
            const QOrganizerItemDetail& detail,
            QVersitDocument* document);
    void encodeEventTimeRange(
            const QOrganizerItemDetail& detail,
            const QVersitDocument& document,
            QList<QVersitProperty>* removedProperties,
            QList<QVersitProperty>* generatedProperties,
            QSet<int>* processedFields);
    void encodeTodoTimeRange(
            const QOrganizerItemDetail& detail,
            const QVersitDocument& document,
            QList<QVersitProperty>* removedProperties,
            QList<QVersitProperty>* generatedProperties,
            QSet<int>* processedFields);
    void encodeJournalTimeRange(
            const QOrganizerItemDetail& detail,
            const QVersitDocument& document,
            QList<QVersitProperty>* removedProperties,
            QList<QVersitProperty>* generatedProperties,
            QSet<int>* processedFields);
    void encodeTimestamp(
            const QOrganizerItemDetail& detail,
            const QVersitDocument& document,
            QList<QVersitProperty>* removedProperties,
            QList<QVersitProperty>* generatedProperties,
            QSet<int>* processedFields);
    void encodeVersion(
            const QOrganizerItemDetail& detail,
            const QVersitDocument& document,
            QList<QVersitProperty>* removedProperties,
            QList<QVersitProperty>* generatedProperties,
            QSet<int>* processedFields);
    void encodeRecurrence(
            const QOrganizerItem& item,
            const QOrganizerItemDetail& detail,
            const QVersitDocument& document,
            QList<QVersitProperty>* removedProperties,
            QList<QVersitProperty>* generatedProperties,
            QSet<int>* processedFields);
    void encodeRecurRule(
            const QString& propertyName,
            const QOrganizerRecurrenceRule& rule,
            QList<QVersitProperty>* generatedProperties);
    void appendInts(QString* str, const QSet<int>& ints);
    QString weekString(Qt::DayOfWeek day);
    void encodeRecurDates(
            const QString& propertyName,
            const QOrganizerItem& item,
            const QSet<QDate>& dates,
            const QVersitDocument& document,
            QList<QVersitProperty>* removedProperties,
            QList<QVersitProperty>* generatedProperties);
    void encodePriority(
            const QOrganizerItemDetail& detail,
            const QVersitDocument& document,
            QList<QVersitProperty>* removedProperties,
            QList<QVersitProperty>* generatedProperties,
            QSet<int>* processedFields);
    void encodeInstanceOrigin(
            const QOrganizerItemDetail& detail,
            const QVersitDocument& document,
            QList<QVersitProperty>* removedProperties,
            QList<QVersitProperty>* generatedProperties,
            QSet<int>* processedFields);
    void encodeTodoProgress(
            const QOrganizerItemDetail& detail,
            const QVersitDocument& document,
            QList<QVersitProperty>* removedProperties,
            QList<QVersitProperty>* generatedProperties,
            QSet<int>* processedFields);
    void encodeComment(
            const QOrganizerItemDetail& detail,
            QList<QVersitProperty>* generatedProperties,
            QSet<int>* processedFields);
    void encodeAudibleReminder(
            const QOrganizerItem &item,
            const QOrganizerItemDetail &detail,
            QList<QVersitProperty> *generatedProperties,
            QSet<int> *processedFields);
    void encodeEmailReminder(
            const QOrganizerItem &item,
            const QOrganizerItemDetail &detail,
            QList<QVersitProperty> *generatedProperties,
            QSet<int> *processedFields);
    void encodeVisualReminder(
            const QOrganizerItem &item,
            const QOrganizerItemDetail &detail,
            QList<QVersitProperty> *generatedProperties,
            QSet<int> *processedFields);
    QVersitDocument encodeItemReminderCommonFields(
                const QOrganizerItem &item,
                const QOrganizerItemReminder &reminder,
                QSet<int> *processedFields);
    void encodeExtendedDetail(
            const QOrganizerItemDetail &detail,
            QList<QVersitProperty> *generatedProperties,
            QSet<int> *processedFields);
    void encodeSimpleProperty(
            const QOrganizerItemDetail& detail,
            const QVersitDocument& document,
            QList<QVersitProperty>* removedProperties,
            QList<QVersitProperty>* generatedProperties,
            QSet<int>* processedFields);
    QString encodeDateTime(const QDateTime& dateTime);

    bool documentContainsUidAndRecurrenceId(const QVersitDocument& document);
    QVersitProperty takeProperty(
            const QVersitDocument& document,
            const QString& propertyName,
            QList<QVersitProperty>* toBeRemoved);

    // definition name -> <field name, versit property name>:
    QMap<QOrganizerItemDetail::DetailType, std::pair<int, QString> > mPropertyMappings;
};

QT_END_NAMESPACE_VERSITORGANIZER

#endif // QVERSITORGANIZEREXPORTER_P_H
