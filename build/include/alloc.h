#ifndef CYB3053_PROJECT2_ALLOC_H
#define CYB3053_PROJECT2_ALLOC_H

#include <stddef.h>

// Free block structure
typedef struct free_block {
    size_t size;
    struct free_block *next;
} free_block;

// Memory allocation strategies
typedef enum {
    FIRST_FIT,
    BEST_FIT,
    WORST_FIT,
    NEXT_FIT
} allocation_strategy;

extern allocation_strategy current_strategy;

void set_allocation_strategy(allocation_strategy strategy);
void *tumalloc(size_t size);
void *tucalloc(size_t num, size_t size);
void *turealloc(void *ptr, size_t new_size);
void tufree(void *ptr);

#endif
