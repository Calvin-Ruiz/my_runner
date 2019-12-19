/*
** EPITECH PROJECT, 2019
** MUL_my_runner
** File description:
** mainloop.c
*/
#include "include/mainloop.h"

int *load_line(data_storage_t *datas)
{
    unsigned char **map = (unsigned char **) datas->map;
    static int col = -1;
    const unsigned char col_len = (*map)[-1];
    unsigned char i = -1;

    if (++col >= datas->nb_cols)
        return (&col);
    while (++i < col_len) {
        if (map[col][i]) {
            pos_t pos = {(sfVector2f) {col * 64, i * 64},
                (sfVector2f) {(col + 1) * 64, (i + 1) * 64}};
            entity_t *entity = new_instance(datas->entities[map[col][i] & 63],
                pos, (sfVector2f) {-0.1f, 0.f}, 0);
            entitylist_append(datas->entitylists[map[col][i] >> 6], entity);
        }
    }
    return (&col);
}

static void my_events(sfRenderWindow *window, data_storage_t *datas)
{
    sfEvent event;

    sfMutex_lock(datas->my_lock);
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfMutex_unlock(datas->my_lock);
            datas->alive = 0;
            destroy_collider();
            destroy_displayer(datas);
            *load_line(datas) = -1;
            sfRenderWindow_close(datas->window);
            return;
        }
        if (event.type == sfEvtKeyPressed)
            event_press(window, datas, event);
        else if (event.type == sfEvtKeyReleased)
            event_release(datas->player->entity, event);
    }
    sfMutex_unlock(datas->my_lock);
}

void mainloop(data_storage_t *datas)
{
    sfRenderWindow *window = datas->window;
    int col = 0;
    int *col_ptr = load_line(datas);
    sfTime test = {50000};

    while (col++ < 20)
        load_line(datas);
    while (sfRenderWindow_isOpen(window)
        && datas->player->entity->health > 0) {
        my_events(window, datas);
        sfSleep(test);
    }
    if (sfRenderWindow_isOpen(window)) {
        datas->alive = 0;
        destroy_collider();
        destroy_displayer(datas);
        *col_ptr = -1;
    }
}
