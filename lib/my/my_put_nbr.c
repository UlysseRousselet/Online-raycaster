/*
** EPITECH PROJECT, 2022
** my_put_nbr.c
** File description:
** nbr
*/

#include <unistd.h>

void my_putchar(char c);

void my_put_nbr(int nb)
{
    int y = 0;
    if (nb >= -2147483647 && nb < 0) {
        my_putchar('-');
        nb = nb * (- 1);
    }
    if (nb < -2147483647 || nb > 2147483647){
        my_putchar('0');
        return;
    }
    y = nb % 10;
    if (nb > 0 && nb <= 2147483647) {
        my_put_nbr(nb / 10);
        my_putchar(48 + y);
    }
}
