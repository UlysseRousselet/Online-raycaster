/*
** EPITECH PROJECT, 2022
** my_put_unsnbr.c
** File description:
** nbr
*/

#include <unistd.h>

void my_putchar(char c);

int my_put_unsnbr(unsigned int nb)
{
    unsigned int y = 0;
    if (nb < 0 || nb > 4294967295){
        my_putchar('0');
        return 0;
    }
    y = nb % 10;
    if (nb > 0 && nb <= 4294967296) {
        my_put_unsnbr(nb / 10);
        my_putchar(48 + y);
    }
    return 0;
}
