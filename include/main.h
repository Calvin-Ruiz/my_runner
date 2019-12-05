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
#include "../entitylib/include/entity.h"
#include "../entitylib/include/entitylist.h"
#include "../entitylib/include/data_storage.h"
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

static inline void load_line (char **map, int col, int nb_cols,
    data_storage_t *datas)
{
    const char col_len = (*map)[-1];
    unsigned char i = -1;

    if (col >= nb_cols)
        return;
    while (++i < col_len) {
        if (!map[col][i]) {
            pos_t pos = {(sfVector2f) {1280.f, i * 64.f},
                (sfVector2f) {0.f, 0.f}};
            entity_t *entity = new_instance(datas->entities[map[col][i] & 63],
                pos, (sfVector2f) {-0.1f, 0.f}, 0);
            entitylist_append(datas->entitylists[map[col][i] >> 6], entity);
        }
    }
}

#endif /* MAIN_H_ */
