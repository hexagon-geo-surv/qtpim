// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QVERSITORGANIZERDEFS_P_H
#define QVERSITORGANIZERDEFS_P_H

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

#include <QtOrganizer/qorganizeritemdetails.h>

#include <QtVersitOrganizer/qversitorganizerglobal.h>

QTORGANIZER_USE_NAMESPACE

QT_BEGIN_NAMESPACE_VERSITORGANIZER

// Mapping between a string in versit specifications and Qt contact details
struct VersitOrganizerDetailMapping {
    const char* versitPropertyName;
    const QOrganizerItemDetail::DetailType detailType;
    const int detailField;
};

// Only put simple mappings in this table; ie. where a Versit property maps to a specific detail's
// specific field (and that detail has no other fields of interest)
const VersitOrganizerDetailMapping versitOrganizerDetailMappings[] = {
    // FIXME
    {"SUMMARY", QOrganizerItemDetail::TypeDisplayLabel, QOrganizerItemDisplayLabel::FieldLabel},
    {"DESCRIPTION", QOrganizerItemDetail::TypeDescription, QOrganizerItemDescription::FieldDescription},
    {"UID", QOrganizerItemDetail::TypeGuid, QOrganizerItemGuid::FieldGuid},
    {"CATEGORIES", QOrganizerItemDetail::TypeTag, QOrganizerItemTag::FieldTag}
};

QT_END_NAMESPACE_VERSITORGANIZER

#endif // QVERSITORGANIZERDEFS_P_H
