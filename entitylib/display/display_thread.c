/*
** EPITECH PROJECT, 2019
** entitylib
** File description:
** display_thread.c
*/
#include <entitylib.h>

static inline void blit_entitylist(data_storage_t *data, entitylist_t *self,
    const float dec, long long delta_time)
{
    short i = -1;
    sfVector2f pos;
    entity_t *entity;
    sfRenderWindow *window = data->window;
    const float time_dec = 0.00002f * (data->last_refresh - data->last_update)
        - 1.f;

    while (++i < self->len) {
        entity = self->list[i];
        if (entity != NULL) {
            pos = entity->pos.v1;
            pos.x += dec + entity->vel.x * time_dec;
            pos.y += ((entity->vel.y == entity->gravity) ?
                0 : entity->vel.y * time_dec);
            entity->timer += delta_time;
            entity->frame = (entity->timer / entity->frame_delay) & 3;
            sfSprite_setPosition(entity->sprite[entity->frame], pos);
            sfRenderWindow_drawSprite(window, entity->sprite[entity->frame], 0);
        }
    }
}

static void blit_player(data_storage_t *data, entity_t *player,
    const float dec, long long delta_time)
{
    const float time_dec = 0.00002f * (data->last_refresh - data->last_update)
        - 1.f;
    sfVector2f pos = player->pos.v1;

    pos.x += dec + player->vel.x * time_dec;
    if (player->vel.y != player->gravity)
        pos.y += player->vel.y * time_dec;
    player->timer += delta_time;
    player->frame = (player->timer / player->frame_delay) & 3;
    sfSprite_setPosition(player->sprite[player->frame], pos);
    sfRenderWindow_drawSprite(data->window, player->sprite[player->frame],
        NULL);
}

static void blit_all_with_dec(data_storage_t *data, collider_t *datas,
    const float dec, long long delta_time)
{
    short i = -1;

    while (++i < datas->nb_mob)
        blit_entitylist(data, datas->mob[i], dec, delta_time);
    blit_player(data, datas->player, dec, delta_time);
    i = -1;
    while (++i < datas->nb_fired)
        blit_entitylist(data, datas->fired[i], dec, delta_time);
    i = -1;
    while (++i < datas->nb_solid_static)
        blit_entitylist(data, datas->solid_static[i], dec, delta_time);
    i = -1;
    while (++i < datas->nb_solid_dynamic)
        blit_entitylist(data, datas->solid_dynamic[i], dec, delta_time);
    i = -1;
    while (++i < datas->nb_hollow_static)
        blit_entitylist(data, datas->hollow_static[i], dec, delta_time);
    i = -1;
    while (++i < datas->nb_hollow_dynamic)
        blit_entitylist(data, datas->hollow_dynamic[i], dec, delta_time);
}

void my_displayer(data_storage_t *datas)
{
    internal_data_t *internal_datas = get_internal_data();
    collider_t *coll = get_collider_data();
    const long long delay = 1000000 / datas->fps;
    const float scroll = coll->my_scroll.x / 1000000;
    sfRenderWindow *window = datas->window;
    long long target = sfClock_getElapsedTime(datas->clock).microseconds;
    long long *actual = &(datas->last_refresh);

    datas->tref = target;
    while (datas->alive) {
        blit_all_with_dec(datas, coll, scroll * (target - datas->tref), delay);
        target += delay;
        display_health_and_score(window, datas, internal_datas);
        sfMutex_lock(datas->my_lock);
        update_window(window, internal_datas, datas);
        sfMutex_unlock(datas->my_lock);
        *actual = sfClock_getElapsedTime(datas->clock).microseconds;
        if (target > *actual)
            sfSleep((sfTime) {target - *actual});
    }
}
