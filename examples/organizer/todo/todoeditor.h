// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#ifndef TODOEDITOR_H
#define TODOEDITOR_H

#include <QWidget>

#include <QtOrganizer/qorganizertodo.h>

QTORGANIZER_USE_NAMESPACE

QT_BEGIN_NAMESPACE
class QDateTimeEdit;
class QComboBox;
class QLineEdit;
class QTextEdit;
class QPushButton;
QT_END_NAMESPACE

//! [0]
class TodoEditor : public QWidget
{
    Q_OBJECT

public:
    TodoEditor();

signals:
    void editingFinished(QOrganizerTodo &todo);

public slots:
    void editTodo(const QOrganizerTodo &todo);

private slots:
    void updateSubject();
    void updateDescription();
    void updateDates();
    void updateStatus(int index);
    void updatePriority(int index);
    void updateAlarm(int index);
    void finishEditing();

private:
    void setupGui();
    void setupCombos();

    QOrganizerTodo todo;

    QDateTimeEdit *startDateEdit;
    QDateTimeEdit *dueDateEdit;
    QComboBox *statusCombo;
    QComboBox *priorityCombo;
    QComboBox *alarmCombo;
    QLineEdit *subjectLineEdit;
    QTextEdit *descriptionTextEdit;
    QPushButton *doneButton;
};
//! [0]

#endif

