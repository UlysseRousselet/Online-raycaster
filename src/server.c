/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** 3D test
*/

#include "my.h"

int main(void)
{
    int socketServer = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addresseServer;
    addresseServer.sin_addr.s_addr = inet_addr("192.168.0.32");
    addresseServer.sin_family = AF_INET;
    addresseServer.sin_port = htons(30000);

    bind(socketServer, (const struct sockaddr *)&addresseServer, sizeof(addresseServer));
    listen(socketServer, 5);
    printf("Serveur en attente de 2 connections\n");
    int socketClient[2];
    struct sockaddr_in addresseClient;
    socklen_t clientsize = sizeof(addresseClient);
    socketClient[0] = accept(socketServer, (struct sockaddr *)&addresseClient, &clientsize);
    printf("client accepté\n");
    printf("client numero %d\n", socketClient[0]);
    socketClient[1] = accept(socketServer, (struct sockaddr *)&addresseClient, &clientsize);
    printf("client accepté\n");
    printf("client numero %d\n", socketClient[1]);
    send(socketClient[0], "Connection avec l'autre joueur établie\n", 41, 0);
    send(socketClient[1], "Connection avec l'autre joueur établie\n", 41, 0);
    double x_and_y[2];
    while (1) {
        recv(socketClient[0], &x_and_y, sizeof(x_and_y), 0);
        send(socketClient[1], &x_and_y, sizeof(x_and_y), 0);
        recv(socketClient[1], &x_and_y, sizeof(x_and_y), 0);
        send(socketClient[0], &x_and_y, sizeof(x_and_y), 0);
    }
    close(socketClient[0]);
    close(socketClient[1]);
    close(socketServer);
    return EXIT_SUCCESS;
}
