// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "vcardpreserver.h"

#include <QtCore/qdatetime.h>
#include <QtCore/qvariant.h>
#include <QtCore/qurl.h>

#include <QtContacts/qcontact.h>
#include <QtContacts/qcontactdetail.h>
#include <QtContacts/qcontactextendeddetail.h>

#include <QtVersit/qversitdocument.h>
#include <QtVersit/qversitproperty.h>

/*
    When these conditions are satisfied, QStringLiteral is implemented by
    gcc's statement-expression extension.  However, in this file it will
    not work, because "statement-expressions are not allowed outside functions
    nor in template-argument lists".

    Fall back to the less-performant QLatin1String in this case.
*/
#if defined(QStringLiteral) && defined(QT_UNICODE_LITERAL_II) && defined(Q_CC_GNU) && !defined(Q_COMPILER_LAMBDA)
# undef QStringLiteral
# define QStringLiteral QLatin1String
#endif

QTCONTACTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE_VERSIT

class VCardPreserver : public QVersitContactHandler
{
public:
    VCardPreserver();
    void propertyProcessed(const QVersitDocument& document,
                           const QVersitProperty& property,
                           const QContact& contact,
                           bool* alreadyProcessed,
                           QList<QContactDetail>* updatedDetails);
    void documentProcessed(const QVersitDocument& document,
                           QContact* contact);
    void detailProcessed(const QContact& contact,
                         const QContactDetail& detail,
                         const QVersitDocument& document,
                         QSet<int>* processedFields,
                         QList<QVersitProperty>* toBeRemoved,
                         QList<QVersitProperty>* toBeAdded);
    void contactProcessed(const QContact& contact,
                          QVersitDocument* document);
};

const QContactDetail::DetailType DetailType(QContactDetail::TypeExtendedDetail);
const QContactExtendedDetail::ExtendedDetailField KeyField(QContactExtendedDetail::FieldName);
const QContactExtendedDetail::ExtendedDetailField ValueField(QContactExtendedDetail::FieldData);


QSet<QString> VCardPreserverFactory::profiles() const
{
    QSet<QString> retval;
    // TODO: use this line in 1.2 when the constant is enabled
    //retval.insert(QVersitContactHandlerFactory::ProfilePreserve);
    retval.insert(QStringLiteral("Preserve"));
    return retval;
}

QString VCardPreserverFactory::name() const
{
    return QStringLiteral("org.qt-project.Qt.VCardPreserverFactory");
}

int VCardPreserverFactory::index() const
{
    // Prefer to run this plugin last, but before the backup handler.
    return -2;
}

QVersitContactHandler* VCardPreserverFactory::createHandler() const
{
    return new VCardPreserver();
}

QStringList VCardPreserverFactory::keys() const
{
    return QStringList() << name();
}

VCardPreserver::VCardPreserver()
{
}

void VCardPreserver::propertyProcessed(const QVersitDocument& document,
                                       const QVersitProperty& property,
                                       const QContact& contact,
                                       bool* alreadyProcessed,
                                       QList<QContactDetail>* updatedDetails)
{
    Q_UNUSED(contact);
    Q_UNUSED(document);
    if (!updatedDetails->isEmpty() || *alreadyProcessed) {
        return;
    }
    QContactDetail detail(DetailType);
    detail.setValue(KeyField, property.name());
    detail.setValue(ValueField, property.value());
    updatedDetails->append(detail);
    *alreadyProcessed = true;
}

void VCardPreserver::documentProcessed(const QVersitDocument& document,
                                       QContact* contact)
{
    Q_UNUSED(document);
    Q_UNUSED(contact);
}

void VCardPreserver::detailProcessed(const QContact& contact,
                                     const QContactDetail& detail,
                                     const QVersitDocument& document,
                                     QSet<int>* processedFields,
                                     QList<QVersitProperty>* toBeRemoved,
                                     QList<QVersitProperty>* toBeAdded)
{
    Q_UNUSED(contact);
    Q_UNUSED(document);
    Q_UNUSED(toBeRemoved);
    if (detail.type() == DetailType
            && processedFields->isEmpty()) {
        QString key(detail.value(KeyField).toString());
        QString value(detail.value(ValueField).toString());
        if (!key.isEmpty() && !value.isEmpty()) {
            QVersitProperty property;
            property.setName(key);
            property.setValue(value);
            toBeAdded->append(property);
        }
        processedFields->insert(KeyField);
        processedFields->insert(ValueField);
    }
}

void VCardPreserver::contactProcessed(const QContact& contact,
                                      QVersitDocument* document)
{
    Q_UNUSED(contact);
    Q_UNUSED(document);
}

QT_END_NAMESPACE_VERSIT

#include "moc_vcardpreserver.cpp"
