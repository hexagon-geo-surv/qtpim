// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QDECLARATIVEGLOBAL_H
#define QDECLARATIVEGLOBAL_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.
// This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <QtCore/qobject.h>

QT_BEGIN_NAMESPACE

QT_MODULE(Declarative)

#define DEFINE_BOOL_CONFIG_OPTION(name, var) \
    static bool name() \
    { \
        static enum { Yes, No, Unknown } status = Unknown; \
        if (status == Unknown) { \
            QByteArray v = qgetenv(#var); \
            bool value = !v.isEmpty() && v != "0" && v != "false"; \
            if (value) status = Yes; \
            else status = No; \
        } \
        return status == Yes; \
    }

struct QQmlGraphics_DerivedObject : public QObject
{
    void setParent_noEvent(QObject *parent) {
        bool sce = d_ptr->sendChildEvents;
        d_ptr->sendChildEvents = false;
        setParent(parent);
        d_ptr->sendChildEvents = sce;
    }
};

/*!
    Returns true if the case of \a fileName is equivalent to the file case of
    \a fileName on disk, and false otherwise.

    This is used to ensure that the behavior of QML on a case-insensitive file
    system is the same as on a case-sensitive file system.  This function
    performs a "best effort" attempt to determine the real case of the file.
    It may have false positives (say the case is correct when it isn't), but it
    should never have a false negative (say the case is incorrect when it is
    correct).
*/
bool QQml_isFileCaseCorrect(const QString &fileName);

/*!
    Makes the \a object a child of \a parent.  Note that when using this method,
    neither \a parent nor the object's previous parent (if it had one) will
    receive ChildRemoved or ChildAdded events.
*/
inline void QQml_setParent_noEvent(QObject *object, QObject *parent)
{
    static_cast<QQmlGraphics_DerivedObject *>(object)->setParent_noEvent(parent);
}

QT_END_NAMESPACE

#endif // QDECLARATIVEGLOBAL_H
