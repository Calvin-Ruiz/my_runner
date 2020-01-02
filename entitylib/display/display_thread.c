/*
** EPITECH PROJECT, 2019
** entitylib
** File description:
** display_thread.c
*/
#include <entitylib.h>

static void blit_entitylist(data_storage_t *data, entitylist_t *self,
    const float dec, long long delta_time)
{
    short i = -1;
    sfVector2f pos;
    entity_t *entity;
    sfRenderWindow *window = data->window;
    const float time_dec = 0.00002f * (data->last_refresh - data->last_update)
        - -1.f;

    while (++i < self->len) {
        entity = self->list[i];
        if (entity != NULL) {
            pos = entity->pos.v1;
            pos.x += dec + entity->vel.x * time_dec;
            pos.y += ((entity->vel.y == entity->gravity) ?
                -entity->gravity : entity->vel.y * time_dec);
            entity->timer += delta_time;
            entity->frame = (entity->timer / entity->frame_delay) & 3;
            sfSprite_setPosition(entity->sprite[entity->frame], pos);
            sfRenderWindow_drawSprite(window, entity->sprite[entity->frame], 0);
        }
    }
}

static void move_backgrounds(data_storage_t *datas, float dec)
{
    datas->background1_pos.x += (dec - datas->old_dec) / 8;
    datas->background2_pos.x += (dec - datas->old_dec) / 4;
    datas->background3_pos.x += (dec - datas->old_dec) / 2;
    if (datas->background1_pos.x < -1280.f)
        datas->background1_pos.x += 1280.f;
    if (datas->background2_pos.x < -1280.f)
        datas->background2_pos.x += 1280.f;
    if (datas->background3_pos.x < -1280.f)
        datas->background3_pos.x += 1280.f;
    datas->old_dec = dec;
}

static void blit_player(data_storage_t *data, entity_t *player,
    const float dec, long long delta_time)
{
    const float time_dec = 0.00002f * (data->last_refresh - data->last_update)
        - 1.f;
    sfVector2f pos = player->pos.v1;

    pos.x += dec + player->vel.x * time_dec;
    pos.y += ((player->vel.y == player->gravity) ?
        -player->gravity : player->vel.y * time_dec);
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
    while (++i < datas->nb_solid_dynamic)
        blit_entitylist(data, datas->solid_dynamic[i], dec, delta_time);
    i = -1;
    while (++i < datas->nb_solid_static)
        blit_entitylist(data, datas->solid_static[i], dec, delta_time);
    i = -1;
    while (++i < datas->nb_hollow_dynamic)
        blit_entitylist(data, datas->hollow_dynamic[i], dec, delta_time);
    i = -1;
    while (++i < datas->nb_hollow_static)
        blit_entitylist(data, datas->hollow_static[i], dec, delta_time);
    move_backgrounds(data, dec);
}

void my_displayer(data_storage_t *datas)
{
    internal_data_t *internal_datas = get_internal_data();
    collider_t *coll = get_collider_data();
    const long long delay = 1000000 / datas->fps;
    const float scroll = 512.f / 1000000.f;
    sfRenderWindow *window = datas->window;
    long long target = sfClock_getElapsedTime(datas->clock).microseconds;

    datas->tref = target;
    while (datas->alive) {
        blit_all_with_dec(datas, coll, scroll * (datas->tref - target), delay);
        target += delay;
        display_health_and_score(window, datas, internal_datas);
        sfMutex_lock(datas->my_lock);
        update_window(window, internal_datas, datas);
        sfMutex_unlock(datas->my_lock);
        datas->score = (target - datas->tref) >> 10;
        datas->last_refresh = sfClock_getElapsedTime(datas->clock).microseconds;
        if (target > datas->last_refresh)
            sfSleep((sfTime) {target - datas->last_refresh});
    }
}
