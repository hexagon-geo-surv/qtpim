// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qversitorganizerhandler.h"

QT_BEGIN_NAMESPACE_VERSITORGANIZER

/*!
  \class QVersitOrganizerHandler
  \brief The QVersitOrganizerHandler class is a union of the
  QVersitOrganizerImporterPropertyHandlerV2 and QVersitOrganizerExporterDetailHandlerV2 interfaces.
  \ingroup versit-extension
  \inmodule QtVersit
 */

/*!
  \class QVersitOrganizerHandlerFactory
  \brief The QVersitOrganizerHandlerFactory class provides the interface for Versit plugins.
  \ingroup versit-extension
  \inmodule QtVersit

  This class provides a simple interface for the creation of QVersitOrganizerHandler instances.
  Implement this interface to write a Versit plugin.  For more details, see \l{Qt Versit Plugins}.
 */

/*!
   \fn static const QString QVersitOrganizerHandlerFactory::ProfileSync()

   The constant string signifying a plugin that is relevant to import and export in a
   synchronization context.
   \sa QVersitOrganizerHandlerFactory::profiles(), QVersitOrganizerImporter, QVersitOrganizerExporter
 */

/*!
   \fn static const QString QVersitOrganizerHandlerFactory::ProfileBackup()

   The constant string signifying a plugin that is relevant to import and export in a backup/restore
   context.
   \sa profiles(),
   QVersitOrganizerImporter::QVersitOrganizerImporter(),
   QVersitOrganizerExporter::QVersitOrganizerExporter()
 */

/*!
  \fn QVersitOrganizerHandlerFactory::~QVersitOrganizerHandlerFactory()
  This frees any memory used by the QVersitOrganizerHandlerFactory.
 */

/*!
  \fn QSet<QString> QVersitOrganizerHandlerFactory::profiles() const
  This function can be overridden to allow a plugin to report which profiles it is to be active
  under.  If this (as in the default case) returns the empty set, it indicates that the plugin
  should be loaded under all profiles.  If it returns a non-empty set, it will only be loaded for
  those profiles that are specified by the importer/exporter class.
 */

/*!
  \fn QString QVersitOrganizerHandlerFactory::name() const
  This function should return a unique string that identifies the handlers provided by this factory.
  Typically, this will be of the form "org.qt-project.Qt.SampleVersitOrganizerHandler" with the
  appropriate domain and handler name substituted.
 */

/*!
  \fn int QVersitOrganizerHandlerFactory::index() const
  This function should return an index that helps with determining the order in which to run the
  plugins.  Plugins are run in the following order:
  \list
  \li Positively-indexed, ascending
  \li Zero-indexed
  \li Negatively-indexed, ascending
  \endlist
  For example, plugins with an index of 1 are run first and plugins of index -1 are run last.
  If more than one plugin share an index, the order of execution between them is undefined.

  By default, this returns 0, which is recommended for plugins with no special ordering
  requirements.
 */

/*!
  \fn QVersitOrganizerHandlerFactory::createHandler() const
  This function is called by the Versit importer or exporter class to create an instance of the
  handler provided by this factory.
 */

/*!
  \fn QVersitOrganizerHandler::~QVersitOrganizerHandler()
  Destroys this QVersitOrganizerHandler.
 */

QT_END_NAMESPACE_VERSITORGANIZER
