// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#ifndef CALENDARDEMO_H
#define CALENDARDEMO_H

#include <QMainWindow>
#include <QDate>
#include <QtOrganizer/qorganizeritemsaverequest.h>
#include <QtOrganizer/qorganizeritemremovebyidrequest.h>

QT_BEGIN_NAMESPACE_ORGANIZER
class QOrganizerManager;
class QOrganizerItem;
QT_END_NAMESPACE_ORGANIZER

QTORGANIZER_USE_NAMESPACE

#define ORGANIZER_ITEM_ROLE Qt::UserRole+1
#define ORGANIZER_CALENDAR_ROLE Qt::UserRole+2

QT_BEGIN_NAMESPACE
class QProgressDialog;
class QStackedWidget;
QT_END_NAMESPACE

class MonthPage;
class DayPage;
class EventEditPage;
class TodoEditPage;
class JournalEditPage;
class EventOccurrenceEditPage;
class AddCalendarPage;
class EditCalendarsPage;

class CalendarDemo : public QMainWindow
{
    Q_OBJECT

public:
    CalendarDemo(QWidget *parent = Q_NULLPTR);
    ~CalendarDemo();

public Q_SLOTS:
    void activateMonthPage();
    void activateDayPage();
    void activateEditPage(const QOrganizerItem &item);
    void activatePreviousPage();
    void addNewEvent();
    void addNewTodo();
    void addNewJournal();
    void changeManager(QOrganizerManager *manager);
    void updateSelectedDay(const QDate& date);

private Q_SLOTS:
    void switchView();
    void editItem();
    void removeItem();
    void addEvents();
    void importItems();
    void exportItems();
    void deleteAllEntries();
    void addCalendar();
    void editCalendar();
    void editExistingCalendar(QOrganizerManager *manager, QOrganizerCollection* calendar);
    void saveReqStateChanged(QOrganizerAbstractRequest::State);
    void removeReqStateChanged(QOrganizerAbstractRequest::State);

private:
    void buildMenu();

    QDate m_currentDate;
    QOrganizerManager *m_manager;
    QStackedWidget *m_stackedWidget;
    MonthPage *m_monthPage;
    DayPage *m_dayPage;
    EventEditPage *m_eventEditPage;
    TodoEditPage *m_todoEditPage;
    JournalEditPage *m_journalEditPage;
    EventOccurrenceEditPage *m_eventOccurrenceEditPage;
    AddCalendarPage *m_addCalendarPage;
    EditCalendarsPage *m_editCalendarsPage;

    int m_previousPage;
    QOrganizerItem m_previousItem;

    QAction *m_switchViewAction;

    QOrganizerItemSaveRequest m_saveReq;
    QOrganizerItemRemoveByIdRequest m_remReq;
    QProgressDialog *m_progressDlg;
};

#endif // CALENDARDEMO_H
