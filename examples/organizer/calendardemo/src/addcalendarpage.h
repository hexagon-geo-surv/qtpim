// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause
#ifndef ADDCALENDARPAGE_H
#define ADDCALENDARPAGE_H

#include <QWidget>
#include <QtOrganizer/qorganizercollection.h>

QT_BEGIN_NAMESPACE_ORGANIZER
class QOrganizerManager;
class QOrganizerCollection;
QT_END_NAMESPACE_ORGANIZER

QTORGANIZER_USE_NAMESPACE

QT_BEGIN_NAMESPACE
class QComboBox;
class QLineEdit;
class QCheckBox;
class QVBoxLayout;
class QString;
QT_END_NAMESPACE

class AddCalendarPage : public QWidget
{
    Q_OBJECT

public:
    AddCalendarPage(QWidget *parent = nullptr);
    ~AddCalendarPage();

public Q_SLOTS:
    void cancelClicked();
    void saveClicked();
    void calendarChanged(QOrganizerManager *manager, QOrganizerCollection& calendar);

Q_SIGNALS:
    void showPreviousPage();

private:
    QOrganizerManager *m_manager;
    QOrganizerCollection m_collection;
};

#endif // ADDCALENDARPAGE_H
