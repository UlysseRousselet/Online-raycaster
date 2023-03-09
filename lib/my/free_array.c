/*
** EPITECH PROJECT, 2022
** free_array.c
** File description:
** lib
*/

#include "my.h"

void free_array(char **array, int size)
{
    for (int i = 0; i < size; i++) {
        free(array[i]);
    }
    free(array);
}
