/*
** EPITECH PROJECT, 2022
** my_printf.c
** File description:
** va_arg
*/

#include <stdarg.h>
#include "my.h"

void (*funct_tab[])(const char *, va_list, int *, int *) = {str_str,
    str_int, str_int, str_char,
    str_unsint, str_mod, str_oct, str_bin,
    str_hex, str_hex2, str_e, str_float, str_g, str_n, str_p,
    str_e2,str_float2,str_m};

int (*funct_flag[])(const char *, int *) = {type_zero,
    type_plus, type_moin, type_space, type_hashtag};

char *arg_type = "sdicu%obxXefgnpEFm";
char *flag_tab = "0+- #";
int my_printf2(int *i, int *count, const char *format, va_list list)
{
    int x = 1;
    int z = 0;
    for (int a = 0;  flag_tab[a] != '\0'; a++) {
        if (format[*i] == '%' && flag_tab[a] == format[*i + 1])
            x = (*funct_flag[a])(format, i);
    }
    for (int y = 0;  arg_type[y] != '\0'; y++) {
        if (format[*i] == '%' && arg_type[y] == format[*i + x]) {
            (*funct_tab[y])(format, list, i, count);
            *i = *i + x - 1;
            z = 1;
        }
    }
    if ( z == 0)
        my_putchar(format[*i]);
    *count++;
}

int my_printf(const char *format, ...)
{
    va_list list;
    va_start(list, format);
    int n = my_strlen(format);
    int count = 0;
    for (int i = 0; i < n; i++) {
        my_printf2(&i, &count, format, list);
    }
    va_end(list);
    return count;
}
