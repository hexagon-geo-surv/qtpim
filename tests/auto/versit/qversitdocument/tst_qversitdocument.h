// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

#ifndef tst_QVERSITDOCUMENT_H
#define tst_QVERSITDOCUMENT_H

#include <QObject>
#include <QtVersit/qversitdocument.h>

QT_BEGIN_NAMESPACE_VERSIT
class QVersitDocument;
QT_END_NAMESPACE_VERSIT

QTVERSIT_USE_NAMESPACE

class tst_QVersitDocument : public QObject
{
    Q_OBJECT

private slots:
    void init();
    void cleanup();

    void testConstructor();
    void testType();
    void testAddProperty();
    void testRemoveProperty();
    void testRemoveAllProperties();
    void testEquality();
    void testHash();

private: // data
    QVersitDocument* mVersitDocument;
};

#endif // tst_QVERSITDOCUMENT_H
