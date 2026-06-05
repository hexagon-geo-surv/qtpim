// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qcontactinvalidfilter.h"

#include "qcontactfilter_p.h"

/*!
  \class QContactInvalidFilter
  \brief The QContactInvalidFilter class matches no contacts.

  \inmodule QtContacts

  \ingroup contacts-filters

  This class provides a filter which will never match any contacts
 */

QT_BEGIN_NAMESPACE_CONTACTS

class QContactInvalidFilterPrivate : public QContactFilterPrivate
{
public:
    QContactInvalidFilterPrivate()
       : QContactFilterPrivate()
    {
    }

    bool compare(const QContactFilterPrivate*) const override
    {
        return true; // all invalid filters are alike
    }

    QDataStream& outputToStream(QDataStream& stream, quint8 formatVersion) const override
    {
        Q_UNUSED(formatVersion);
        return stream;
    }

    QDataStream& inputFromStream(QDataStream& stream, quint8 formatVersion) override
    {
        Q_UNUSED(formatVersion);
        return stream;
    }

#ifndef QT_NO_DEBUG_STREAM
    QDebug& debugStreamOut(QDebug& dbg) const override
    {
        dbg.nospace() << "QContactInvalidFilter()";
        return dbg.maybeSpace() ;
    }
#endif

    /* There is no way this can be called - d is never detached */
    QContactFilterPrivate* clone() const override
    {
        return new QContactInvalidFilterPrivate();
    }

    QContactFilter::FilterType type() const override
    {
        return QContactFilter::InvalidFilter;
    }
};

/*!
 * Constructs a new invalid filter
 */
QContactInvalidFilter::QContactInvalidFilter()
    : QContactFilter(new QContactInvalidFilterPrivate)
{
}

/*!
 * Constructs a new invalid filter, ignoring the \a other filter
 */
QContactInvalidFilter::QContactInvalidFilter(const QContactFilter& other)
    : QContactFilter(new QContactInvalidFilterPrivate)
{
    // Initializing a QCIF from anything is the same as just constructing a QCIF
    Q_UNUSED(other);
}

QT_END_NAMESPACE_CONTACTS
