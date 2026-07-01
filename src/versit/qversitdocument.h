// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QVERSITDOCUMENT_H
#define QVERSITDOCUMENT_H

#include <QtCore/qlist.h>
#include <QtCore/qshareddata.h>

#include <QtVersit/qversitdocument.h>
#include <QtVersit/qversitproperty.h>

QT_BEGIN_NAMESPACE_VERSIT

class QVersitProperty;

class QVersitDocumentPrivate;
class Q_VERSIT_EXPORT QVersitDocument
{
public:
    enum VersitType {
        InvalidType,
        VCard21Type,    // vCard version 2.1
        VCard30Type,    // vCard version 3.0 (RFC 2426)
        VCard40Type,    // vCard version 4.0
        ICalendar20Type // iCalendar version 2.0 (RFC 2445/5545)
    };

    QVersitDocument();
    QVersitDocument(const QVersitDocument& other);
    QVersitDocument(VersitType type);
    ~QVersitDocument();

    QVersitDocument& operator=(const QVersitDocument& other);
    bool operator==(const QVersitDocument& other) const;
    bool operator!=(const QVersitDocument& other) const;

    // Metadata about the versit document
    // The type determines the format for serialization
    void setType(VersitType type);
    VersitType type() const;

    // The componentType is the value of the BEGIN property
    void setComponentType(QString componentType);
    QString componentType() const;

    // The content
    void addProperty(const QVersitProperty& property);
    void removeProperty(const QVersitProperty& property);
    void removeProperties(const QString& name);
    void setProperties(const QList<QVersitProperty>& properties);
    QList<QVersitProperty> properties() const;

    void addSubDocument(const QVersitDocument& subdocument);
    void removeSubDocument(const QVersitDocument& subdocument);
    void setSubDocuments(const QList<QVersitDocument>& documents);
    QList<QVersitDocument> subDocuments() const;

    bool isEmpty() const;
    void clear();

private:

    QSharedDataPointer<QVersitDocumentPrivate> d;
};

Q_VERSIT_EXPORT uint qHash(const QVersitDocument& key);
#ifndef QT_NO_DEBUG_STREAM
Q_VERSIT_EXPORT QDebug operator<<(QDebug dbg, const QVersitDocument& property);
#endif

QT_END_NAMESPACE_VERSIT

Q_DECLARE_METATYPE(QTVERSIT_PREPEND_NAMESPACE(QVersitDocument))

#endif // QVERSITDOCUMENT_H
