// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtQuick 2.0
import QtOrganizer 5.0

RollerRow {
    label: "Collection"
    valueSet: createCollectionNameValueSet();

    function createCollectionNameValueSet() {
         var collectionNameArray = new Array();
         for (var i=0;i<organizer.collections.length;i++) {
             collectionNameArray.push(organizer.collections[i].name);
             }
         return collectionNameArray;
     }

    function findCollectionArrayIndex(itemCollectionId) {
        // search item's collection id
        for (var i=0;i<organizer.collections.length;i++) {
            if (organizer.collections[i].collectionId == itemCollectionId) {
                return i;
                }
            }
        // item's collection id not found, use default one
        for (var i=0;i<organizer.collections.length;i++) {
            if (organizer.collections[i].collectionId == organizer.defaultCollectionId()) {
                return i;
                }
            }
        return -1;
       }
}

