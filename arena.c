#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

typedef struct {
    size_t capacity;
    size_t offset;
    uint8_t *data;
} Arena;

Arena arena_alloc(size_t size)
{
    uint8_t *data = malloc(size);
    Arena result = {
        .capacity = size,
        .offset = 0,
        .data = data,
    };
    return result;
}

void *arena_push(Arena *arena, size_t size)
{
    // If true, then the object can be allocated
    if(arena->offset + size < arena->capacity)
    {
        void *ptr = &arena->data[arena->offset];
        // Increment offset by size of object
        arena->offset += size;
        memset(ptr, 1, size);
        return ptr;
    }

    printf("Oops");
    return NULL;
}

void arena_free_all(Arena *arena)
{
    // Should this suffice? i think im still leaking memory
    arena->offset = 0;

    // free it? this feels fucking wierd
    free(arena->data);
}

