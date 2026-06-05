// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QCONTACTINVALIDBACKEND_P_H
#define QCONTACTINVALIDBACKEND_P_H

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

#include <QtContacts/qcontactmanagerengine.h>

QT_BEGIN_NAMESPACE_CONTACTS

class QContactInvalidEngine : public QContactManagerEngine
{
public:
    QContactInvalidEngine();
    QString managerName() const override;

    /*! \reimp */
    int managerVersion() const override {return 0;}
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTINVALIDBACKEND_P_H
