/*
** EPITECH PROJECT, 2018
** PSU_2018_malloc
** File description:
** Realloc
*/

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "malloc.h"

void *realloc(void *ptr, size_t size)
{
    void *new_ptr;
    meta_data_t *block;

    if (!ptr)
        return malloc(size);
    block = get_header(ptr);
    if (block->size >= size)
        return ptr;
    new_ptr = malloc(size);
    if (!new_ptr)
        return NULL;
    memcpy(new_ptr, ptr, block->size);
    free(ptr);
    return new_ptr;
}