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

Arena arena_alloc(size_t size);
void *arena_push(Arena *arena, size_t size);
void arena_free_all(Arena *arena);
