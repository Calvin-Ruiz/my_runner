/*
** EPITECH PROJECT, 2019
** entitylib
** File description:
** internal_collider.h
*/

#ifndef INTERNAL_COLLIDER_H_
#define INTERNAL_COLLIDER_H_

#include "entitybase.h"
#include "data_storage.h"
#include "base_collider.h"
#include "fast_collider.h"
#include "collider_part.h"

static inline void collide_custom_only(entity_t *entity, entity_t *fired)
{
    if (fired == NULL || fired == entity
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
    if (entity->pos.v1.y - entity->vel.y + 0.1f > solid->pos.v2.y) {
        entity->pos.v1.y = solid->pos.v2.y;
        entity->pos.v2.y = solid->pos.v2.y + entity->size[1];
        entity->vel.y = 0.f;
    } else if (entity->pos.v2.y - entity->vel.y < solid->pos.v1.y + 0.1f) {
        entity->pos.v1.y = solid->pos.v1.y - entity->size[1];
        entity->pos.v2.y = solid->pos.v1.y;
        entity->vel.y = 0.f;
    } else
        collide_once(entity, solid);
}

static inline void collide(entity_t *obj, entity_t *blc)
{
    if (blc == NULL
        || obj->pos.v1.x > blc->pos.v2.x || obj->pos.v2.x < blc->pos.v1.x
        || obj->pos.v1.y > blc->pos.v2.y || obj->pos.v2.y < blc->pos.v1.y)
        return;
    if (obj->pos.v1.y - obj->vel.y + 0.1f > blc->pos.v2.y - blc->vel.y) {
        obj->pos.v1.y = blc->pos.v2.y;
        obj->pos.v2.y = blc->pos.v2.y + obj->size[1];
        obj->vel.y = 0.f;
    } else if (obj->pos.v2.y - obj->vel.y < blc->pos.v1.y - blc->vel.y + 0.1f) {
        obj->pos.v1.y = blc->pos.v1.y - obj->size[1];
        obj->pos.v2.y = blc->pos.v1.y;
        obj->vel.y = 0.f;
    } else
        collide_dual(obj, blc);
}

static inline void static_collide_with_custom(entity_t *entity, entity_t *solid)
{
    if (solid == NULL
        || entity->pos.v1.x > solid->pos.v2.x
        || entity->pos.v2.x < solid->pos.v1.x
        || entity->pos.v1.y > solid->pos.v2.y
        || entity->pos.v2.y < solid->pos.v1.y)
        return;
    if (entity->pos.v1.y - entity->vel.y + 0.1f > solid->pos.v2.y) {
        entity->pos.v1.y = solid->pos.v2.y;
        entity->pos.v2.y = solid->pos.v2.y + entity->size[1];
        entity->vel.y = 0.f;
        solid->custom_y(solid, entity);
    } else if (entity->pos.v2.y - entity->vel.y < solid->pos.v1.y + 0.1f) {
        entity->pos.v1.y = solid->pos.v1.y - entity->size[1];
        entity->pos.v2.y = solid->pos.v1.y;
        entity->vel.y = 0.f;
        solid->custom_y(solid, entity);
    } else
        collide_once_custom(entity, solid);
}

static inline void collide_with_custom(entity_t *obj, entity_t *blc)
{
    if (blc == NULL
        || obj->pos.v1.x > blc->pos.v2.x || obj->pos.v2.x < blc->pos.v1.x
        || obj->pos.v1.y > blc->pos.v2.y || obj->pos.v2.y < blc->pos.v1.y)
        return;
    if (obj->pos.v1.y - obj->vel.y + 0.1f > blc->pos.v2.y - blc->vel.y) {
        obj->pos.v1.y = blc->pos.v2.y;
        obj->pos.v2.y = blc->pos.v2.y + obj->size[1];
        obj->vel.y = 0.f;
        blc->custom_y(blc, obj);
    } else if (obj->pos.v2.y - obj->vel.y < blc->pos.v1.y - blc->vel.y + 0.1f) {
        obj->pos.v1.y = blc->pos.v1.y - obj->size[1];
        obj->pos.v2.y = blc->pos.v1.y;
        obj->vel.y = 0.f;
        blc->custom_y(blc, obj);
    } else
        collide_dual_custom(obj, blc);
}

#endif /* INTERNAL_COLLIDER_H_ */
