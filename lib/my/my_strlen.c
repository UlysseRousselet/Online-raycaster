/*
** EPITECH PROJECT, 2022
** my_strlen.c
** File description:
** a
*/

#include <unistd.h>

int my_strlen(char const *str)
{
    int count = 0;
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        count++;
    }
    return count;
}
