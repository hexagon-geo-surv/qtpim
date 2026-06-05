// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause
#ifndef EVENTEDITPAGE_H_
#define EVENTEDITPAGE_H_

#include <QWidget>
#include <QDate>
#include <QtOrganizer/qorganizeritemid.h>
#include <QtOrganizer/qorganizerevent.h>
#include <QtOrganizer/qorganizercollection.h>

QT_BEGIN_NAMESPACE_ORGANIZER
class QOrganizerManager;
class QOrganizerItemSaveRequest;
class QOrganizerEvent;
class QOrganizerItem;
QT_END_NAMESPACE_ORGANIZER

QTORGANIZER_USE_NAMESPACE

QT_BEGIN_NAMESPACE
class QComboBox;
class QLineEdit;
class QDateTimeEdit;
class QVBoxLayout;
class QString;
class QSpinBox;
class QDateEdit;
QT_END_NAMESPACE

class EventEditPage : public QWidget
{
    Q_OBJECT

public:
    EventEditPage(QWidget *parent = nullptr);
    ~EventEditPage();

public Q_SLOTS:
    void cancelClicked();
    void saveClicked();
    void eventChanged(QOrganizerManager *manager, const QOrganizerEvent &event);
    void frequencyChanged(const QString&);
    void countChanged(int);
    void untilChanged(QDate);
    void endConditionChanged(const QString&);
    void alarmIndexChanged(const QString);
    void setCountField();
    void setRepeatUntilField();

Q_SIGNALS:
    void showDayPage();

protected: // from QWidget
    void showEvent(QShowEvent *event);

private:
    QOrganizerManager *m_manager;
    QOrganizerEvent m_organizerEvent;
    QList<QOrganizerItem> m_listOfEvents;
    QOrganizerItemSaveRequest *m_saveItemRequest;
    QVBoxLayout *m_repeatControls;
    QComboBox *m_alarmComboBox;
    QComboBox *m_typeComboBox;
    QLineEdit *m_subjectEdit;
    QDateTimeEdit *m_startTimeEdit;
    QDateTimeEdit *m_endTimeEdit;
    QComboBox *m_endConditionComboBox;
    QSpinBox *m_countSpinBox;
    QDateEdit *m_repeatUntilDate;
    QComboBox *m_calendarComboBox;
    QList<QOrganizerCollection> m_collections;
};

#endif // EVENTEDITPAGE_H_
