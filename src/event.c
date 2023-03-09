/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** 3D test
*/

#include "my.h"

void move_player(env *env)
{
    if (env->player->avancer == 1) {
        env->player->x += cos(env->player->angle / (180/PI));
        env->player->y += sin(env->player->angle / (180/PI));
        if (check_collision(env, env->player->x, env->player->y)) {
            env->player->x -= cos(env->player->angle / (180/PI));
            env->player->y -= sin(env->player->angle / (180/PI));
        }
    }
    if (env->player->reculer == 1) {
        env->player->x -= cos(env->player->angle / (180/PI));
        env->player->y -= sin(env->player->angle / (180/PI));
        if (check_collision(env, env->player->x, env->player->y)) {
            env->player->x += cos(env->player->angle / (180/PI));
            env->player->y += sin(env->player->angle / (180/PI));
        }
    }
    if (env->player->droite == 1) {
        env->player->x -= cos((env->player->angle - 90) / (180/PI));
        env->player->y -= sin((env->player->angle - 90) / (180/PI));
        if (check_collision(env, env->player->x, env->player->y)) {
            env->player->x -= cos((env->player->angle + 90) / (180/PI));
            env->player->y -= sin((env->player->angle + 90) / (180/PI));
        }
    }
    if (env->player->gauche == 1) {
        env->player->x -= cos((env->player->angle + 90) / (180/PI));
        env->player->y -= sin((env->player->angle + 90) / (180/PI));
        if (check_collision(env, env->player->x, env->player->y)) {
            env->player->x -= cos((env->player->angle - 90) / (180/PI));
            env->player->y -= sin((env->player->angle - 90) / (180/PI));
        }
    }
}

void event_fct(sfRenderWindow *window, sfEvent event, env *env)
{
    sfMouse_setPositionRenderWindow(env->middle_of_screen, window);
    while (sfRenderWindow_pollEvent(window, &event))
    {
        if (event.type == sfEvtKeyPressed) {
            switch (event.key.code) {
                case sfKeyZ:
                    env->player->avancer = 1;
                    break;
                case sfKeyS:
                    env->player->reculer = 1;
                    break;
                case sfKeyD:
                    env->player->droite = 1;
                    break;
                case sfKeyQ:
                    env->player->gauche = 1;
                    break;
                default:
                    break; 
            }
        }
        if (event.type == sfEvtKeyReleased) {
            switch (event.key.code) {
                case sfKeyZ:
                    env->player->avancer = 0;
                    break;
                case sfKeyS:
                    env->player->reculer = 0;
                    break;
                case sfKeyD:
                    env->player->droite = 0;
                    break;
                case sfKeyQ:
                    env->player->gauche = 0;
                    break;
                default:
                    break; 
            }
        }
        if (event.type == sfEvtMouseMoved) {
            env->player->angle += (float)(event.mouseMove.x - env->middle_of_screen.x) / env->player->sensivity;
            if (env->player->angle > 360)
                env->player->angle = 0;
            if (env->player->angle < 0)
                env->player->angle = 360;
        }
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
    move_player(env);
    
}
