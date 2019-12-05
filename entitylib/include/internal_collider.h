/*
** EPITECH PROJECT, 2019
** entitylib
** File description:
** internal_collider.h
*/

#ifndef INTERNAL_COLLIDER_H_
#define INTERNAL_COLLIDER_H_

#include "entitybase.h"
#include "collider.h"
#include "fast_collider.h"

static inline void collide_custom_only(entity_t *entity, entity_t *fired)
{
    if (fired == NULL
        || entity->pos.v1.x > fired->pos.v2.x
        || entity->pos.v2.x < fired->pos.v1.x
        || entity->pos.v1.y > fired->pos.v2.y
        || entity->pos.v2.y < fired->pos.v1.y)
        return;
    fired->custom(fired, entity);
}


static inline void static_collide(entity_t *entity, entity_t *solid)
{
    if (solid == NULL
        || entity->pos.v1.x > solid->pos.v2.x
        || entity->pos.v2.x < solid->pos.v1.x
        || entity->pos.v1.y > solid->pos.v2.y
        || entity->pos.v2.y < solid->pos.v1.y)
        return;
    if (entity->pos.v1.x - entity->vel.x >= solid->pos.v2.x)
        entity->pos.v1.x = solid->pos.v2.x;
    else if (entity->pos.v2.x - entity->vel.x <= solid->pos.v1.x)
        entity->pos.v1.x = solid->pos.v1.x - *(entity->size);
    if (entity->pos.v1.y - entity->vel.y >= solid->pos.v2.y)
        entity->pos.v1.y = solid->pos.v2.y;
    else if (entity->pos.v2.y - entity->vel.y <= solid->pos.v1.y)
        entity->pos.v1.y = solid->pos.v1.y - entity->size[1];
}

static inline void collide(entity_t *entity, entity_t *solid)
{
    if (solid == NULL
        || entity->pos.v1.x > solid->pos.v2.x
        || entity->pos.v2.x < solid->pos.v1.x
        || entity->pos.v1.y > solid->pos.v2.y
        || entity->pos.v2.y < solid->pos.v1.y)
        return;
    if (entity->pos.v1.x - entity->vel.x >= solid->pos.v2.x - solid->vel.x)
        entity->pos.v1.x = solid->pos.v2.x;
    else if (entity->pos.v2.x - entity->vel.x <= solid->pos.v1.x - solid->vel.x)
        entity->pos.v1.x = solid->pos.v1.x - *(entity->size);
    if (entity->pos.v1.y - entity->vel.y >= solid->pos.v2.y - solid->vel.y)
        entity->pos.v1.y = solid->pos.v2.y;
    else if (entity->pos.v2.y - entity->vel.y <= solid->pos.v1.y - solid->vel.y)
        entity->pos.v1.y = solid->pos.v1.y - entity->size[1];
}

static inline void collide_with_custom(entity_t *entity, entity_t *solid)
{
    if (solid == NULL
        || entity->pos.v1.x > solid->pos.v2.x
        || entity->pos.v2.x < solid->pos.v1.x
        || entity->pos.v1.y > solid->pos.v2.y
        || entity->pos.v2.y < solid->pos.v1.y)
        return;
    solid->custom(solid, entity);
    if (entity->pos.v1.x - entity->vel.x >= solid->pos.v2.x)
        entity->pos.v1.x = solid->pos.v2.x;
    else if (entity->pos.v2.x - entity->vel.x <= solid->pos.v1.x)
        entity->pos.v1.x = solid->pos.v1.x - *(entity->size);
    if (entity->pos.v1.y - entity->vel.y >= solid->pos.v2.y)
        entity->pos.v1.y = solid->pos.v2.y;
    else if (entity->pos.v2.y - entity->vel.y <= solid->pos.v1.y)
        entity->pos.v1.y = solid->pos.v1.y - entity->size[1];
}

#endif /* INTERNAL_COLLIDER_H_ */
