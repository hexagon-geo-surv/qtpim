// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

#include <QtPlugin>
#include "plugin5.h"

QTVERSIT_USE_NAMESPACE

class ContactHandler5 : public QVersitContactHandler
{
public:
    void propertyProcessed(const QVersitDocument& document,
                           const QVersitProperty& property,
                           const QContact& contact,
                           bool* alreadyProcessed,
                           QList<QContactDetail>* updatedDetails) override
    {
        Q_UNUSED(document)
        Q_UNUSED(property)
        Q_UNUSED(contact)
        Q_UNUSED(alreadyProcessed)
        Q_UNUSED(updatedDetails)
    }
    void documentProcessed(const QVersitDocument& document,
                           QContact* contact) override
    {
        Q_UNUSED(document)
        QContactDetail detail(QContactDetail::TypeExtendedDetail);
        detail.setValue(0, 5);
        contact->saveDetail(&detail);
    }
    void detailProcessed(const QContact& contact,
                         const QContactDetail& detail,
                         const QVersitDocument& document,
                         QSet<int>* processedFields,
                         QList<QVersitProperty>* toBeRemoved,
                         QList<QVersitProperty>* toBeAdded) override
    {
        Q_UNUSED(contact)
        Q_UNUSED(detail)
        Q_UNUSED(document)
        Q_UNUSED(processedFields)
        Q_UNUSED(toBeRemoved)
        Q_UNUSED(toBeAdded)
    }
    void contactProcessed(const QContact& contact,
                          QVersitDocument* document) override
    {
        Q_UNUSED(contact)
        QVersitProperty property;
        property.setName("TEST-PROPERTY");
        property.setValue("5");
        document->addProperty(property);
    }
};

QString Plugin5::name() const
{
    return QStringLiteral("org.qt-project.Qt.QVersitContactPluginsTest.Plugin5");
}

int Plugin5::index() const
{
    return 1;
}

QVersitContactHandler* Plugin5::createHandler() const
{
    return new ContactHandler5;
}

QSet<QString> Plugin5::profiles() const
{
    return QSet<QString>() << "Test";
}
