/*
** EPITECH PROJECT, 2019
** entitylib
** File description:
** display_thread.c
*/
#include <entitylib.h>

static inline void blit_entitylist(sfRenderWindow *window, entitylist_t *self,
    const float dec)
{
    short i = -1;
    sfVector2f pos;
    entity_t *entity;

    while (++i < self->len) {
        if (self->list[i] != NULL) {
            entity = self->list[i];
            pos = entity->pos.v1;
            pos.x += dec;
            sfSprite_setPosition(entity->sprite[entity->frame], pos);
            sfRenderWindow_drawSprite(window, entity->sprite[entity->frame],
                NULL);
        }
    }
}

static void blit_player(sfRenderWindow *window, entity_t *player,
    const float dec)
{
    sfVector2f pos = player->pos.v1;
    pos.x += dec;
    sfSprite_setPosition(player->sprite[player->frame], pos);
    sfRenderWindow_drawSprite(window, player->sprite[player->frame], NULL);
}

static void blit_all_with_dec(sfRenderWindow *window, collider_t *datas,
    float dec)
{
    short i = -1;
    while (++i < datas->nb_mob)
        blit_entitylist(window, datas->mob[i], dec);
    blit_player(window, datas->player, dec);
    i = -1;
    while (++i < datas->nb_fired)
        blit_entitylist(window, datas->fired[i], dec);
    i = -1;
    while (++i < datas->nb_solid_static)
        blit_entitylist(window, datas->solid_static[i], dec);
    i = -1;
    while (++i < datas->nb_solid_dynamic)
        blit_entitylist(window, datas->solid_dynamic[i], dec);
    i = -1;
    while (++i < datas->nb_hollow_static)
        blit_entitylist(window, datas->hollow_static[i], dec);
    i = -1;
    while (++i < datas->nb_hollow_dynamic)
        blit_entitylist(window, datas->hollow_dynamic[i], dec);
    sfRenderWindow_display(window);
}

void my_displayer(void *ptr)
{
    internal_data_t *internal_datas = get_internal_data();
    data_storage_t *datas = ptr;
    sfRenderWindow *window = datas->window;
    collider_t *coll = get_collider_data();
    sfClock *clock = datas->clock;
    const long long frame_delay = 1000000 / datas->fps;
    const float my_scroll = coll->my_scroll.x / 1000000;
    const long long time_ref = sfClock_getElapsedTime(clock).microseconds;
    long long target = 0;
    long long actual = time_ref;

    while (datas->alive) {
        target = sfClock_getElapsedTime(clock).microseconds + frame_delay;
        blit_all_with_dec(window, coll, my_scroll * (actual - time_ref));
        display_health_and_score(window, datas, internal_datas);
        update_window(window, internal_datas, datas);
        actual = sfClock_getElapsedTime(clock).microseconds;
        if (target > actual)
            sfSleep((sfTime) {target - actual});
    }
}
