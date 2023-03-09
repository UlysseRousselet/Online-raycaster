/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** 3D test
*/

#include "my.h"

void set_up_wall(env *env)
{
    env->wall_tab = malloc(sizeof(sfVector2f) * env->nbr_of_wall);
    int largeur = my_strlen(env->map[0]);
    int longueur = my_len_of_array(env->map);
    int nbr_of_wall = 0;
    for (int i = 0; i < longueur; i++) {
        for (int y = 0; y < largeur; y++) {
            if (env->map[i][y] == '#') {
                env->wall_tab[nbr_of_wall].x = y * 30;
                env->wall_tab[nbr_of_wall].y = i * 30;
                nbr_of_wall++;
            }
        }
    }
}

void set_up(env *env, Player *player, Other_Player *other_Player)
{    
    player->x = 40;
    player->y = 40;
    player->angle = 0;
    env->middle_of_screen.x = 960;
    env->middle_of_screen.y = 540;
    player->sensivity = 100;
    player->avancer = 0;
    player->droite = 0;
    player->gauche = 0;
    player->reculer = 0;
    player->draw_distance = 300;

    other_Player->x = 40;
    other_Player->y = 40;
    other_Player->texture = sfTexture_createFromFile("assets/Doom_guy.png", NULL);
    other_Player->sprite = sfSprite_create();
    sfSprite_setTexture(other_Player->sprite, other_Player->texture, sfTrue);
    env->other_Player = other_Player;

    env->map = file_into_2d_array("map.txt");
    env->nbr_of_wall = get_nbr_wall(env->map);
    set_up_wall(env);
    env->wall_3d = sfConvexShape_create();
    sfConvexShape_setPointCount(env->wall_3d, 4);
    env->clock = sfClock_create();

    env->wall_rect_test = sfRectangleShape_create();
    sfRectangleShape_setFillColor(env->wall_rect_test, sfGreen);
    sfVector2f size = {30, 30};
    sfRectangleShape_setSize(env->wall_rect_test, size);
    player->point_player_test = sfCircleShape_create();
    sfCircleShape_setRadius(player->point_player_test, 2);
    sfCircleShape_setFillColor(player->point_player_test, sfWhite);
    player->line_direction_player_test = sfConvexShape_create();
    sfConvexShape_setPointCount(player->line_direction_player_test, 4);
    sfConvexShape_setFillColor(player->line_direction_player_test, sfWhite);
    sfConvexShape_setOutlineThickness(player->line_direction_player_test, 1);

    env->player = player;
}