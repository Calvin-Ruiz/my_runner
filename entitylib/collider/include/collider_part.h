/*
** EPITECH PROJECT, 2019
** entitylib
** File description:
** collider_part.h
*/

#ifndef COLLIDER_PART_H_
#define COLLIDER_PART_H_

#include <stdio.h>

static inline void collide_once(entity_t *entity, entity_t *solid)
{
    if (entity->pos.v1.x - entity->vel.x + 0.1f > solid->pos.v2.x) {
        entity->pos.v1.x = solid->pos.v2.x;
        entity->pos.v2.x = solid->pos.v2.x + *(entity->size);
        entity->vel.x = (entity->vel.x < 0.f) ? 0.f : entity->vel.x;
    } else if (entity->pos.v2.x - entity->vel.x < solid->pos.v1.x + 0.1f) {
        entity->pos.v1.x = solid->pos.v1.x - *(entity->size);
        entity->pos.v2.x = solid->pos.v1.x;
        entity->vel.x = (entity->vel.x > 0.f) ? 0.f : entity->vel.x;
    }
}

static inline void collide_dual(entity_t *obj, entity_t *solid)
{
    if (obj->pos.v1.x - obj->vel.x + 0.1f > solid->pos.v2.x - solid->vel.x) {
        obj->pos.v1.x = solid->pos.v2.x;
        obj->pos.v2.x = solid->pos.v2.x + *(obj->size);
        obj->vel.x = (obj->vel.x < 0.f) ? 0.f : obj->vel.x;
    } else if (obj->pos.v2.x - obj->vel.x <
        (solid->pos.v1.x - solid->vel.x + 0.1f)) {
        obj->pos.v1.x = solid->pos.v1.x - *(obj->size);
        obj->pos.v2.x = solid->pos.v1.x;
        obj->vel.x = (obj->vel.x > 0.f) ? 0.f : obj->vel.x;
    }
}

#endif /* COLLIDER_PART_H_ */
