/*
** EPITECH PROJECT, 2018
** PSU_2018_malloc
** File description:
** Split blocks
*/

#include <unistd.h>
#include <stdlib.h>
#include "malloc.h"
#include "struct.h"

void split_mem(meta_data_t *block, size_t size)
{
    meta_data_t *new;
    long long int calc = block->size - size - (8 - size % 8) -
        sizeof(meta_data_t);

    block->free = FALSE;
    block->size = size + (8 - size % 8);
    if (calc > 0) {
        new = (void *)(block + 1) + size + (8 - size % 8);
        new->size = calc;
        new->next = block->next;
        new->free = TRUE;
        block->next = new;
    }
}