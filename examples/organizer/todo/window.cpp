// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#include <QtWidgets>

#include <QtOrganizer/qorganizer.h>

#include "window.h"
#include "todoeditor.h"

QTORGANIZER_USE_NAMESPACE

//! [0]
Window::Window()
{
    setupGui();

    manager = new QOrganizerManager("memory");

    setWindowTitle(tr("ToDo Example"));
    refreshList();
}
//! [0]

Window::~Window()
{
    delete manager;
}

//! [1]
void Window::editNewTodo()
{
    QOrganizerTodo newTodo;
    newTodo.setPriority(QOrganizerItemPriority::HighPriority);
    newTodo.setStatus(QOrganizerTodoProgress::StatusNotStarted);
    QDateTime currentDateTime(calendarWidget->selectedDate(),
        QTime::currentTime());
    newTodo.setStartDateTime(currentDateTime);
    newTodo.setDueDateTime(currentDateTime.addSecs(60*60));

    todoEditor->editTodo(newTodo);

    stackedWidget->setCurrentWidget(todoEditor);
}
//! [1]

//! [2]
Q_DECLARE_METATYPE(QOrganizerTodo)

void Window::editTodo(QListWidgetItem *item)
{
    QVariant variant = item->data(Qt::UserRole);
    if (!variant.canConvert<QOrganizerTodo>())
        return;

    QOrganizerTodo todo = variant.value<QOrganizerTodo>();
    todoEditor->editTodo(todo);
    stackedWidget->setCurrentWidget(todoEditor);
}
//! [2]

//! [3]
void Window::saveTodo(QOrganizerTodo &todo)
{
    manager->saveItem(&todo);

    stackedWidget->setCurrentIndex(0);
    refreshList();
}
//! [3]

//! [4]
void Window::deleteTodo()
{
    QList<QListWidgetItem *> items = listWidget->selectedItems();
    if (!items.isEmpty()) {
        QVariant variant = items.at(0)->data(Qt::UserRole);
        if (variant.canConvert<QOrganizerTodo>()) {
            QOrganizerTodo theTodo = variant.value<QOrganizerTodo>();
            manager->removeItem(theTodo.id());
            refreshList();
        }
    }
}
//! [4]

//! [5]
void Window::refreshList()
{
    listWidget->clear();

    QOrganizerItemSortOrder sortOrder;
    sortOrder.setDetail(QOrganizerItemDetail::TypeTodoTime, QOrganizerTodoTime::FieldDueDateTime);

    QList<QOrganizerItem> items =
            manager->items(QDateTime(), QDateTime(), QOrganizerItemFilter(), -1, QList<QOrganizerItemSortOrder>() << sortOrder);
//! [5]
    if (items.isEmpty()) {
       new QListWidgetItem("<No Todos>", listWidget);
    }
//! [6]
    foreach(QOrganizerItem item, items) {
        if (item.type() == QOrganizerItemType::TypeTodo) {
            QOrganizerTodo todo = static_cast<QOrganizerTodo>(item);
            if (todo.startDateTime() > calendarWidget->selectedDate().endOfDay() ||
                todo.dueDateTime() < calendarWidget->selectedDate().startOfDay())
                continue;

            QString display = todo.startDateTime().toString("yy/MM/dd hh:mm") +
                "-" + todo.dueDateTime().toString("yy/MM/dd hh:mm") +
                " - "+ todo.displayLabel();

            QListWidgetItem *listItem =
                new QListWidgetItem(display, listWidget);
            listItem->setData(Qt::UserRole, QVariant::fromValue(todo));
        }
    }
}
//! [6]

void Window::setupGui()
{
    todoEditor = new TodoEditor;

    listWidget = new QListWidget;
    stackedWidget = new QStackedWidget;
    newTodoButton = new QPushButton(tr("New Todo"));
    deletTodoButton = new QPushButton(tr("Delete Todo"));
    calendarWidget = new QCalendarWidget;

    connect(newTodoButton, SIGNAL(clicked()), this, SLOT(editNewTodo()));
    connect(todoEditor, SIGNAL(editingFinished(QOrganizerTodo &)),
            this, SLOT(saveTodo(QOrganizerTodo &)));
    connect(listWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)),
            this, SLOT(editTodo(QListWidgetItem*)));
    connect(calendarWidget, SIGNAL(selectionChanged()),
            this, SLOT(refreshList()));
    connect(deletTodoButton, SIGNAL(clicked()), this, SLOT(deleteTodo()));

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(calendarWidget);
    mainLayout->addWidget(listWidget);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(newTodoButton);
    buttonLayout->addWidget(deletTodoButton);
    mainLayout->addLayout(buttonLayout);

    QWidget *frontPage = new QWidget;
    frontPage->setLayout(mainLayout);

    stackedWidget->addWidget(frontPage);
    stackedWidget->addWidget(todoEditor);

    // Adding a scroll area to allow proper rendering of the UI on small screens
    QScrollArea *scrollArea = new QScrollArea;
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(stackedWidget);
    QSize suggestedSize;
    suggestedSize = stackedWidget->sizeHint();
    stackedWidget->setMinimumSize(suggestedSize);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(scrollArea);

    setLayout(layout);
}
