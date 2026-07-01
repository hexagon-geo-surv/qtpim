// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#ifndef DAYPAGE_H_
#define DAYPAGE_H_

#include <QWidget>
#include <QDate>
#include <QtOrganizer/qorganizeritemid.h>

QT_BEGIN_NAMESPACE_ORGANIZER
class QOrganizerManager;
class QOrganizerItem;
QT_END_NAMESPACE_ORGANIZER

QTORGANIZER_USE_NAMESPACE

QT_BEGIN_NAMESPACE
class QMainWindow;
class QLabel;
class QListWidget;
class QListWidgetItem;
class QMenuBar;
class QMenu;
QT_END_NAMESPACE

class DayPage : public QWidget
{
    Q_OBJECT

public:
    DayPage(QWidget *parent = Q_NULLPTR);
    ~DayPage();

public Q_SLOTS:
    void refresh();
    void changeManager(QOrganizerManager *manager);
    void dayChanged(QDate date);
    void editItem();
    void removeItem();

private Q_SLOTS:
    void itemDoubleClicked(QListWidgetItem *listItem);
    void viewMonthClicked();

Q_SIGNALS:
    void showMonthPage();
    void showEditPage(const QOrganizerItem &item);
    void addNewEvent();
    void addNewTodo();
    void addNewJournal();

protected: // from QWidget
    void showEvent(QShowEvent *event);

private:
    QOrganizerManager *m_manager;
    QDate m_day;
    QLabel *m_dateLabel;
    QListWidget *m_itemList;
    QMenuBar *m_menuBar;
};

#endif // DAYPAGE_H_
