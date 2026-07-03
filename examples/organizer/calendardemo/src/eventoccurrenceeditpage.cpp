// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause
#include "eventoccurrenceeditpage.h"

#include <QtWidgets>
#include <QtOrganizer/qorganizer.h>

QTORGANIZER_USE_NAMESPACE

EventOccurrenceEditPage::EventOccurrenceEditPage(QWidget *parent)
    :QWidget(parent),
    m_manager(0),
    scrollAreaLayout(0),
    m_typeComboBox(0),
    m_subjectEdit(0),
    m_countSpinBox(0),
    m_repeatUntilDate(0)
{
    //create asynch request to save an item
    m_saveItemRequest = new QOrganizerItemSaveRequest(this);
    // Create widgets
    QLabel *subjectLabel = new QLabel("Subject:", this);
    m_subjectEdit = new QLineEdit(this);
    QLabel *startTimeLabel = new QLabel("Start time:", this);
    m_startTimeEdit = new QDateTimeEdit(this);
    m_startTimeEdit->setDisplayFormat(QString("yyyy-MM-dd hh:mm:ss AP"));
    QLabel *endTimeLabel = new QLabel("End time:", this);
    m_endTimeEdit = new QDateTimeEdit(this);
    m_endTimeEdit->setDisplayFormat(QString("yyyy-MM-dd hh:mm:ss AP"));

    // Add push buttons
    QHBoxLayout* hbLayout = new QHBoxLayout();
    QPushButton *okButton = new QPushButton("Ok", this);
    connect(okButton, &QPushButton::clicked, this, &EventOccurrenceEditPage::saveOrNextClicked);
    hbLayout->addWidget(okButton);
    QPushButton *cancelButton = new QPushButton("Cancel", this);
    connect(cancelButton, &QPushButton::clicked, this, &EventOccurrenceEditPage::cancelClicked);
    hbLayout->addWidget(cancelButton);

    scrollAreaLayout = new QVBoxLayout();
    scrollAreaLayout->addWidget(subjectLabel);
    scrollAreaLayout->addWidget(m_subjectEdit);
    scrollAreaLayout->addWidget(startTimeLabel);
    scrollAreaLayout->addWidget(m_startTimeEdit);
    scrollAreaLayout->addWidget(endTimeLabel);
    scrollAreaLayout->addWidget(m_endTimeEdit);
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

    m_countFieldAdded = false;
    m_multipleEntries = false;
    m_listOfEvents.clear();
}

EventOccurrenceEditPage::~EventOccurrenceEditPage()
{

}

void EventOccurrenceEditPage::eventOccurrenceChanged(QOrganizerManager *manager, const QOrganizerEventOccurrence &eventOccurrence)
{
    m_manager = manager;
    m_organizerEventOccurrence = eventOccurrence;
    m_subjectEdit->setText(eventOccurrence.displayLabel());
    m_startTimeEdit->setDateTime(eventOccurrence.startDateTime());
    m_endTimeEdit->setDateTime(eventOccurrence.endDateTime());
}

void EventOccurrenceEditPage::cancelClicked()
{
    emit showDayPage();
}

void EventOccurrenceEditPage::saveOrNextClicked()
{
    QDateTime start(m_startTimeEdit->dateTime());
    QDateTime end(m_endTimeEdit->dateTime());
    if (start > end) {
        QMessageBox::warning(this, "Failed!", "Start date is not before end date");
        return;
    }

    m_organizerEventOccurrence.setDisplayLabel(m_subjectEdit->text());
    m_organizerEventOccurrence.setStartDateTime(start);
    m_organizerEventOccurrence.setEndDateTime(end);
    m_listOfEvents.append(m_organizerEventOccurrence);
    if (m_numOfEntiresToBeCreated > 1) {
        m_numOfEntiresToBeCreated--;
        // Clear subject field indicating its a new editor.
        m_subjectEdit->clear();
    } else {
        if (!m_multipleEntries) {
                // If single entry
                m_manager->saveItem(&m_organizerEventOccurrence);
        } else {
                // If multiple entries, save asynchronously.
                m_saveItemRequest->setItems(m_listOfEvents);
                m_saveItemRequest->setManager(m_manager);
                m_saveItemRequest->start();
        }

        if (m_manager->error())
                QMessageBox::warning(this, "Failed!", QString("Failed to save event occurrence!\n(error code %1)").arg(m_manager->error()));
        else
                emit showDayPage();
    }
}

void EventOccurrenceEditPage::showEvent(QShowEvent *event)
{
    window()->setWindowTitle("Edit event occurrence");
    QWidget::showEvent(event);
}

