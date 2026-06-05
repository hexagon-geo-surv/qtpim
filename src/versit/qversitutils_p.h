// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QVERSITUTILS_P_H
#define QVERSITUTILS_P_H

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

#include <QtCore/qbytearray.h>
#include <QtCore/qbytearraymatcher.h>
#include <QtCore/qlist.h>
#include <QtCore/QMutex>

#include <QtVersit/qversitproperty.h>

QT_FORWARD_DECLARE_CLASS(QString)
QT_FORWARD_DECLARE_CLASS(QTextCodec)
QT_FORWARD_DECLARE_CLASS(QVariant)

QT_BEGIN_NAMESPACE_VERSIT

class QVersitDocument;

class Q_VERSIT_EXPORT VersitUtils
{
public:
    static QByteArray encode(const QByteArray& ba, QTextCodec* codec);
    static QByteArray encode(char ch, QTextCodec* codec);
    static QList<QByteArrayMatcher>* newlineList(QTextCodec* codec);
    static void changeCodec(QTextCodec* codec);
    static QVersitProperty takeProperty(const QVersitDocument& document,
                                        const QString& propertyName,
                                        QList<QVersitProperty>* toBeRemoved);
    static bool isValidUtf8(const QByteArray& bytes);
    static bool convertToJson(const QVariant &data, QString *json);
    static bool convertFromJson(const QString &json, QVariant *data);

private:
    // These are caches for performance:
    // The previous codec that encode(char, QTextCodec) was called with
    static QTextCodec* m_previousCodec;
    // The QByteArray corresponding to each char from 0-255, encoded with m_previousCodec
    static QByteArray m_encodingMap[256];
    // List of different newline delimeters, encoded with m_previousCodec
    static QList<QByteArrayMatcher>* m_newlineList;
    static QBasicMutex m_staticLock;
};

QT_END_NAMESPACE_VERSIT

#endif // QVERSITUTILS_P_H
