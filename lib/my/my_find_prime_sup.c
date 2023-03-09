/*
** EPITECH PROJECT, 2022
** my_find_is_prime_sup.c
** File description:
** a
*/

int my_find_prime_sup(int nb)
{
    int val;
    for (int i = 2; i < nb; i ++) {
        val = nb % i;
        if (val == 0) {
            nb++;
            i = 2;
        }
    }
    return nb;
}
