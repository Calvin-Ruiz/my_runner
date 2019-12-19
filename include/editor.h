/*
** EPITECH PROJECT, 2019
** MUL_my_runner
** File description:
** editor.h
*/

#ifndef EDITOR_H_
#define EDITOR_H_

#include "menu_bar.h"
#include <data_storage.h>
#include <internal_data.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

static inline void display_bloc(sfRenderWindow *window, char bloc_id,
    sfVector2f pos, data_storage_t *datas)
{
    sfSprite *sprite;

    if (bloc_id) {
        sprite = *(datas->entities[bloc_id & 63]->sprite);
        sfSprite_setPosition(sprite, pos);
        sfRenderWindow_drawSprite(window, sprite, NULL);
    }
}

static inline void event_press(sfEvent event, int *col)
{
    if (event.key.code == sfKeyLeft) {
        *col -= (event.key.shift) ? 10 : 1;
        if (*col < 0)
            *col = 0;
    }
    if (event.key.code == sfKeyRight) {
        *col += (event.key.shift) ? 10 : 1;
    }
}

static inline int add_lines(data_storage_t *datas, int nb_cols_needed)
{
    char **map = datas->map;
    char **new = malloc(sizeof(char *) * (nb_cols_needed));
    char *str2 = malloc((nb_cols_needed - datas->nb_cols) * map[0][-1]);
    int i = -1;

    if (str2 == NULL || new == NULL)
        return (84);
    memset(str2, 0, (nb_cols_needed - datas->nb_cols) * map[0][-1]);
    while (++i < datas->nb_cols)
        new[i] = map[i];
    while (i < nb_cols_needed) {
        new[i++] = str2;
        str2 += map[0][-1];
    }
    datas->map = new;
    datas->nb_cols = nb_cols_needed;
    free(map);
    return (0);
}

static inline void mouse_press(sfEvent event, menu_bar_t *menubar,
    data_storage_t *datas, int col)
{
    int line = (int) (event.mouseButton.y * datas->coef_y) >> 6;

    col += (int) (event.mouseButton.x * datas->coef_x) >> 6;
    if (col >= datas->nb_cols) {
        if (add_lines(datas, col + 1)) {
            write(2, "Memory Error : Faild to allocate memory\n", 40);
            return;
        }
    }
    if (event.mouseButton.button == 0) {
        datas->map[col][line] = menubar->bloc_id[menubar->select_bloc];
    } else if (event.mouseButton.button == 1)
        datas->map[col][line] = 0;
}

static inline void mouse_wheel(sfEvent event, menu_bar_t *menubar)
{
    if (event.mouseWheelScroll.delta > 0.f) {
        if (menubar->select_bloc > 0)
            menubar->select_bloc--;
    } else {
        if (menubar->select_bloc < 63)
            menubar->select_bloc++;
    }
}

#endif /* EDITOR_H_ */
