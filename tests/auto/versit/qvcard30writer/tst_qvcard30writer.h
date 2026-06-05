// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

#ifndef tst_QVCARD30WRITER_H
#define tst_QVCARD30WRITER_H

#include <QObject>
#include <QtVersit/qversitglobal.h>

QT_BEGIN_NAMESPACE_VERSIT
class QVCard30Writer;
QT_END_NAMESPACE_VERSIT

QTVERSIT_USE_NAMESPACE

class tst_QVCard30Writer : public QObject
{
     Q_OBJECT

private slots: // Tests

#ifdef QT_BUILD_INTERNAL
    void init();
    void cleanup();

    void testEncodeVersitProperty();
    void testEncodeVersitProperty_data();
    void testEncodeParameters();
    void testBackSlashEscape();
#endif

private: // Data
    QVCard30Writer* mWriter;
};

#endif // tst_QVCARD30WRITER_H
