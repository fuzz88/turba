#ifndef vm_h
#define vm_h


#include "chunk.h"


typedef struct {
    Chunk* chunk;
} VM;


void initVM();
void freeVM();

#endif
