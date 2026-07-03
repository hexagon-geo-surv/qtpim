// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause
#include "addcalendarpage.h"

#include <QtWidgets>
#include <QtOrganizer/qorganizer.h>

QTORGANIZER_USE_NAMESPACE

AddCalendarPage::AddCalendarPage(QWidget *parent)
    :QWidget(parent),
    m_manager(0)
{
    QHBoxLayout* hbLayout = new QHBoxLayout();
    QPushButton *okButton = new QPushButton("Save", this);
    connect(okButton, &QPushButton::clicked, this, &AddCalendarPage::saveClicked);
    hbLayout->addWidget(okButton);
    QPushButton *cancelButton = new QPushButton("Cancel", this);
    connect(cancelButton, &QPushButton::clicked, this, &AddCalendarPage::cancelClicked);
    hbLayout->addWidget(cancelButton);

    QVBoxLayout *scrollAreaLayout = new QVBoxLayout();
    scrollAreaLayout->addStretch();
    scrollAreaLayout->addLayout(hbLayout);

    QScrollArea *scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);
    QWidget *formContainer = new QWidget(scrollArea);
    formContainer->setLayout(scrollAreaLayout);
    scrollArea->setWidget(formContainer);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(scrollArea);
    setLayout(mainLayout);
}

AddCalendarPage::~AddCalendarPage()
{

}

void AddCalendarPage::cancelClicked()
{
    emit showPreviousPage();
}

void AddCalendarPage::saveClicked()
{
    m_manager->saveCollection(&m_collection);
    if (m_manager->error())
        QMessageBox::warning(this, "Failed!", QString("Failed to save calendar!\n(error code %1)").arg(m_manager->error()));
    else
        emit showPreviousPage();
}

void AddCalendarPage::calendarChanged(QOrganizerManager *manager, QOrganizerCollection& calendar)
{
    m_manager = manager;
    m_collection = calendar;
    window()->setWindowTitle(!calendar.id().isNull() ? "Edit calendar" : "Add calendar");
}
