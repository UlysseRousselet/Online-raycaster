/*
** EPITECH PROJECT, 2022
** my_show_word_array.c
** File description:
** s
*/

int my_putstr(char const *str);
void my_putchar(char c);

int my_len_of_array(char **tab)
{
    int nbr_arg = 0;
    while (*tab) {
        tab++;
        nbr_arg++;
    }
    return nbr_arg;
}
