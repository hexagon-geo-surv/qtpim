// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

#ifndef tst_QVERSITORGANIZERIMPORTER_H
#define tst_QVERSITORGANIZERIMPORTER_H

#include <QObject>
#include <QtVersitOrganizer/qversitorganizerimporter.h>
#include <QtVersit/qversitdocument.h>
#include <QtVersit/qversitproperty.h>
#include <QtOrganizer/qorganizer.h>

QTORGANIZER_USE_NAMESPACE
QTVERSIT_USE_NAMESPACE
QTVERSITORGANIZER_USE_NAMESPACE

class tst_QVersitOrganizerImporter : public QObject
{
    Q_OBJECT

private slots:
    void testImport();
    void testImport_data();

    void testImportEventProperties();
    void testImportEventProperties_data();

    void testImportTodoProperties();
    void testImportTodoProperties_data();

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

    void testTimeZones();
    void testTimeZones_data();
};

#endif
