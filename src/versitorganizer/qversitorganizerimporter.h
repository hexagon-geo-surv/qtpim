// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QVERSITORGANIZERIMPORTER_H
#define QVERSITORGANIZERIMPORTER_H

#include <QtCore/qlist.h>
#include <QtCore/qmap.h>

#include <QtOrganizer/qorganizeritem.h>
#include <QtOrganizer/qorganizeritemdetail.h>

#include <QtVersit/qversitglobal.h>

#include <QtVersitOrganizer/qversitorganizerglobal.h>

QT_BEGIN_NAMESPACE_VERSIT
class QVersitDocument;
class QVersitProperty;
QT_END_NAMESPACE_VERSIT

QTORGANIZER_USE_NAMESPACE
QTVERSIT_USE_NAMESPACE

QT_BEGIN_NAMESPACE_VERSITORGANIZER

class QVersitOrganizerImporterPrivate;

class Q_VERSIT_ORGANIZER_EXPORT QVersitOrganizerImporterPropertyHandler
{
public:
    virtual ~QVersitOrganizerImporterPropertyHandler() {}
    virtual void propertyProcessed(const QVersitDocument& document,
                                   const QVersitProperty& property,
                                   const QOrganizerItem& item,
                                   bool *alreadyProcessed,
                                   QList<QOrganizerItemDetail>* updatedDetails) = 0;
    virtual void subDocumentProcessed(const QVersitDocument& topLevel,
                                      const QVersitDocument& subDocument,
                                      QOrganizerItem* item) = 0;
};

class Q_VERSIT_ORGANIZER_EXPORT QVersitOrganizerImporter
{
public:
    enum Error {
        NoError = 0,
        InvalidDocumentError,
        EmptyDocumentError
    };

    QVersitOrganizerImporter();
    explicit QVersitOrganizerImporter(const QString& profile);
    ~QVersitOrganizerImporter();

    bool importDocument(const QVersitDocument& document);
    QList<QOrganizerItem> items() const;
    QMap<int, Error> errorMap() const;

    void setPropertyHandler(QVersitOrganizerImporterPropertyHandler* handler);

private:
    QVersitOrganizerImporterPrivate* d;
};

QT_END_NAMESPACE_VERSITORGANIZER

#endif // QVERSITORGANIZERIMPORTER_H
