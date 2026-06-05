// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

#include <QtPlugin>
#include "plugin4.h"

QTVERSIT_USE_NAMESPACE

class ContactHandler4 : public QVersitContactHandler
{
public:
    void propertyProcessed(const QVersitDocument& document,
                           const QVersitProperty& property,
                           const QContact& contact,
                           bool* alreadyProcessed,
                           QList<QContactDetail>* updatedDetails) override
    {
        Q_UNUSED(document);
        Q_UNUSED(property);
        Q_UNUSED(contact);
        Q_UNUSED(alreadyProcessed);
        Q_UNUSED(updatedDetails);
    }
    void documentProcessed(const QVersitDocument& document,
                           QContact* contact) override
    {
        Q_UNUSED(document);
        QContactDetail detail(QContactDetail::TypeExtendedDetail);
        detail.setValue(0, 4);
        contact->saveDetail(&detail);
    }
    void detailProcessed(const QContact& contact,
                         const QContactDetail& detail,
                         const QVersitDocument& document,
                         QSet<int>* processedFields,
                         QList<QVersitProperty>* toBeRemoved,
                         QList<QVersitProperty>* toBeAdded) override
    {
        Q_UNUSED(contact);
        Q_UNUSED(detail);
        Q_UNUSED(document);
        Q_UNUSED(processedFields);
        Q_UNUSED(toBeRemoved);
        Q_UNUSED(toBeAdded);
    }
    void contactProcessed(const QContact& contact,
                          QVersitDocument* document) override
    {
        Q_UNUSED(contact);
        QVersitProperty property;
        property.setName("TEST-PROPERTY");
        property.setValue("4");
        document->addProperty(property);
    }
};

QString Plugin4::name() const
{
    return QStringLiteral("org.qt-project.Qt.QVersitContactPluginsTest.Plugin4");
}

int Plugin4::index() const
{
    return 2;
}

QVersitContactHandler* Plugin4::createHandler() const
{
    return new ContactHandler4;
}

QSet<QString> Plugin4::profiles() const
{
    return QSet<QString>() << "Test";
}
