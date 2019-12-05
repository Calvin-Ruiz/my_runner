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
    collwith_hollow_static(data->player, data);
    collwith_hollow_dynamic(data->player, data);
}

#endif /* PLAYER_COLLIDER_H_ */
