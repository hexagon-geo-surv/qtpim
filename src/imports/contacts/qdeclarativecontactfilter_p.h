// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QDECLARATIVECONTACTFILTER_P_H
#define QDECLARATIVECONTACTFILTER_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.
// This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <QtQml/qqml.h>

#include <QtContacts/qcontactfilter.h>

QTCONTACTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE

class QDeclarativeContactFilter : public QObject
{
    Q_OBJECT
    Q_PROPERTY(FilterType type READ type NOTIFY filterChanged)
    Q_ENUMS(FilterType)
    Q_FLAGS(MatchFlags)
public:
    QDeclarativeContactFilter(QObject *parent=0)
        :QObject(parent)
    {
        //for grouped filter: intersect /union filters
        if (parent && qobject_cast<QDeclarativeContactFilter*>(parent)) {
            connect(this, SIGNAL(filterChanged()), parent, SIGNAL(filterChanged()));
        }
    }

    enum FilterType {
        InvalidFilter = QContactFilter::InvalidFilter,
        DetailFilter = QContactFilter::ContactDetailFilter,
        DetailRangeFilter = QContactFilter::ContactDetailRangeFilter,
        ChangeLogFilter = QContactFilter::ChangeLogFilter,
        ActionFilter = QContactFilter::ActionFilter,
        RelationshipFilter = QContactFilter::RelationshipFilter,
        IntersectionFilter = QContactFilter::IntersectionFilter,
        UnionFilter = QContactFilter::UnionFilter,
        IdFilter = QContactFilter::IdFilter,
        DefaultFilter = QContactFilter::DefaultFilter
    };

    FilterType type() const {
        return static_cast<FilterType>(filter().type());
    }

    enum MatchFlag {
        MatchExactly = QContactFilter::MatchExactly,
        MatchContains = QContactFilter::MatchContains,
        MatchStartsWith = QContactFilter::MatchStartsWith,
        MatchEndsWith = QContactFilter::MatchEndsWith,
        MatchFixedString = QContactFilter::MatchFixedString,
        MatchCaseSensitive = QContactFilter::MatchCaseSensitive,
        MatchPhoneNumber = QContactFilter::MatchPhoneNumber,
        MatchKeypadCollation = QContactFilter::MatchKeypadCollation
    };
    Q_DECLARE_FLAGS(MatchFlags, MatchFlag)

    virtual QContactFilter filter() const
    {
        return QContactFilter();
    }

signals:
    void filterChanged();
};

class QDeclarativeContactCompoundFilter : public QDeclarativeContactFilter
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<QDeclarativeContactFilter> filters READ filters)
    Q_CLASSINFO("DefaultProperty", "filters")

public:
    explicit QDeclarativeContactCompoundFilter(QObject* parent = nullptr) : QDeclarativeContactFilter(parent){}
    virtual ~QDeclarativeContactCompoundFilter() {}
    // 'READ' accessor for the filters, basically this is also a 'WRITE' accessor
    // as per QQmlListProperty's design.
    QQmlListProperty<QDeclarativeContactFilter> filters();

    static void filters_append(QQmlListProperty<QDeclarativeContactFilter>* prop, QDeclarativeContactFilter* filter);
    static qsizetype filters_count(QQmlListProperty<QDeclarativeContactFilter>* prop);
    static QDeclarativeContactFilter* filters_at(QQmlListProperty<QDeclarativeContactFilter>* prop, qsizetype index);
    static void filters_clear(QQmlListProperty<QDeclarativeContactFilter>* prop);

protected:
    QList<QDeclarativeContactFilter*> m_filters;
};

QT_END_NAMESPACE

QML_DECLARE_TYPE(QDeclarativeContactFilter)
QML_DECLARE_TYPE(QDeclarativeContactCompoundFilter)

#endif // QDECLARATIVECONTACTFILTER_P_H
