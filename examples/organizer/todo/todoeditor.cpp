// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#include <QtWidgets>

#include <QtOrganizer/qorganizer.h>

#include "todoeditor.h"

QTORGANIZER_USE_NAMESPACE

TodoEditor::TodoEditor()
{
    setupGui();
}

//! [1]
void TodoEditor::editTodo(const QOrganizerTodo &newTodo)
{
    todo = newTodo;

    subjectLineEdit->setText(todo.displayLabel());
    startDateEdit->setDateTime(todo.startDateTime());
    dueDateEdit->setDateTime(todo.dueDateTime());
    priorityCombo->setCurrentIndex(
        priorityCombo->findData(QVariant(todo.priority())));
    statusCombo->setCurrentIndex(
        statusCombo->findData(QVariant(todo.status())));
    descriptionTextEdit->setText(todo.description());
//! [1]

//! [2]
    if (!todo.details(QOrganizerItemDetail::TypeVisualReminder).isEmpty()){
        QOrganizerItemVisualReminder reminder =
            todo.detail(QOrganizerItemDetail::TypeVisualReminder);
        int seconds = reminder.secondsBeforeStart();
        alarmCombo->setCurrentIndex(seconds/(15*60));
    } else
        alarmCombo->setCurrentIndex(0);
}
//! [2]

//! [3]
void TodoEditor::updateSubject()
{
    todo.setDisplayLabel(subjectLineEdit->text());
}

void TodoEditor::updateDescription()
{
    todo.setDescription(descriptionTextEdit->toPlainText());
}
//! [3]

//! [4]
void TodoEditor::updateDates()
{
    QDateTime startTime = startDateEdit->dateTime();
    QDateTime dueDateTime = dueDateEdit->dateTime();

    todo.setStartDateTime(startTime);
    todo.setDueDateTime(dueDateTime);

    updateAlarm(alarmCombo->currentIndex());
}
//! [4]

//! [5]
void TodoEditor::updateStatus(int index)
{
    QOrganizerTodoProgress::Status status =
        (QOrganizerTodoProgress::Status) statusCombo->itemData(index).toInt();
    todo.setStatus(status);
}

void TodoEditor::updatePriority(int index)
{
    QOrganizerItemPriority::Priority priority =
        (QOrganizerItemPriority::Priority)
            priorityCombo->itemData(index).toInt();
    todo.setPriority(priority);
}
//! [5]

//! [6]
void TodoEditor::updateAlarm(int index)
{
    int seconds = index * (15*60);
    QDateTime dueDate = todo.dueDateTime();

    QOrganizerItemVisualReminder oldReminder =
        todo.detail(QOrganizerItemDetail::TypeVisualReminder);
    todo.removeDetail(&oldReminder);

    if (seconds == 0)
        return;

    QOrganizerItemVisualReminder reminder;
    reminder.setSecondsBeforeStart(seconds);

    todo.saveDetail(&reminder);
}
//! [6]

void TodoEditor::finishEditing()
{
    emit editingFinished(todo);
}

void TodoEditor::setupGui()
{
    startDateEdit = new QDateTimeEdit;
    dueDateEdit = new QDateTimeEdit;
    subjectLineEdit = new QLineEdit;
    descriptionTextEdit = new QTextEdit;
    doneButton = new QPushButton(tr("Done"));

    setupCombos();

    connect(startDateEdit, SIGNAL(editingFinished()),
        this, SLOT(updateDates()));
    connect(dueDateEdit, SIGNAL(editingFinished()), this, SLOT(updateDates()));
    connect(subjectLineEdit, SIGNAL(editingFinished()),
        this, SLOT(updateSubject()));
    connect(descriptionTextEdit, SIGNAL(textChanged()),
        this, SLOT(updateDescription()));
    connect(statusCombo, SIGNAL(activated(int)), this, SLOT(updateStatus(int)));
    connect(priorityCombo, SIGNAL(activated(int)),
        this, SLOT(updatePriority(int)));
    connect(alarmCombo, SIGNAL(activated(int)), this, SLOT(updateAlarm(int)));
    connect(doneButton, SIGNAL(clicked()), this, SLOT(finishEditing()));

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(new QLabel(tr("Subject:")));
    layout->addWidget(subjectLineEdit);
    layout->addWidget(new QLabel(tr("Start Date:")));
    layout->addWidget(startDateEdit);
    layout->addWidget(new QLabel(tr("Due Date:")));
    layout->addWidget(dueDateEdit);
    layout->addWidget(new QLabel(tr("Status:")));
    layout->addWidget(statusCombo);
    layout->addWidget(new QLabel(tr("Priority:")));
    layout->addWidget(priorityCombo);
    layout->addWidget(new QLabel(tr("Alarm:")));
    layout->addWidget(alarmCombo);
    layout->addWidget(new QLabel(tr("Description")));
    layout->addWidget(descriptionTextEdit);
    layout->addWidget(doneButton);

    setLayout(layout);
}

//! [0]
void TodoEditor::setupCombos()
{
    priorityCombo = new QComboBox;
    priorityCombo->addItem("Unknown", QOrganizerItemPriority::UnknownPriority);
    priorityCombo->addItem("Highest", QOrganizerItemPriority::HighestPriority);
    priorityCombo->addItem("Extremely high",
        QOrganizerItemPriority::ExtremelyHighPriority);
    priorityCombo->addItem("Very high",
        QOrganizerItemPriority::VeryHighPriority);
    priorityCombo->addItem("High", QOrganizerItemPriority::HighPriority);
    priorityCombo->addItem("Medium", QOrganizerItemPriority::MediumPriority);
    priorityCombo->addItem("Low", QOrganizerItemPriority::LowPriority);
    priorityCombo->addItem("Very low", QOrganizerItemPriority::VeryLowPriority);
    priorityCombo->addItem("Extremely low",
        QOrganizerItemPriority::ExtremelyLowPriority);
    priorityCombo->addItem("Lowest", QOrganizerItemPriority::LowestPriority);

    statusCombo = new QComboBox;
    statusCombo->addItem("Not started",
        QOrganizerTodoProgress::StatusNotStarted);
    statusCombo->addItem("In progress", QOrganizerTodoProgress::StatusInProgress);
    statusCombo->addItem("Complete",
        QOrganizerTodoProgress::StatusComplete);

    alarmCombo = new QComboBox;
    QStringList alarmList;
    alarmList << "None" << "15 minutes" << "30 minutes" << "45 minutes"
              << "1 hour";
    alarmCombo->addItems(alarmList);
}
//! [0]

