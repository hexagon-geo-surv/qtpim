// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#ifndef MONTHPAGE_H_
#define MONTHPAGE_H_

#include <QWidget>
#include <QDate>
#include <QtOrganizer/qorganizerglobal.h>

QT_BEGIN_NAMESPACE_ORGANIZER
class QOrganizerManager;
class QOrganizerItem;
QT_END_NAMESPACE_ORGANIZER

QTORGANIZER_USE_NAMESPACE

QT_BEGIN_NAMESPACE
class QComboBox;
class QCalendarWidget;
class QLabel;
class QListWidget;
class QListWidgetItem;
class QMenu;
QT_END_NAMESPACE

class MonthPage : public QWidget
{
    Q_OBJECT

public:
    MonthPage(QWidget *parent = Q_NULLPTR);
    ~MonthPage();
    void init();

private Q_SLOTS:
    void backendChanged(const QString &managerName);
    void refreshDayItems();
    void currentMonthChanged();
    void dayDoubleClicked(QDate date);
    void openDay();
    void itemDoubleClicked(QListWidgetItem *listItem);

public Q_SLOTS:
    void editItem();
    void removeItem();
    void refresh();

Q_SIGNALS:
    void managerChanged(QOrganizerManager *manager);
    void currentDayChanged(QDate date);
    void showDayPage(QDate date);
    void showEditPage(const QOrganizerItem &item);
    void addNewEvent();
    void addNewTodo();

protected: // from QWidget
    void showEvent(QShowEvent *event);

private:
    QComboBox* m_managerComboBox;
    QOrganizerManager *m_manager;
    QCalendarWidget *m_calendarWidget;
    QLabel *m_dateLabel;
    QListWidget *m_itemList;
    bool m_ignoreShowDayPageOnceFlag;
};

#endif // MONTHPAGE_H_
