/*
** EPITECH PROJECT, 2022
** my_compute_power_rec.c
** File description:
** a
*/

int my_compute_power_rec(int nb, int p)
{
    if (p == 0) {
        return 1;
    }
    if (p < 0) {
        return 0;
    }
    p--;
    nb *= my_compute_power_rec(nb, p);
    return nb;
}
