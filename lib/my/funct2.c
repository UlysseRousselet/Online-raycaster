/*
** EPITECH PROJECT, 2022
** my_printf.c
** File description:
** va_arg
*/

#include <stdarg.h>
#include "my.h"

void str_unsint(const char *format, va_list list, int *i, int *count)
{
    int b = va_arg(list, int);
    if (b < 0) {
        b = 4294967296 + b;
    }
    if (b > 4294967295)
        my_putchar('0');
    my_put_unsnbr(b);
    *count += my_get_nbr_2(b);
    *i = *i + 1;
}

void str_oct(const char *format, va_list list, int *i, int *count)
{
    char hexa[30000];
    int a = 0;
    int j = 0;
    unsigned long long deci = 0;
    unsigned long long quotient = 0;
    unsigned long long reste = 0;
    deci = va_arg(list, unsigned long long);
    quotient = deci;
    while (quotient != 0) {
        reste = quotient % 8;
        if (reste < 10) {
            hexa[j++] = 48 + reste;
        } else
            hexa[j++] = 87 + reste;
        quotient = quotient / 8;
    }
    for (a = j; a >= 1; a--) {
        my_putchar(hexa[a - 1]);
    }
    *i = *i + 1;
}

void str_bin(const char *format, va_list list, int *i, int *count)
{
    int bin[30000];
    int j = 0;
    int a = 1;
    long deci;
    long quotient; long b = 0;
    deci = va_arg(list,int);
    if (deci == 0)
        my_putchar('0');
    if (deci != 0) {
        quotient = deci;
        while (quotient != 0) {
            bin[a++] = quotient % 2;
            quotient = quotient / 2;
        }
        for (j = a - 1; j > 0; j--)
            b = b * 10 + bin[j];
        my_put_nbr(b);
    }
    *i = *i + 1;
}

void str_hex(const char *format, va_list list, int *i, int *count)
{
    char hexa[30000];
    int a = 0;
    int j = 0;
    unsigned long long deci = 0;
    unsigned long long quotient = 0;
    unsigned long long reste = 0;
    deci = va_arg(list, unsigned long long);
    quotient = deci;
    while (quotient != 0) {
        reste = quotient % 16;
        if (reste < 10) {
            hexa[j++] = 48 + reste;
        } else
            hexa[j++] = 87 + reste;
        quotient = quotient / 16;
    }
    for (a = j; a >= 1; a--) {
        my_putchar(hexa[a - 1]);
    }
    *i = *i + 1;
}

void str_e(const char *format, va_list list, int *i, int *count)
{
    double deci = va_arg(list, double); int a = 0;
    while (deci >= 10 || deci <= 1 && deci != 0) {
        if (deci >= 10) {
            deci = deci / 10; a++;
        }
        if (deci <= 1) {
            deci *= 10; a--;
        }
    } my_printf("%f",deci); my_putchar('e');
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
