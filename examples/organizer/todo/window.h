// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QtOrganizer/qorganizerglobal.h>

QT_BEGIN_NAMESPACE_ORGANIZER
class QOrganizerManager;
class QOrganizerTodo;
QT_END_NAMESPACE_ORGANIZER

QTORGANIZER_USE_NAMESPACE

class TodoEditor;

QT_BEGIN_NAMESPACE
class QListWidget;
class QStackedWidget;
class QPushButton;
class QListWidgetItem;
class QCalendarWidget;
QT_END_NAMESPACE

//![0]
class Window : public QWidget
{
    Q_OBJECT

public:
    Window();
    ~Window();

private slots:
    void editNewTodo();
    void editTodo(QListWidgetItem *item);
    void saveTodo(QOrganizerTodo &todo);
    void refreshList();
    void deleteTodo();

private:
    void setupGui();

    QOrganizerManager *manager;

    TodoEditor *todoEditor;

    QListWidget *listWidget;
    QStackedWidget *stackedWidget;
    QPushButton *newTodoButton;
    QPushButton *deletTodoButton;
    QCalendarWidget *calendarWidget;
};
//![0]

#endif

