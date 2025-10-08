#ifndef chunk_h
#define chunk_h

#include "common.h"
#include "value.h"


typedef enum {
    OP_ADD,
    OP_SUBSTRACT,
    OP_MULTIPLY,
    OP_DIVIDE,
    OP_CONSTANT,
    OP_NEGATE,
    OP_RETURN,
    OP_NIL,
    OP_TRUE,
    OP_FALSE,
    OP_NOT,
    OP_EQUAL,
    OP_GREATER,
    OP_LESS,
    OP_PRINT,
    OP_POP,
    OP_DEFINE_GLOBAL,
    OP_GET_GLOBAL,
    OP_SET_GLOBAL,
    OP_GET_LOCAL,
    OP_SET_LOCAL,
    OP_JUMP_IF_FALSE,
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
