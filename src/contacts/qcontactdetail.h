// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QCONTACTDETAIL_H
#define QCONTACTDETAIL_H

#include <QtCore/qmap.h>
#include <QtCore/qshareddata.h>
#include <QtCore/qstringlist.h>
#include <QtCore/qvariant.h>

#include <QtContacts/qcontactsglobal.h>

QT_BEGIN_NAMESPACE_CONTACTS

class QContact;
class QContactActionDescriptor;
class QContactDetailPrivate;
class Q_CONTACTS_EXPORT QContactDetail
{
public:
    enum DetailType {
        TypeUndefined = 0,
        TypeAddress,
        TypeAnniversary,
        TypeAvatar,
        TypeBirthday,
        TypeDisplayLabel,
        TypeEmailAddress,
        TypeExtendedDetail,
        TypeFamily,
        TypeFavorite,
        TypeGender,
        TypeGeoLocation,
        TypeGlobalPresence,
        TypeGuid,
        TypeHobby,
        TypeName,
        TypeNickname,
        TypeNote,
        TypeOnlineAccount,
        TypeOrganization,
        TypePhoneNumber,
        TypePresence,
        TypeRingtone,
        TypeSyncTarget,
        TypeTag,
        TypeTimestamp,
        TypeType,
        TypeUrl,
        TypeVersion
    };

    enum DetailContext {
        ContextHome = 0,
        ContextWork,
        ContextOther
    };

    enum DetailField {
        FieldContext = 5000, //to avoid clashing with other detail field values from leaf classes
        FieldDetailUri,
        FieldLinkedDetailUris,
        FieldProvenance,
        FieldMaximumUserVisible = 10000 // keys above this will not be reported to clients via values() etc accessors.
    };

    enum AccessConstraint {
        NoConstraint = 0,
        ReadOnly = 0x01,
        Irremovable = 0x02
    };
    Q_DECLARE_FLAGS(AccessConstraints, AccessConstraint)

protected:
    QSharedDataPointer<QContactDetailPrivate> d;

public:
    QContactDetail();
    explicit QContactDetail(DetailType _type);
    QContactDetail(const QContactDetail &other);
    ~QContactDetail();
    QContactDetail& operator=(const QContactDetail& other);

    bool operator==(const QContactDetail& other) const;
    bool operator!=(const QContactDetail& other) const { return !(other == *this); }

    DetailType type() const;

    int key() const;
    void resetKey();

    AccessConstraints accessConstraints() const;

    bool isEmpty() const;
    bool setValue(int field, const QVariant& value);
    bool removeValue(int field);
    bool hasValue(int field) const;

    void setValues(const QMap<int, QVariant> &newValues);
    QMap<int, QVariant> values() const;
    QVariant value(int field) const;
    template <typename T> T value(int field) const {
        return value(field).value<T>();
    }

    void setContexts(int newContext)
    {
        QList<int> newContexts;
        newContexts << newContext;
        setValue(FieldContext, QVariant::fromValue(newContexts));
    }

    void setContexts(const QList<int>& newContexts)
    {
        setValue(FieldContext, QVariant::fromValue(newContexts));
    }

    QList<int> contexts() const
    {
        return value< QList<int> >(FieldContext);
    }

    void setDetailUri(const QString& newDetailUri)
    {
        setValue(FieldDetailUri, newDetailUri);
    }

    QString detailUri() const
    {
        return value(FieldDetailUri).toString();
    }

    void setLinkedDetailUris(const QStringList& newLinkedDetailUris)
    {
        setValue(FieldLinkedDetailUris, newLinkedDetailUris);
    }

    void setLinkedDetailUris(const QString& linkedDetailUri)
    {
        setValue(FieldLinkedDetailUris, QStringList(linkedDetailUri));
    }

    QStringList linkedDetailUris() const
    {
        return value<QStringList>(FieldLinkedDetailUris);
    }

    QString provenance() const
    {
        return value(FieldProvenance).toString();
    }

protected:
    QContactDetail(const QContactDetail &other, DetailType expectedType);
    QContactDetail& assign(const QContactDetail &other, DetailType expectedType);

private:
    friend class QContactDetailPrivate;
    friend class QContact;
    friend class QContactManagerEngine;
#ifndef QT_NO_DATASTREAM
    Q_CONTACTS_EXPORT friend QDataStream& operator>>(QDataStream& in, QContactDetail& detail);
#endif
};

Q_CONTACTS_EXPORT size_t qHash(const QContactDetail &key, size_t seed = 0) noexcept;
#ifndef QT_NO_DEBUG_STREAM
Q_CONTACTS_EXPORT QDebug operator<<(QDebug dbg, const QContactDetail& detail);
#endif
#ifndef QT_NO_DATASTREAM
Q_CONTACTS_EXPORT QDataStream& operator<<(QDataStream& out, const QContactDetail& detail);
Q_CONTACTS_EXPORT QDataStream& operator>>(QDataStream& in, QContactDetail& detail);
#endif

Q_DECLARE_OPERATORS_FOR_FLAGS(QContactDetail::AccessConstraints)

#define Q_DECLARE_CUSTOM_CONTACT_DETAIL(className) \
    className() : QContactDetail(Type) {} \
    className(const QContactDetail &field) : QContactDetail(field, Type) {} \
    className& operator=(const QContactDetail &other) {assign(other, Type); return *this;} \
    static const DetailType Type;

QT_END_NAMESPACE_CONTACTS

QT_BEGIN_NAMESPACE
Q_DECLARE_TYPEINFO(QTCONTACTS_PREPEND_NAMESPACE(QContactDetail), Q_MOVABLE_TYPE);
QT_END_NAMESPACE

#endif // QCONTACTDETAIL_H
