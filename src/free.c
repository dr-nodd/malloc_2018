/*
** EPITECH PROJECT, 2018
** PSU_2018_malloc
** File description:
** Free
*/

#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include "malloc.h"

meta_data_t *get_header(void *ptr)
{
    if (!ptr)
        return (NULL);
    return ((meta_data_t *)ptr - 1);
}

size_t merge(meta_data_t *block)
{
    size_t tmp;

    if (block->next != NULL && block->next->free == TRUE) {
        tmp = block->size + block->next->size + sizeof(meta_data_t);
        block->next = block->next->next;
        return (tmp);
    }
    return (block->size);
}

void free(void *ptr)
{
    meta_data_t *block;

    if (!ptr)
        return;
    block = get_header(ptr);
    if (!block)
        return;
    if (block->free == TRUE)
        return;
    block->free = TRUE;
    block->size = merge(block);
}