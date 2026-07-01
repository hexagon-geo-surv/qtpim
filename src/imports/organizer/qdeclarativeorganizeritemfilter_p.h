// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QDECLARATIVEORGANIZERITEMFILTER_P_H
#define QDECLARATIVEORGANIZERITEMFILTER_P_H

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

#include <QtOrganizer/qorganizeritemfilters.h>

#include "qdeclarativeorganizeritemdetail_p.h"

QTORGANIZER_USE_NAMESPACE

QT_BEGIN_NAMESPACE

class QDeclarativeOrganizerItemFilter : public QObject
{
    Q_OBJECT

    Q_ENUMS(FilterType)
    Q_FLAGS(MatchFlags)
    Q_PROPERTY(FilterType type READ type NOTIFY filterChanged)

public:
    QDeclarativeOrganizerItemFilter(QObject *parent = Q_NULLPTR);

    enum FilterType {
        DefaultFilter = QOrganizerItemFilter::DefaultFilter,
        InvalidFilter = QOrganizerItemFilter::InvalidFilter,
        IntersectionFilter = QOrganizerItemFilter::IntersectionFilter,
        UnionFilter = QOrganizerItemFilter::UnionFilter,
        CollectionFilter = QOrganizerItemFilter::CollectionFilter,
        DetailFilter = QOrganizerItemFilter::DetailFilter,
        DetailFieldFilter = QOrganizerItemFilter::DetailFieldFilter,
        DetailRangeFilter = QOrganizerItemFilter::DetailRangeFilter,
        IdFilter = QOrganizerItemFilter::IdFilter
    };

    FilterType type() const;

    enum MatchFlag {
        MatchExactly = QOrganizerItemFilter::MatchExactly,
        MatchContains = QOrganizerItemFilter::MatchContains,
        MatchStartsWith = QOrganizerItemFilter::MatchStartsWith,
        MatchEndsWith = QOrganizerItemFilter::MatchEndsWith,
        MatchFixedString = QOrganizerItemFilter::MatchFixedString,
        MatchCaseSensitive = QOrganizerItemFilter::MatchCaseSensitive
    };
    Q_DECLARE_FLAGS(MatchFlags, MatchFlag)

    // used by model
    virtual QOrganizerItemFilter filter() const;

Q_SIGNALS:
    void filterChanged();
};


class QDeclarativeOrganizerItemInvalidFilter : public QDeclarativeOrganizerItemFilter
{
    Q_OBJECT

public:
    QDeclarativeOrganizerItemInvalidFilter(QObject *parent = Q_NULLPTR);

    // used by model
    QOrganizerItemFilter filter() const override;
};


class QDeclarativeOrganizerItemCompoundFilter : public QDeclarativeOrganizerItemFilter
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<QDeclarativeOrganizerItemFilter> filters READ filters NOTIFY valueChanged)
    Q_CLASSINFO("DefaultProperty", "filters")

public:
    explicit QDeclarativeOrganizerItemCompoundFilter(QObject *parent = Q_NULLPTR);
    virtual ~QDeclarativeOrganizerItemCompoundFilter();

    QQmlListProperty<QDeclarativeOrganizerItemFilter> filters();

    static void filters_append(QQmlListProperty<QDeclarativeOrganizerItemFilter> *prop, QDeclarativeOrganizerItemFilter *filter);
    static qsizetype filters_count(QQmlListProperty<QDeclarativeOrganizerItemFilter> *prop);
    static QDeclarativeOrganizerItemFilter *filters_at(QQmlListProperty<QDeclarativeOrganizerItemFilter> *prop, qsizetype index);
    static void filters_clear(QQmlListProperty<QDeclarativeOrganizerItemFilter> *prop);

Q_SIGNALS:
    void valueChanged();

protected:
    QList<QDeclarativeOrganizerItemFilter *> m_filters;
};


class QDeclarativeOrganizerItemIntersectionFilter : public QDeclarativeOrganizerItemCompoundFilter
{
    Q_OBJECT

public:
    QDeclarativeOrganizerItemIntersectionFilter(QObject *parent = Q_NULLPTR);

    // used by model
    QOrganizerItemFilter filter() const override;
};


class QDeclarativeOrganizerItemUnionFilter : public QDeclarativeOrganizerItemCompoundFilter
{
    Q_OBJECT
public:
    QDeclarativeOrganizerItemUnionFilter(QObject *parent = Q_NULLPTR);

    // used by model
    QOrganizerItemFilter filter() const override;
};


class QDeclarativeOrganizerItemCollectionFilter : public QDeclarativeOrganizerItemFilter
{
    Q_OBJECT
    Q_PROPERTY(QStringList ids READ ids WRITE setIds NOTIFY valueChanged)

public:
    QDeclarativeOrganizerItemCollectionFilter(QObject *parent = Q_NULLPTR);

    QStringList ids() const;
    void setIds(const QStringList &ids);

    // used by model
    QOrganizerItemFilter filter() const override;

Q_SIGNALS:
    void valueChanged();

private:
    QStringList m_ids;
};


class QDeclarativeOrganizerItemDetailFilter : public QDeclarativeOrganizerItemFilter
{
    Q_OBJECT
    Q_PROPERTY(QDeclarativeOrganizerItemDetail *detail READ detail WRITE setDetail NOTIFY valueChanged)

public:
    QDeclarativeOrganizerItemDetailFilter(QObject *parent = Q_NULLPTR);

