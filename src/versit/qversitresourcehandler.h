// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QVERSITRESOURCEHANDLER_H
#define QVERSITRESOURCEHANDLER_H

#include <QtVersit/qversitglobal.h>

QT_FORWARD_DECLARE_CLASS(QByteArray)
QT_FORWARD_DECLARE_CLASS(QString)

QT_BEGIN_NAMESPACE_VERSIT

class QVersitDefaultResourceHandlerPrivate;
class QVersitProperty;

class Q_VERSIT_EXPORT QVersitResourceHandler
{
public:
    virtual ~QVersitResourceHandler() {}
    virtual bool loadResource(const QString& location, QByteArray* contents, QString* mimeType) = 0;
    virtual bool saveResource(const QByteArray& contents, const QVersitProperty& property,
                              QString* location) = 0;
};

class Q_VERSIT_EXPORT QVersitDefaultResourceHandler : public QVersitResourceHandler
{
public:
    QVersitDefaultResourceHandler();
    virtual ~QVersitDefaultResourceHandler();
    virtual bool loadResource(const QString& location, QByteArray* contents, QString* mimeType) override;
    virtual bool saveResource(const QByteArray& contents, const QVersitProperty& property,
                              QString* location) override;

protected:
    QVersitDefaultResourceHandlerPrivate* d;
};

QT_END_NAMESPACE_VERSIT

#endif // QVERSITRESOURCEHANDLER_H
