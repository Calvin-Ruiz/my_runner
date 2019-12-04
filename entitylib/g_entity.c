/*
** EPITECH PROJECT, 2019
** entitylib
** File description:
** g_entity.c
*/
#include "include/entity.h"
#include "include/entitylist.h"
#include "include/data_storage.h"

void g_entity_update(entity_t *self, float delta_time)
{
    self->timer += delta_time;
    if (self->timer > self->frame_delay) {
        self->timer -= self->frame_delay;
        self->frame = (self->frame + 1) & 3;
    }
}

entity_t *create_g_entity(sfTexture *t, uint_t *size, float fdelay, int hp)
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
    new->frame_delay = fdelay;
    new->update = g_entity_update;
    new->custom = no_custom;
    return (new);
}
