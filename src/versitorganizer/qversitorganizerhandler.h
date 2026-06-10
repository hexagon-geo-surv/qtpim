// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QVERSITORGANIZERHANDLER_H
#define QVERSITORGANIZERHANDLER_H

#include <QtVersitOrganizer/qversitorganizerimporter.h>
#include <QtVersitOrganizer/qversitorganizerexporter.h>

QT_BEGIN_NAMESPACE_VERSITORGANIZER

// qdoc seems to not find QVersitOrganizerHandler if it is declared first, hence this forward
// declaration
class QVersitOrganizerHandler;

class Q_VERSIT_ORGANIZER_EXPORT QVersitOrganizerHandlerFactory
{
public:
    virtual ~QVersitOrganizerHandlerFactory() {}
    virtual QSet<QString> profiles() const { return QSet<QString>(); }
    virtual QString name() const = 0;
    virtual int index() const { return 0; }
    virtual QVersitOrganizerHandler* createHandler() const = 0;

    inline static const QString ProfileSync() {return QStringLiteral("Sync");};
    inline static const QString ProfileBackup() {return QStringLiteral("Backup");};
};

class Q_VERSIT_ORGANIZER_EXPORT QVersitOrganizerHandler : public QVersitOrganizerImporterPropertyHandler,
                                                public QVersitOrganizerExporterDetailHandler
{
public:
    virtual ~QVersitOrganizerHandler() {}
};

QT_END_NAMESPACE_VERSITORGANIZER

#define QT_VERSIT_ORGANIZER_HANDLER_INTERFACE "org.qt-project.Qt.QVersitOrganizerHandlerFactory"
QT_BEGIN_NAMESPACE
Q_DECLARE_INTERFACE(QtVersitOrganizer::QVersitOrganizerHandlerFactory, QT_VERSIT_ORGANIZER_HANDLER_INTERFACE)
QT_END_NAMESPACE

#endif // QVERSITORGANIZERHANDLER_H
