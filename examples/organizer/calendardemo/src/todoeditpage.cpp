// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause
#include "todoeditpage.h"

#include <QtWidgets>
#include <QComboBox>
#include <QtOrganizer/qorganizer.h>

QTORGANIZER_USE_NAMESPACE

TodoEditPage::TodoEditPage(QWidget *parent)
    :QWidget(parent),
    m_manager(0),
    m_subjectEdit(0),
    m_startTimeEdit(0),
    m_dueTimeEdit(0),
    m_priorityEdit(0),
    m_statusEdit(0),
    m_alarmComboBox(0)
{
    // Create widgets
    QLabel *subjectLabel = new QLabel("Subject:", this);
    m_subjectEdit = new QLineEdit(this);
    QLabel *startTimeLabel = new QLabel("Start time:", this);
    m_startTimeEdit = new QDateTimeEdit(this);
    m_startTimeEdit->setDisplayFormat(QString("yyyy-MM-dd hh:mm:ss AP"));
    QLabel *dueTimeLabel = new QLabel("Due time:", this);
    m_dueTimeEdit = new QDateTimeEdit(this);
    m_dueTimeEdit->setDisplayFormat(QString("yyyy-MM-dd hh:mm:ss AP"));
    QLabel *priorityLabel = new QLabel("Priority:", this);
    m_priorityEdit = new QComboBox(this);
    QLabel *statusLabel = new QLabel("Status:", this);
    m_statusEdit = new QComboBox(this);
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
    connect(m_alarmComboBox, SIGNAL(currentIndexChanged(const QString)), this,
                        SLOT(handleAlarmIndexChanged(const QString)));

    m_calendarComboBox = new QComboBox(this);
    // the calendar names are not know here, fill the combo box later...

    // Add push buttons
    QHBoxLayout* hbLayout = new QHBoxLayout();
    QPushButton *okButton = new QPushButton("Save", this);
    connect(okButton,SIGNAL(clicked()),this,SLOT(saveClicked()));
    hbLayout->addWidget(okButton);
    QPushButton *cancelButton = new QPushButton("Cancel", this);
    connect(cancelButton,SIGNAL(clicked()),this,SLOT(cancelClicked()));
    hbLayout->addWidget(cancelButton);

    // check to see whether we support alarms.
    QOrganizerManager defaultManager;
    QList<QOrganizerItemDetail::DetailType> supportedDetails = defaultManager.supportedItemDetails(QOrganizerItemType::TypeTodo);

    QVBoxLayout *scrollAreaLayout = new QVBoxLayout();
    scrollAreaLayout->addWidget(subjectLabel);
    scrollAreaLayout->addWidget(m_subjectEdit);
    scrollAreaLayout->addWidget(startTimeLabel);
    scrollAreaLayout->addWidget(m_startTimeEdit);
    scrollAreaLayout->addWidget(dueTimeLabel);
    scrollAreaLayout->addWidget(m_dueTimeEdit);
    scrollAreaLayout->addWidget(priorityLabel);
    scrollAreaLayout->addWidget(m_priorityEdit);
    scrollAreaLayout->addWidget(statusLabel);
    scrollAreaLayout->addWidget(m_statusEdit);
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

    // Fill priority combo
    m_priorityEdit->addItem("Unknown", QVariant(QOrganizerItemPriority::UnknownPriority));
    m_priorityEdit->addItem("Highest", QVariant(QOrganizerItemPriority::HighestPriority));
    m_priorityEdit->addItem("Extremely high", QVariant(QOrganizerItemPriority::ExtremelyHighPriority));
    m_priorityEdit->addItem("Very high", QVariant(QOrganizerItemPriority::VeryHighPriority));
    m_priorityEdit->addItem("High", QVariant(QOrganizerItemPriority::HighPriority));
    m_priorityEdit->addItem("Medium", QVariant(QOrganizerItemPriority::MediumPriority));
    m_priorityEdit->addItem("Low", QVariant(QOrganizerItemPriority::LowPriority));
    m_priorityEdit->addItem("Very low", QVariant(QOrganizerItemPriority::VeryLowPriority));
    m_priorityEdit->addItem("Extremely low", QVariant(QOrganizerItemPriority::ExtremelyLowPriority));
    m_priorityEdit->addItem("Lowest", QVariant(QOrganizerItemPriority::LowestPriority));

    // Fill status combo
    m_statusEdit->addItem("Not started", QVariant(QOrganizerTodoProgress::StatusNotStarted));
    m_statusEdit->addItem("In progress", QVariant(QOrganizerTodoProgress::StatusInProgress));
    m_statusEdit->addItem("Complete", QVariant(QOrganizerTodoProgress::StatusComplete));
}

TodoEditPage::~TodoEditPage()
{

}

