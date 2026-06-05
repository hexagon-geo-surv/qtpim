// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:critical reason:data-parser

#ifndef QVERSITCONTACTIMPORTER_H
#define QVERSITCONTACTIMPORTER_H

#include <QtCore/qlist.h>
#include <QtCore/qmap.h>

#include <QtContacts/qcontact.h>
#include <QtContacts/qcontactdetail.h>

#include <QtVersit/qversitdocument.h>
#include <QtVersit/qversitresourcehandler.h>

QTCONTACTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE_VERSIT

class QVersitProperty;

class QVersitContactImporterPrivate;

class Q_VERSIT_EXPORT QVersitContactImporterPropertyHandler
{
public:
    virtual ~QVersitContactImporterPropertyHandler() {}
    virtual bool preProcessProperty(const QVersitDocument& document,
                                    const QVersitProperty& property,
                                    int contactIndex,
                                    QContact* contact) = 0;
    virtual bool postProcessProperty(const QVersitDocument& document,
                                     const QVersitProperty& property,
                                     bool alreadyProcessed,
                                     int contactIndex,
                                     QContact* contact) = 0;
};

class Q_VERSIT_EXPORT QVersitContactImporterPropertyHandlerV2
{
public:
    virtual ~QVersitContactImporterPropertyHandlerV2() {}
    virtual void propertyProcessed(const QVersitDocument& document,
                                   const QVersitProperty& property,
                                   const QContact& contact,
                                   bool *alreadyProcessed,
                                   QList<QContactDetail>* updatedDetails) = 0;
    virtual void documentProcessed(const QVersitDocument& document,
                                   QContact* contact) = 0;
};

class Q_VERSIT_EXPORT QVersitContactImporter
{
public:
    enum Error {
        NoError = 0,
        InvalidDocumentError,
        EmptyDocumentError
    };

    QVersitContactImporter();
    explicit QVersitContactImporter(const QString& profile);
    explicit QVersitContactImporter(const QStringList& profiles);
    ~QVersitContactImporter();

    bool importDocuments(const QList<QVersitDocument>& documents);
    QList<QContact> contacts() const;
    QMap<int, Error> errorMap() const;

    void setPropertyHandler(QVersitContactImporterPropertyHandlerV2* handler);

    void setResourceHandler(QVersitResourceHandler* handler);
    QVersitResourceHandler* resourceHandler() const;

    /* deprecated */
    QMap<int, Error> errors() const;
    void setPropertyHandler(QVersitContactImporterPropertyHandler* handler);
    QVersitContactImporterPropertyHandler* propertyHandler() const;

private:
    QVersitContactImporterPrivate* d;
};

QT_END_NAMESPACE_VERSIT

#endif // QVERSITCONTACTIMPORTER_H

