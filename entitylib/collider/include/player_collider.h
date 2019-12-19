/*
** EPITECH PROJECT, 2019
** entitylib
** File description:
** player_collider.h
*/

#ifndef PLAYER_COLLIDER_H_
#define PLAYER_COLLIDER_H_

static inline void collide_player(collider_t *data)
{
    data->player->update(data->player);
    collwith_hollow_static(data->player, data);
    collwith_hollow_dynamic(data->player, data);
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

#endif /* PLAYER_COLLIDER_H_ */
