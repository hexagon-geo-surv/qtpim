// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause
#ifndef EDITCALENDARSPAGE_H
#define EDITCALENDARSPAGE_H

#include <QWidget>
#include <QtOrganizer/qorganizercollection.h>

QT_BEGIN_NAMESPACE_ORGANIZER
class QOrganizerManager;
QT_END_NAMESPACE_ORGANIZER

QTORGANIZER_USE_NAMESPACE

QT_BEGIN_NAMESPACE
class QListWidget;
class QListWidgetItem;
class QVBoxLayout;
class QString;
QT_END_NAMESPACE

class EditCalendarsPage : public QWidget
{
    Q_OBJECT

public:
    EditCalendarsPage(QWidget *parent = nullptr);
    ~EditCalendarsPage();

public Q_SLOTS:
    void editClicked();
    void deleteClicked();
    void backClicked();
    void itemDoubleClicked(QListWidgetItem *listItem);
    void showPage(QOrganizerManager *manager);

Q_SIGNALS:
    void addClicked();
    void showPreviousPage();
    void showAddCalendarPage(QOrganizerManager*, QOrganizerCollection*);

protected: // from QWidget
    void showEvent(QShowEvent *event);

private:
    QOrganizerManager *m_manager;
    QOrganizerCollection m_collection;
    QListWidget *m_calendarList;
};

#endif // EDITCALENDARSPAGE_H
