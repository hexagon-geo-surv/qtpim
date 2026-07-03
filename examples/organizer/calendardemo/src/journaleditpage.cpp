// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause
#include "journaleditpage.h"

#include <QtWidgets>
#include <QComboBox>
#include <QtOrganizer/qorganizer.h>

QTORGANIZER_USE_NAMESPACE

JournalEditPage::JournalEditPage(QWidget *parent)
    :QWidget(parent),
    m_manager(0),
    m_subjectEdit(0),
    m_timeEdit(0),
    m_alarmComboBox(0)
{
    // Create widgets
    QLabel *subjectLabel = new QLabel("Subject:", this);
    m_subjectEdit = new QLineEdit(this);
    QLabel *startTimeLabel = new QLabel("Time:", this);
    m_timeEdit = new QDateTimeEdit(this);
    m_timeEdit->setDisplayFormat(QString("yyyy-MM-dd hh:mm:ss AP"));
    QLabel *alarmLabel = new QLabel("Alarm:", this);
    m_alarmComboBox = new QComboBox(this);
    QLabel *calendarLabel = new QLabel("Calendar:", this);

    QStringList alarmList;
    alarmList  << "None"
                << "0 minutes before"
                << "5 minutes before"
                << "15 minutes before"
                << "30 minutes before"
                << "1 hour before";
    m_alarmComboBox->addItems(alarmList);
    connect(m_alarmComboBox, &QComboBox::currentTextChanged, this,
                        &JournalEditPage::handleAlarmIndexChanged);

    m_calendarComboBox = new QComboBox(this);
    // the calendar names are not know here, fill the combo box later...

    // Add push buttons
    QHBoxLayout* hbLayout = new QHBoxLayout();
    QPushButton *okButton = new QPushButton("Ok", this);
    connect(okButton, &QPushButton::clicked, this, &JournalEditPage::saveClicked);
    hbLayout->addWidget(okButton);
    QPushButton *cancelButton = new QPushButton("Cancel", this);
    connect(cancelButton, &QPushButton::clicked, this, &JournalEditPage::cancelClicked);
    hbLayout->addWidget(cancelButton);

    // check to see whether we support alarms.
    QOrganizerManager defaultManager;
    QList<QOrganizerItemDetail::DetailType> supportedDetails = defaultManager.supportedItemDetails(QOrganizerItemType::TypeJournal);

    QVBoxLayout *scrollAreaLayout = new QVBoxLayout();
    scrollAreaLayout->addWidget(subjectLabel);
    scrollAreaLayout->addWidget(m_subjectEdit);
    scrollAreaLayout->addWidget(startTimeLabel);
    scrollAreaLayout->addWidget(m_timeEdit);
    if (supportedDetails.contains(QOrganizerItemDetail::TypeVisualReminder)) {
        scrollAreaLayout->addWidget(alarmLabel);
        scrollAreaLayout->addWidget(m_alarmComboBox);
    }
    scrollAreaLayout->addWidget(calendarLabel);
    scrollAreaLayout->addWidget(m_calendarComboBox);
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

JournalEditPage::~JournalEditPage()
{

}

void JournalEditPage::journalChanged(QOrganizerManager *manager, const QOrganizerJournal &journal)
{
    m_manager = manager;
    m_organizerJournal = journal;
    m_subjectEdit->setText(journal.displayLabel());
    m_timeEdit->setDateTime(journal.dateTime());

    // set calendar selection
    m_calendarComboBox->clear();

    // resolve metadata field that contains calendar name (if any)
    m_collections = m_manager->collections();
    int index = 0;
    int journalCalendarIndex = -1;
    foreach(QOrganizerCollection collection, m_collections) {
        // We currently have no way of stringifying ids
        // QString visibleName = "Calendar id = " + QString::number(collection.id().localId());
        QString visibleName = collection.metaData(QOrganizerCollection::KeyName).toString();
        if (visibleName.isEmpty())
            visibleName = "Calendar " + QString::number(index);

        m_calendarComboBox->addItem(visibleName);
        if (collection.id() == journal.collectionId())
            journalCalendarIndex = index;
        ++index;
    }

    if (journalCalendarIndex > -1) {
        m_calendarComboBox->setCurrentIndex(journalCalendarIndex);
        m_calendarComboBox->setEnabled(false); // when modifying existing events, the calendar can't be changed anymore
    }
    else {
        m_calendarComboBox->setEnabled(true);
    }
}


void JournalEditPage::cancelClicked()
{
    emit showDayPage();
}

void JournalEditPage::saveClicked()
{
    // Read data from page
    m_organizerJournal.setDisplayLabel(m_subjectEdit->text());
    m_organizerJournal.setDateTime(m_timeEdit->dateTime());

    // Save
    if (m_calendarComboBox->currentIndex() > -1) {
        m_organizerJournal.setCollectionId(m_collections[m_calendarComboBox->currentIndex()].id());
    }
    m_manager->saveItem(&m_organizerJournal);
    if (m_manager->error())
        QMessageBox::warning(this, "Failed!", QString("Failed to save journal!\n(error code %1)").arg(m_manager->error()));
    else
        emit showDayPage();
}

void JournalEditPage::showEvent(QShowEvent *event)
{
    window()->setWindowTitle("Edit journal");
    QWidget::showEvent(event);
}

void JournalEditPage::handleAlarmIndexChanged(const QString time)
{
    QOrganizerItemVisualReminder reminder;
    reminder.setMessage(m_subjectEdit->text());

    if (time == "None") {
         QOrganizerItemVisualReminder fetchedReminder = m_organizerJournal.detail(QOrganizerItemDetail::TypeVisualReminder);
         m_organizerJournal.removeDetail(&fetchedReminder);
        return;
    } else if (time == "0 minutes before") {
        reminder.setSecondsBeforeStart(0);
    } else if (time == "5 minutes before") {
        reminder.setSecondsBeforeStart(5*60);
    } else if (time == "15 minutes before") {
        reminder.setSecondsBeforeStart(15*60);
    } else if (time == "30 minutes before") {
        reminder.setSecondsBeforeStart(30*60);
    } else if (time == "1 hour before") {
        reminder.setSecondsBeforeStart(60*60);
    }

    m_organizerJournal.saveDetail(&reminder);
}

