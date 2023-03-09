/*
** EPITECH PROJECT, 2022
** my_strcmp.c
** File description:
** s
*/

#include <stddef.h>
#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    if (my_strlen(s1) != my_strlen(s2))
        return 0;
    for (int i = 0; i < my_strlen(s1); i++) {
        if (s1[i] != s2[i])
            return 0;
    }
    return 1;
}

int my_strcmplen(char const *s1, char const *s2, int len)
{
    for (int i = 0; i < my_strlen(s1) && i < len; i++) {
        if (s1[i] != s2[i])
            return 0;
    }
    return 1;
}
