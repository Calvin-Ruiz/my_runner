/*
** EPITECH PROJECT, 2019
** MUL_my_runner
** File description:
** mainloop.c
*/
#include "include/mainloop.h"

void load_line(data_storage_t *datas)
{
    const int nb_cols = datas->nb_cols;
    char **map = datas->map;
    static int col = -1;
    const char col_len = (*map)[-1];
    unsigned char i = -1;

    if (++col >= nb_cols)
        return;
    while (++i < col_len) {
        if (map[col][i]) {
            pos_t pos = {(sfVector2f) {col * 64, i * 64},
                (sfVector2f) {(col + 1) * 64, (i + 1) * 64}};
            entity_t *entity = new_instance(datas->entities[map[col][i] & 63],
                pos, (sfVector2f) {-0.1f, 0.f}, 0);
            entitylist_append(datas->entitylists[map[col][i] >> 6], entity);
        }
    }
}

static void my_events(sfRenderWindow *window, data_storage_t *datas)
{
    sfEvent event;
    sfTime test = {50000};
    sfMutex_lock(datas->my_lock);
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfMutex_unlock(datas->my_lock);
            datas->alive = 0;
            destroy_collider();
            sfThread_destroy(datas->displayer);
            sfRenderWindow_display(window);
            sfRenderWindow_close(window);
            return;
        }
        if (event.type == sfEvtKeyPressed)
            event_press(window, datas, event);
        else if (event.type == sfEvtKeyReleased)
            event_release(datas->player->entity, event);
    }
    sfMutex_unlock(datas->my_lock);
    sfSleep(test);
}

void mainloop(data_storage_t *datas)
{
    sfRenderWindow *window = datas->window;
    int col = 0;

    while (col++ < 21)
        load_line(datas);
    while (sfRenderWindow_isOpen(datas->window)) {
        my_events(window, datas);
    }
}
