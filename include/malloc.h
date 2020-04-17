/*
** EPITECH PROJECT, 2018
** PSU_2018_malloc
** File description:
** Malloc header
*/

#ifndef PSU_2018_MALLOC_MALLOC_H
#define PSU_2018_MALLOC_MALLOC_H

#include <stdlib.h>
#include "struct.h"

void *malloc(size_t);
void *realloc(void *, size_t);
void free(void *);

meta_data_t *get_header(void *);
void show_alloc_mem();
void split_mem(meta_data_t *, size_t);

void my_putchar(char);
void put_pointer(void *ptr);
long long int my_put_nbr(long long int nb);

#endif //PSU_2018_MALLOC_MALLOC_H
