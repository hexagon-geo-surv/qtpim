// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QVERSITORGANIZEREXPORTER_H
#define QVERSITORGANIZEREXPORTER_H

#include <QtCore/qlist.h>
#include <QtCore/qmap.h>
#include <QtCore/qset.h>

#include <QtOrganizer/qorganizeritem.h>

#include <QtVersit/qversitdocument.h>
#include <QtVersit/qversitproperty.h>

#include <QtVersitOrganizer/qversitorganizerglobal.h>

QT_BEGIN_NAMESPACE_ORGANIZER
class QOrganizerItemDetail;
QT_END_NAMESPACE_ORGANIZER

QTORGANIZER_USE_NAMESPACE
QTVERSIT_USE_NAMESPACE

QT_BEGIN_NAMESPACE_VERSITORGANIZER

class QVersitOrganizerExporterPrivate;

class Q_VERSIT_ORGANIZER_EXPORT QVersitOrganizerExporterDetailHandler
{
public:
    virtual ~QVersitOrganizerExporterDetailHandler();
    virtual void detailProcessed(const QOrganizerItem& item,
                                 const QOrganizerItemDetail& detail,
                                 const QVersitDocument& document,
                                 QSet<int>* processedFields,
                                 QList<QVersitProperty>* toBeRemoved,
                                 QList<QVersitProperty>* toBeAdded) = 0;
    virtual void itemProcessed(const QOrganizerItem& item,
                               QVersitDocument* document) = 0;
};

class Q_VERSIT_ORGANIZER_EXPORT QVersitOrganizerExporter
{
public:
    enum Error {
        NoError = 0,
        EmptyOrganizerError,
        UnknownComponentTypeError,
        UnderspecifiedOccurrenceError
    };

    QVersitOrganizerExporter();
    explicit QVersitOrganizerExporter(const QString& profile);
    ~QVersitOrganizerExporter();

    bool exportItems(const QList<QOrganizerItem>& items,
            QVersitDocument::VersitType versitType = QVersitDocument::ICalendar20Type);
    QVersitDocument document() const;
    QMap<int, Error> errorMap() const;

    void setDetailHandler(QVersitOrganizerExporterDetailHandler* handler);

private:
    QVersitOrganizerExporterPrivate* d;
};

QT_END_NAMESPACE_VERSITORGANIZER

#endif // QVERSITORGANIZEREXPORTER_H
