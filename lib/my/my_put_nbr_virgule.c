/*
** EPITECH PROJECT, 2022
** my_put_nbr_virgule.c
** File description:
** nbr
*/

#include <unistd.h>

void my_putchar(char c);
int my_put_nbr(int nb);
int my_put_nbr_virgule(int nb, int virgule)
{
    int y = 0;
    if (nb >= -2147483647 && nb < 0) {
        my_putchar('-');
        nb = nb * (- 1);
    }
    if (nb < -2147483647 || nb > 2147483647){
        my_putchar('0');
        return 0;
    }
    y = nb % 10;
    if (nb > 0 && nb <= 2147483647) {
        virgule++;
        my_put_nbr_virgule(nb / 10, virgule);
        my_putchar('.');
        my_put_nbr(virgule);
        my_putchar(48 + y);
    }
    return 0;
}
