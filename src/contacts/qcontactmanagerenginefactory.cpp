// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qcontactmanagerenginefactory.h"

QT_BEGIN_NAMESPACE_CONTACTS

/*!
  \class QContactManagerEngineFactory
  \brief The QContactManagerEngineFactory class provides the interface for
 plugins that implement QContactManagerEngine functionality.

  \inmodule QtContacts

  \ingroup contacts-backends

  This class provides a simple interface for the creation of
  manager engine instances.  Each factory has a specific id
  associated with it, which forms the \c managerName parameter
  when creating \l QContactManager objects.

  More information on writing a contacts engine plugin is available in
  the \l{Qt Contacts Manager Engines} documentation.

  \sa QContactManager, QContactManagerEngine
 */

/*!
  A default, empty destructor.
 */
QContactManagerEngineFactory::~QContactManagerEngineFactory()
{
}

/*!
  \internal
 */
QStringList QContactManagerEngineFactory::keys() const
{
    return QStringList() << managerName();
}

/*!
  \fn QContactManagerEngineFactory::engine(const QMap<QString, QString>& parameters, QContactManager::Error* error)

  This function is called by the QContactManager implementation to
  create an instance of the engine provided by this factory.

  The \a parameters supplied can be ignored or interpreted as desired.

  If a supplied parameter results in an unfulfillable request, or some other error
  occurs, this function may return a null pointer, and the client developer will get an
  invalid QContactManager in return.  Any error should be stored in the supplied \a error
  reference.
 */

/*!
  \fn QContactManagerEngineFactory::managerName() const

  This function should return a unique string that identifies
  the engines provided by this factory.

  Typically this would be of the form "org.qt-project.Qt.SampleContactEngine", with
  the appropriate domain and engine name substituted.
 */

/*!
  \fn QContactManagerEngineFactory::supportedImplementationVersions() const

  This function should return a list of versions of the engine which this factory can instantiate.
 */
QList<int> QContactManagerEngineFactory::supportedImplementationVersions() const
{
    return QList<int>();
}

QT_END_NAMESPACE_CONTACTS

#include "moc_qcontactmanagerenginefactory.cpp"
