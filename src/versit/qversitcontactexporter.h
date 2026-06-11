// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QVERSITCONTACTEXPORTER_H
#define QVERSITCONTACTEXPORTER_H

#include <QtCore/qlist.h>
#include <QtCore/qmap.h>

#include <QtContacts/qcontact.h>

#include <QtVersit/qversitresourcehandler.h>
#include <QtVersit/qversitdocument.h>

QT_BEGIN_NAMESPACE_CONTACTS
class QContactDetail;
QT_END_NAMESPACE_CONTACTS

QTCONTACTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE_VERSIT

class QVersitContactExporterPrivate;

class Q_VERSIT_EXPORT QVersitContactExporterDetailHandler
{
public:
    virtual ~QVersitContactExporterDetailHandler();
    virtual bool preProcessDetail(const QContact& contact,
                                  const QContactDetail& detail,
                                  QVersitDocument* document) = 0;
    virtual bool postProcessDetail(const QContact& contact,
                                   const QContactDetail& detail,
                                   bool alreadyProcessed,
                                   QVersitDocument* document) = 0;

};

class Q_VERSIT_EXPORT QVersitContactExporterDetailHandlerV2
{
public:
    virtual ~QVersitContactExporterDetailHandlerV2();

    virtual void detailProcessed(const QContact& contact,
                                 const QContactDetail& detail,
                                 const QVersitDocument& document,
                                 QSet<int>* processedFields,
                                 QList<QVersitProperty>* toBeRemoved,
                                 QList<QVersitProperty>* toBeAdded) = 0;
    virtual void contactProcessed(const QContact& contact,
                                  QVersitDocument* document) = 0;
};

class Q_VERSIT_EXPORT QVersitContactExporter
{
public:
    enum Error {
        NoError = 0,
        EmptyContactError,
        NoNameError
    };

    QVersitContactExporter();
    explicit QVersitContactExporter(const QString& profile);
    explicit QVersitContactExporter(const QStringList& profile);
    ~QVersitContactExporter();

    bool exportContacts(const QList<QTCONTACTS_PREPEND_NAMESPACE(QContact)>& contacts,
            QVersitDocument::VersitType versitType = QVersitDocument::VCard30Type);
    QList<QVersitDocument> documents() const;
    QMap<int, Error> errorMap() const;

    void setDetailHandler(QVersitContactExporterDetailHandlerV2* handler);

    void setResourceHandler(QVersitResourceHandler* handler);
    QVersitResourceHandler* resourceHandler() const;

    /* deprecated */
    QMap<int, Error> errors() const;
    void setDetailHandler(QVersitContactExporterDetailHandler* handler);
    QVersitContactExporterDetailHandler* detailHandler() const;

private:
    QVersitContactExporterPrivate* d;
};

QT_END_NAMESPACE_VERSIT

#endif // QVERSITCONTACTEXPORTER_H
