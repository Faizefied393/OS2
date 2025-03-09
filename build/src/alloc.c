allocation_strategy current_strategy = FIRST_FIT;
void set_allocation_strategy(allocation_strategy strategy) {
    current_strategy = strategy;
}

void *tumalloc(size_t size) {
    if (size <= 0) return NULL;

    free_block *prev = NULL, *current = HEAD;
    free_block *best_prev = NULL, *worst_prev = NULL, *next_prev = NULL;
    free_block *best_block = NULL, *worst_block = NULL;
    static free_block *next_block = NULL;  // For Next Fit

    // First Fit (Default)
    if (current_strategy == FIRST_FIT) {
        while (current) {
            if (current->size >= size) {
                if (prev) prev->next = current->next;
                else HEAD = current->next;
                return (void *)(current + 1);
            }
            prev = current;
            current = current->next;
        }
    }

    // Best Fit: Finds the smallest suitable block
    else if (current_strategy == BEST_FIT) {
        while (current) {
            if (current->size >= size && (!best_block || current->size < best_block->size)) {
                best_block = current;
                best_prev = prev;
            }
            prev = current;
            current = current->next;
        }
        if (best_block) {
            if (best_prev) best_prev->next = best_block->next;
            else HEAD = best_block->next;
            return (void *)(best_block + 1);
        }
    }

    // Worst Fit: Finds the largest block
    else if (current_strategy == WORST_FIT) {
        while (current) {
            if (current->size >= size && (!worst_block || current->size > worst_block->size)) {
                worst_block = current;
                worst_prev = prev;
            }
            prev = current;
            current = current->next;
        }
        if (worst_block) {
            if (worst_prev) worst_prev->next = worst_block->next;
            else HEAD = worst_block->next;
            return (void *)(worst_block + 1);
        }
    }

    // Next Fit: Starts search from the last allocated block
    else if (current_strategy == NEXT_FIT) {
        if (!next_block) next_block = HEAD;
        prev = NULL;
        current = next_block;

        while (current) {
            if (current->size >= size) {
                next_block = current->next;
                if (prev) prev->next = current->next;
                else HEAD = current->next;
                return (void *)(current + 1);
            }
            prev = current;
            current = current->next;
        }

        // If no block found, restart from HEAD
        next_block = HEAD;
        return tumalloc(size);
    }

    return do_alloc(size);  // If no block found, allocate new memory
}

