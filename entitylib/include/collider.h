/*
** EPITECH PROJECT, 2019
** entitylib
** File description:
** collider.h
*/

#ifndef COLLIDER_H_
#define COLLIDER_H_

typedef struct collider_data {
    entitylist_t *solid_static;
    int nb_solid_static;
    entitylist_t *solid_dynamic;
    int nb_solid_dynamic;
    entitylist_t *hollow_static;
    int nb_hollow_static;
    entitylist_t *hollow_dynamic;
    int nb_hollow_dynamic;
    entitylist_t *fired;
    int nb_fired;
    entitylist_t *mob;
    int nb_mob;
    entity_t *player;
} collider_t;

static inline collider_t *get_collider_data(void)
{
    static collider_t data[1];
    return (data);
}

void collwith_solid_static(entity_t *entity, collider_t *data);
void collwith_solid_dynamic(entity_t *entity, collider_t *data);
void collwith_hollow_static(entity_t *entity, collider_t *data);
void collwith_hollow_dynamic(entity_t *entity, collider_t *data);
void collwith_fired(entity_t *entity, collider_t *data);
void collwith_mob(entity_t *entity, collider_t *data);
void collwith_player(entity_t *entity, collider_t *player);

static inline void collide_solid_static(collider_t *data)
{
    int i = -1;
    int j = -1;

    while (++i < data->nb_solid_static) {
        j = -1;
        while (++j < data->solid_static[i].len) {
            collwith_fired(data->solid_static[i].list[j], data);
            collwith_player(data->solid_static[i].list[j], data);
        }
    }
}

static inline void collide_solid_dynamic(collider_t *data)
{
    int i = -1;
    int j = -1;

    while (++i < data->nb_solid_dynamic) {
        j = -1;
        while (++j < data->solid_dynamic[i].len) {
            collwith_solid_static(data->solid_dynamic[i].list[j], data);
            collwith_fired(data->solid_dynamic[i].list[j], data);
            collwith_player(data->solid_dynamic[i].list[j], data);
        }
    }
}

static inline void collide_fired(collider_t *data)
{
    int i = -1;
    int j = -1;

    while (++i < data->nb_fired) {
        j = -1;
        while (++j < data->fired[i].len) {
            collwith_fired(data->fired[i].list[j], data);
            collwith_player(data->fired[i].list[j], data);
        }
    }
}

static inline void collide_mob(collider_t *data)
{
    int i = -1;
    int j = -1;

    while (++i < data->nb_mob) {
        j = -1;
        while (++j < data->mob[i].len) {
            collwith_solid_static(data->mob[i].list[j], data);
            collwith_solid_dynamic(data->mob[i].list[j], data);
            collwith_fired(data->mob[i].list[j], data);
            collwith_mob(data->mob[i].list[j], data);
            collwith_player(data->mob[i].list[j], data);
        }
    }
}

#include "player_collider.h"

#endif /* COLLIDER_H_ */
