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
    if (entity->pos.v1.x - entity->vel.x >= solid->pos.v2.x) {
        entity->pos.v1.x = solid->pos.v2.x;
        entity->vel.x = 0.f;
    } else if (entity->pos.v2.x - entity->vel.x <= solid->pos.v1.x) {
        entity->pos.v1.x = solid->pos.v1.x - *(entity->size);
        entity->vel.x = 0.f;
    }
    if (entity->pos.v1.y - entity->vel.y >= solid->pos.v2.y) {
        entity->pos.v1.y = solid->pos.v2.y;
        entity->vel.y = 0.f;
    } else if (entity->pos.v2.y - entity->vel.y <= solid->pos.v1.y) {
        entity->pos.v1.y = solid->pos.v1.y - entity->size[1];
        entity->vel.y = 0.f;
    }
}

static inline void collide(entity_t *mov, entity_t *blc)
{
    if (mov == NULL
        || mov->pos.v1.x > blc->pos.v2.x || mov->pos.v2.x < blc->pos.v1.x
        || mov->pos.v1.y > blc->pos.v2.y || mov->pos.v2.y < blc->pos.v1.y)
        return;
    if (mov->pos.v1.y - mov->vel.y >= blc->pos.v2.y - blc->vel.y) {
        mov->pos.v1.y = blc->pos.v2.y;
        mov->vel.y = 0.f;
    } else if (mov->pos.v2.y - mov->vel.y <= blc->pos.v1.y - blc->vel.y) {
        mov->pos.v1.y = blc->pos.v1.y - mov->size[1];
        mov->vel.y = 0.f;
    } else {
        if (mov->pos.v1.x - mov->vel.x >= blc->pos.v2.x - blc->vel.x) {
            mov->pos.v1.x = blc->pos.v2.x;
            mov->vel.x = 0.f;
        } else if (mov->pos.v2.x - mov->vel.x <= blc->pos.v1.x - blc->vel.x) {
            mov->pos.v1.x = blc->pos.v1.x - *(mov->size);
            mov->vel.x = 0.f;
        }
    }
}

static inline void collide_with_custom(entity_t *entity, entity_t *solid)
{
    if (solid == NULL || entity->pos.v1.x > solid->pos.v2.x
        || entity->pos.v2.x < solid->pos.v1.x || (entity->pos.v1.y >
        solid->pos.v2.y) || entity->pos.v2.y < solid->pos.v1.y)
        return;
    solid->custom(solid, entity);
    if (entity->pos.v1.y - entity->vel.y + 0.1f >= solid->pos.v2.y) {
        entity->pos.v1.y = solid->pos.v2.y;
        entity->vel.y = 0.f;
    } else if (entity->pos.v2.y - entity->vel.y <= solid->pos.v1.y + 0.1f) {
        entity->pos.v1.y = solid->pos.v1.y - entity->size[1];
        entity->vel.y = 0.f;
    } else {
        if (entity->pos.v1.x - entity->vel.x + 0.1f >= solid->pos.v2.x) {
            entity->pos.v1.x = solid->pos.v2.x;
            entity->vel.x = 0.f;
        } else if (entity->pos.v2.x - entity->vel.x <= solid->pos.v1.x + 0.1f) {
            entity->pos.v1.x = solid->pos.v1.x - *(entity->size);
            entity->vel.x = 0.f;
        }
    }
}

#endif /* INTERNAL_COLLIDER_H_ */
