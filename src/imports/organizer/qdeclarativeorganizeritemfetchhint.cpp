// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qdeclarativeorganizeritemfetchhint_p.h"

#include <QtCore/qset.h>

QTORGANIZER_USE_NAMESPACE

QT_BEGIN_NAMESPACE

/*!
    \qmltype FetchHint
    \instantiates QDeclarativeOrganizerItemFetchHint
    \brief The FetchHint element provides hints to the manager about which organizer item
           information needs to be retrieved in an asynchronous fetch request or a synchronous
           function call.
    \inqmlmodule QtOrganizer
    \ingroup qml-organizer-filters
 */

/*!
  \qmlsignal FetchHint::onFetchHintChanged()

  This signal is emitted, when any of the FetchHint's properties have been changed.
 */

/*!
    \internal
 */
QDeclarativeOrganizerItemFetchHint::QDeclarativeOrganizerItemFetchHint(QObject *parent)
    : QObject(parent)
{
}

/*!
    \qmlproperty enumeration FetchHint::optimizationHints

    This property holds the optimization hint flags specified by the client.

    \list
    \li AllRequired          Tells the backend that all information is required.
    \li NoActionPreferences  Tells the backend that the client does not require retrieved
                            organizer items to include a cache of action preferences.
    \li NoBinaryBlobs        Tells the backend that the client does not require retrieved
                            organizer items to include binary blobs such as thumbnail images.
    \endlist
 */
QDeclarativeOrganizerItemFetchHint::OptimizationHints QDeclarativeOrganizerItemFetchHint::optimizationHints() const
{
    OptimizationHints hints;
    hints = ~hints & (int)d.optimizationHints();
    return hints;
}

void QDeclarativeOrganizerItemFetchHint::setOptimizationHints(OptimizationHints hints)
{
    if (hints != d.optimizationHints()) {
        QOrganizerItemFetchHint::OptimizationHints newHints;
        newHints = ~newHints & (int)hints;
        d.setOptimizationHints(newHints);
        emit fetchHintChanged();
    }
}

/*!
  \qmlproperty list<int> FetchHint::detailTypesHint

  This property holds a list of organizer item detail types
  the manager should (at a minimum) retrieve when fetching contacts.
  */
QList<int> QDeclarativeOrganizerItemFetchHint::detailTypesHint() const
{
    QList<int> savedList;
    for (const QOrganizerItemDetail::DetailType &detailTypeHint : d.detailTypesHint())
        savedList << static_cast<int>(detailTypeHint);

    return savedList;
}

void QDeclarativeOrganizerItemFetchHint::setDetailTypesHint(const QList<int> &detailTypes)
{
    const QList<int> current = detailTypesHint();
    if (QSet<int>(detailTypes.cbegin(), detailTypes.cend()) != QSet<int>(current.cbegin(), current.cend())) {
        QList<QOrganizerItemDetail::DetailType> convertedDetailTypes;
        for (const int detailType : detailTypes)
            convertedDetailTypes << static_cast<QOrganizerItemDetail::DetailType>(detailType);

        d.setDetailTypesHint(convertedDetailTypes);
        emit fetchHintChanged();
    }
}

/*!
    \internal
 */
QOrganizerItemFetchHint QDeclarativeOrganizerItemFetchHint::fetchHint() const
{
    return d;
}

/*!
    \internal
 */
void QDeclarativeOrganizerItemFetchHint::setFetchHint(const QOrganizerItemFetchHint &fetchHint)
{
    d = fetchHint;
    emit fetchHintChanged();
}

#include "moc_qdeclarativeorganizeritemfetchhint_p.cpp"

QT_END_NAMESPACE
