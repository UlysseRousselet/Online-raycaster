/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** raycaster
*/

#include "my.h"

void game_loop(sfRenderWindow *window, sfEvent event, env *env, int socketClient)
{
    while (sfRenderWindow_isOpen(window)) {
        sfClock_restart(env->clock);
        double x_and_y[2] = {env->player->x, env->player->y};
        send(socketClient, &x_and_y, sizeof(x_and_y), 0);
        recv(socketClient, &x_and_y, sizeof(x_and_y), 0);
        env->other_Player->x = x_and_y[0];
        env->other_Player->y = x_and_y[1];
        //printf("%lf %lf\n", env->other_Player->x, env->player->x);
        event_fct(window, event, env);
        sfRenderWindow_clear(window, sfBlack);
        //debug_2d_draw(window, env);
        raycast_draw(window, env);
        sfRenderWindow_display(window);
        sfTime time = sfClock_getElapsedTime(env->clock);
        if (sfTime_asMicroseconds(time) > 30000) {
            env->player->draw_distance -= 20;
        } else if (env->player->draw_distance < 500)
            env->player->draw_distance += 20;
    }
}

int main(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow* window;
    sfEvent event;
    env env;
    Player player;
    Other_Player other_Player;
    set_up(&env, &player, &other_Player);
    /////////////
    int socketClient = socket(AF_INET, SOCK_STREAM, 0);
    
    struct sockaddr_in addresseClient;
    addresseClient.sin_addr.s_addr = inet_addr("78.198.90.102");
    addresseClient.sin_family = AF_INET;
    addresseClient.sin_port = htons(30000);
    connect(socketClient, (const struct sockaddr *)&addresseClient, sizeof(addresseClient));
    my_printf("Waiting for other player\n");
    char buffer[1000];
    recv(socketClient, &buffer, 1000, 0);
    fcntl(socketClient, F_SETFL, O_NONBLOCK);
    my_printf("%s\n", buffer);
    /////////////
    window = sfRenderWindow_create(mode, "3D test", sfResize | sfClose, NULL);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    sfRenderWindow_setFramerateLimit(window, 60);
    game_loop(window, event, &env, socketClient);
    
    sfRenderWindow_destroy(window);
    return EXIT_SUCCESS;
}
