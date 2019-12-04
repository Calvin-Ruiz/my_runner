/*
** EPITECH PROJECT, 2019
** entitylib
** File description:
** bonus.c
*/
#include "include/entity.h"
#include "include/data_storage.h"

void bonus_entity_update(entity_t *self, float delta_time)
{
    self->timer += delta_time;
    self->pos.v1.x += self->vel.x * delta_time;
    self->pos.v1.y = self->pos.v2.y + self->timer * (self->vel.y +
        200.f * self->timer);
    if (self->pos.v1.y > 800)
        self->health = 0;
}

entity_t *create_bonus_entity(sfTexture *t, uint_t *size, float fdelay, int hp)
{
    entity_t *new = malloc(sizeof(entity_t));

    if (new == NULL || t == NULL || size == NULL)
        return (NULL);
    new->sprite = malloc(sizeof(void *) * size[2] * 4);
    if (new->sprite == NULL)
        return (NULL);
    create_sprite(new->sprite, t, size);
    new->size = size;
    new->health = hp;
    new->frame = 0;
    new->frame_delay = fdelay;
    new->update = bonus_entity_update;
    new->custom = no_custom;
    return (new);
}
