// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qorganizermanagerenginefactory.h"

QT_BEGIN_NAMESPACE_ORGANIZER

/*!
    \class QOrganizerManagerEngineFactory
    \brief The QOrganizerManagerEngineFactory class provides the interface to implement the creation
           of organizer manager engine instances.
    \inmodule QtOrganizer
    \ingroup organizer-backends

    This class should only be used by backend developers. All the functions are only called internally
    by QOrganizerManager, and should not be called by others.

    More information on writing a organizer engine plugin is available in the \l{Qt Organizer Manager Engines}
    documentation.

    \sa QOrganizerManager, QOrganizerManagerEngine
 */

/*!
    A default, empty destructor.
 */
QOrganizerManagerEngineFactory::~QOrganizerManagerEngineFactory()
{
}

/*!
    \fn QOrganizerManagerEngineFactory::engine(const QMap<QString, QString> &parameters, QOrganizerManager::Error *error)

    This function should return an instance of the engine provided by this factory.

    The \a parameters supplied can be ignored or interpreted as desired.

    If a supplied parameter results in an unfulfillable request, or some other error occurs, this
    function may return a null pointer, and the client developer will get an invalid QOrganizerManager
    in return. Any error should be saved in \a error.
 */

/*!
    \fn QOrganizerManagerEngineFactory::managerName() const

    This function should return a unique string that identifies the engines provided by this factory.

    Typically this would be of the form "org.qt-project.Qt.SampleOrganizerEngine", with the appropriate
    domain and engine name substituted.
 */

/*!
    \internal
 */
QStringList QOrganizerManagerEngineFactory::keys() const
{
    return QStringList() << managerName();
}

QT_END_NAMESPACE_ORGANIZER

#include "moc_qorganizermanagerenginefactory.cpp"
