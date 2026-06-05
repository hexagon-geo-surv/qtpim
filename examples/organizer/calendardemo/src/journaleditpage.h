// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#ifndef JOURNALEDITPAGE_H_
#define JOURNALEDITPAGE_H_

#include <QWidget>
#include <QDate>
#include <QtOrganizer/qorganizeritemid.h>
#include <QtOrganizer/qorganizerjournal.h>
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

class JournalEditPage : public QWidget
{
    Q_OBJECT

public:
    JournalEditPage(QWidget *parent = nullptr);
    ~JournalEditPage();

public Q_SLOTS:
    void cancelClicked();
    void saveClicked();
    void journalChanged(QOrganizerManager *manager, const QOrganizerJournal &journal);
    void handleAlarmIndexChanged(const QString);

Q_SIGNALS:
    void showDayPage();

protected: // from QWidget
    void showEvent(QShowEvent *event);

private:
    QOrganizerManager *m_manager;
    QOrganizerJournal m_organizerJournal;
    QLineEdit *m_subjectEdit;
    QDateTimeEdit *m_timeEdit;
    QComboBox *m_alarmComboBox;
    QComboBox *m_calendarComboBox;
    QList<QOrganizerCollection> m_collections;
};

#endif // JOURNALEDITPAGE_H_
