/*
** EPITECH PROJECT, 2018
** PSU_2018_malloc
** File description:
** Print address
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_puthexa(long unsigned int i)
{
    if (i > 16)
        return (84);
    if (i < 10)
        my_putchar(48 + i);
    else
        my_putchar(97 + (i - 10));
    return (0);
}

void print_address(void *ptr)
{
    long unsigned int i = 0;
    long unsigned int nb = (long unsigned int)(ptr);

    if (nb >= 16) {
        i = nb % 16;
        nb = nb / 16;
        print_address((void *)nb);
        my_puthexa(i);
    } else
        my_puthexa(nb);
}

void put_pointer(void *ptr)
{
    write(1, "0x", 2);
    print_address(ptr);
}