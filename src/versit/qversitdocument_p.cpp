// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qversitdocument_p.h"

QT_BEGIN_NAMESPACE_VERSIT

QVersitDocumentPrivate::QVersitDocumentPrivate()
    : QSharedData(),
    mVersitType(QVersitDocument::InvalidType)
{
}

QVersitDocumentPrivate::QVersitDocumentPrivate(const QVersitDocumentPrivate& other)
    : QSharedData(other),
    mVersitType(other.mVersitType),
    mComponentType(other.mComponentType),
    mProperties(other.mProperties),
    mSubDocuments(other.mSubDocuments)
{
}

QT_END_NAMESPACE_VERSIT
