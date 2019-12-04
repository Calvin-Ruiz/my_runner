/*
** EPITECH PROJECT, 2019
** entitylib
** File description:
** score.c
*/
#include "include/entity.h"
#include "include/data_storage.h"

void score_entity_update(entity_t *self, float delta_time)
{
    self->timer += delta_time;
    self->pos.v1.y += self->vel.x * delta_time;
    if (self->timer > 0.5f)
        self->health = 0;
}

entity_t *create_score_entity(sfTexture *t, uint_t *size, float fdelay, int hp)
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
    new->update = score_entity_update;
    new->custom = no_custom;
    return (new);
}
