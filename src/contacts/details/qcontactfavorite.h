// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QCONTACTFAVORITE_H
#define QCONTACTFAVORITE_H

#include <QtContacts/qcontactdetail.h>

QT_BEGIN_NAMESPACE_CONTACTS

class QContactFilter;

/* Leaf class */
class Q_CONTACTS_EXPORT QContactFavorite : public QContactDetail
{
public:
#ifndef Q_QDOC
    Q_DECLARE_CUSTOM_CONTACT_DETAIL(QContactFavorite)
#else
    static const DetailType Type;
#endif

    enum FavoriteField {
        FieldFavorite = 0,
        FieldIndex
    };

    void setFavorite(bool _isFavorite);
    bool isFavorite() const;
    void setIndex(int _index);
    int index() const;

    // Convenience filter
    static QContactFilter match();
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTFAVORITE_H
