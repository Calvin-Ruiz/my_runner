/*
** EPITECH PROJECT, 2019
** MUL_my_runner
** File description:
** main.h
*/

#ifndef MAIN_H_
#define MAIN_H_

#include "my_getnbr.h"
#include <my_read.h>
#include <entitylib.h>
#include <player.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <get_next_line.h>

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

char **load_map(char *filename, long int *len, int *nb_cols,
    char nb_cols_param);
void mainloop(data_storage_t *datas);
void my_init_entity_bases(data_storage_t *datas);
int map_editor(char **map, int nb_cols, int nb_lines_param,
    const char *filename);
int my_menu(param_t *params, char ***map, int nb_cols);

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

static inline void remove_all_entities(entity_t **entities, const int len)
{
    int i = -1;

    while (++i < len) {
        if (entities[i]) {
            free(entities[i]);
            entities[i] = NULL;
        }
    }
}

static inline void reset_entities(entitylist_t **elists, entity_t *player,
    char nb_lines)
{
    data_storage_t *datas = get_data_storage();
    int j = -1;
    entity_t *tmp = elists[4]->list[0];

    elists[4]->list[0] = NULL;
    while (++j < 6)
        remove_all_entities(elists[j]->list, elists[j]->len);
    tmp->pos.v1.x = -80.f;
    elists[4]->list[0] = tmp;
    player->health = 3;
    player->pos.v1 = (sfVector2f) {256, 64 * (nb_lines - 2)};
    player->pos.v2 = (sfVector2f) {320, 64 * (nb_lines - 1)};
    player->gravity = 4.f;
    player->vel.x = 25.6f;
    player->vel.y = 0.f;
    datas->next_shoot = 0;
    datas->background1_pos.x = 0;
    datas->background2_pos.x = 0;
    datas->background3_pos.x = 0;
    datas->old_dec = 0;
}

static inline int my_play(char **map, int nb_cols)
{
    data_storage_t *datas = get_data_storage();
    internal_data_t *dat = get_internal_data();
    int sizes[6] = {1, 1, 1, 1, 1, 1};
    int pos[6] = {0, 1, 2, 3, 4, 5};
    reset_entities(datas->entitylists, datas->player->entity, map[0][-1]);
    datas->map = map;
    datas->nb_cols = nb_cols;
    datas->alive = 1;
    if (init_heart_and_score(datas->textures[1], datas->textures[0]))
        return (84);
    if (init_collider(pos, sizes, datas, 20))
        return (84);
    sfThread_launch(datas->displayer);
    mainloop(datas);
    if (sfRenderWindow_isOpen(datas->window))
        my_game_over(datas->window, dat, datas, (datas->player->entity->health
            == -2) ? dat->level_completed : dat->game_over);
    destroy_heart_and_score();
    save_higher_score(datas);
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
