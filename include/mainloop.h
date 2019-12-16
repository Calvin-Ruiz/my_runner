/*
** EPITECH PROJECT, 2019
** MUL_my_runner
** File description:
** mainloop.h
*/

#ifndef MAINLOOP_H_
#define MAINLOOP_H_

#include <entitylib.h>

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
    if (event.key.code == sfKeySpace && (datas->player->entity->vel.y == 4.f)) {
        datas->player->entity->pos.v1.y -= 4.01f;
        datas->player->entity->pos.v2.y -= 4.01f;
        datas->player->entity->vel.y = -38.4f;
    }
}

static inline void event_release(entity_t *entity, sfEvent event)
{
    if (event.key.code == sfKeyLeft && entity->vel.x == 12.8f)
        entity->vel.x = 25.6f;
    if (event.key.code == sfKeyRight && entity->vel.x == 38.4f)
        entity->vel.x = 25.6f;
}

#endif /* MAINLOOP_H_ */
