/*
** EPITECH PROJECT, 2022
** my_get_nbr.c
** File description:
** a
*/

#include <unistd.h>

int my_getnbr(char const *str)
{
    int i = 0;
    int nombre = 0;
    int moin = 0;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == 45 && (str[i + 1 ] >= 48 || str[i + 1 ] <= 57))
            moin = 1;
        if (str[i] >= 48 && str[i] <= 57) {
            nombre *= 10;
            nombre += ((int)str[i] - 48);
        }
        if (nombre != 0 && (str[i] < 48 || str[i] > 57))
            break;
    }
    if (nombre > 32767 || nombre < -32767)
        return 0;
    if (moin == 1) {
        return (-nombre);
    } else {
        return nombre;
    }
}
