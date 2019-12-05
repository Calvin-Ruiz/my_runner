/*
** EPITECH PROJECT, 2019
** entitylib
** File description:
** collwith_2.c
*/
#include "include/internal_collider.h"

void collwith_mob(entity_t *entity, collider_t *data)
{
    if (entity == NULL)
        return;
    int i = -1;
    int j = -1;

    while (++i < data->nb_mob) {
        j = -1;
        while (++j < data->solid_static[i].len)
            collide_with_custom(entity, data->solid_static[i].list[j]);
    }
}

void collwith_player(entity_t *entity, collider_t *data)
{
    if (entity == NULL)
        return;
    collide_with_custom(data->player, entity);
}
