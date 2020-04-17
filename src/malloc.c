/*
** EPITECH PROJECT, 2018
** PSU_2018_malloc
** File description:
** Malloc
*/

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include "malloc.h"

void *first_node = NULL;

void show_alloc_mem(void)
{
    meta_data_t *block = first_node;

    write(1, "break : ", 8);
    put_pointer(sbrk(0));
    write(1, "\n", 1);
    while (block->next != NULL) {
        put_pointer(block);
        write(1, " - ", 3);
        put_pointer(block + block->size);
        write(1, " : ", 3);
        my_put_nbr(block->size);
        write(1, " bytes\n", 7);
        block = block->next;
    }
    put_pointer(block);
    write(1, " - ", 3);
    put_pointer(block + block->size);
    write(1, " : ", 3);
    my_put_nbr(block->size);
    write(1, " bytes\n", 7);
}

meta_data_t *allocate_block(meta_data_t *last, size_t size)
{
    meta_data_t *block;
    long unsigned int x = 1;

    while (x * sysconf(_SC_PAGESIZE) < (size + sizeof(meta_data_t)))
        x *= sysconf(_SC_PAGESIZE) * 10 * 16;
    block = sbrk(x * sysconf(_SC_PAGESIZE));
    if (block == (void *) -1)
        return (NULL);
    block->size = x * sysconf(_SC_PAGESIZE) - sizeof(meta_data_t);
    block->free = FALSE;
    if (last != NULL)
        last->next = block;
    block->next = NULL;
    split_mem(block, size);
    return (block);
}

meta_data_t *find_free_block(size_t size)
{
    meta_data_t *block;

    block = first_node;
    while (block != NULL && !(block->free == TRUE && block->size > size))
        block = block->next;
    return (block);
}

void *my_malloc(size_t size)
{
    meta_data_t *block;
    meta_data_t *tmp;

    if (first_node == NULL) {
        block = allocate_block(NULL, size);
        if (block == NULL)
            return NULL;
        first_node = block;
    } else {
        block = find_free_block(size);
        if (block == NULL) {
            tmp = first_node;
            for (; tmp->next != NULL; tmp = tmp->next);
            block = allocate_block(tmp, size);
            if (block == NULL)
                return NULL;
        } else
            split_mem(block, size);
    }
    return (void *)(block + 1);
}

void *malloc(size_t size)
{
    void *ptr;

    static pthread_mutex_t mutex;
    pthread_mutex_lock(&mutex);
    ptr = my_malloc(size);
    pthread_mutex_unlock(&mutex);
    return (ptr);
}