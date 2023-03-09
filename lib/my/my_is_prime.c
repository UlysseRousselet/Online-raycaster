/*
** EPITECH PROJECT, 2022
** my_is_prime.c
** File description:
** a
*/

int my_is_prime(int nb)
{
    int val;
    for (int i = 2; i < nb; i ++) {
        val = nb % i;
        if (val == 0) {
            return 0;
        }
    }
    return 1;
}