    QDeclarativeOrganizerItemDetail *detail() const;
    void setDetail(QDeclarativeOrganizerItemDetail *detail);

    // used by model
    QOrganizerItemFilter filter() const override;

signals:
    void valueChanged();

private:
    QDeclarativeOrganizerItemDetail *m_detail;
    QOrganizerItemDetailFilter d;
};


class QDeclarativeOrganizerItemDetailFieldFilter : public QDeclarativeOrganizerItemFilter
{
    Q_OBJECT
    Q_PROPERTY(QVariant value READ value WRITE setValue NOTIFY valueChanged)
    Q_PROPERTY(MatchFlags matchFlags READ matchFlags WRITE setMatchFlags NOTIFY valueChanged)
    Q_PROPERTY(int field READ field WRITE setField NOTIFY valueChanged)
    Q_PROPERTY(int detail READ detail WRITE setDetail NOTIFY valueChanged)

public:
    QDeclarativeOrganizerItemDetailFieldFilter(QObject *parent = Q_NULLPTR);

    int detail() const;
    void setDetail(int detail);

    int field() const;
    void setField(int field);

    void setValue(const QVariant &value);
    QVariant value() const;

    QDeclarativeOrganizerItemFilter::MatchFlags matchFlags() const;
    void setMatchFlags(QDeclarativeOrganizerItemFilter::MatchFlags flags);

    // used by model
    QOrganizerItemFilter filter() const override;

signals:
    void valueChanged();

private:
    QOrganizerItemDetailFieldFilter d;
};


class QDeclarativeOrganizerItemDetailRangeFilter : public QDeclarativeOrganizerItemFilter
{
    Q_OBJECT
    Q_FLAGS(RangeFlags)
    Q_PROPERTY(QVariant min READ minValue WRITE setMinValue NOTIFY valueChanged)
    Q_PROPERTY(QVariant max READ maxValue WRITE setMaxValue NOTIFY valueChanged)
    Q_PROPERTY(MatchFlags matchFlags READ matchFlags WRITE setMatchFlags NOTIFY valueChanged)
    Q_PROPERTY(RangeFlags rangeFlags READ rangeFlags WRITE setRangeFlags NOTIFY valueChanged)
    Q_PROPERTY(QDeclarativeOrganizerItemDetail::DetailType detail READ detail WRITE setDetail NOTIFY valueChanged)
    Q_PROPERTY(int field READ field WRITE setField NOTIFY valueChanged)

public:
    enum RangeFlag {
        IncludeLower = QOrganizerItemDetailRangeFilter::IncludeLower,
        IncludeUpper = QOrganizerItemDetailRangeFilter::IncludeUpper,
        ExcludeLower = QOrganizerItemDetailRangeFilter::ExcludeLower,
        ExcludeUpper = QOrganizerItemDetailRangeFilter::ExcludeUpper
    };
    Q_DECLARE_FLAGS(RangeFlags, RangeFlag)

    QDeclarativeOrganizerItemDetailRangeFilter(QObject *parent = Q_NULLPTR);

    QDeclarativeOrganizerItemDetail::DetailType detail() const;
    void setDetail(QDeclarativeOrganizerItemDetail::DetailType detail);

    int field() const;
    void setField(int field);

    QDeclarativeOrganizerItemFilter::MatchFlags matchFlags() const;
    void setMatchFlags(QDeclarativeOrganizerItemFilter::MatchFlags flags);

    RangeFlags rangeFlags() const;
    void setRangeFlags(RangeFlags flags);

    QVariant minValue() const;
    void setMinValue(const QVariant &value);

    QVariant maxValue() const;
    void setMaxValue(const QVariant &value);

    // used by model
    QOrganizerItemFilter filter() const override;

signals:
    void valueChanged();

private:
    QOrganizerItemDetailRangeFilter d;

};


class QDeclarativeOrganizerItemIdFilter : public QDeclarativeOrganizerItemFilter
{
    Q_OBJECT
    Q_PROPERTY(QStringList ids READ ids WRITE setIds NOTIFY valueChanged)

public:
    QDeclarativeOrganizerItemIdFilter(QObject *parent = Q_NULLPTR);

    QStringList ids() const;
    void setIds(const QStringList &ids);

    // used by model
    QOrganizerItemFilter filter() const override;

Q_SIGNALS:
    void valueChanged();

private:
    QStringList m_ids;
};

QT_END_NAMESPACE

QML_DECLARE_TYPE(QDeclarativeOrganizerItemFilter)
QML_DECLARE_TYPE(QDeclarativeOrganizerItemInvalidFilter)
QML_DECLARE_TYPE(QDeclarativeOrganizerItemCompoundFilter)
QML_DECLARE_TYPE(QDeclarativeOrganizerItemIntersectionFilter)
QML_DECLARE_TYPE(QDeclarativeOrganizerItemUnionFilter)
QML_DECLARE_TYPE(QDeclarativeOrganizerItemCollectionFilter)
QML_DECLARE_TYPE(QDeclarativeOrganizerItemDetailFilter)
QML_DECLARE_TYPE(QDeclarativeOrganizerItemDetailFieldFilter)
QML_DECLARE_TYPE(QDeclarativeOrganizerItemDetailRangeFilter)
QML_DECLARE_TYPE(QDeclarativeOrganizerItemIdFilter)

#endif // QDECLARATIVEORGANIZERITEMFILTER_P_H
