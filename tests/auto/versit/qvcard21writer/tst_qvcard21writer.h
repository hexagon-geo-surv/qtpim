// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

#ifndef tst_QVCARD21WRITER_H
#define tst_QVCARD21WRITER_H

#include <QObject>
#include <QtVersit/qversitglobal.h>

QT_BEGIN_NAMESPACE_VERSIT
class QVCard21Writer;
QT_END_NAMESPACE_VERSIT

QTVERSIT_USE_NAMESPACE

class tst_QVCard21Writer : public QObject
{
     Q_OBJECT

private slots: // Tests
#ifdef QT_BUILD_INTERNAL
    void init();
    void cleanup();
    void testEncodeVersitProperty();
    void testEncodeVersitProperty_data();
    void testEncodeParameters();
    void testEncodeParameters_data();
    void testEncodeGroupsAndName();
    void testQuotedPrintableEncode();
#endif

private: // Data
    QVCard21Writer* mWriter;
};

#endif // tst_QVCARD21WRITER_H
