// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause
#ifndef EVENTOCCURRENCEEDITPAGE_H_
#define EVENTOCCURRENCEEDITPAGE_H_

#include <QWidget>
#include <QDate>
#include <QtOrganizer/qorganizeritemid.h>
#include <QtOrganizer/qorganizerevent.h>
#include <QtOrganizer/qorganizereventoccurrence.h>

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

class EventOccurrenceEditPage : public QWidget
{
    Q_OBJECT

public:
    EventOccurrenceEditPage(QWidget *parent = nullptr);
    ~EventOccurrenceEditPage();

public Q_SLOTS:
    void cancelClicked();
    void saveOrNextClicked();
    void eventOccurrenceChanged(QOrganizerManager *manager, const QOrganizerEventOccurrence &eventOccurrence);

Q_SIGNALS:
    void showDayPage();

protected: // from QWidget
    void showEvent(QShowEvent *event);

private:
    QOrganizerManager *m_manager;
    QOrganizerEventOccurrence m_organizerEventOccurrence;
    QList<QOrganizerItem> m_listOfEvents;
    QOrganizerItemSaveRequest *m_saveItemRequest;
    QVBoxLayout *scrollAreaLayout;
    QComboBox *m_typeComboBox;
    QLineEdit *m_subjectEdit;
    QDateTimeEdit *m_startTimeEdit;
    QDateTimeEdit *m_endTimeEdit;
    QSpinBox *m_countSpinBox;
    QDateEdit *m_repeatUntilDate;
    int m_numOfEntiresToBeCreated;
    bool m_countFieldAdded;
    bool m_multipleEntries;
};

#endif // EVENTOCCURRENCEEDITPAGE_H_
