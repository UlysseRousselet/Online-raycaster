/*
** EPITECH PROJECT, 2022
** B-MUL-100-PAR-1-1-myhunter-ulysse.rousselet
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_
    #define PI 3.14159
    #include <signal.h>
    #include <sys/types.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <ucontext.h>
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include <math.h>
    #include <pthread.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <netdb.h>
    #include <arpa/inet.h>
    #include <fcntl.h>
    
typedef struct Player {
    int last_mouse_pos_x;
    int last_mouse_pos_y;
    int sensivity;
    double angle;
    double x;
    double y;
    int avancer;
    int reculer;
    int droite;
    int gauche;
    int draw_distance;
    sfCircleShape *point_player_test;
    sfConvexShape *line_direction_player_test;
    
} Player;

typedef struct Other_Player {
    double x;
    double y;
    sfTexture *texture;
    sfSprite *sprite;
    float distance_x;
    float distance_y;
    float i;
} Other_Player;

typedef struct env {
    Player *player;
    sfVector2i middle_of_screen;
    Other_Player *other_Player;
    char **map;
    int nbr_of_wall;
    sfRectangleShape *wall_rect_test;
    sfConvexShape *wall_3d;
    sfVector2f *wall_tab;
    sfClock *clock;
} env;

int my_printf(const char *format, ...);
int my_show_word_array(char * const *tab);
void my_putchar(char c);
char *my_strstr(char *str, char const *to_find);
int my_isneg(int nb);
int my_strcmp(char const *s1, char const *s2);
int my_put_nbr(int nb);
int my_strncmp(char const *s1, char const *s2, int n);
void my_swap(int *a, int *b);
char *my_strupcase(char *str);
int my_putstr(char const *str);
char *my_strlowcase(char *str);
int my_strlen(char const *str);
char *my_strcapitalize(char *str);
int my_getnbr(char const *str);
int my_str_isalpha(char const *str);
void my_sort_int_array(int *tab, int size);
int my_str_isnum(char const *str);
int my_compute_power_rec(int nb, int power);
int my_str_islower(char const *str);
int my_compute_square_root(int nb);
int my_str_isupper(char const *str);
int my_is_prime(int nb);
int my_str_isprintable(char const *str);
int my_find_prime_sup(int nb);
int my_showstr(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_showmem(char const *str, int size);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcat(char *dest, char const *src);
char *my_revstr(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_get_nbr_2(int nb);
void str_str(const char *format, va_list list, int *i, int *count);
void str_int(const char *format, va_list list, int *i, int *count);
void str_char(const char *format, va_list list, int *i, int *count);
void str_unsint(const char *format, va_list list, int *i, int *count);
void str_mod(const char *format, va_list list, int *i, int *count);
void str_oct(const char *format, va_list list, int *i, int *count);
void str_bin(const char *format, va_list list, int *i, int *count);
void str_hex(const char *format, va_list list, int *i, int *count);
void str_hex2(const char *format, va_list list, int *i, int *count);
void str_e(const char *format, va_list list, int *i, int *count);
void str_float(const char *format, va_list list, int *i, int *count);
void str_g(const char *format, va_list list, int *i, int *count);
int my_put_unsnbr(unsigned int nb);
int my_put_nbr_virgule(int nb, int virgule);
void str_n(const char *format, va_list list, int *i, int *count);
void str_p(const char *format, va_list list, int *i, int *count);
int type_zero(const char *format, int *i);
int type_plus(const char *format, int *i);
int type_moin(const char *format, int *i);
int type_space(const char *format, int *i);
int type_hashtag(const char *format, int *i);
void str_e2(const char *format, va_list list, int *i, int *count);
void str_float2(const char *format, va_list list, int *i, int *count);
void str_m(const char *format, va_list list, int *i, int *count);
char **malloc_2d_array(int y, int x);
void set_up(env *env, Player *player, Other_Player *other_Player);
void event_fct(sfRenderWindow *window, sfEvent event, env *env);
char **file_into_2d_array(char *filepath);
char **my_str_to_word_array(char *str, char delimiter);
int my_len_of_array(char **tab);
void reduce_len_of_str(char *dest, char *src, int reduce);
void free_array(char **array, int size);
int my_strcmplen(char const *s1, char const *s2, int len);
int get_nbr_wall(char **map);
int check_collision(env *env, float x, float y);
void raycast_draw(sfRenderWindow *window, env *env);
void draw_3d(sfRenderWindow *window, env *env, float distance, int index);
void draw_2d_debug(sfRenderWindow *window, env *env, float distance_x, float distance_y);
int check_collision(env *env, float x, float y);
void debug_2d_draw(sfRenderWindow *window, env *env);

#endif
