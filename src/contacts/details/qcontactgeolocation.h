// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:significant reason:default

#ifndef QCONTACTGEOLOCATION_H
#define QCONTACTGEOLOCATION_H

#include <QtCore/qdatetime.h>

#include <QtContacts/qcontactdetail.h>

QT_BEGIN_NAMESPACE_CONTACTS

/* Leaf class */
// replaces the below
class Q_CONTACTS_EXPORT QContactGeoLocation : public QContactDetail
{
public:
#ifndef Q_QDOC
    Q_DECLARE_CUSTOM_CONTACT_DETAIL(QContactGeoLocation)
#else
    static const DetailType Type;
#endif

    enum GeoLocationField {
        FieldLabel = 0,
        FieldLatitude,
        FieldLongitude,
        FieldAccuracy,
        FieldAltitude,
        FieldAltitudeAccuracy,
        FieldHeading,
        FieldSpeed,
        FieldTimestamp
    };

    void setLabel(const QString& _label);
    QString label() const;
    void setLatitude(double _latitude);
    double latitude() const;
    void setLongitude(double _longitude);
    double longitude() const;
    void setAccuracy(double _accuracy);
    double accuracy() const;
    void setAltitude(double _altitude);
    double altitude() const;
    void setAltitudeAccuracy(double _altitudeAccuracy);
    double altitudeAccuracy() const;
    void setHeading(double _heading);
    double heading() const;
    void setSpeed(double _speed);
    double speed() const;
    void setTimestamp(const QDateTime& _timestamp);
    QDateTime timestamp() const;
};

QT_END_NAMESPACE_CONTACTS

#endif // QCONTACTGEOLOCATION_H
