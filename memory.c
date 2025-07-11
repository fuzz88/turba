#include <stdlib.h>

#include "memory.h"


void* reallocate(void* pointer, size_t oldSize, size_t newSize)
    /* TODO:    hardcore mode:
     *          implement your own heap memory allocator.         
    */ 
{
    if (newSize == 0) {
        free(pointer);
        return NULL;
    }
    
    void* result = realloc(pointer, newSize);
    if (result == NULL) exit(1);
    return result;

