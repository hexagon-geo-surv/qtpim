// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause
#ifndef TODOEDITPAGE_H_
#define TODOEDITPAGE_H_

#include <QWidget>
#include <QDate>
#include <QtOrganizer/qorganizeritemid.h>
#include <QtOrganizer/qorganizertodo.h>
#include <QtOrganizer/qorganizercollection.h>

QT_BEGIN_NAMESPACE_ORGANIZER
class QOrganizerManager;
class QOrganizerEvent;
class QOrganizerItem;
QT_END_NAMESPACE_ORGANIZER

QTORGANIZER_USE_NAMESPACE

QT_BEGIN_NAMESPACE
class QComboBox;
class QLineEdit;
class QDateTimeEdit;
QT_END_NAMESPACE

class TodoEditPage : public QWidget
{
    Q_OBJECT

public:
    TodoEditPage(QWidget *parent = Q_NULLPTR);
    ~TodoEditPage();

public Q_SLOTS:
    void cancelClicked();
    void saveClicked();
    void todoChanged(QOrganizerManager *manager, const QOrganizerTodo &todo);
    void handleAlarmIndexChanged(const QString);


Q_SIGNALS:
    void showDayPage();

protected: // from QWidget
    void showEvent(QShowEvent *event);

private:
    QOrganizerManager *m_manager;
    QOrganizerTodo m_organizerTodo;
    QLineEdit *m_subjectEdit;
    QDateTimeEdit *m_startTimeEdit;
    QDateTimeEdit *m_dueTimeEdit;
    QComboBox *m_priorityEdit;
    QComboBox *m_statusEdit;
    QComboBox *m_alarmComboBox;
    QComboBox *m_calendarComboBox;
    QList<QOrganizerCollection> m_collections;
};

#endif // TODOEDITPAGE_H_
