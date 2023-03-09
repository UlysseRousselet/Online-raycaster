/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** my_printf
*/

#include <stdarg.h>
#include "my.h"

void str_e2(const char *format, va_list list, int *i, int *count)
{
    double deci = va_arg(list, double); int a = 0;
    while (deci >= 10 || deci <= 1 && deci != 0) {
        if (deci >= 10) {
            deci = deci / 10; a++;
        }
        if (deci <= 1) {
            deci *= 10; a--;
        }
    } my_printf("%f",deci); my_putchar('E');
    if (a >= 0) {
        my_putchar('+'); if (a >= 0 && a < 10)
            my_putchar('0');
        if (a == 0)
            my_putchar('0');
        my_put_nbr(a);
    } if (a < 0) {
        my_putchar('-'); if ( a <= 0 && a > -10)
            my_putchar('0');
        a *= -1; my_put_nbr(a);
    } *i = *i + 1;
}

void str_float2(const char *format, va_list list, int *i, int *count)
{
    double nbr = va_arg(list, double);
    if (nbr < 0)
        nbr -= 0.0000005;
    else
        nbr += 0.0000005;
    if (nbr < 0 && nbr > -1)
        my_putchar('-');
    if (nbr < 1 && nbr > -1)
        my_putchar('0');
    long int test = nbr * 10; long int avantvirgule = nbr;
    long int aprèsvirgule = (nbr  - avantvirgule) * 1000000;
    my_put_nbr(avantvirgule);
    my_putchar('.'); int y = 1;
    while (y != 1000000) {
        y *= 10; test = nbr * y;
        if (avantvirgule * y == test)
            my_putchar('0');
    } if (nbr < 0)
        aprèsvirgule *= -1;
    my_put_nbr(aprèsvirgule); *i = *i + 1;
}

void str_m(const char *format, va_list list, int *i, int *count)
{
    my_putstr("Success");
}
