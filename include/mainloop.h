/*
** EPITECH PROJECT, 2019
** MUL_my_runner
** File description:
** mainloop.h
*/

#ifndef MAINLOOP_H_
#define MAINLOOP_H_

#include <entitylib.h>
#include <display_thread.h>

static inline void event_press(sfRenderWindow *window, data_storage_t *datas,
    sfEvent event)
{
    entity_t *entity = datas->player->entity;

    if (event.key.code == sfKeyEscape)
        my_pause_game(window, datas);
    if (event.key.code == sfKeyF12)
        my_take_screenshoot(window, datas);
    if (event.key.code == sfKeyLeft)
        datas->player->entity->vel.x = 12.8f;
    if (event.key.code == sfKeyRight)
        datas->player->entity->vel.x = 38.4f;
    if (event.key.code == sfKeySpace
        && (entity->vel.y == entity->gravity)) {
        entity->pos.v1.y -= entity->gravity * 1.01f;
        entity->pos.v2.y -= entity->gravity * 1.01f;
        entity->vel.y = -9.f * entity->gravity;
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
