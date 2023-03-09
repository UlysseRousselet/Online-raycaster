/*
** EPITECH PROJECT, 2022
** my_compute_square_root.c
** File description:
** a
*/

int my_compute_square_root(int nb)
{
    int val;
    for (int i = 0; i <= nb; i++) {
        val = i * i;
        if (val == nb) {
            return i;
        }
    }
    return 0;
}
