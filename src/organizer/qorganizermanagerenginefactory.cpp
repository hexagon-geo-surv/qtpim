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

#include "moc_qorganizermanagerenginefactory.cpp"

QT_END_NAMESPACE_ORGANIZER
