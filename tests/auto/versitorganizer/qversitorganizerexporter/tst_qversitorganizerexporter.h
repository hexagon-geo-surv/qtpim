// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

#ifndef tst_QVERSITORGANIZEREXPORTER_H
#define tst_QVERSITORGANIZEREXPORTER_H

#include <QObject>
#include <QtVersitOrganizer/qversitorganizerexporter.h>
#include <QtVersit/qversitdocument.h>
#include <QtVersit/qversitproperty.h>
#include <QtOrganizer/qorganizer.h>

QTORGANIZER_USE_NAMESPACE
QTVERSIT_USE_NAMESPACE
QTVERSITORGANIZER_USE_NAMESPACE

class tst_QVersitOrganizerExporter : public QObject
{
    Q_OBJECT

private slots:
    void testExport();
    void testExport_data();

    void testExportError();
    void testExportError_data();

    void testExportEventDetails();
    void testExportEventDetails_data();

    void testExportTodoDetails();
    void testExportTodoDetails_data();

    void testEmptyItemShouldNotBeExported();

    void testExtendedDetail();
    void testExtendedDetail_data();
    void testMultipleExtendedDetails();
    QOrganizerItemExtendedDetail createExtendedDetail(
            const QString &name,
            const QVariant &data);
    QVersitProperty createExtendedDetailProperty(
                const QString &name,
                const QVariant &data);
    QVersitProperty createExtendedDetailPropertyForStringData(
            const QString &name,
            const QString &data);

    static QList<QVersitProperty> findPropertiesByName(const QVersitDocument &document, const QString &propertyName);
};

#endif
