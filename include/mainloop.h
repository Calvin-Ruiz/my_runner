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

static inline void shoot_once(data_storage_t *datas)
{
    if (sfClock_getElapsedTime(datas->clock).microseconds > datas->next_shoot) {
        entitylist_append(datas->entitylists[4], new_instance(
            datas->entities[34], (pos_t) {(sfVector2f)
            {datas->player->entity->pos.v2.x + 0.001f,
            datas->player->entity->pos.v1.y + 28.f},
            (sfVector2f) {0.f, 0.f}}, (sfVector2f) {60.f, 0.f}, 0));
        datas->next_shoot = (sfClock_getElapsedTime(datas->clock).microseconds
            + 200000);
    }
}

static inline void event_press(sfRenderWindow *window, data_storage_t *datas,
    sfEvent event)
{
    entity_t *entity = datas->player->entity;
    if (event.key.code == sfKeyC)
        shoot_once(datas);
    if (event.key.code == sfKeyEscape)
        my_pause_game(window, datas);
    if (event.key.code == sfKeyF12)
        my_take_screenshoot(window, datas);
    if (event.key.code == sfKeyLeft)
        datas->player->entity->vel.x = 12.8f;
    if (event.key.code == sfKeyRight)
        datas->player->entity->vel.x = 38.4f;
    if (event.key.code == sfKeySpace || datas->spacebar) {
        datas->spacebar = 1;
        if (entity->vel.y == entity->gravity) {
            entity->pos.v1.y -= entity->gravity * 1.01f;
            entity->pos.v2.y -= entity->gravity * 1.01f;
            entity->vel.y = -9.01f * entity->gravity;
            sfSound_play(datas->sounds[0]);
        }
    }
}

static inline void event_release(entity_t *entity, sfEvent event,
    data_storage_t *datas)
{
    if (event.key.code == sfKeyLeft && entity->vel.x == 12.8f)
        entity->vel.x = 25.6f;
    if (event.key.code == sfKeyRight && entity->vel.x == 38.4f)
        entity->vel.x = 25.6f;
    if (event.key.code == sfKeySpace)
        datas->spacebar = 0;
}

#endif /* MAINLOOP_H_ */
