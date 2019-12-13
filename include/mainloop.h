/*
** EPITECH PROJECT, 2019
** MUL_my_runner
** File description:
** mainloop.h
*/

#ifndef MAINLOOP_H_
#define MAINLOOP_H_

#include <entitylib.h>

static inline void load_line(char **map, int col, const int nb_cols,
    data_storage_t *datas)
{
    const char col_len = (*map)[-1];
    unsigned char i = -1;

    if (col >= nb_cols)
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

static inline void event_press(sfRenderWindow *window, data_storage_t *datas,
    sfEvent event)
{
    if (event.key.code == sfKeyEscape)
        my_pause_game(window, datas);
    if (event.key.code == sfKeyF12)
        my_take_screenshoot(window, datas);
    if (event.key.code == sfKeyLeft)
        datas->player->entity->vel.x = 12.8f;
    if (event.key.code == sfKeyRight)
        datas->player->entity->vel.x = 38.4f;
    if (event.key.code == sfKeySpace && (datas->player->entity->vel.y == 0.f
        || datas->player->entity->vel.y == 4.f))
        datas->player->entity->vel.y = -38.4f;
}

static inline void event_release(entity_t *entity, sfEvent event)
{
    if (event.key.code == sfKeyLeft && entity->vel.x == 12.8f)
        entity->vel.x = 25.6f;
    if (event.key.code == sfKeyRight && entity->vel.x == 38.4f)
        entity->vel.x = 25.6f;
}

#endif /* MAINLOOP_H_ */
