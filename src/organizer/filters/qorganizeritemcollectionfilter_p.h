/****************************************************************************
**
** Copyright (C) 2017 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtOrganizer module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl-3.0.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or (at your option) the GNU General
** Public license version 3 or any later version approved by the KDE Free
** Qt Foundation. The licenses are as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-2.0.html and
** https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QORGANIZERITEMCOLLECTIONFILTER_P_H
#define QORGANIZERITEMCOLLECTIONFILTER_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <QtOrganizer/qorganizeritemcollectionfilter.h>
#include <QtOrganizer/private/qorganizeritemfilter_p.h>

#include <algorithm>

QT_BEGIN_NAMESPACE_ORGANIZER

class QOrganizerItemCollectionFilterPrivate : public QOrganizerItemFilterPrivate
{
public:
    QOrganizerItemCollectionFilterPrivate()
        : QOrganizerItemFilterPrivate()
    {
    }

    QOrganizerItemCollectionFilterPrivate(const QOrganizerItemCollectionFilterPrivate &other)
        : QOrganizerItemFilterPrivate(other), m_ids(other.m_ids)
    {
    }

    virtual bool compare(const QOrganizerItemFilterPrivate *other) const override
    {
        const QOrganizerItemCollectionFilterPrivate *od = static_cast<const QOrganizerItemCollectionFilterPrivate *>(other);
        if (od)
            return m_ids == od->m_ids;
        return false;
    }

#ifndef QT_NO_DATASTREAM
    QDataStream &outputToStream(QDataStream &stream, quint8 formatVersion) const override
    {
        if (formatVersion == 1)
            stream << m_ids;
        return stream;
    }

    QDataStream &inputFromStream(QDataStream &stream, quint8 formatVersion) override
    {
        if (formatVersion == 1)
            stream >> m_ids;
        return stream;
    }
#endif // QT_NO_DATASTREAM

#ifndef QT_NO_DEBUG_STREAM
    QDebug &debugStreamOut(QDebug &dbg) const override
    {
        dbg.nospace() << "QOrganizerItemCollectionFilter(collectionIds=";
        QList<QOrganizerCollectionId> ids(m_ids.values());
        std::sort(ids.begin(), ids.end());
        dbg.nospace() << ids;
        dbg.nospace() << ")";
        return dbg.maybeSpace();
    }
#endif // QT_NO_DEBUG_STREAM

    Q_IMPLEMENT_ORGANIZERITEMFILTER_VIRTUALCTORS(QOrganizerItemCollectionFilter, QOrganizerItemFilter::CollectionFilter)

    QSet<QOrganizerCollectionId> m_ids;
};

QT_END_NAMESPACE_ORGANIZER

#endif // QORGANIZERITEMCOLLECTIONFILTER_P_H
