/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** maze
*/

#include "my.h"  

int get_nbr_wall(char **map)
{
    int largeur = my_strlen(map[0]);
    int longueur = my_len_of_array(map);
    int nbr_of_wall = 0;
    for (int i = 0; i < longueur; i++) {
        for (int y = 0; y < largeur; y++) {
            if (map[i][y] == '#')
                nbr_of_wall++;
        }
    }
    return nbr_of_wall;
}

void delete_return_of_line(char *line, int largeur)
{
    for (int i = 0; i < largeur; i++) {
        if (line[i] == '\n') {
            line[i] = '\0';
        }
    }
}

char **file_into_2d_array2(char *filepath, int hauteur, int largeur)
{
    FILE * fp;
    char **maze = malloc_2d_array(hauteur, largeur);
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    hauteur = 0;
    fp = fopen(filepath, "r");
    while ((read = getline(&line, &len, fp)) != -1) {
        delete_return_of_line(line, largeur);
        my_strcpy(maze[hauteur], line);
        hauteur++;
    }
    free(line);
    fclose(fp);
    return maze;
}

char **file_into_2d_array(char *filepath)
{
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    fp = fopen(filepath, "r");
    if (fp == NULL) exit(84);
    int hauteur = 0; int largeur = 0;
    while ((read = getline(&line, &len, fp)) != -1) {
        hauteur++;
        if (read > largeur)
            largeur = read;
    }
    if (hauteur == 0 || largeur == 0)
        exit(84);
    free(line);
    fclose(fp);
    char **maze = file_into_2d_array2(filepath, hauteur, largeur);
    return maze;
}