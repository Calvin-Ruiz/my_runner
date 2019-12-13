/*
** EPITECH PROJECT, 2019
** MUL_my_runner
** File description:
** mainloop.c
*/
#include "include/mainloop.h"

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
            sfRenderWindow_close(window);
            break;
        }
        if (event.type == sfEvtKeyPressed)
            event_press(window, datas, event);
        else if (event.type == sfEvtKeyReleased)
            event_release(datas->player->entity, event);
    }
    sfMutex_unlock(datas->my_lock);
    sfSleep(test);
}

void mainloop(data_storage_t *datas, char **map, const int nb_cols)
{
    sfRenderWindow *window = datas->window;
    int col = -1;

    while (++col < 30)
        load_line(map, col, nb_cols, datas);
    while (sfRenderWindow_isOpen(datas->window)) {
        my_events(window, datas);
    }
}
