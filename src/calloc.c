/*
** EPITECH PROJECT, 2018
** PSU_2018_malloc
** File description:
** Calloc
*/

#include <string.h>
#include "malloc.h"

void *calloc(size_t elem, size_t elemsize)
{
    long long unsigned int size = elem * elemsize;
    void *ptr = malloc(size);

    memset(ptr, 0, size);
    return ptr;
}