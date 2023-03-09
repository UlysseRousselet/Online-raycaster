/*
** EPITECH PROJECT, 2022
** funct_flag.c
** File description:
** printf
*/

#include <stdarg.h>
#include "my.h"

int type_zero(const char *format, int *i)
{
    return 2;
}

int type_plus(const char *format, int *i)
{
    my_putchar('+');
    return 2;
}

int type_moin(const char *format, int *i)
{
    return 2;
}

int type_space(const char *format, int *i)
{
    int x;
    for (x = 1; format[*i] == '%' && format[*i + x] == ' '; x++);
    if (x > 1)
        my_putchar(' ');
    return x;
}

int type_hashtag(const char *format, int *i)
{
    return 2;
}
