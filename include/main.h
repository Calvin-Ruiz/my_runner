/*
** EPITECH PROJECT, 2019
** MUL_my_runner
** File description:
** main.h
*/

#ifndef MAIN_H_
#define MAIN_H_

#include "my_getnbr.h"
#include "my_read.h"
#include <entitylib.h>
#include <player.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"

typedef struct param {
    int fps;
    char menu;
    char practice;
    char editor;
    int nb_lines;
    char optimize;
    char *name;
    sfVector2u fen_size;
} param_t;

char **load_map(const char *filename, long int *len, int *nb_cols,
    char nb_cols_param);
void mainloop(data_storage_t *datas);
void my_init_entity_bases(data_storage_t *datas);
int map_editor(char **map, int nb_cols, int nb_lines_param,
    const char *filename);

void my_jump(entity_t *self, entity_t *target);
void my_kill(entity_t *self, entity_t *target);
void my_gravity_inverter(entity_t *entity, entity_t *target);
void my_jump_sphere(entity_t *self, entity_t *target);
void my_overjump_sphere(entity_t *self, entity_t *target);

static inline int apply_parameter(int i, char **args, param_t *parameters)
{
    if (args[i][1] == 'f') {
        if (args[++i])
            parameters->fps = my_getnbr(args[i]);
    } else if (args[i][1] == 'p')
        parameters->practice = 1;
    if (args[i][1] == 'n') {
        if (args[++i])
            parameters->nb_lines = my_getnbr(args[i]);
    } else if (args[i][1] == 'r')
        parameters->menu = 0;
    if (args[i][1] == 's') {
        if (args[++i] && args[i + 1]) {
            parameters->fen_size.x = my_getnbr(args[i++]);
            parameters->fen_size.y = my_getnbr(args[i]);
        }
    } else if (args[i][1] == 'e')
        parameters->editor = 1;
    return (i);
}

static inline int my_play(char **map, int nb_cols)
{
    data_storage_t *datas = get_data_storage();
    int sizes[6] = {1, 1, 1, 1, 1, 1};
    int pos[6] = {0, 1, 2, 3, 4, 5};

    datas->map = map;
    datas->nb_cols = nb_cols;
    if (init_heart_and_score(datas->textures[1], datas->textures[0]))
        return (84);
    if (init_collider(pos, sizes, datas, 20))
        return (84);
    sfThread_launch(datas->displayer);
    mainloop(datas);
    if (sfRenderWindow_isOpen(datas->window))
        my_game_over(datas->window, get_internal_data(), datas);
    destroy_heart_and_score();
    return (0);
}

static inline void my_help(int n, char **args)
{
    int fd;
    char *str;
    long int len = 0;

    if (n != 2 || args[1][0] != '-' || args[1][1] != 'h' || args[1][2] != '\0')
        return;
    fd = open("readme.txt", O_RDONLY);
    if (fd == -1) {
        write(2, "Help unavailable : file 'readme.txt' not found.\n", 48);
        return;
    }
    str = my_read(fd, &len);
    close(fd);
    if (str == NULL) {
        write(2, "Help unavailable : read error\n", 30);
        return;
    }
    write(1, str, len);
    free(str);
}

#endif /* MAIN_H_ */
