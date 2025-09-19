#include <stdlib.h>

#include "chunk.h"
#include "memory.h"


void initChunk(Chunk* chunk) {
    chunk->count = 0;
    chunk->capacity = 0;
    chunk->code = NULL;

    chunk->lines = malloc(sizeof(Lines));
    chunk->lines->count = 0;
    chunk->lines->capacity = 0;
    chunk->lines->items = NULL;
    chunk->lines->items = GROW_ARRAY(int, chunk->lines->items, 0, chunk->lines->capacity);

    initValueArray(&chunk->constants);
}

void freeChunk(Chunk* chunk) {
    FREE_ARRAY(uint8_t, chunk->code, chunk->capacity);
    FREE_ARRAY(uint8_t, chunk->lines->items, chunk->lines->capacity);
    free(chunk->lines);
    freeValueArray(&chunk->constants);
    initChunk(chunk);

}

void writeChunk(Chunk* chunk, uint8_t byte, int line) {
    if (chunk->capacity < chunk->count + 1) {
        int oldCapacity = chunk->capacity;
        chunk->capacity = GROW_CAPACITY(oldCapacity);
        chunk->code  = GROW_ARRAY(uint8_t, chunk->code, oldCapacity, chunk->capacity);
    }
    chunk->code[chunk->count] = byte;
    chunk->count++;

    if ((chunk->lines->count >= 2) && (chunk->lines->items[chunk->lines->count - 1] == line)) {
        chunk->lines->items[chunk->lines->count - 2]++; 
    } else {
        if (chunk->lines->capacity < chunk->lines->count + 2) {
            int oldCapacity = chunk->lines->capacity;
            chunk->lines->capacity = GROW_CAPACITY(oldCapacity);
            chunk->lines->items = GROW_ARRAY(int, chunk->lines->items, oldCapacity, chunk->lines->capacity);
        }
        // run-length encoding for line numbers
        chunk->lines->items[chunk->lines->count] = 1;
        chunk->lines->items[chunk->lines->count + 1] = line;
        chunk->lines->count += 2;
    }

}

int addConstant(Chunk* chunk, Value value) {
    writeValueArray(&chunk->constants, value);
    return chunk->constants.count - 1;
}
