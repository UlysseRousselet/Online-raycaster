/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** my_str_to_word_array.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int len_of_space(char *str, int i)
{
    if (i == my_strlen(str))
        return 1;
    int y = 1;
    for (y = 1; str[i + y] == ' ' || str[i + y] == '\n'; y++);
    return y;
}

char **set_str_array(char **str_array, char *str, char delimiter)
{
    int len_word = 0;
    int number_of_space = 0;
    for (int i = 0; i <= my_strlen(str); i++) {
        if (str[i] == delimiter || i == my_strlen(str)) {
            str_array[number_of_space][len_word] = '\0';
            number_of_space++;
            len_word = 0;
            i += len_of_space(str, i) - 1;
        } else {
            str_array[number_of_space][len_word] = str[i];
            len_word++;
        }
    }
    str_array[number_of_space] = NULL;
    return str_array;
}

char **my_str_to_word_array(char *str, char delimiter)
{
    int len_for_each_word[30000];
    int len_word = 0;
    int number_of_space = 0;
    for (int i = 0; i < my_strlen(str) + 1; i++) {
        if (str[i] == delimiter || i == my_strlen(str)) {
            len_for_each_word[number_of_space] = len_word;
            number_of_space++;
            len_word = 0;
            i += len_of_space(str, i) - 1;
        } else
            len_word++;
    }
    char **str_array = malloc(sizeof(char *) * (number_of_space + 1));
    int i = 0;
    for (i = 0; i < number_of_space; i++) {
        str_array[i] = malloc(sizeof(char) * (len_for_each_word[i] + 1));
    }
    set_str_array(str_array, str, delimiter);
    return str_array;
}
