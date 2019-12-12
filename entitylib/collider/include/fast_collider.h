/*
** EPITECH PROJECT, 2019
** entitylib
** File description:
** fast_collider.h
*/

#ifndef FAST_COLLIDER_H_
#define FAST_COLLIDER_H_

static inline void fast_collide(entity_t *entity, entity_t *solid)
{
    if (solid == NULL
        || entity->pos.v2.x < solid->pos.v1.x
        || entity->pos.v1.x > solid->pos.v2.x
        || entity->pos.v2.y < solid->pos.v1.y
        || entity->pos.v1.y > solid->pos.v2.y)
        return;
    if (entity->vel.x < 0)
        entity->pos.v1.x = solid->pos.v2.x;
    else
        entity->pos.v1.x = solid->pos.v1.x - *(entity->size);
    if (entity->vel.y < 0) {
        entity->pos.v1.y = solid->pos.v2.y;
    } else {
        entity->pos.v1.y = solid->pos.v1.y - entity->size[1];
    }
}

static inline void fast_collide_with_custom(entity_t *entity, entity_t *solid)
{
    if (solid == NULL
        || entity->pos.v2.x < solid->pos.v1.x
        || entity->pos.v1.x > solid->pos.v2.x
        || entity->pos.v2.y < solid->pos.v1.y
        || entity->pos.v1.y > solid->pos.v2.y)
        return;
    solid->custom(solid, entity);
    if (entity->vel.x < 0)
        entity->pos.v1.x = solid->pos.v2.x;
    else
        entity->pos.v1.x = solid->pos.v1.x - *(entity->size);
    if (entity->vel.y < 0)
        entity->pos.v1.y = solid->pos.v2.y;
    else
        entity->pos.v1.y = solid->pos.v1.y - entity->size[1];
}

#endif /* FAST_COLLIDER_H_ */
