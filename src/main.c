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
        double x_and_y[2] = {env->player->x, env->player->y};
        send(socketClient, &x_and_y, sizeof(x_and_y), 0);
        recv(socketClient, &env->player->x_and_y, sizeof(env->player->x_and_y), 0);
        //printf("x = %f, y = %f\n", env->player->x_and_y[0], env->player->x_and_y[1]);
        event_fct(window, event, env);
        sfRenderWindow_clear(window, sfBlack);
        debug_2d_draw(window, env);
        raycast_draw(window, env);
        sfRenderWindow_display(window);
    }
}

int main(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow* window;
    sfEvent event;
    env env;
    Player player;
    set_up(&env, &player);
    /////////////
    int socketClient = socket(AF_INET, SOCK_STREAM, 0);
    
    struct sockaddr_in addresseClient;
    addresseClient.sin_addr.s_addr = inet_addr("127.0.0.1");
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
