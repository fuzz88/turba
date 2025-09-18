#ifndef table_h
#define table_h

#include "common.h"
#include "value.h"

typedef struct {
    ObjString* key;
    Value value;
}

typedef struct {
    int count;
    int capacity;
    Entry* entries;
} Table;

void initTable(Table* table);
void freeTable(Table* table);

#endif
