/*
** EPITECH PROJECT, 2019
** entitylib
** File description:
** collider_2.h
*/

#ifndef COLLIDER_2_H_
#define COLLIDER_2_H_

static inline void collide_player(collider_t *data)
{
    data->player->update(data->player);
    collwith_hollow_static(data->player, data);
    collwith_hollow_dynamic(data->player, data);
    collwith_fired(data->player, data);
}

static inline void update_hollow(collider_t *data)
{
    int i = -1;
    int j = -1;

    while (++i < data->nb_hollow_static) {
        j = -1;
        while (++j < data->hollow_static[i]->len)
            check_update(data->hollow_static[i]->list + j);
    }
    i = -1;
    while (++i < data->nb_hollow_dynamic) {
        j = -1;
        while (++j < data->hollow_dynamic[i]->len)
            check_update(data->hollow_dynamic[i]->list + j);
    }
}

static inline void collide_all(collider_t *data)
{
    collide_solid_static(data);
    collide_solid_dynamic(data);
    collide_fired(data);
    collide_mob(data);
    collide_player(data);
    update_hollow(data);
}

static inline void my_sync_with_display(data_storage_t *datas)
{
    datas->tref = datas->last_update - ((
        (long long) datas->entitylists[4]->list[0]->pos.v1.x + 80)
        * 1000000) / 512;
}

static inline void my_fix_fps(data_storage_t *datas)
{
    entity_t *entity;

    if (datas->coll_target > datas->last_update)
        sfSleep((sfTime) {datas->coll_target - datas->last_update});
    else
        my_sync_with_display(datas);
    if ((datas->last_update & 63) == 0) {
        entity = new_instance(datas->entities[33], datas->player->entity->pos,
            (sfVector2f) {-1.5, 0}, 0);
        if (entity != NULL) {
            entity->pos.v1.x = datas->col * 64.f;
            entity->gravity = datas->player->entity->gravity;
            entity->pos.v1.y -= entity->gravity * 4;
            entitylist_append(datas->entitylists[5], entity);
        }
    }
}

#endif /* COLLIDER_2_H_ */
