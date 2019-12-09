/*
** EPITECH PROJECT, 2019
** entitylib
** File description:
** player_collider.h
*/

#ifndef PLAYER_COLLIDER_H_
#define PLAYER_COLLIDER_H_

static inline void collide_mob(collider_t *data)
{
    int i = -1;
    int j = -1;
    entity_t *entity;

    while (++i < data->nb_mob) {
        j = -1;
        while (++j < data->mob[i]->len) {
            entity = data->mob[i]->list[j];
            check_update(entity);
            collwith_solid_static(entity, data);
            collwith_solid_dynamic(entity, data);
            collwith_fired(entity, data);
            collwith_mob(entity, data);
            collwith_player(entity, data);
        }
    }
}

static inline void collide_player(collider_t *data)
{
    data->player->update(data->player);
    collwith_hollow_static(data->player, data);
    collwith_hollow_dynamic(data->player, data);
}

#endif /* PLAYER_COLLIDER_H_ */
