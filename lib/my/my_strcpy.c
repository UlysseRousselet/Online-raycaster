/*
** EPITECH PROJECT, 2022
** my_strcpy.c
** File description:
** s
*/

char *my_strcpy(char *dest, char const *src)
{
    int a = 0;
    for (int i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
        a++;
    }
    dest[a] = '\0';
    return dest;
}
