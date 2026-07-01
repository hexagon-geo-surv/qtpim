// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qorganizeriteminvalidfilter.h"

#include "qorganizeritemfilter_p.h"

/*!
    \class QOrganizerItemInvalidFilter
    \brief The QOrganizerItemInvalidFilter class matches no organizeritems.
    \inmodule QtOrganizer
    \ingroup organizer-filters

    This class provides a filter which will never match any organizer items.
 */

QT_BEGIN_NAMESPACE_ORGANIZER

class QOrganizerItemInvalidFilterPrivate : public QOrganizerItemFilterPrivate
{
public:
    QOrganizerItemInvalidFilterPrivate()
       : QOrganizerItemFilterPrivate()
    {
    }

    bool compare(const QOrganizerItemFilterPrivate *) const override
    {
        return true;
    }

#ifndef QT_NO_DATASTREAM
    QDataStream &outputToStream(QDataStream &stream, quint8 formatVersion) const override
    {
        Q_UNUSED(formatVersion)
        return stream;
    }

    QDataStream &inputFromStream(QDataStream &stream, quint8 formatVersion) override
    {
        Q_UNUSED(formatVersion)
        return stream;
    }
#endif // QT_NO_DATASTREAM

#ifndef QT_NO_DEBUG_STREAM
    QDebug &debugStreamOut(QDebug &dbg) const override
    {
        dbg.nospace() << "QOrganizerItemInvalidFilter()";
        return dbg.maybeSpace() ;
    }
#endif // QT_NO_DEBUG_STREAM

    QOrganizerItemFilterPrivate *clone() const override
    {
        return new QOrganizerItemInvalidFilterPrivate();
    }

    QOrganizerItemFilter::FilterType type() const override
    {
        return QOrganizerItemFilter::InvalidFilter;
    }

    QList<QOrganizerItemFilter> m_filters;
};

/*!
    Constructs a new invalid filter.
 */
QOrganizerItemInvalidFilter::QOrganizerItemInvalidFilter()
    : QOrganizerItemFilter(new QOrganizerItemInvalidFilterPrivate)
{
}

/*!
    Constructs a new invalid filter, ignoring the \a other filter.
 */
QOrganizerItemInvalidFilter::QOrganizerItemInvalidFilter(const QOrganizerItemFilter &other)
    : QOrganizerItemFilter(new QOrganizerItemInvalidFilterPrivate)
{
    Q_UNUSED(other);
}

QT_END_NAMESPACE_ORGANIZER
