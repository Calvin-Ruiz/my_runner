/*
** EPITECH PROJECT, 2019
** entitylib
** File description:
** display_thread.c
*/
#include <entitylib.h>

static inline void blit_entitylist(sfRenderWindow *window, entitylist_t *self,
    const float dec, long long delta_time)
{
    short i = -1;
    sfVector2f pos;
    entity_t *entity;

    while (++i < self->len) {
        entity = self->list[i];
        if (entity != NULL) {
            pos = entity->pos.v1;
            pos.x += dec;
            entity->timer += delta_time;
            entity->frame = (entity->timer / entity->frame_delay) & 3;
            sfSprite_setPosition(entity->sprite[entity->frame], pos);
            sfRenderWindow_drawSprite(window, entity->sprite[entity->frame],
                NULL);
        }
    }
}

static void blit_player(sfRenderWindow *window, entity_t *player,
    const float dec, long long delta_time)
{
    sfVector2f pos = player->pos.v1;
    pos.x += dec;
    player->timer += delta_time;
    player->frame = (player->timer / player->frame_delay) & 3;
    sfSprite_setPosition(player->sprite[player->frame], pos);
    sfRenderWindow_drawSprite(window, player->sprite[player->frame], NULL);
}

static void blit_all_with_dec(sfRenderWindow *window, collider_t *datas,
    const float dec, long long delta_time)
{
    short i = -1;
    while (++i < datas->nb_mob)
        blit_entitylist(window, datas->mob[i], dec, delta_time);
    blit_player(window, datas->player, dec, delta_time);
    i = -1;
    while (++i < datas->nb_fired)
        blit_entitylist(window, datas->fired[i], dec, delta_time);
    i = -1;
    while (++i < datas->nb_solid_static)
        blit_entitylist(window, datas->solid_static[i], dec, delta_time);
    i = -1;
    while (++i < datas->nb_solid_dynamic)
        blit_entitylist(window, datas->solid_dynamic[i], dec, delta_time);
    i = -1;
    while (++i < datas->nb_hollow_static)
        blit_entitylist(window, datas->hollow_static[i], dec, delta_time);
    i = -1;
    while (++i < datas->nb_hollow_dynamic)
        blit_entitylist(window, datas->hollow_dynamic[i], dec, delta_time);
}

void my_displayer(data_storage_t *datas)
{
    internal_data_t *internal_datas = get_internal_data();
    sfRenderWindow *window = datas->window;
    collider_t *coll = get_collider_data();
    sfClock *clock = datas->clock;
    const long long delay = 1000000 / datas->fps;
    const float scroll = coll->my_scroll.x / 1000000;
    datas->tref = sfClock_getElapsedTime(clock).microseconds;
    long long target = datas->tref;
    long long actual = datas->tref;
    while (datas->alive) {
        blit_all_with_dec(window, coll, scroll * (target - datas->tref), delay);
        target =+ delay;
        display_health_and_score(window, datas, internal_datas);
        sfMutex_lock(datas->my_lock);
        update_window(window, internal_datas, datas);
        sfMutex_unlock(datas->my_lock);
        actual = sfClock_getElapsedTime(clock).microseconds;
        if (target > actual)
            sfSleep((sfTime) {target - actual});
    }
}
