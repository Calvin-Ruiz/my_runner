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

typedef struct param {
    int fps;
    char menu;
    char practice;
    char editor;
    int nb_lines;
    char optimize;
    char *name;
} param_t;

char **load_map(const char *filename, long int *len, int *nb_cols);
void mainloop(data_storage_t *datas, char **map, const int nb_cols);

static inline int apply_parameter(int i, char **args, param_t *parameters)
{
    switch (args[i][1]) {
    case 'f':
        if (args[i + 1])
            parameters->fps = my_getnbr(args[i + 1]);
        return (i + 1);
    case 'p':
        parameters->practice = 1;
        return (i);
    case 'r':
        parameters->menu = 0;
        return (i);
    case 'e':
        parameters->editor = 1;
        return (i + 1);
    case 'n':
        if (++args)
            parameters->nb_lines = my_getnbr(args[i + 1]);
        return (i + 1);
    }
    return (i);
}

static inline int my_init_uninit(char **map, param_t *params, int nb_cols,
    long int len)
{
    data_storage_t *datas = get_data_storage();

    if (init_heart_and_score(datas->textures[1], datas->textures[0]))
        return (84);
    int sizes[6] = {1, 1, 1, 1, 1, 1};
    int pos[6] = {0, 1, 2, 3, 4, 5};
    if (init_collider(pos, sizes, datas, 20))
        return (84);
    sfThread_launch(datas->displayer);
    mainloop(datas, map, nb_cols);
    free_storage_content(datas, 63);
    destroy_heart_and_score();
    free(*map - 1);
    free(map);
    return (0);
}

#endif /* MAIN_H_ */
