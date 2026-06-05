// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QVERSITPROPERTY_H
#define QVERSITPROPERTY_H

#include <QtCore/qhash.h>
#include <QtCore/qshareddata.h>
#include <QtCore/qstringlist.h>
#include <QtCore/qvariant.h>

#include <QtVersit/qversitglobal.h>

QT_BEGIN_NAMESPACE_VERSIT

class QVersitPropertyPrivate;
class Q_VERSIT_EXPORT QVersitProperty
{
public:
    enum ValueType {
        PlainType,
        CompoundType,
        ListType,
        BinaryType,
        VersitDocumentType,
        PreformattedType
    };

    QVersitProperty();
    QVersitProperty(const QVersitProperty& other);
    ~QVersitProperty();

    QVersitProperty& operator=(const QVersitProperty& other);
    bool operator==(const QVersitProperty& other) const;
    bool operator!=(const QVersitProperty& other) const;

    void setGroups(const QStringList& groups);
    QStringList groups() const;

    void setName(const QString& name);
    QString name() const;

    void insertParameter(const QString& name, const QString& value);
    void removeParameter(const QString& name, const QString& value);
    void removeParameters(const QString& name);

    void setParameters(const QMultiHash<QString,QString>& parameters);
    QMultiHash<QString,QString> parameters() const;

    void setValue(const QVariant& value);
    QVariant variantValue() const;
    template <typename T> T value() const
    {
        return variantValue().value<T>();
    }
    QString value() const;

    void setValueType(ValueType type);
    ValueType valueType() const;

    bool isEmpty() const;
    void clear();

private:

    QSharedDataPointer<QVersitPropertyPrivate> d;
};

Q_VERSIT_EXPORT size_t qHash(const QVersitProperty& key);
#ifndef QT_NO_DEBUG_STREAM
Q_VERSIT_EXPORT QDebug operator<<(QDebug dbg, const QVersitProperty& property);
#endif

QT_END_NAMESPACE_VERSIT

#endif // QVERSITPROPERTY_H
