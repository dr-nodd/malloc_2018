/*
** EPITECH PROJECT, 2018
** PSU_2018_malloc
** File description:
** Structure for malloc
*/

#ifndef PSU_2018_MALLOC_STRUCT_H
#define PSU_2018_MALLOC_STRUCT_H

#define TRUE 0
#define FALSE 1

typedef struct meta_data_s {
    size_t size;
    int free;
    struct meta_data_s *next;
} meta_data_t;

#endif //PSU_2018_MALLOC_STRUCT_H
