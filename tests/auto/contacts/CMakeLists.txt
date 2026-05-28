# Copyright (C) 2026 The Qt Company Ltd.
# SPDX-License-Identifier: BSD-3-Clause

add_subdirectory(qcontact)
add_subdirectory(qcontactasync)
add_subdirectory(qcontactcollection)
add_subdirectory(qcontactdetail)
add_subdirectory(qcontactdetails)
add_subdirectory(qcontactfilter)
add_subdirectory(qcontactmanager)
add_subdirectory(qcontactmanagerdetails)
add_subdirectory(qcontactmanagerfiltering)
add_subdirectory(qcontactmanagerplugins)
add_subdirectory(qcontactmemusage)
add_subdirectory(qcontactrelationship)
add_subdirectory(qcontactsortorder)
add_subdirectory(qmlcontacts)

if(TARGET Qt6::ServiceFramework)
    add_subdirectory(qcontactactions)
endif()
