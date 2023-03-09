/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** 3D test
*/

#include "my.h"

void debug_2d_draw(sfRenderWindow *window, env *env)
{
    for (int i = 0; i < env->nbr_of_wall; i++) {
        sfRectangleShape_setPosition(env->wall_rect_test ,env->wall_tab[i]);
        sfRenderWindow_drawRectangleShape(window, env->wall_rect_test, NULL);
    }
    sfVector2f player_pos_test = {env->player->x, env->player->y};
    sfCircleShape_setPosition(env->player->point_player_test, player_pos_test);
    sfRenderWindow_drawCircleShape(window ,env->player->point_player_test, NULL);
    sfConvexShape_setPoint(env->player->line_direction_player_test, 0, player_pos_test);
    sfConvexShape_setPoint(env->player->line_direction_player_test, 1, player_pos_test);
    sfVector2f player_angle_line_test = {env->player->x + (cos(env->player->angle / (180/PI)) * 30), env->player->y + (sin(env->player->angle / (180/PI)) * 30)};
    sfConvexShape_setPoint(env->player->line_direction_player_test, 2, player_angle_line_test);
    sfConvexShape_setPoint(env->player->line_direction_player_test, 3, player_angle_line_test);
    sfRenderWindow_drawConvexShape(window, env->player->line_direction_player_test, NULL);
}

int check_collision(env *env, float x, float y)
{
    for (int i = 0; i < env->nbr_of_wall; i++) {
        if (x < env->wall_tab[i].x + 30 && x > env->wall_tab[i].x && y < env->wall_tab[i].y + 30 && y > env->wall_tab[i].y) {
            return 1;
        }
    }
    return 0;
}

void draw_2d_debug(sfRenderWindow *window, env *env, float distance_x, float distance_y)
{
    sfVector2f player_pos = {env->player->x, env->player->y};
    sfConvexShape_setPoint(env->player->line_direction_player_test, 0, player_pos);
    sfConvexShape_setPoint(env->player->line_direction_player_test, 1, player_pos);
    player_pos.x = distance_x;
    player_pos.y = distance_y;
    sfConvexShape_setPoint(env->player->line_direction_player_test, 2, player_pos);
    sfConvexShape_setPoint(env->player->line_direction_player_test, 3, player_pos);
    sfRenderWindow_drawConvexShape(window, env->player->line_direction_player_test, NULL);
}

void draw_3d(sfRenderWindow *window, env *env, float distance, int index) {
    if ((env->player->angle + index < 135 && env->player->angle + index > 45) || (env->player->angle + index < 315 && env->player->angle + index > 225))
        distance *= sin((env->player->angle + index) / (180/PI));
    else
        distance *= cos((env->player->angle + index) / (180/PI));
    if (distance < 0)
        distance *= -1;
    distance = 3000 / distance; 
    if (distance > 500)
        distance = 500;
    sfVector2f wall = {(index + 45) * 22, env->middle_of_screen.y - distance};
    sfConvexShape_setPoint(env->wall_3d, 0, wall);
    wall.x += 22;
    sfConvexShape_setPoint(env->wall_3d, 1, wall);
    wall.y += distance * 2;
    sfConvexShape_setPoint(env->wall_3d, 2, wall);
    wall.x -= 22;
    sfConvexShape_setPoint(env->wall_3d, 3, wall);
    distance *= 2;
    if (distance > 200)
        distance = 200;
    sfColor color = {distance, distance, distance, 255};
    sfConvexShape_setFillColor(env->wall_3d, color);
    sfRenderWindow_drawConvexShape(window, env->wall_3d, NULL);
}

void raycast_draw(sfRenderWindow *window, env *env)
{
    float distance_x = 0;
    float distance_y = 0;
    for (int i = -45; i < 46; i++) {
        for (int y = 1; y < 500; y++) {
            distance_x = env->player->x + cos((env->player->angle + i) / (180/PI)) * y;
            distance_y = env->player->y + sin((env->player->angle + i) / (180/PI)) * y;
            if (check_collision(env, distance_x, distance_y)) {
                draw_2d_debug(window, env, distance_x, distance_y);
                draw_3d(window, env, sqrt((env->player->x - distance_x) * (env->player->x - distance_x) + (env->player->y - distance_y) * (env->player->y - distance_y)), i);
                break;
            }
        }
    }
}
