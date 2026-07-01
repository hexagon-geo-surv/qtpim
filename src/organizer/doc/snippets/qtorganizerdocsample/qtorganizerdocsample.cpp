// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#include <QtOrganizer>

#include <QDebug>
#include <QCoreApplication>
#include <QObject>
#include <QTimer>

QTORGANIZER_USE_NAMESPACE

static void snippets();
static void dumpItems(QOrganizerManager* manager);
static void dumpItem(const QOrganizerItem& item);

int main(int, char**)
{
    snippets();
    return 0;
}

void snippets()
{
    //! [Instantiating the default manager for the platform]
    QOrganizerManager defaultManager;
    //! [Instantiating the default manager for the platform]

    //! [Instantiating a specific manager]
    QOrganizerManager specificManager("KCal");
    //! [Instantiating a specific manager]

    // XXX TODO: use rrule instead of rdates.
    QDateTime startDateTime = QDateTime::currentDateTime();
    QDate firstOccDate = startDateTime.date().addDays(7);
    QDate secondOccDate = startDateTime.date().addDays(14);
    QDate thirdOccDate = startDateTime.date().addDays(21);
    QDateTime endDateTime = startDateTime.addDays(28);
    QSet<QDate> rDates;
    rDates << firstOccDate << secondOccDate << thirdOccDate;

    //! [Creating a recurrent event]
    QOrganizerEvent marshmallowMeeting;
    marshmallowMeeting.setRecurrenceDates(rDates);
    marshmallowMeeting.setPriority(QOrganizerItemPriority::HighPriority);
    marshmallowMeeting.setLocation("Meeting Room 8");
    marshmallowMeeting.setDescription("A meeting every wednesday to discuss the vitally important topic of marshmallows");
    marshmallowMeeting.setDisplayLabel("Marshmallow Conference");
    if (!defaultManager.saveItem(&marshmallowMeeting))
        qDebug() << "Failed to save the recurrent event; error:" << defaultManager.error();
    //! [Creating a recurrent event]

    //! [Retrieving occurrences of a particular recurrent event within a time period]
    QList<QOrganizerItem> instances = defaultManager.itemOccurrences(marshmallowMeeting, startDateTime, endDateTime);
    //! [Retrieving occurrences of a particular recurrent event within a time period]
    qDebug() << "dumping retrieved instances:";
    foreach (const QOrganizerItem& currInst, instances)
    {
        dumpItem(currInst);
        qDebug() << "....................";
    }


    //! [Retrieving the next 5 occurrences of a particular recurrent event]
    instances = defaultManager.itemOccurrences(marshmallowMeeting, QDateTime::currentDateTime(), QDateTime(), 5);
    //! [Retrieving the next 5 occurrences of a particular recurrent event]

    //! [Retrieving the next 10 occurrences of any item (Agenda View)]
    instances = defaultManager.items(QDateTime::currentDateTime(), QDateTime());
    instances = instances.mid(0, 10);
    //! [Retrieving the next 10 occurrences of any item (Agenda View)]

    //! [Creating a non-recurrent entry]
    // a default constructed journal will have it's date/time set to the current date/time.
    QOrganizerJournal journal;
    journal.setDescription("The conference went well.  We all agree that marshmallows are awesome, "\
                    "but we were unable to reach any agreement as to how we could possibly "\
                    "increase our intake of marshmallows.  Several action points were assigned "\
                    "to various members of the group; I have been tasked with finding a good "\
                    "recipe that combines both marshmallows and chocolate, by next Wednesday.");
    defaultManager.saveItem(&journal);
    //! [Creating a non-recurrent entry]

    //! [Editing a non-recurrent entry]
    journal.addComment("Serves: 8.  Ingredients: 500g Milk Chocolate, 500g Marshmallows."\
                    "  Step 1: Put the marshmallows into 8 separate bowls."\
                    "  Step 2: Melt the chocolate."\
                    "  Step 3: Pour the chocolate over the marshmallows in the bowls."\
                    "  Step 4: Put the bowls into the refrigerator for 20 minutes; serve chilled.");
    if (!defaultManager.saveItem(&journal))
        qDebug() << "Unable to save updated journal!  Error:" << defaultManager.error();
    //! [Editing a non-recurrent entry]

    //! [Removing an entry]
    defaultManager.removeItem(journal.id());
    //! [Removing an entry]

    //! [Retrieving entries for a time period]
    QList<QOrganizerItem> entries =
        defaultManager.items(QDateTime(QDate(2010, 1, 1), QTime(0, 0, 0)),
                             QDateTime(QDate(2010, 1, 31), QTime(23, 59, 59)));
    //! [Retrieving entries for a time period]

    //! [Retrieving entries with a filter]
    entries = defaultManager.items(QOrganizerItemLocation::match("Meeting Room 8"));
    //! [Retrieving entries with a filter]

    //! [Downcasting items]
    QList<QOrganizerItem> items = defaultManager.items();
    foreach (QOrganizerItem item, entries) {
        if (item.type() == QOrganizerItemType::TypeEvent) {
            QOrganizerEvent event(item);
            qDebug() << "Event:" << event.startDateTime() << ", " << event.displayLabel();
        } else if (item.type() == QOrganizerItemType::TypeEventOccurrence) {
            QOrganizerEventOccurrence event(item);
            qDebug() << "Event:" << event.startDateTime() << ", " << event.displayLabel();
        } else if (item.type() == QOrganizerItemType::TypeTodo) {
            // process todos
        } else if (item.type() == QOrganizerItemType::TypeTodoOccurrence) {
            // process recurring todos
        } else if (item.type() == QOrganizerItemType::TypeJournal) {
            // process journals
        } else if (item.type() == QOrganizerItemType::TypeNote) {
            // process notes
        }
    }
    //! [Downcasting items]

    //! [Creating an exception to a particular recurrent event]
    QOrganizerEventOccurrence nextMarshmallowMeeting = defaultManager.itemOccurrences(marshmallowMeeting).value(0);
    nextMarshmallowMeeting.setStartDateTime(QDateTime::fromString("13.05.2010 18:00:00", "dd.MM.yy hh:mm:ss"));
    nextMarshmallowMeeting.setEndDateTime(QDateTime::fromString("13.05.2010 20:00:00", "dd.MM.yy hh:mm:ss"));
    nextMarshmallowMeeting.addComment("The next meeting will go for an hour longer (starting one "\
                                      "hour earlier than usual), since we have scheduled one hour"\
                                      "to taste the results of the recipe that I will be presenting "\
                                      "at the meeting.");
    defaultManager.saveItem(&nextMarshmallowMeeting);
    //! [Creating an exception to a particular recurrent event]

    //! [Getting a list of collections]
    QList<QOrganizerCollection> collections = defaultManager.collections();
    //! [Getting a list of collections]

    QOrganizerCollection collection = collections.first();

    //! [Saving an item to a collection]
    marshmallowMeeting.setCollectionId(collection.id());
    defaultManager.saveItem(&marshmallowMeeting);
    //! [Saving an item to a collection]

    //! [Retrieving items in a collection]
    QOrganizerItemCollectionFilter collectionFilter;
    collectionFilter.setCollectionId(collection.id());
    items = defaultManager.items(collectionFilter);
    //! [Retrieving items in a collection]

    dumpItems(&defaultManager);
}

void dumpItems(QOrganizerManager* manager)
{
    QList<QOrganizerItem> items = manager->items();
    qDebug() << "dumping" << items.count() << "items:";
    qDebug() << "=============================";
    for (int i = 0; i < items.size(); ++i) {
        QOrganizerItem curr = items.at(i);
        dumpItem(curr);
        if (i < (items.size() - 1)) {
            qDebug() << "--------------";
        }
    }
    qDebug() << "=============================";
}

void dumpItem(const QOrganizerItem& item)
{
    qDebug() << "item:" << item.displayLabel() << ", id:" << item.id();
    QList<QOrganizerItemDetail> dets = item.details();
    foreach (const QOrganizerItemDetail det, dets) {
        qDebug() << "    new" << det.definitionName() << "detail:";
        QVariantMap values = det.variantValues();
        QStringList keys = values.keys();
        foreach (const QString& key, keys) {
            qDebug() << "        " << key << "=" << values.value(key);
        }
    }
}