void TodoEditPage::todoChanged(QOrganizerManager *manager, const QOrganizerTodo &todo)
{
    m_manager = manager;
    m_organizerTodo = todo;
    m_subjectEdit->setText(todo.displayLabel());
    m_startTimeEdit->setDateTime(todo.startDateTime());
    m_dueTimeEdit->setDateTime(todo.dueDateTime());
    int index = m_priorityEdit->findData(QVariant(todo.priority()));
    m_priorityEdit->setCurrentIndex(index);
    index = m_priorityEdit->findData(QVariant(todo.status()));
    m_statusEdit->setCurrentIndex(index);

    // set calendar selection
    m_calendarComboBox->clear();

    // resolve metadata field that contains calendar name (if any)
    m_collections = m_manager->collections();
    int counter = 0;
    int todoCalendarIndex = -1;
    foreach(QOrganizerCollection collection, m_collections) {
        // We currently have no way of stringifying ids
        // QString visibleName = "Calendar id = " + QString::number(collection.id().localId());
        QString visibleName = collection.metaData(QOrganizerCollection::KeyName).toString();
        if (visibleName.isEmpty())
            visibleName = "Calendar " + QString::number(index);

        m_calendarComboBox->addItem(visibleName);
        if (collection.id() == todo.collectionId())
            todoCalendarIndex = counter;
        ++counter;
    }

    if (todoCalendarIndex > -1) {
        m_calendarComboBox->setCurrentIndex(todoCalendarIndex);
        m_calendarComboBox->setEnabled(false); // when modifying existing todos, the calendar can't be changed anymore
    }
    else {
        m_calendarComboBox->setEnabled(true);
    }
}


void TodoEditPage::cancelClicked()
{
    emit showDayPage();
}

void TodoEditPage::saveClicked()
{
    // Read data from page
    QDateTime start(m_startTimeEdit->dateTime());
    QDateTime due(m_dueTimeEdit->dateTime());
    if (start > due) {
        QMessageBox::warning(this, "Failed!", "Start date is not before due date");
        return;
    }

    m_organizerTodo.setDisplayLabel(m_subjectEdit->text());
    m_organizerTodo.setStartDateTime(start);
    m_organizerTodo.setDueDateTime(due);
    int index = m_priorityEdit->currentIndex();
    m_organizerTodo.setPriority((QOrganizerItemPriority::Priority) m_priorityEdit->itemData(index).toInt());

    index = m_statusEdit->currentIndex();
    QOrganizerTodoProgress::Status currentStatus = (QOrganizerTodoProgress::Status) m_statusEdit->itemData(index).toInt();
    QOrganizerTodoProgress oldStatus = m_organizerTodo.detail(QOrganizerItemDetail::TypeTodoProgress);
    m_organizerTodo.removeDetail(&oldStatus);
    if (currentStatus == QOrganizerTodoProgress::StatusComplete && oldStatus.status() != QOrganizerTodoProgress::StatusComplete)
        m_organizerTodo.setFinishedDateTime(QDateTime::currentDateTime());
    m_organizerTodo.setStatus(currentStatus);

    // Save
    if (m_calendarComboBox->currentIndex() > -1) {
        m_organizerTodo.setCollectionId(m_collections[m_calendarComboBox->currentIndex()].id());
    }

    m_manager->saveItem(&m_organizerTodo);
    if (m_manager->error())
        QMessageBox::warning(this, "Failed!", QString("Failed to save todo!\n(error code %1)").arg(m_manager->error()));
    else
        emit showDayPage();
}

void TodoEditPage::showEvent(QShowEvent *event)
{
    window()->setWindowTitle("Edit todo");
    QWidget::showEvent(event);
}

void TodoEditPage::handleAlarmIndexChanged(const QString time)
{
    bool noVisualReminders = !m_manager->supportedItemDetails(QOrganizerItemType::TypeEvent).contains(QOrganizerItemDetail::TypeVisualReminder);

        QScopedPointer<QOrganizerItemReminder> reminder;
        if (noVisualReminders) {
            reminder.reset(new QOrganizerItemReminder());
        } else {
            reminder.reset(new QOrganizerItemVisualReminder());
            static_cast<QOrganizerItemVisualReminder *>(reminder.data())->setMessage(m_subjectEdit->text());
        }

    if (time == "None") {
        QOrganizerItemVisualReminder fetchedReminder = m_organizerTodo.detail(QOrganizerItemDetail::TypeVisualReminder);
        m_organizerTodo.removeDetail(&fetchedReminder);
        return;
    } else if (time == "0 minutes before") {
        reminder->setSecondsBeforeStart(0);
    } else if (time == "5 minutes before") {
        reminder->setSecondsBeforeStart(5*60);
    } else if (time == "15 minutes before") {
        reminder->setSecondsBeforeStart(15*60);
    } else if (time == "30 minutes before") {
        reminder->setSecondsBeforeStart(30*60);
    } else if (time == "1 hour before") {
        reminder->setSecondsBeforeStart(60*60);
    }

    m_organizerTodo.saveDetail(reminder.data());
}

