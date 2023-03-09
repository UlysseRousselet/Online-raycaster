/*
** EPITECH PROJECT, 2022
** funct_flag.c
** File description:
** printf
*/

#include <stdlib.h>
#include "my.h"

char **malloc_2d_array(int y, int x)
{
    char **tab = malloc(sizeof(char*) * (y + 1));
    int i = 0;
    for (i = 0; i < y; i++) {
        tab[i] = malloc(sizeof(char) * (x + 1));
    }
    tab[y] = NULL;
    return tab;
}
