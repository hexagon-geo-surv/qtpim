// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QCONTACTNOTE_H
#define QCONTACTNOTE_H

#include <QtContacts/qcontactdetail.h>

QT_BEGIN_NAMESPACE_CONTACTS

/* Leaf class */
class Q_CONTACTS_EXPORT QContactNote : public QContactDetail
{
public:
#ifndef Q_QDOC
    Q_DECLARE_CUSTOM_CONTACT_DETAIL(QContactNote)
#else
    static const DetailType Type;
#endif

    enum NoteField {
        FieldNote = 0
    };

    void setNote(const QString& _note);
    QString note() const;
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTNOTE_H
