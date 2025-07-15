#ifndef chunk_h
#define chunk_h

#include "common.h"
#include "value.h"


typedef enum {
    OP_CONSTANT,
    OP_RETURN,
} OpCode;

typedef struct {
    int count;
    int capacity;
    int* items;
} Lines;

typedef struct {
    int count;
    int capacity;
    uint8_t* code;
    Lines* lines;
    ValueArray constants;
} Chunk;


void initChunk(Chunk* chunk);
void freeChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte, int line);
int addConstant(Chunk* chunk, Value value);

// TODO: OP_CONSTANT_LONG for 24-bit number constant.
// void writeConstant(Chunk* chunk, Value value, int line);
#endif
