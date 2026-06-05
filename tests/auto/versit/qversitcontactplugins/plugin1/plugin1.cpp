// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

#include <QtPlugin>
#include "plugin1.h"

QTVERSIT_USE_NAMESPACE

class ContactHandler1 : public QVersitContactHandler
{
public:
    void propertyProcessed(const QVersitDocument& document,
                           const QVersitProperty& property,
                           const QContact& contact,
                           bool* alreadyProcessed,
                           QList<QContactDetail>* updatedDetails)
    {
        Q_UNUSED(document);
        Q_UNUSED(property);
        Q_UNUSED(contact);
        Q_UNUSED(alreadyProcessed);
        Q_UNUSED(updatedDetails);
    }
    void documentProcessed(const QVersitDocument& document,
                           QContact* contact)
    {
        Q_UNUSED(document);
        QContactDetail detail(QContactDetail::TypeExtendedDetail);
        detail.setValue(0, 1);
        contact->saveDetail(&detail);
    }
    void detailProcessed(const QContact& contact,
                         const QContactDetail& detail,
                         const QVersitDocument& document,
                         QSet<int>* processedFields,
                         QList<QVersitProperty>* toBeRemoved,
                         QList<QVersitProperty>* toBeAdded)
    {
        Q_UNUSED(contact);
        Q_UNUSED(detail);
        Q_UNUSED(document);
        Q_UNUSED(processedFields);
        Q_UNUSED(toBeRemoved);
        Q_UNUSED(toBeAdded);
    }
    void contactProcessed(const QContact& contact,
                          QVersitDocument* document)
    {
        Q_UNUSED(contact);
        QVersitProperty property;
        property.setName("TEST-PROPERTY");
        property.setValue("1");
        document->addProperty(property);
    }
};

QString Plugin1::name() const
{
    return QStringLiteral("org.qt-project.Qt.QVersitContactPluginsTest.Plugin1");
}

int Plugin1::index() const
{
    return 5;
}

QVersitContactHandler* Plugin1::createHandler() const
{
    return new ContactHandler1;
}

QSet<QString> Plugin1::profiles() const
{
    return QSet<QString>() << "Test";
}
