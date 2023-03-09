/*
** EPITECH PROJECT, 2022
** my_printf.c
** File description:
** va_arg
*/

#include <stdarg.h>
#include "my.h"

void str_hex2(const char *format, va_list list, int *i, int *count)
{
    char hexa[30000]; int a;
    int j = 0; long deci;
    long quotient; long reste;
    deci = va_arg(list, int);
    quotient = deci;
    while (quotient != 0) {
        reste = quotient % 16;
        if (reste < 10) {
            hexa[j++] = 48 + reste;
        } else
            hexa[j++] = 55 + reste;
        quotient = quotient / 16;
    }
    for (a = j; a >= 1; a--) {
        my_putchar(hexa[a - 1]);
    }
    *i = *i + 1;
}

void str_float(const char *format, va_list list, int *i, int *count)
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

void str_g(const char *format, va_list list, int *i, int *count)
{
    double nbr = va_arg(list, double); double nbr2 = nbr;
    int avantvirgule = nbr; int apvirgule = 0;
    int dav = 0; int dap = 0;
    for (int y = 10; nbr > 0 && y != 10000000; y *= 10)
        nbr -= y; dav++;
    dap = 6 - dav;
    double nbr3 = nbr2 - avantvirgule;
    for (int r = 0; r < dap; r++)
        nbr3 *= 10;
    apvirgule = nbr3;
    if (dav >= 6)
        my_printf("%e", nbr2);
    else
        my_printf("%d", avantvirgule);
    if (dav < 6)
        if (apvirgule != 0)
            my_printf(".%d", apvirgule);
    *i = *i + 1;
}

void str_n(const char *format, va_list list, int *i, int *count)
{
    int *a = va_arg(list, int*);
    *a = *i;
    *i = *i + 1;
}

void str_p(const char *format, va_list list, int *i, int *count)
{
    void *ptr;
    ptr = va_arg(list, void*);
    unsigned long long result = (unsigned long long)ptr;
    my_printf("0x%x", result);
    *i = *i + 1;
}
