/*
** EPITECH PROJECT, 2022
** my_strcat.c
** File description:
** s
*/

#include <stddef.h>
#include <stdio.h>
#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int count;
    count = my_strlen(dest);
    int i = 0;
    for (i = 0; src[i] != '\0'; i++) {
        dest[count + i] = src[i];
    }
    dest[count + i] = '\0';
    return dest;
}
