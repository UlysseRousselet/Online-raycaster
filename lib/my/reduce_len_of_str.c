/*
** EPITECH PROJECT, 2022
** my_strncat.c
** File description:
** s
*/

#include "my.h"

void reduce_len_of_str(char *dest, char *src, int reduce)
{
    int i = 0;
    for (; i < my_strlen(src) - reduce; i++) {
        dest[i] = src[i + reduce];
    }
    dest[i] = '\0';
}
