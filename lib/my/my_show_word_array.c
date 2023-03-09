/*
** EPITECH PROJECT, 2022
** my_show_word_array.c
** File description:
** s
*/

int my_putstr(char const *str);
void my_putchar(char c);

int my_show_word_array(char **tab)
{
    int nbr_arg;
    while (*tab) {
        my_putstr(*tab);
        my_putchar(10);
        tab++;
        nbr_arg++;
    }
    return nbr_arg;
}
