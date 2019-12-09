/*
** EPITECH PROJECT, 2019
** entitylib
** File description:
** collider.h
*/

#ifndef COLLIDER_H_
#define COLLIDER_H_

#include "base_collider.h"

void collwith_solid_static(entity_t *entity, collider_t *data);
void collwith_solid_dynamic(entity_t *entity, collider_t *data);
void collwith_hollow_static(entity_t *entity, collider_t *data);
void collwith_hollow_dynamic(entity_t *entity, collider_t *data);
void collwith_fired(entity_t *entity, collider_t *data);
void collwith_mob(entity_t *entity, collider_t *data);
void collwith_player(entity_t *entity, collider_t *player);

static inline void check_update(entity_t *entity)
{
    if (entity != NULL)
        entity->update(entity);
}

static  void collide_solid_static(collider_t *data)
{
    int i = -1;
    int j = -1;
    entity_t *entity;

    while (++i < data->nb_solid_static) {
        j = -1;
        while (++j < data->solid_static[i]->len) {
            entity = data->solid_static[i]->list[j];
            check_update(entity);
            collwith_fired(entity, data);
            collwith_player(entity, data);
        }
    }
}

static  void collide_solid_dynamic(collider_t *data)
{
    int i = -1;
    int j = -1;
    entity_t *entity;

    while (++i < data->nb_solid_dynamic) {
        j = -1;
        while (++j < data->solid_dynamic[i]->len) {
            entity = data->solid_dynamic[i]->list[j];
            check_update(entity);
            collwith_solid_static(entity, data);
            collwith_fired(entity, data);
            collwith_player(entity, data);
        }
    }
}

static  void collide_fired(collider_t *data)
{
    int i = -1;
    int j = -1;
    entity_t *entity;

    while (++i < data->nb_fired) {
        j = -1;
        while (++j < data->fired[i]->len) {
            entity = data->fired[i]->list[j];
            check_update(entity);
            collwith_fired(entity, data);
            collwith_player(entity, data);
        }
    }
}

#include "player_collider.h"

#endif /* COLLIDER_H_ */
