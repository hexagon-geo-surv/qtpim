// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

#ifndef tst_QVERSITPROPERTY_H
#define tst_QVERSITPROPERTY_H

#include <QObject>
#include <QtVersit/qversitproperty.h>

QT_BEGIN_NAMESPACE_VERSIT
class QVersitProperty;
QT_END_NAMESPACE_VERSIT

QTVERSIT_USE_NAMESPACE

class tst_QVersitProperty : public QObject
{
    Q_OBJECT

private slots:

    void init();
    void cleanup();

private slots: //test methods

    void testGroup();
    void testName();
    void testParameters();
    void testValue();
    void testEmbeddedDocument();
    void testEquality();
    void testHash();

private:
    QVersitProperty* mVersitProperty;

};

#endif //tst_QVERSITPROPERTY_H
