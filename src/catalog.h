//
// Created by Kanari on 2016/12/23.
//

#ifndef REBASE_CATALOG_H
#define REBASE_CATALOG_H

#include "redbase.h"

struct RelCatEntry {
    char relName[MAXNAME + 1]; // relation name
    int tupleLength;           // tuple length in bytes
    int attrCount;             // number of attributes
    int indexCount;            // number of indexed attributes (not decreased when index is dropped)
    int recordCount;           // number of records in the relation
};

struct AttrCatEntry {
    char relName[MAXNAME + 1];  // this attribute's relation
    char attrName[MAXNAME + 1]; // attribute name
    int offset;                 // offset in bytes from beginning of tuple
    AttrType attrType;          // attribute type
    int attrSize;               // attribute size
    int attrDisplayLength;             // attribute length
                                //     for INT columns the length is only used to format display
                                //     for STRING columns the length does NOT include '\0'
    int attrSpecs;              // attribute specification(s)
    int indexNo;                // index number, or -1 if not indexed
};

#endif //REBASE_CATALOG_H
