// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

#include <malloc.h>
#include <QtTest/QtTest>

#include <QtContacts/qcontacts.h>

//TESTED_COMPONENT=src/contacts

QTCONTACTS_USE_NAMESPACE

// Define global op new so we can track some amount of allocations
static qulonglong cAllocated = 0;
static qulonglong nAllocations = 0;

/*
void * operator new(size_t sz)
{
    nAllocations++;
    cAllocated += sz;
    return malloc(sz);
}
void * operator new[](size_t sz)
{
    nAllocations++;
    cAllocated += sz;
    return malloc(sz);
}
void operator delete(void * block)
{
    if (block)
        free(block);
}

void operator delete[](void *block)
{
    if (block)
        free(block);
}
*/


// Also hook malloc (with glibc)
#if defined(__malloc_hook)
void *(*old_hook)(size_t, const void*);
void *qmallochook(size_t size, const void* )
{
    void * ret;
    nAllocations++;
    cAllocated += size;
    __malloc_hook = old_hook;
    ret = malloc(size);
    __malloc_hook = qmallochook;
    return ret;
}

// I can't seem to get the __malloc_init_hook method working (C++ mangling?)
static int qmallocinithook()
{
    old_hook = __malloc_hook;
    __malloc_hook = qmallochook;
    return 1;
}

Q_CONSTRUCTOR_FUNCTION(qmallocinithook);
#endif // defined(__malloc_hook)

class QMemUsed
{
public:
    QMemUsed() : mLabel(0), mAllocated(cAllocated), mAllocations(nAllocations), mItems(0)
    {
    }
    QMemUsed(const char* name) : mLabel(name), mAllocated(cAllocated), mAllocations(nAllocations), mItems(0)
    {
    }
    QMemUsed(const char* name, int nItems) : mLabel(name), mAllocated(cAllocated), mAllocations(nAllocations), mItems(nItems)
    {
    }
    ~QMemUsed()
    {
        mAllocated = cAllocated - mAllocated;
        mAllocations = nAllocations - mAllocations;
        QString allocations = mAllocations > 1 ? QString("allocations") : QString("allocation");
        if (mItems > 1) {
            QString msg("%1 bytes in %2 %8 (for %3 x %6 -> %4 bytes, %5 allocations per %7)");
            qDebug() << msg.arg(mAllocated).arg(mAllocations).arg(mItems).arg(((double)mAllocated) / mItems).arg(((double) mAllocations) / mItems).arg(mLabel).arg(mLabel).arg(allocations).toLatin1().constData();
        } else if (mLabel.latin1()){
            QString msg("%1 bytes in %2 %4 for %3");
            qDebug() << msg.arg(mAllocated).arg(mAllocations).arg(mLabel).arg(allocations).toLatin1().constData();
        } else {
            QString msg("%1 bytes in %2 %3");
            qDebug() << msg.arg(mAllocated).arg(mAllocations).arg(allocations).toLatin1().constData();
        }
    }
    QLatin1String mLabel;
    qulonglong mAllocated;
    qulonglong mAllocations;
    int mItems;
};

QTCONTACTS_USE_NAMESPACE
class tst_QContactMemUsage : public QObject
{
Q_OBJECT

public:
    tst_QContactMemUsage();
    virtual ~tst_QContactMemUsage();

public slots:
    void init();
    void cleanup();

private slots:
    void single();
    void multiple();

private:
    QMemUsed mem;
};

tst_QContactMemUsage::tst_QContactMemUsage()
{
}

tst_QContactMemUsage::~tst_QContactMemUsage()
{
}

void tst_QContactMemUsage::init()
{
}

void tst_QContactMemUsage::cleanup()
{
}

void tst_QContactMemUsage::single()
{
    // Try single allocations
    {
        QMemUsed m("PhoneNumber");
        QContactPhoneNumber p1;
    }

    {
        QMemUsed m("Address");
        QContactAddress a;
    }

    {
        QMemUsed m("Name");
        QContactName p1;
    }
}

void tst_QContactMemUsage::multiple()
{
    // First 10
    {
        QMemUsed m("PhoneNumber", 10);
        QContactPhoneNumber p1;
        QContactPhoneNumber p2;
        QContactPhoneNumber p3;
        QContactPhoneNumber p4;
        QContactPhoneNumber p5;
        QContactPhoneNumber p6;
        QContactPhoneNumber p7;
        QContactPhoneNumber p8;
        QContactPhoneNumber p9;
        QContactPhoneNumber p10;
    }

    {
        QMemUsed m("Address", 10);
        QContactAddress p1;
        QContactAddress p2;
        QContactAddress p3;
        QContactAddress p4;
        QContactAddress p5;
        QContactAddress p6;
        QContactAddress p7;
        QContactAddress p8;
        QContactAddress p9;
        QContactAddress p10;
    }

    {
        QMemUsed m("Address", 10);
        QContactAddress p1;
        QContactAddress p2;
        QContactAddress p3;
        QContactAddress p4;
        QContactAddress p5;
        QContactAddress p6;
        QContactAddress p7;
        QContactAddress p8;
        QContactAddress p9;
        QContactAddress p10;
    }

    {
        QMemUsed m("Name", 10);
        QContactName p1;
        QContactName p2;
        QContactName p3;
        QContactName p4;
        QContactName p5;
        QContactName p6;
        QContactName p7;
        QContactName p8;
        QContactName p9;
        QContactName p10;
    }

    {
        QList<QContactDetail> details;
        QMemUsed m("PhoneNumber", 100);
        for (int i = 0; i < 100; i++) {
            QContactPhoneNumber a;
            details.append(a);
        }
    }


    {
        QList<QContactDetail> details;
        QMemUsed m("Address", 100);
        for (int i = 0; i < 100; i++) {
            QContactAddress a;
            details.append(a);
        }
    }


    {
        QList<QContactDetail> details;
        QMemUsed m("Name", 100);
        for (int i = 0; i < 100; i++) {
            QContactName a;
            details.append(a);
        }
    }


    // Now set some values
    {
        QString v("1234");
        QMemUsed m("PhoneNumber with number");
        QContactPhoneNumber p;
        p.setNumber(v);
    }

    {
        QVariant v("1234");
        QMemUsed m("PhoneNumber with number as variant");
        QContactPhoneNumber p;
        p.setValue(QContactPhoneNumber::FieldNumber, v);
    }


    {
        QMemUsed m("PhoneNumber with number and subtype");
        QContactPhoneNumber p;
        p.setNumber("1234");
        p.setSubTypes(QList<int>() << QContactPhoneNumber::SubTypeMobile);
    }

    {
        QMemUsed m("PhoneNumber with custom fields");
        QContactPhoneNumber p;
        QVariant v = QString("1234");
        p.setValue(QContactAddress::FieldCountry, v);
        p.setValue(QContactUrl::FieldUrl, v);
        p.setValue(QContactEmailAddress::FieldEmailAddress, v);
        p.setValue(QContactName::FieldFirstName, v);
        p.setValue(QContactName::FieldLastName, v);
        p.setValue(QContactName::FieldMiddleName, v);
        p.setValue(QContactName::FieldPrefix, v);
        p.setValue(QContactName::FieldSuffix, v);
        p.setValue(QContactAddress::FieldLocality, v);
        p.setValue(QContactAddress::FieldRegion, v);
    }


}

QTEST_MAIN(tst_QContactMemUsage)
#include "tst_qcontactmemusage.moc"
