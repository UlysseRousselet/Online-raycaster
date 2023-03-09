/*
** EPITECH PROJECT, 2022
** my_putstr.c
** File description:
** a
*/

#include <unistd.h>

void my_putchar(char c);

void my_putstr(char const *str)
{
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
}
